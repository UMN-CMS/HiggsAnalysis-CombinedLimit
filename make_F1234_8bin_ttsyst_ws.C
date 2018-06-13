// Config that uses 8 bins (Njets=7,...,14), and uses N7 for
//  the bases of calculating the other Njets bins.
// rateParam is used for normalization of tt background.
// Aron Soha
// May 7, 2018

void make_F1234_8bin_ttsyst_ws() {
  using namespace RooFit;
  // Load the combine library to get access to the RooParametricHist
  gSystem->Load("libHiggsAnalysisCombinedLimit.so");
    
  // Output file and workspace 
  TFile *fOut = new TFile("multiF_syst_ws.root","RECREATE");
  RooWorkspace *wspace = new RooWorkspace("wspace","wspace");
  //RooWorkspace *wspace = new RooWorkspace("wspace",false);

  // njet is our variable, 8 bins, from 7 up through 14,
  //   Note that njet=14 is inclusive as >=14
  wspace->factory("nj_F1[6.5,14.5]");
  wspace->var("nj_F1")->setBins(8);
  RooArgSet vars_F1(*wspace->var("nj_F1"));

  wspace->factory("nj_F2[6.5,14.5]");
  wspace->var("nj_F2")->setBins(8);
  RooArgSet vars_F2(*wspace->var("nj_F2"));

  wspace->factory("nj_F3[6.5,14.5]");
  wspace->var("nj_F3")->setBins(8);
  RooArgSet vars_F3(*wspace->var("nj_F3"));

  wspace->factory("nj_F4[6.5,14.5]");
  wspace->var("nj_F4")->setBins(8);
  RooArgSet vars_F4(*wspace->var("nj_F4"));

    
  // file for obtaining histograms
  TFile* file = TFile::Open("njets_rebinned.root");

  TH1* data_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 550",data_th1_F1);
  //file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodata",data_th1_F1);
  TH1* ttMC_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_TT",ttMC_th1_F1);
  TH1D* ttMC_syst_th1_F1 = 0;
  file->GetObject("tt_F1_syst",ttMC_syst_th1_F1);
  TH1* otherMC_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_other",otherMC_th1_F1);
  TH1* sigMC_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 550",sigMC_th1_F1);

  TH1* data_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 550",data_th1_F2);
  //file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodata",data_th1_F2);
  TH1* ttMC_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_TT",ttMC_th1_F2);
  TH1D* ttMC_syst_th1_F2 = 0;
  file->GetObject("tt_F2_syst",ttMC_syst_th1_F2);
  TH1* otherMC_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_other",otherMC_th1_F2);
  TH1* sigMC_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 550",sigMC_th1_F2);

  TH1* data_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 550",data_th1_F3);
  //file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodata",data_th1_F3);
  TH1* ttMC_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_TT",ttMC_th1_F3);
  TH1D* ttMC_syst_th1_F3 = 0;
  file->GetObject("tt_F3_syst",ttMC_syst_th1_F3);
  TH1* otherMC_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_other",otherMC_th1_F3);
  TH1* sigMC_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 550",sigMC_th1_F3);

  TH1* data_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 550",data_th1_F4);
  //file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodata",data_th1_F4);
  TH1* ttMC_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_TT",ttMC_th1_F4);
  TH1D* ttMC_syst_th1_F4 = 0;
  file->GetObject("tt_F4_syst",ttMC_syst_th1_F4);
  TH1* otherMC_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_other",otherMC_th1_F4);
  TH1* sigMC_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 550",sigMC_th1_F4);


  // tt bkg param setup
  //wspace->factory("p0_tt[0.35,0.14,.54]");
  //wspace->factory("p1_tt[0.21,0.15,0.35]");	
  //wspace->factory("p2_tt[-0.25,-0.52,-0.05]");
  wspace->factory("p0_tt[0.35,0.0,1.00]");
  wspace->factory("p1_tt[0.21,-1.00,1.00]");	
  wspace->factory("p2_tt[-0.25,-1.00,0.0]");

  double_t n7_tt_portion_F1 = data_th1_F1->GetBinContent(1) - otherMC_th1_F1->GetBinContent(1) - sigMC_th1_F1->GetBinContent(1);
  wspace->factory(TString::Format("N7_tt_F1[%f,%f,%f]",n7_tt_portion_F1,n7_tt_portion_F1-5000,n7_tt_portion_F1+5000));

  double_t n7_tt_portion_F2 = data_th1_F2->GetBinContent(1) - otherMC_th1_F2->GetBinContent(1) - sigMC_th1_F2->GetBinContent(1);
  wspace->factory(TString::Format("N7_tt_F2[%f,%f,%f]",n7_tt_portion_F2,n7_tt_portion_F2-5000,n7_tt_portion_F2+5000));

  double_t n7_tt_portion_F3 = data_th1_F3->GetBinContent(1) - otherMC_th1_F3->GetBinContent(1) - sigMC_th1_F3->GetBinContent(1);
  wspace->factory(TString::Format("N7_tt_F3[%f,%f,%f]",n7_tt_portion_F3,n7_tt_portion_F3-5000,n7_tt_portion_F3+5000));

  double_t n7_tt_portion_F4 = data_th1_F4->GetBinContent(1) - otherMC_th1_F4->GetBinContent(1) - sigMC_th1_F4->GetBinContent(1);
  wspace->factory(TString::Format("N7_tt_F4[%f,%f,%f]",n7_tt_portion_F4,n7_tt_portion_F4-5000,n7_tt_portion_F4+5000));

  wspace->factory("np_tt_F1[1.0]");
  wspace->factory("np_tt_F2[1.0]");
  wspace->factory("np_tt_F3[1.0]");
  wspace->factory("np_tt_F4[1.0]");

    

  // ---------------------- Fisher bin 1  ------------------

  // Dataset with 8 rbins
  RooDataHist data_hist_F1("data_obs_F1","Data observed in Fisher bin 1",vars_F1,data_th1_F1);
  wspace->import(data_hist_F1);

  // ttbar bkg in F1
  wspace->import(*ttMC_syst_th1_F1);
  RooNjetsSystPdf background_tt_F1("background_tt_F1","background_tt_F1",*wspace->var("nj_F1"),*wspace->var("p0_tt"),*wspace->var("p1_tt"),*wspace->var("p2_tt"),*wspace->var("N7_tt_F1"),*wspace->var("np_tt_F1"),*ttMC_syst_th1_F1);
  wspace->import(background_tt_F1);
  //wspace->factory("RooNjetsSystPdf::background_tt_F1(nj_F1,p0_tt,p1_tt,p2_tt,N7_tt_F1,np_tt_F1,*tt_F1_syst)");
  //wspace->import(*wspace->pdf("background_tt_F1"));

  // other bkg in F1
  RooDataHist background_other_F1("background_other_F1","other MC observed in Fisher bin 1",vars_F1,otherMC_th1_F1);
  wspace->import(background_other_F1);

  // signal in F1
  RooDataHist sigMC_hist_F1("sigMC_hist_F1","signal MC in Fisher bin 1",vars_F1,sigMC_th1_F1);
  wspace->import(*(new RooHistPdf("signal_F1","",vars_F1,sigMC_hist_F1)));

  // ---------------------- Fisher bin 2  ------------------

  // Dataset with 8 rbins
  RooDataHist data_hist_F2("data_obs_F2","Data observed in Fisher bin 2",vars_F2,data_th1_F2);
  wspace->import(data_hist_F2);

  // ttbar bkg in F2
  wspace->import(*ttMC_syst_th1_F2);
  RooNjetsSystPdf background_tt_F2("background_tt_F2","background_tt_F2",*wspace->var("nj_F2"),*wspace->var("p0_tt"),*wspace->var("p1_tt"),*wspace->var("p2_tt"),*wspace->var("N7_tt_F2"),*wspace->var("np_tt_F2"),*ttMC_syst_th1_F2);
  wspace->import(background_tt_F2);
  //wspace->factory("RooNjetsSystPdf::background_tt_F2(nj_F2,p0_tt,p1_tt,p2_tt,N7_tt_F2,np_tt_F2,tt_F2_syst)");
  //wspace->import(*wspace->pdf("background_tt_F2"));

  // other bkg in F2
  RooDataHist background_other_F2("background_other_F2","other MC observed in Fisher bin 2",vars_F2,otherMC_th1_F2);
  wspace->import(background_other_F2);

  // signal in F2
  RooDataHist sigMC_hist_F2("sigMC_hist_F2","signal MC in Fisher bin 2",vars_F2,sigMC_th1_F2);
  wspace->import(*(new RooHistPdf("signal_F2","",vars_F2,sigMC_hist_F2)));

  // ---------------------- Fisher bin 3  ------------------

  // Dataset with 8 rbins
  RooDataHist data_hist_F3("data_obs_F3","Data observed in Fisher bin 3",vars_F3,data_th1_F3);
  wspace->import(data_hist_F3);

  // ttbar bkg in F3
  wspace->import(*ttMC_syst_th1_F3);
  RooNjetsSystPdf background_tt_F3("background_tt_F3","background_tt_F3",*wspace->var("nj_F3"),*wspace->var("p0_tt"),*wspace->var("p1_tt"),*wspace->var("p2_tt"),*wspace->var("N7_tt_F3"),*wspace->var("np_tt_F3"),*ttMC_syst_th1_F3);
  wspace->import(background_tt_F3);
  //wspace->factory("RooNjetsSystPdf::background_tt_F3(nj_F3,p0_tt,p1_tt,p2_tt,N7_tt_F3,np_tt_F3,tt_F3_syst)");
  //wspace->import(*wspace->pdf("background_tt_F3"));

  // other bkg in F3
  RooDataHist background_other_F3("background_other_F3","other MC observed in Fisher bin 3",vars_F3,otherMC_th1_F3);
  wspace->import(background_other_F3);

  // signal in F3
  RooDataHist sigMC_hist_F3("sigMC_hist_F3","signa3 MC in Fisher bin 3",vars_F3,sigMC_th1_F3);
  wspace->import(*(new RooHistPdf("signal_F3","",vars_F3,sigMC_hist_F3)));


  // ---------------------- Fisher bin 4  ------------------

  // Dataset with 8 rbins
  RooDataHist data_hist_F4("data_obs_F4","Data observed in Fisher bin 4",vars_F4,data_th1_F4);
  wspace->import(data_hist_F4);

  // ttbar bkg in F4
  wspace->import(*ttMC_syst_th1_F4);
  RooNjetsSystPdf background_tt_F4("background_tt_F4","background_tt_F4",*wspace->var("nj_F4"),*wspace->var("p0_tt"),*wspace->var("p1_tt"),*wspace->var("p2_tt"),*wspace->var("N7_tt_F4"),*wspace->var("np_tt_F4"),*ttMC_syst_th1_F4);
  wspace->import(background_tt_F4);
  //wspace->factory("RooNjetsSystPdf::background_tt_F4(nj_F4,p0_tt,p1_tt,p2_tt,N7_tt_F4,np_tt_F4,tt_F4_syst)");
  //wspace->import(*wspace->pdf("background_tt_F4"));

  // other bkg in F4
  RooDataHist background_other_F4("background_other_F4","other MC observed in Fisher bin 4",vars_F4,otherMC_th1_F4);
  wspace->import(background_other_F4);

  // signal in F4
  RooDataHist sigMC_hist_F4("sigMC_hist_F4","signal MC in Fisher bin 4",vars_F4,sigMC_th1_F4);
  wspace->import(*(new RooHistPdf("signal_F4","",vars_F4,sigMC_hist_F4)));


  // =================================================================================

  // Create the funcitonal form for tt bakcground normalization rateParam
  //  for each of the Fisher bins

  // The normalization expression takes the form:
   // N7+g7
   // + (N7+g7)*a0+g8
   // + ((N7+g7)*a0+g8)*a1+g9
   // + (((N7+g7)*a0+g8)*a1+g9)*a2+g10
   // + ((((N7+g7)*a0+g8)*a1+g9)*a2+g10)*a3+g11
   // + (((((N7+g7)*a0+g8)*a1+g9)*a2+g10)*a3+g11)*a4+g12
   // + ((((((N7+g7)*a0+g8)*a1+g9)*a2+g10)*a3+g11)*a4+g12)*a5+g13
   // + (((((((N7+g7)*a0+g8)*a1+g9)*a2+g10)*a3+g11)*a4+g12)*a5+g13)*a6+g14

   //   where gN = (np-1)*syst_N
   //   and   aN = p1 + (p0-p1)e^(N*p2)

  wspace->factory(TString::Format("expr::ttBkgRateF1('@3+(@4-1)*%f + (@3+(@4-1)*%f)*@0+(@4-1)*%f + ((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f + (((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f + ((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f + (((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(4*@2))+(@4-1)*%f + ((((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(4*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(5*@2))+(@4-1)*%f + (((((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(4*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(5*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(6*@2))+(@4-1)*%f',{p0_tt,p1_tt,p2_tt,N7_tt_F1,np_tt_F1})",
   ttMC_syst_th1_F1->GetBinContent(1),
   ttMC_syst_th1_F1->GetBinContent(1),ttMC_syst_th1_F1->GetBinContent(2),
   ttMC_syst_th1_F1->GetBinContent(1),ttMC_syst_th1_F1->GetBinContent(2),ttMC_syst_th1_F1->GetBinContent(3),
   ttMC_syst_th1_F1->GetBinContent(1),ttMC_syst_th1_F1->GetBinContent(2),ttMC_syst_th1_F1->GetBinContent(3),ttMC_syst_th1_F1->GetBinContent(4),
   ttMC_syst_th1_F1->GetBinContent(1),ttMC_syst_th1_F1->GetBinContent(2),ttMC_syst_th1_F1->GetBinContent(3),ttMC_syst_th1_F1->GetBinContent(4),ttMC_syst_th1_F1->GetBinContent(5),
   ttMC_syst_th1_F1->GetBinContent(1),ttMC_syst_th1_F1->GetBinContent(2),ttMC_syst_th1_F1->GetBinContent(3),ttMC_syst_th1_F1->GetBinContent(4),ttMC_syst_th1_F1->GetBinContent(5),ttMC_syst_th1_F1->GetBinContent(6),
   ttMC_syst_th1_F1->GetBinContent(1),ttMC_syst_th1_F1->GetBinContent(2),ttMC_syst_th1_F1->GetBinContent(3),ttMC_syst_th1_F1->GetBinContent(4),ttMC_syst_th1_F1->GetBinContent(5),ttMC_syst_th1_F1->GetBinContent(6),ttMC_syst_th1_F1->GetBinContent(7),
   ttMC_syst_th1_F1->GetBinContent(1),ttMC_syst_th1_F1->GetBinContent(2),ttMC_syst_th1_F1->GetBinContent(3),ttMC_syst_th1_F1->GetBinContent(4),ttMC_syst_th1_F1->GetBinContent(5),ttMC_syst_th1_F1->GetBinContent(6),ttMC_syst_th1_F1->GetBinContent(7),ttMC_syst_th1_F1->GetBinContent(8)
   ));


  wspace->import(*wspace->function("ttBkgRateF1"));

  wspace->factory(TString::Format("expr::ttBkgRateF2('@3+(@4-1)*%f + (@3+(@4-1)*%f)*@0+(@4-1)*%f + ((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f + (((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f + ((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f + (((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(4*@2))+(@4-1)*%f + ((((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(4*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(5*@2))+(@4-1)*%f + (((((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(4*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(5*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(6*@2))+(@4-1)*%f',{p0_tt,p1_tt,p2_tt,N7_tt_F2,np_tt_F2})",
   ttMC_syst_th1_F2->GetBinContent(1),
   ttMC_syst_th1_F2->GetBinContent(1),ttMC_syst_th1_F2->GetBinContent(2),
   ttMC_syst_th1_F2->GetBinContent(1),ttMC_syst_th1_F2->GetBinContent(2),ttMC_syst_th1_F2->GetBinContent(3),
   ttMC_syst_th1_F2->GetBinContent(1),ttMC_syst_th1_F2->GetBinContent(2),ttMC_syst_th1_F2->GetBinContent(3),ttMC_syst_th1_F2->GetBinContent(4),
   ttMC_syst_th1_F2->GetBinContent(1),ttMC_syst_th1_F2->GetBinContent(2),ttMC_syst_th1_F2->GetBinContent(3),ttMC_syst_th1_F2->GetBinContent(4),ttMC_syst_th1_F2->GetBinContent(5),
   ttMC_syst_th1_F2->GetBinContent(1),ttMC_syst_th1_F2->GetBinContent(2),ttMC_syst_th1_F2->GetBinContent(3),ttMC_syst_th1_F2->GetBinContent(4),ttMC_syst_th1_F2->GetBinContent(5),ttMC_syst_th1_F2->GetBinContent(6),
   ttMC_syst_th1_F2->GetBinContent(1),ttMC_syst_th1_F2->GetBinContent(2),ttMC_syst_th1_F2->GetBinContent(3),ttMC_syst_th1_F2->GetBinContent(4),ttMC_syst_th1_F2->GetBinContent(5),ttMC_syst_th1_F2->GetBinContent(6),ttMC_syst_th1_F2->GetBinContent(7),
   ttMC_syst_th1_F2->GetBinContent(1),ttMC_syst_th1_F2->GetBinContent(2),ttMC_syst_th1_F2->GetBinContent(3),ttMC_syst_th1_F2->GetBinContent(4),ttMC_syst_th1_F2->GetBinContent(5),ttMC_syst_th1_F2->GetBinContent(6),ttMC_syst_th1_F2->GetBinContent(7),ttMC_syst_th1_F2->GetBinContent(8)
   ));

  wspace->import(*wspace->function("ttBkgRateF2"));

  wspace->factory(TString::Format("expr::ttBkgRateF3('@3+(@4-1)*%f + (@3+(@4-1)*%f)*@0+(@4-1)*%f + ((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f + (((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f + ((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f + (((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(4*@2))+(@4-1)*%f + ((((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(4*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(5*@2))+(@4-1)*%f + (((((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(4*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(5*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(6*@2))+(@4-1)*%f',{p0_tt,p1_tt,p2_tt,N7_tt_F3,np_tt_F3})",
   ttMC_syst_th1_F3->GetBinContent(1),
   ttMC_syst_th1_F3->GetBinContent(1),ttMC_syst_th1_F3->GetBinContent(2),
   ttMC_syst_th1_F3->GetBinContent(1),ttMC_syst_th1_F3->GetBinContent(2),ttMC_syst_th1_F3->GetBinContent(3),
   ttMC_syst_th1_F3->GetBinContent(1),ttMC_syst_th1_F3->GetBinContent(2),ttMC_syst_th1_F3->GetBinContent(3),ttMC_syst_th1_F3->GetBinContent(4),
   ttMC_syst_th1_F3->GetBinContent(1),ttMC_syst_th1_F3->GetBinContent(2),ttMC_syst_th1_F3->GetBinContent(3),ttMC_syst_th1_F3->GetBinContent(4),ttMC_syst_th1_F3->GetBinContent(5),
   ttMC_syst_th1_F3->GetBinContent(1),ttMC_syst_th1_F3->GetBinContent(2),ttMC_syst_th1_F3->GetBinContent(3),ttMC_syst_th1_F3->GetBinContent(4),ttMC_syst_th1_F3->GetBinContent(5),ttMC_syst_th1_F3->GetBinContent(6),
   ttMC_syst_th1_F3->GetBinContent(1),ttMC_syst_th1_F3->GetBinContent(2),ttMC_syst_th1_F3->GetBinContent(3),ttMC_syst_th1_F3->GetBinContent(4),ttMC_syst_th1_F3->GetBinContent(5),ttMC_syst_th1_F3->GetBinContent(6),ttMC_syst_th1_F3->GetBinContent(7),
   ttMC_syst_th1_F3->GetBinContent(1),ttMC_syst_th1_F3->GetBinContent(2),ttMC_syst_th1_F3->GetBinContent(3),ttMC_syst_th1_F3->GetBinContent(4),ttMC_syst_th1_F3->GetBinContent(5),ttMC_syst_th1_F3->GetBinContent(6),ttMC_syst_th1_F3->GetBinContent(7),ttMC_syst_th1_F3->GetBinContent(8)
   ));

  wspace->import(*wspace->function("ttBkgRateF3"));

  wspace->factory(TString::Format("expr::ttBkgRateF4('@3+(@4-1)*%f + (@3+(@4-1)*%f)*@0+(@4-1)*%f + ((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f + (((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f + ((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f + (((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(4*@2))+(@4-1)*%f + ((((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(4*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(5*@2))+(@4-1)*%f + (((((((@3+(@4-1)*%f)*@0+(@4-1)*%f)*(@1+(@0-@1)*exp(@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(2*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(3*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(4*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(5*@2))+(@4-1)*%f)*(@1+(@0-@1)*exp(6*@2))+(@4-1)*%f',{p0_tt,p1_tt,p2_tt,N7_tt_F4,np_tt_F4})",
   ttMC_syst_th1_F4->GetBinContent(1),
   ttMC_syst_th1_F4->GetBinContent(1),ttMC_syst_th1_F4->GetBinContent(2),
   ttMC_syst_th1_F4->GetBinContent(1),ttMC_syst_th1_F4->GetBinContent(2),ttMC_syst_th1_F4->GetBinContent(3),
   ttMC_syst_th1_F4->GetBinContent(1),ttMC_syst_th1_F4->GetBinContent(2),ttMC_syst_th1_F4->GetBinContent(3),ttMC_syst_th1_F4->GetBinContent(4),
   ttMC_syst_th1_F4->GetBinContent(1),ttMC_syst_th1_F4->GetBinContent(2),ttMC_syst_th1_F4->GetBinContent(3),ttMC_syst_th1_F4->GetBinContent(4),ttMC_syst_th1_F4->GetBinContent(5),
   ttMC_syst_th1_F4->GetBinContent(1),ttMC_syst_th1_F4->GetBinContent(2),ttMC_syst_th1_F4->GetBinContent(3),ttMC_syst_th1_F4->GetBinContent(4),ttMC_syst_th1_F4->GetBinContent(5),ttMC_syst_th1_F4->GetBinContent(6),
   ttMC_syst_th1_F4->GetBinContent(1),ttMC_syst_th1_F4->GetBinContent(2),ttMC_syst_th1_F4->GetBinContent(3),ttMC_syst_th1_F4->GetBinContent(4),ttMC_syst_th1_F4->GetBinContent(5),ttMC_syst_th1_F4->GetBinContent(6),ttMC_syst_th1_F4->GetBinContent(7),
   ttMC_syst_th1_F4->GetBinContent(1),ttMC_syst_th1_F4->GetBinContent(2),ttMC_syst_th1_F4->GetBinContent(3),ttMC_syst_th1_F4->GetBinContent(4),ttMC_syst_th1_F4->GetBinContent(5),ttMC_syst_th1_F4->GetBinContent(6),ttMC_syst_th1_F4->GetBinContent(7),ttMC_syst_th1_F4->GetBinContent(8)
   ));

  wspace->import(*wspace->function("ttBkgRateF4"));

  // ---------------------------------------------------------------------------------

   
  fOut->cd();
  wspace->Write();

  // TCanvas *c1 = new TCanvas("c1","c1");
  // data_hist_F4.createHistogram("nj")->Draw("H");

  // TCanvas *c2 = new TCanvas("c2","c2");
  // ttMC_hist_F4.createHistogram("nj")->Draw("H");

  // TCanvas *c3 = new TCanvas("c3","c3");
  // otherMC_hist_F4.createHistogram("nj")->Draw("H");

  // TCanvas *c4 = new TCanvas("c4","c4");
  // sigMC_hist_F4.createHistogram("nj")->Draw("H");


  // TCanvas *c1 = new TCanvas("c1","c1");
  // data_hist_F4.createHistogram("nj")->Draw("H");

  // TCanvas *c2 = new TCanvas("c2","c2");
  // ttMC_hist_F4.createHistogram("nj")->Draw("H");

  // TCanvas *c3 = new TCanvas("c3","c3");
  // otherMC_hist_F4.createHistogram("nj")->Draw("H");

  // TCanvas *c4 = new TCanvas("c4","c4");
  // sigMC_hist_F4.createHistogram("nj")->Draw("H");


}
