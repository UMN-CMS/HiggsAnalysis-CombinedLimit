// Config that uses 8 bins (Njets=7,...,14), and uses N7 for
//  the bases of calculating the other Njets bins.
// tt Njets shape systematic is included.
// Aron Soha
// May 7, 2018
// Sep 19, 2018 : This version now uses the new DeepESM descriminant (instead of the Fisher)
// Nov 2, 2018 : This version switches to using RooParametricHist for ttbar
// Nov 13, 2018 : Added helper function to construct RooArgList of RooFormulaVar's for tt bkg,
//                and feature to allow highest njets bin to be inclusive up to a set number.
// Nov 14, 2018 : Add multiplicative ttbar shape systematics with log normal nuisance parameters.
// Dec 12, 2018 : Switched to new fit function for tt background (solves correlation issue).

#include "RooArgSet.h"
#include "RooArgList.h"
#include "RooFormulaVar.h"
#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooDataHist.h"
#include "interface/RooParametricHist.h"

#include "TH1.h"
#include "TFile.h"
#include "TSystem.h"
#include "TTreeFormulaManager.h"

#include <iostream>
#include <sstream>
#include <string>

class NuisanceParam
{
private:
    const bool useNPYear(const std::pair<std::string, std::vector<int>>& yearMatch)
    {
        bool useNP = true;
        if(yearMatch.second.size())
        {
            useNP = false;
            for(auto year : yearMatch.second)
            {
                if(std::to_string(year) == yearMatch.first)  useNP = true;
            }
        }
        return useNP;
    }

    template<typename T> T* getSysHist(TFile* tt_syst_file, const std::string& h_name)
    {
        auto* h = static_cast<T*>(tt_syst_file->Get(h_name.c_str()));
        if(h == nullptr) 
        {
            std::cout<<"Error: This histogram \""<<h_name<<"\" was not found in the ttbar_systematic.root file"<<std::endl;
            exit(0);
        }
        return h;
    } 

public:
    enum NuisanceType {NORMAL, RPRIME, RFIT};

    const RooAbsArg& r_name;
    const TH1D* h_r;
    const TH1D* h_rprime;
    RooArgList rprime_names;
    std::map<int, std::vector<double>> coefMap;
    RooArgList coefNames;
    bool useNP;
    NuisanceType type;

    NuisanceParam(const RooAbsArg& r_name, std::map<int, std::vector<double>> coefMap, RooArgList coefNames) 
        : r_name(r_name)
        , h_r(nullptr)
        , h_rprime(nullptr)
        , coefMap(coefMap)
        , coefNames(coefNames)
        , type(RFIT)
        , useNP(true)
    {        
    }
    
    NuisanceParam(const RooAbsArg& r_name, const TH1D* h_r, const TH1D* h_rprime, RooArgList rprime_names) 
        : r_name(r_name)
        , h_r(h_r)
        , h_rprime(h_rprime)
        , rprime_names(rprime_names)
        , type(RPRIME)
        , useNP(true)
    {        
    }

    NuisanceParam(const RooAbsArg& r_name, const TH1D* h_r, const std::pair<std::string, std::vector<int>>& yearMatch = {}) 
        : r_name(r_name)
        , h_r(h_r)
        , h_rprime(nullptr)
        , type(NORMAL)
    {
        useNP = useNPYear(yearMatch);
    }

    NuisanceParam(const RooAbsArg& r_name, TFile* tt_syst_file, const std::string& h_name, const std::pair<std::string, std::vector<int>>& yearMatch = {}) 
        : NuisanceParam(r_name, getSysHist<TH1D>(tt_syst_file, h_name), yearMatch) 
    {
    }
};

Double_t step(double_t x) 
{
    return 1;
}

void addNPs(stringstream& f, RooArgList& list, const double r, const RooAbsArg& NP)
{
    std::string paramNum = std::to_string(list.getSize());
    f << "*TMath::Power(" << r << ",@"+paramNum+")";
    list.add(NP);
}

void addNPs(stringstream& f, RooArgList& list, const double r, const RooAbsArg& NP, const double rprime, const RooAbsArg& NPg)
{
    std::string paramNum  = std::to_string(list.getSize());
    std::string paramNumG = std::to_string(list.getSize()+1);
    f << "*TMath::Power(" << r << ",@"+paramNum+")*TMath::Power(" << rprime << ",@"+paramNumG+"*@"+paramNum+")";
    list.add(NP);
    list.add(NPg);
}

void addNPs(stringstream& f, RooArgList& list, const RooAbsArg& NP, const std::vector<double>& coefVec, const RooArgList& coefNames)
{
    int paramNum  = list.getSize();
    f << "*TMath::Power("<<coefVec[0]<<" + "<<coefVec[1]<<"*@"<<paramNum+1<<" + "<<coefVec[2]<<"*@"<<paramNum+2<<" + "<<coefVec[3]<<"*@"<<paramNum+3<<",@"<<paramNum<<")";
    list.add(NP);
    list.add(coefNames[0]);
    list.add(coefNames[1]);
    list.add(coefNames[2]);
}

template<typename T> void WriteHisto2WS(TFile* f, const std::string& histName, const std::string& wsName, const std::string& bin, const std::string& type = "")
{
    T* h = (T*)f->Get( (bin+"_"+histName).c_str() );
    std::string name = bin+"_"+wsName;
    if( type != "") 
        name = bin+"_"+type+"_mcStat"+bin+type+"Bin"+wsName;
    h->SetName( name.c_str() );
    h->Write();
}

std::string getR(const int j)
{    
    std::stringstream R;
    //R << "@3 + TMath::Power( TMath::Power( @2-@3 , "<<j<<"-0 ) / TMath::Power( @1-@3 , "<<j<<"-2 ) , 1/(2-0) )";
    //R << "@3 + TMath::Power( TMath::Power( @2-@3 , "<<j<<" ) / TMath::Power( @1-@3 , "<<j-2<<" ) , 1/2 )* ( ( @1-@2 > 0) ? 1.0 : 0.0 ) * ((@2-@3 > 0) ? 1.0 : 0.0)";
    //R << "@3 + TMath::Power( TMath::Power( @2-@3 , "<<j<<" ) / TMath::Power( @1-@3 , "<<j-2<<" ) , 1/2 )* ( ((@1-@2<0)(0.0)+(@1-@2>=0)(1.0))*((@2-@3<0)(0.0)+(@2-@3>=0)(1.0)) )";
    //R << "@3 + TMath::Power( TMath::Power( @2-@3 , "<<j<<" ) / TMath::Power( @1-@3 , "<<j-2<<" ) , 1/2 )* step(1.0)";
    //R << "@3 + (@1-@2>0)*(@2-@3>0)*TMath::Power( TMath::Power( @2-@3 , "<<j<<" ) / TMath::Power( @1-@3 , "<<j-2<<" ) , 1/2 )";
    //R << "@3 + TMath::Power( TMath::Power( @2-@3 , "<<j<<" ) / TMath::Power( @1-@3 , "<<j-2<<" ) , 1/2 )";
    //R << "@3 + (@1-@2>0)*(@2-@3>0)*TMath::Power( TMath::Abs( TMath::Power( @2-@3 , "<<j<<" ) / TMath::Power( @1-@3 , "<<j-2<<" ) ) , 1/2 )";
    //R << "@3 + TMath::Power( TMath::Abs( TMath::Power( @2-@3 , "<<j<<" ) / TMath::Power( @1-@3 , "<<j-2<<" ) ) , 1/2 )";
    R << "@3>1 ? ( @2 - 1./@3 + TMath::Power(  TMath::Power( 1./@3 , "<<j<<" ) / TMath::Power( @1-@2+1./@3 , "<<j-2<<" ) , 1/2 ) ) : ( @2 - (2.-@3) + TMath::Power( TMath::Power( (2.-@3) , "<<j<<" ) / TMath::Power( @1-@2+(2.-@3) , "<<j-2<<" ) , 1/2 ) )";
    return R.str();
}

void construct_formula(const std::string& procName, RooArgList& binlist, const RooArgList& paramlist, const std::vector<NuisanceParam>& NPs, TH1D* dyMC_th1_bin) 
{
    // Functional form:
    // f(x) = Njets bin x / Njets bin x-1 = a2 + [ (a1-a2)^(x-a0_val) / (a0-a2)^(x-a1_val) ]^(1/(a1_val-a0_val)) where a1 > a2,
    //   where x = 0 corresponds to 8.
    // a0 = Ratio of Njets=8 to Njets=7
    // a1 = Ratio of Njets=10 to Njets=9
    // a2 = Asymptotic value as Njets-->Inf

    // In terms of njets instead of ratio:
    // F(0) = N7
    // F(1) = N7*f(0)
    // F(2) = F(1)*f(1) = N7*f(0)*f(1)
    //     ...
    // N7 = Njets=7

    //std::cout << "size of NPs: " << NPs.size() << std::endl;
    ROOT::v5::TFormula::SetMaxima(10000);

    // Updated this to go only to 12 jets, rather than 14. So 6 bins instead of 8
    for (int i=0; i<9; i++) 
    {
        std::stringstream form;
        RooArgList formArgList;

        if(i==0){
	  form << "(@0*" << dyMC_th1_bin->GetBinContent(i+1) << " - @1*900.)";
	  formArgList.add(paramlist[0]);
	  formArgList.add(paramlist[1]);
	}else if(i==1){
          form << "(@0*" << dyMC_th1_bin->GetBinContent(i+1) << " - @1*1100.)";
          formArgList.add(paramlist[0]);
          formArgList.add(paramlist[1]);
	}else if(i==2){
          form << "(@0*" << dyMC_th1_bin->GetBinContent(i+1) << " - @1*1300.)";
          formArgList.add(paramlist[0]);
          formArgList.add(paramlist[1]);
	}else if(i==3){
          form << "(@0*" << dyMC_th1_bin->GetBinContent(i+1) << " - @1*1500.)";
          formArgList.add(paramlist[0]);
          formArgList.add(paramlist[1]);
	}else if(i==4){
          form << "(@0*" << dyMC_th1_bin->GetBinContent(i+1) <<" - @1*1800.)";
          formArgList.add(paramlist[0]);
          formArgList.add(paramlist[1]);
	}else if(i==5){
          form << "(@0*" << dyMC_th1_bin->GetBinContent(i+1) <<" - @1*2200.)";
          formArgList.add(paramlist[0]);
          formArgList.add(paramlist[1]);
	}else if(i==6){
          form << "(@0*" << dyMC_th1_bin->GetBinContent(i+1) <<" - @1*2600.)";
          formArgList.add(paramlist[0]);
          formArgList.add(paramlist[1]);
	}else if(i==7){
          form << "(@0*" << dyMC_th1_bin->GetBinContent(i+1) <<" - @1*3000.)";
          formArgList.add(paramlist[0]);
          formArgList.add(paramlist[1]);
	}else if(i==8){
          form << "(@0*" << dyMC_th1_bin->GetBinContent(i+1) <<" - @1*5600.)";
          formArgList.add(paramlist[0]);
          formArgList.add(paramlist[1]);
	}

        // Add nuisance parameters
        //std::cout<<"Adding NP"<<std::endl;
/*        for(unsigned int j = 0; j < NPs.size(); j++)
        {
            if(!NPs[j].useNP) continue;

            double r = (NPs[j].h_r) ? NPs[j].h_r->GetBinContent(i+1) : 1.0;
            if(NPs[j].type == NuisanceParam::RPRIME)
            {
                double rprime = NPs[j].h_rprime->GetBinContent(i+1);
                addNPs(form, formArgList, r, NPs[j].r_name, rprime, NPs[j].rprime_names[i]);
            }
            else if(NPs[j].type == NuisanceParam::RFIT)
            {
                if(NPs[j].coefMap.empty()) { std::cout<<"Error: coefMap is empty"<<std::endl; exit(0); }
                addNPs(form, formArgList, NPs[j].r_name, NPs[j].coefMap.find(i+1)->second, NPs[j].coefNames);
            }
            else if(NPs[j].type == NuisanceParam::NORMAL)
            {
                addNPs(form, formArgList, r, NPs[j].r_name);
            }
            else
            {
                std::cout<<"Error: NP type not found"<<std::endl;
                exit(0);
            }
        }*/

        // Create RooFormulaVar for this bin
        std::stringstream binName;
        binName << procName << "_b" << i;
        RooFormulaVar* binvar = new RooFormulaVar(binName.str().c_str(), "", form.str().c_str(), RooArgList(formArgList));
        binlist.add(*binvar);

        std::cout << "bin i = " << i << " , njets = " << i+7 << std::endl;
        std::cout << "process bin name : " << binName.str() << std::endl;
        std::cout << "Formula : " << form.str() << std::endl;
        formArgList.Print();
    }
}

void make_DY_massFit(const std::string year = "2016", const std::string infile_path = "Keras_V1.2.8_Approval_StatErrPlusFullDev_12JetFix", const std::string region = "ZPeak",
                       const std::string syst = "", bool TTonly = false) 
{
    using namespace RooFit;
    // Load the combine library to get access to the RooParametricHist
    gSystem->Load("libHiggsAnalysisCombinedLimit.so");
    
    // Output file and workspace 
//    TFile* fOut = new TFile(("DY_massFit_"+year+"_SRws.root").c_str(),"RECREATE");
    TFile* fOut = new TFile(("DY_massFit_"+year+"_"+region+"ws.root").c_str(),"RECREATE");
    RooWorkspace* wspace = new RooWorkspace("wspace","wspace");
    RooFit::Silence();
    wspace->factory("CMS_th1x[800,8000]");
//    wspace->var("CMS_th1x")->setBinning(9);
    wspace->var("CMS_th1x")->setBins(9);
  
    // file for obtaining histograms
//    TFile* file = TFile::Open((infile_path+"/WR_NR_MuMuJJ_ResolvedSignalRegion2018.root").c_str());
    TFile* file = TFile::Open((infile_path+"/WR_NR_MuMuJJ_Resolved"+region+"2018.root").c_str());

    // tt bkg param setup
    RooRealVar a0_DY(("a0_DY_"+year).c_str(),("a0 of DY bkg shape for "+year).c_str(),1.0,0.5,1.5);
    RooRealVar a1_DY(("a1_DY_"+year).c_str(),("a1 DY  bkg shape for "+year).c_str(),0.0001,0.,0.05);

    // tt shape systematic nuisance parameters
    std::string corrYear = (year == "2016") ? "2016" : "2017_2018";
/*    wspace->factory(("np_tt_pdf_"+corrYear+"[0.0]").c_str()); // uncorrelated for 2016 only
    wspace->factory(("np_tt_FSR_"+corrYear+"[0.0]").c_str()); // uncorrelated for 2016 only
    wspace->factory(("np_tt_ISR_"+corrYear+"[0.0]").c_str()); // uncorrelated for 2016 only
    wspace->factory("np_tt_scl[0.0]"); // correlated
    wspace->factory(("np_tt_erdOn_"+corrYear+"[0.0]").c_str()); // uncorrelated for 2016 only
    wspace->factory(("np_tt_hdampUp_"+corrYear+"[0.0]").c_str()); // uncorrelated for 2016 only
    wspace->factory(("np_tt_hdampDown_"+corrYear+"[0.0]").c_str()); // uncorrelated for 2016 only
    wspace->factory(("np_tt_underlyingEvtUp_"+corrYear+"[0.0]").c_str()); // uncorrelated for 2016 only
    wspace->factory(("np_tt_underlyingEvtDown_"+corrYear+"[0.0]").c_str()); // uncorrelated for 2016 only
    wspace->factory(("np_tt_mpTScaled_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_noHT_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_MADGRAPH_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_CP2CP5_2017_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_prf_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_JECUp_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_JECDown_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_JERUp_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_JERDown_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_btg_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_lep_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_nom_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_qcdCR_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_ht_"+year+"[0.0]").c_str());// uncorrelated
    wspace->factory(("np_tt_httail_"+year+"[0.0]").c_str());// uncorrelated
    wspace->factory(("np_tt_htnjet_"+year+"[0.0]").c_str());// uncorrelated
    wspace->factory(("np_tt_pu_"+year+"[0.0]").c_str());// uncorrelated
    wspace->factory(("np_tt_qcdCRD1Coef1_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_qcdCRD1Coef2_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_qcdCRD1Coef3_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_qcdCRD2Coef1_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_qcdCRD2Coef2_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_qcdCRD2Coef3_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_qcdCRD3Coef1_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_qcdCRD3Coef2_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_qcdCRD3Coef3_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_qcdCRD4Coef1_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_qcdCRD4Coef2_"+year+"[0.0]").c_str()); // uncorrelated
    wspace->factory(("np_tt_qcdCRD4Coef3_"+year+"[0.0]").c_str()); // uncorrelated

    // Load in the histograms with the bin-by-bin ratios to be used in the ttbar shape systematics
    TFile* tt_syst_file = TFile::Open((infile_path+"/ttbar_systematics.root").c_str());
*/

    // ----------------------------------------------------
    // ----------------------  MVA bins   -----------------
    // ----------------------------------------------------
//    const std::vector<std::string>& MVABins = {"D1","D2","D3","D4"};
    const std::vector<std::string>& MVABins = {"MuMuJJ"};
    for(const auto& bin : MVABins)
    {
        // Dataset with 6 bins
        RooArgList vars_bin(*wspace->var("CMS_th1x"));
	cout << "vars_bin" << endl;
	vars_bin.Print("V");

        TH1D* data_th1_bin = nullptr;
        data_th1_bin = (TH1D*)file->Get((bin+"/data_obs").c_str());  // Actual data -- be careful
        TH1D* dyMC_th1_bin = (TH1D*)file->Get((bin+"/DY").c_str());
        TH1D* dibosonMC_th1_bin = (TH1D*)file->Get((bin+"/DiBoson").c_str());
        TH1D* wjetsMC_th1_bin = (TH1D*)file->Get((bin+"/WJets").c_str());
        TH1D* tribosonMC_th1_bin = (TH1D*)file->Get((bin+"/TriBoson").c_str());
        TH1D* stMC_th1_bin = (TH1D*)file->Get((bin+"/ST").c_str());
        TH1D* ttvMC_th1_bin = (TH1D*)file->Get((bin+"/ttV").c_str());
        TH1D* sigMC_th1_bin = (TH1D*)file->Get((bin+"/WR_5000_NR_2600").c_str());

        RooRealVar a0_DY_bin(("a0_DY_"+bin+"_"+year).c_str(),("a0 of DY bkg shape "+bin+" for "+year).c_str(),1.0,0.0,2.0);
        RooRealVar a1_DY_bin(("a1_DY_"+bin+"_"+year).c_str(),("a1 of DY bkg shape "+bin+" for "+year).c_str(),0.24,0.0,1.0);

	cout << "Data hist Integral = " << data_th1_bin->Integral() << endl;
	cout << "Data hist binContent(9) = " << data_th1_bin->GetBinContent(9) << endl;
        RooDataHist data_hist_bin(("data_obs_"+bin).c_str(),("Data observed in region "+bin).c_str(),vars_bin,data_th1_bin);
	//data_hist_bin.Print("V");
	//CMS_th1x = 900.;
	data_hist_bin.get(RooArgSet(*wspace->var("CMS_th1x")))->Print();
	cout << "Data RooDataHist Sum = " << data_hist_bin.weight() << endl;
        wspace->import(data_hist_bin);
  
        //list of nuisance parameters for tt bkg bin
/*        std::vector<NuisanceParam> newNuisance_bin;
        std::vector<NuisanceParam> temp = {
           {*wspace->var(("np_tt_mpTScaled_"+year).c_str()),             tt_syst_file, bin+"_mpTScaled"},
           {*wspace->var(("np_tt_noHT_"+year).c_str()),                  tt_syst_file, bin+"_noHT"},
           {*wspace->var(("np_tt_erdOn_"+corrYear).c_str()),             tt_syst_file, bin+"_erdOn"},
           {*wspace->var(("np_tt_hdampUp_"+corrYear).c_str()),           tt_syst_file, bin+"_hdampUp"},
           {*wspace->var(("np_tt_hdampDown_"+corrYear).c_str()),         tt_syst_file, bin+"_hdampDown"},
           {*wspace->var(("np_tt_underlyingEvtUp_"+corrYear).c_str()),   tt_syst_file, bin+"_underlyingEvtUp"},
           {*wspace->var(("np_tt_underlyingEvtDown_"+corrYear).c_str()), tt_syst_file, bin+"_underlyingEvtDown"},
           {*wspace->var(("np_tt_prf_"+year).c_str()),                   tt_syst_file, bin+"_prf", {year,{2017}}},
        };
        std::move(temp.begin(), temp.end(), std::back_inserter(newNuisance_bin));

        std::vector<NuisanceParam> nuisanceParams_bin = {
            {*wspace->var(("np_tt_pdf_"+corrYear).c_str()),               tt_syst_file, bin+"_pdf"},
            {*wspace->var(("np_tt_FSR_"+corrYear).c_str()),               tt_syst_file, bin+"_FSR"},
            {*wspace->var(("np_tt_ISR_"+corrYear).c_str()),               tt_syst_file, bin+"_ISR"},
            {*wspace->var("np_tt_scl"),                                   tt_syst_file, bin+"_scl"},
            {*wspace->var(("np_tt_JECUp_"+year).c_str()),                 tt_syst_file, bin+"_JECUp"},
            {*wspace->var(("np_tt_JECDown_"+year).c_str()),               tt_syst_file, bin+"_JECDown"},
            {*wspace->var(("np_tt_JERUp_"+year).c_str()),                 tt_syst_file, bin+"_JERUp"},
            {*wspace->var(("np_tt_JERDown_"+year).c_str()),               tt_syst_file, bin+"_JERDown"},
            {*wspace->var(("np_tt_btg_"+year).c_str()),                   tt_syst_file, bin+"_btg"},
            {*wspace->var(("np_tt_lep_"+year).c_str()),                   tt_syst_file, bin+"_lep"},
            {*wspace->var(("np_tt_nom_"+year).c_str()),                   tt_syst_file, bin+"_nom"},
            {*wspace->var(("np_tt_ht_"+year).c_str()),                    tt_syst_file, bin+"_ht"},
            {*wspace->var(("np_tt_httail_"+year).c_str()),                tt_syst_file, bin+"_httail"},
            {*wspace->var(("np_tt_htnjet_"+year).c_str()),                tt_syst_file, bin+"_htnjet"},
            {*wspace->var(("np_tt_pu_"+year).c_str()),                    tt_syst_file, bin+"_pu"},
            {
                *wspace->var(("np_tt_qcdCR_"+year).c_str()), qcdcrMap[qcdcrYear]["MVABin"+bin],
                {
                    *wspace->var(("np_tt_qcdCR"+bin+"Coef1_"+year).c_str()),
                    *wspace->var(("np_tt_qcdCR"+bin+"Coef2_"+year).c_str()),
                    *wspace->var(("np_tt_qcdCR"+bin+"Coef3_"+year).c_str()),
                }
            },
        };
        std::move(newNuisance_bin.begin(), newNuisance_bin.end(), std::back_inserter(nuisanceParams_bin));
*/
        std::vector<NuisanceParam> nuisanceParams_bin;

        RooArgList* bkg_DY_bins_bin = new RooArgList();
//        std::string procName_bin = "background_DY_SR_"+year;
        std::string procName_bin = "background_DY_"+region+"_"+year;
//        std::string procName_bin = "background_DY_"+bin+"_"+year;

        RooArgList parlist_bin(a0_DY,a1_DY);  // list of shape parameters for DY bkg
        construct_formula(procName_bin,*bkg_DY_bins_bin,parlist_bin,nuisanceParams_bin,dyMC_th1_bin);
        std::cout << "after constructing formula" << std::endl;

//        RooParametricHist background_DY_bin(procName_bin.c_str(),"",*wspace->var("CMS_th1x"),*bkg_DY_bins_bin,*dyMC_th1_bin);
	cout << "DY RooParametricHist name: " << procName_bin.c_str() << endl;
        RooParametricHist background_DY_bin(procName_bin.c_str(),"",*wspace->var("CMS_th1x"),*bkg_DY_bins_bin,*data_th1_bin);
        wspace->import(background_DY_bin,RooFit::RecycleConflictNodes());
	cout << "DY norm name: " << (procName_bin+"_norm").c_str() << endl;
        RooAddition DY_norm_bin((procName_bin+"_norm").c_str(),"",*bkg_DY_bins_bin);
 	cout << "DY_norm_bin = " << DY_norm_bin.getVal() << endl;
        wspace->import(DY_norm_bin,RooFit::RecycleConflictNodes());

        // Write Shape histograms
        fOut->cd();
/*        sigMC_th1_bin->Write();  
        dibosonMC_th1_bin->Write();  
        tribosonMC_th1_bin->Write();
        wjetsMC_th1_bin->Write();
        stMC_th1_bin->Write();
        ttvMC_th1_bin->Write();**/

        // =================================================================================
        // Systematics
        // =================================================================================
  /*
        // Signal systematics
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_JECUp",   "SIG_JEC_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_JECDown", "SIG_JEC_"+year+"Down", bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_JERUp",   "SIG_JER_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_JERDown", "SIG_JER_"+year+"Down", bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_btgUp",   "SIG_btg_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_btgDown", "SIG_btg_"+year+"Down", bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_lepUp",   "SIG_lep_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_lepDown", "SIG_lep_"+year+"Down", bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_pdfUp",   "SIG_pdf_"+corrYear+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_pdfDown", "SIG_pdf_"+corrYear+"Down", bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_sclUp",   "SIG_sclUp",            bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_sclDown", "SIG_sclDown",          bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_puUp",    "SIG_pu_"+year+"Up",    bin);
        WriteHisto2WS<TH1D>(file, "h_njets_pt30_1l_puDown",  "SIG_pu_"+year+"Down",  bin);

        // "OTHER" background systematics
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_JECUp",   "OTHER_JEC_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_JECDown", "OTHER_JEC_"+year+"Down", bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_JERUp",   "OTHER_JER_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_JERDown", "OTHER_JER_"+year+"Down", bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_btgUp",   "OTHER_btg_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_btgDown", "OTHER_btg_"+year+"Down", bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_lepUp",   "OTHER_lep_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_lepDown", "OTHER_lep_"+year+"Down", bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_pdfUp",   "OTHER_pdf_"+corrYear+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_pdfDown", "OTHER_pdf_"+corrYear+"Down", bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_sclUp",   "OTHER_sclUp",            bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_sclDown", "OTHER_sclDown",          bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_htUp",    "OTHER_ht_"+year+"Up",    bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_htDown",  "OTHER_ht_"+year+"Down",  bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_puUp",    "OTHER_pu_"+year+"Up",    bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_puDown",  "OTHER_pu_"+year+"Down",  bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_prfUp",   "OTHER_prf_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "OTHER_h_njets_pt30_1l_prfDown", "OTHER_prf_"+year+"Down", bin);
    
        // "TTX" background systematics
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_JECUp",   "TTX_JEC_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_JECDown", "TTX_JEC_"+year+"Down", bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_JERUp",   "TTX_JER_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_JERDown", "TTX_JER_"+year+"Down", bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_btgUp",   "TTX_btg_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_btgDown", "TTX_btg_"+year+"Down", bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_lepUp",   "TTX_lep_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_lepDown", "TTX_lep_"+year+"Down", bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_pdfUp",   "TTX_pdf_"+corrYear+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_pdfDown", "TTX_pdf_"+corrYear+"Down", bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_sclUp",   "TTX_sclUp",            bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_sclDown", "TTX_sclDown",          bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_htUp",    "TTX_ht_"+year+"Up",    bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_htDown",  "TTX_ht_"+year+"Down",  bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_puUp",    "TTX_pu_"+year+"Up",    bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_puDown",  "TTX_pu_"+year+"Down",  bin);    
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_prfUp",   "TTX_prf_"+year+"Up",   bin);
        WriteHisto2WS<TH1D>(file, "TTX_h_njets_pt30_1l_prfDown", "TTX_prf_"+year+"Down", bin);    
*/
        // =================================================================================
        // Statistics-based Uncertainties
        // =================================================================================
  /*
        // MC stat uncertainty histograms
        const std::vector<std::string>& nJetBin = {"1","2","3","4","5","6"};
        std::string mcYear = (year == "2018pre" || year == "2018post") ? "2018" : year;
        for(const auto& i : nJetBin)
        {
            // Particular signal model and mass point
            WriteHisto2WS<TH1D>(file, "mcStatBin"+i+"Up",   i+"_"+mcYear+"Up",   bin, "SIG");      
            WriteHisto2WS<TH1D>(file, "mcStatBin"+i+"Down", i+"_"+mcYear+"Down", bin, "SIG");      
            // OTHER backgrounds
            WriteHisto2WS<TH1D>(file, "OTHER_mcStatBin"+i+"Up",   i+"_"+mcYear+"Up",   bin, "OTHER");      
            WriteHisto2WS<TH1D>(file, "OTHER_mcStatBin"+i+"Down", i+"_"+mcYear+"Down", bin, "OTHER");      
            // QCD backgrounds
            WriteHisto2WS<TH1D>(file, "QCD_mcStatBin"+i+"Up",   i+"_"+mcYear+"Up",   bin, "QCD");      
            WriteHisto2WS<TH1D>(file, "QCD_mcStatBin"+i+"Down", i+"_"+mcYear+"Down", bin, "QCD");      
            // TTX backgrounds
            WriteHisto2WS<TH1D>(file, "TTX_mcStatBin"+i+"Up",   i+"_"+mcYear+"Up",   bin, "TTX");      
            WriteHisto2WS<TH1D>(file, "TTX_mcStatBin"+i+"Down", i+"_"+mcYear+"Down", bin, "TTX");      
        }*/
    }
  
    //Finally write out the work space
    cout << "Writing workspace" << endl;
    wspace->Write();
}

int main()
{
    make_DY_massFit();
}
