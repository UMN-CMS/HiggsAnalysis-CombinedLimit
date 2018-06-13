// Fits to background samples
// to extract parameters
// Aron Soha
// April 5, 2018

#include "RooRealVar.h"
#include "RooFitResult.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
#include "TFile.h"
#include "TH2.h"

using namespace RooFit;

void bkg_fits() {

  RooWorkspace *w = new RooWorkspace("w","w");
  w->factory("nj[6.5,14.5]");
  w->var("nj")->setBins(8);
  RooArgSet vars(*w->var("nj"));

  TFile* file = TFile::Open("njets_rebinned.root");

  // tt ---------------------------------------------------------------------------------------

  // F1
  TH1* ttMC_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_TT",ttMC_th1_F1);

  w->factory("p0_tt_F1[0.34,0.14,0.54]");
  w->factory("p1_tt_F1[0.22,0.02,0.42]");
  w->factory("p2_tt_F1[-0.32,-0.52,-0.12]");

  w->factory(TString::Format("N7_tt_F1[%f,%f,%f]",ttMC_th1_F1->GetBinContent(1),ttMC_th1_F1->GetBinContent(1)-5000,ttMC_th1_F1->GetBinContent(1)+5000));
  
  RooDataHist ttMC_hist_F1("ttMC_obs_F1","tt MC observed in signal region 1",vars,ttMC_th1_F1);
  w->import(ttMC_hist_F1);
  // shape for tt bkg MC
  w->factory("RooNjetsPdf::bkgMC_tt_F1(nj,p0_tt_F1,p1_tt_F1,p2_tt_F1,N7_tt_F1)");
  w->import(*w->pdf("bkgMC_tt_F1"));

  RooAbsPdf* model_tt_F1 = w->pdf("bkgMC_tt_F1");
  SumW2Error(kTRUE);
  RooFitResult* r_tt_F1 = model_tt_F1->fitTo(ttMC_hist_F1,Save());
  r_tt_F1->Print("V");

  RooPlot* ttframe_F1 = w->var("nj")->frame(Title("njets tt F1 PDF"));
  ttMC_hist_F1.plotOn(ttframe_F1);
  model_tt_F1->plotOn(ttframe_F1);
  model_tt_F1->paramOn(ttframe_F1,Layout(0.35,0.622912,0.773497));
  ttframe_F1->getAttLine()->SetLineWidth(0);

  //new TCanvas("tt F1 fit result","tt F1 fit results",600,600);
  //gPad->SetLeftMargin(0.15);
  //ttframe_F1->GetYaxis()->SetTitleOffset(2.0);
  //ttframe_F1->Draw();

  // F2
  TH1* ttMC_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_TT",ttMC_th1_F2);

  w->factory("p0_tt_F2[0.34,0.14,0.54]");
  w->factory("p1_tt_F2[0.22,0.02,0.42]");
  w->factory("p2_tt_F2[-0.32,-0.52,-0.12]");

  w->factory(TString::Format("N7_tt_F2[%f,%f,%f]",ttMC_th1_F2->GetBinContent(1),ttMC_th1_F2->GetBinContent(1)-5000,ttMC_th1_F2->GetBinContent(1)+5000));
  
  RooDataHist ttMC_hist_F2("ttMC_obs_F2","tt MC observed in signal region 2",vars,ttMC_th1_F2);
  w->import(ttMC_hist_F2);
  // shape for tt bkg MC
  w->factory("RooNjetsPdf::bkgMC_tt_F2(nj,p0_tt_F2,p1_tt_F2,p2_tt_F2,N7_tt_F2)");
  w->import(*w->pdf("bkgMC_tt_F2"));

  RooAbsPdf* model_tt_F2 = w->pdf("bkgMC_tt_F2");
  SumW2Error(kTRUE);
  RooFitResult* r_tt_F2 = model_tt_F2->fitTo(ttMC_hist_F2,Save());
  r_tt_F2->Print("V");

  RooPlot* ttframe_F2 = w->var("nj")->frame(Title("njets tt F2 PDF"));
  ttMC_hist_F2.plotOn(ttframe_F2);
  model_tt_F2->plotOn(ttframe_F2);
  model_tt_F2->paramOn(ttframe_F2,Layout(0.35,0.622912,0.773497));
  ttframe_F2->getAttLine()->SetLineWidth(0);

  //new TCanvas("tt F2 fit result","tt F2 fit results",600,600);
  //gPad->SetLeftMargin(0.15);
  //ttframe_F2->GetYaxis()->SetTitleOffset(2.0);
  //ttframe_F2->Draw();

  // F3
  TH1* ttMC_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_TT",ttMC_th1_F3);

  w->factory("p0_tt_F3[0.34,0.14,0.54]");
  w->factory("p1_tt_F3[0.22,0.02,0.42]");
  w->factory("p2_tt_F3[-0.32,-0.52,-0.12]");

  w->factory(TString::Format("N7_tt_F3[%f,%f,%f]",ttMC_th1_F3->GetBinContent(1),ttMC_th1_F3->GetBinContent(1)-5000,ttMC_th1_F3->GetBinContent(1)+5000));
  
  RooDataHist ttMC_hist_F3("ttMC_obs_F3","tt MC observed in signal region 3",vars,ttMC_th1_F3);
  w->import(ttMC_hist_F3);
  // shape for tt bkg MC
  w->factory("RooNjetsPdf::bkgMC_tt_F3(nj,p0_tt_F3,p1_tt_F3,p2_tt_F3,N7_tt_F3)");
  w->import(*w->pdf("bkgMC_tt_F3"));

  RooAbsPdf* model_tt_F3 = w->pdf("bkgMC_tt_F3");
  SumW2Error(kTRUE);
  RooFitResult* r_tt_F3 = model_tt_F3->fitTo(ttMC_hist_F3,Save());
  r_tt_F3->Print("V");

  RooPlot* ttframe_F3 = w->var("nj")->frame(Title("njets tt F3 PDF"));
  ttMC_hist_F3.plotOn(ttframe_F3);
  model_tt_F3->plotOn(ttframe_F3);
  model_tt_F3->paramOn(ttframe_F3,Layout(0.35,0.622912,0.773497));
  ttframe_F3->getAttLine()->SetLineWidth(0);

  //new TCanvas("tt F3 fit result","tt F3 fit results",600,600);
  //gPad->SetLeftMargin(0.15);
  //ttframe_F3->GetYaxis()->SetTitleOffset(2.0);
  //ttframe_F3->Draw();

  // F4
  TH1* ttMC_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_TT",ttMC_th1_F4);

  w->factory("p0_tt_F4[0.34,0.14,0.54]");
  w->factory("p1_tt_F4[0.22,0.02,0.42]");
  w->factory("p2_tt_F4[-0.32,-0.52,-0.12]");

  w->factory(TString::Format("N7_tt_F4[%f,%f,%f]",ttMC_th1_F4->GetBinContent(1),ttMC_th1_F4->GetBinContent(1)-5000,ttMC_th1_F4->GetBinContent(1)+5000));
  
  RooDataHist ttMC_hist_F4("ttMC_obs_F4","tt MC observed in signal region 4",vars,ttMC_th1_F4);
  w->import(ttMC_hist_F4);
  // shape for tt bkg MC
  w->factory("RooNjetsPdf::bkgMC_tt_F4(nj,p0_tt_F4,p1_tt_F4,p2_tt_F4,N7_tt_F4)");
  w->import(*w->pdf("bkgMC_tt_F4"));

  RooAbsPdf* model_tt_F4 = w->pdf("bkgMC_tt_F4");
  SumW2Error(kTRUE);
  RooFitResult* r_tt_F4 = model_tt_F4->fitTo(ttMC_hist_F4,Save());
  r_tt_F4->Print("V");

  RooPlot* ttframe_F4 = w->var("nj")->frame(Title("njets tt F4 PDF"));
  ttMC_hist_F4.plotOn(ttframe_F4);
  model_tt_F4->plotOn(ttframe_F4);
  model_tt_F4->paramOn(ttframe_F4,Layout(0.35,0.622912,0.773497));
  ttframe_F4->getAttLine()->SetLineWidth(0);

  //new TCanvas("tt F4 fit result","tt F4 fit results",600,600);
  //gPad->SetLeftMargin(0.15);
  //ttframe_F4->GetYaxis()->SetTitleOffset(2.0);
  //ttframe_F4->Draw();


  // other ---------------------------------------------------------------------------------------

  // F1
  TH1* otherMC_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_other",otherMC_th1_F1);

  w->factory("p0_other_F1[0.24,0.0,1.5]");
  w->factory("p1_other_F1[0.27,0.0,0.42]");
  w->factory("p2_other_F1[-0.64,-2.5,0.0]");

  w->factory(TString::Format("N7_other_F1[%f,%f,%f]",otherMC_th1_F1->GetBinContent(1),otherMC_th1_F1->GetBinContent(1)-5000,otherMC_th1_F1->GetBinContent(1)+5000));

  RooDataHist otherMC_hist_F1("otherMC_obs_F1","other MC observed in signal region 1",vars,otherMC_th1_F1);
  w->import(otherMC_hist_F1);
  // shape for other bkg MC
  w->factory("RooNjetsPdf::bkgMC_other_F1(nj,p0_other_F1,p1_other_F1,p2_other_F1,N7_other_F1)");
  w->import(*w->pdf("bkgMC_other_F1"));

  RooAbsPdf* model_other_F1 = w->pdf("bkgMC_other_F1");
  SumW2Error(kTRUE);
  RooFitResult* r_other_F1 = model_other_F1->fitTo(otherMC_hist_F1,Save());
  r_other_F1->Print("V");

  RooPlot* otherframe_F1 = w->var("nj")->frame(Title("njets other F1 PDF"));
  otherMC_hist_F1.plotOn(otherframe_F1);
  model_other_F1->plotOn(otherframe_F1);
  model_other_F1->paramOn(otherframe_F1,Layout(0.35,0.622912,0.773497));
  otherframe_F1->getAttLine()->SetLineWidth(0);

  //new TCanvas("other F1 fit result","other F1 fit results",600,600);
  //gPad->SetLeftMargin(0.15);
  //otherframe_F1->GetYaxis()->SetTitleOffset(2.0);
  //otherframe_F1->Draw();

  // F2
  TH1* otherMC_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_other",otherMC_th1_F2);

  w->factory("p0_other_F2[0.24,0.0,1.5]");
  w->factory("p1_other_F2[0.27,0.0,0.42]");
  w->factory("p2_other_F2[-0.64,-2.5,0.0]");

  w->factory(TString::Format("N7_other_F2[%f,%f,%f]",otherMC_th1_F2->GetBinContent(1),otherMC_th1_F2->GetBinContent(1)-5000,otherMC_th1_F2->GetBinContent(1)+5000));
  
  RooDataHist otherMC_hist_F2("otherMC_obs_F2","other MC observed in signal region 2",vars,otherMC_th1_F2);
  w->import(otherMC_hist_F2);
  // shape for other bkg MC
  w->factory("RooNjetsPdf::bkgMC_other_F2(nj,p0_other_F2,p1_other_F2,p2_other_F2,N7_other_F2)");
  w->import(*w->pdf("bkgMC_other_F2"));

  RooAbsPdf* model_other_F2 = w->pdf("bkgMC_other_F2");
  SumW2Error(kTRUE);
  RooFitResult* r_other_F2 = model_other_F2->fitTo(otherMC_hist_F2,Save());
  r_other_F2->Print("V");

  RooPlot* otherframe_F2 = w->var("nj")->frame(Title("njets other F2 PDF"));
  otherMC_hist_F2.plotOn(otherframe_F2);
  model_other_F2->plotOn(otherframe_F2);
  model_other_F2->paramOn(otherframe_F2,Layout(0.35,0.622912,0.773497));
  otherframe_F2->getAttLine()->SetLineWidth(0);

  //new TCanvas("other F2 fit result","other F2 fit results",600,600);
  //gPad->SetLeftMargin(0.15);
  //otherframe_F2->GetYaxis()->SetTitleOffset(2.0);
  //otherframe_F2->Draw();

  // F3
  TH1* otherMC_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_other",otherMC_th1_F3);

  w->factory("p0_other_F3[0.24,0.0,1.5]");
  w->factory("p1_other_F3[0.27,0.0,0.42]");
  w->factory("p2_other_F3[-0.64,-2.5,0.0]");

  w->factory(TString::Format("N7_other_F3[%f,%f,%f]",otherMC_th1_F3->GetBinContent(1),otherMC_th1_F3->GetBinContent(1)-5000,otherMC_th1_F3->GetBinContent(1)+5000));

  RooDataHist otherMC_hist_F3("otherMC_obs_F3","other MC observed in signal region 3",vars,otherMC_th1_F3);
  w->import(otherMC_hist_F3);
  // shape for other bkg MC
  w->factory("RooNjetsPdf::bkgMC_other_F3(nj,p0_other_F3,p1_other_F3,p2_other_F3,N7_other_F3)");
  w->import(*w->pdf("bkgMC_other_F3"));

  RooAbsPdf* model_other_F3 = w->pdf("bkgMC_other_F3");
  SumW2Error(kTRUE);
  RooFitResult* r_other_F3 = model_other_F3->fitTo(otherMC_hist_F3,Save());
  r_other_F3->Print("V");

  RooPlot* otherframe_F3 = w->var("nj")->frame(Title("njets other F3 PDF"));
  otherMC_hist_F3.plotOn(otherframe_F3);
  model_other_F3->plotOn(otherframe_F3);
  model_other_F3->paramOn(otherframe_F3,Layout(0.35,0.622912,0.773497));
  otherframe_F3->getAttLine()->SetLineWidth(0);

  //new TCanvas("other F3 fit result","other F3 fit results",600,600);
  //gPad->SetLeftMargin(0.15);
  //otherframe_F3->GetYaxis()->SetTitleOffset(2.0);
  //otherframe_F3->Draw();

  // F4
  TH1* otherMC_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_other",otherMC_th1_F4);

  w->factory("p0_other_F4[0.24,0.0,1.5]");
  w->factory("p1_other_F4[0.27,0.0,0.42]");
  w->factory("p2_other_F4[-0.64,-2.5,0.0]");

  w->factory(TString::Format("N7_other_F4[%f,%f,%f]",otherMC_th1_F4->GetBinContent(1),otherMC_th1_F4->GetBinContent(1)-5000,otherMC_th1_F4->GetBinContent(1)+5000));
  
  RooDataHist otherMC_hist_F4("otherMC_obs_F4","other MC observed in signal region 4",vars,otherMC_th1_F4);
  w->import(otherMC_hist_F4);
  // shape for other bkg MC
  w->factory("RooNjetsPdf::bkgMC_other_F4(nj,p0_other_F4,p1_other_F4,p2_other_F4,N7_other_F4)");
  w->import(*w->pdf("bkgMC_other_F4"));

  RooAbsPdf* model_other_F4 = w->pdf("bkgMC_other_F4");
  SumW2Error(kTRUE);
  RooFitResult* r_other_F4 = model_other_F4->fitTo(otherMC_hist_F4,Save());
  r_other_F4->Print("V");

  RooPlot* otherframe_F4 = w->var("nj")->frame(Title("njets other F4 PDF"));
  otherMC_hist_F4.plotOn(otherframe_F4);
  model_other_F4->plotOn(otherframe_F4);
  model_other_F4->paramOn(otherframe_F4,Layout(0.35,0.622912,0.773497));
  otherframe_F4->getAttLine()->SetLineWidth(0);

  //new TCanvas("other F4 fit result","other F4 fit results",600,600);
  //gPad->SetLeftMargin(0.15);
  //otherframe_F4->GetYaxis()->SetTitleOffset(2.0);
  //otherframe_F4->Draw();

  // ===================================================================================

  // Clone the fit result frames, so that I can plot a log version without the fit params
  RooPlot* clone_ttframe_F1 = (RooPlot*)ttframe_F1->Clone("ttframe_F1");
  RooPlot* clone_ttframe_F2 = (RooPlot*)ttframe_F2->Clone("ttframe_F2");
  RooPlot* clone_ttframe_F3 = (RooPlot*)ttframe_F3->Clone("ttframe_F3");
  RooPlot* clone_ttframe_F4 = (RooPlot*)ttframe_F4->Clone("ttframe_F4");

  RooPlot* clone_otherframe_F1 = (RooPlot*)otherframe_F1->Clone("otherframe_F1");
  RooPlot* clone_otherframe_F2 = (RooPlot*)otherframe_F2->Clone("otherframe_F2");
  RooPlot* clone_otherframe_F3 = (RooPlot*)otherframe_F3->Clone("otherframe_F3");
  RooPlot* clone_otherframe_F4 = (RooPlot*)otherframe_F4->Clone("otherframe_F4");

  // ===================================================================================

  // Get the N7 for each fit

  TPaveText *text_N7_tt_F1 = new TPaveText(0.352682,0.785388,0.626392,0.875761,"blNDC");
  text_N7_tt_F1->AddText(TString::Format("N7 = %.1f",ttMC_th1_F1->GetBinContent(1)));
  text_N7_tt_F1->SetFillStyle(0);
  text_N7_tt_F1->SetBorderSize(1);
  text_N7_tt_F1->SetLineColor(0);
  TPaveText *text_N7_tt_F2 = new TPaveText(0.352682,0.785388,0.626392,0.875761,"blNDC");
  text_N7_tt_F2->AddText(TString::Format("N7 = %.1f",ttMC_th1_F2->GetBinContent(1)));
  text_N7_tt_F2->SetFillStyle(0);
  text_N7_tt_F2->SetBorderSize(1);
  text_N7_tt_F2->SetLineColor(0);
  TPaveText *text_N7_tt_F3 = new TPaveText(0.352682,0.785388,0.626392,0.875761,"blNDC");
  text_N7_tt_F3->AddText(TString::Format("N7 = %.1f",ttMC_th1_F3->GetBinContent(1)));
  text_N7_tt_F3->SetFillStyle(0);
  text_N7_tt_F3->SetBorderSize(1);
  text_N7_tt_F3->SetLineColor(0);
  TPaveText *text_N7_tt_F4 = new TPaveText(0.352682,0.785388,0.626392,0.875761,"blNDC");
  text_N7_tt_F4->AddText(TString::Format("N7 = %.1f",ttMC_th1_F4->GetBinContent(1)));
  text_N7_tt_F4->SetFillStyle(0);
  text_N7_tt_F4->SetBorderSize(1);
  text_N7_tt_F4->SetLineColor(0);

  TPaveText *text_N7_other_F1 = new TPaveText(0.352682,0.785388,0.626392,0.875761,"blNDC");
  text_N7_other_F1->AddText(TString::Format("N7 = %.1f",otherMC_th1_F1->GetBinContent(1)));
  text_N7_other_F1->SetFillStyle(0);
  text_N7_other_F1->SetBorderSize(1);
  text_N7_other_F1->SetLineColor(0);
  TPaveText *text_N7_other_F2 = new TPaveText(0.352682,0.785388,0.626392,0.875761,"blNDC");
  text_N7_other_F2->AddText(TString::Format("N7 = %.1f",otherMC_th1_F2->GetBinContent(1)));
  text_N7_other_F2->SetFillStyle(0);
  text_N7_other_F2->SetBorderSize(1);
  text_N7_other_F2->SetLineColor(0);
  TPaveText *text_N7_other_F3 = new TPaveText(0.352682,0.785388,0.626392,0.875761,"blNDC");
  text_N7_other_F3->AddText(TString::Format("N7 = %.1f",otherMC_th1_F3->GetBinContent(1)));
  text_N7_other_F3->SetFillStyle(0);
  text_N7_other_F3->SetBorderSize(1);
  text_N7_other_F3->SetLineColor(0);
  TPaveText *text_N7_other_F4 = new TPaveText(0.352682,0.785388,0.626392,0.875761,"blNDC");
  text_N7_other_F4->AddText(TString::Format("N7 = %.1f",otherMC_th1_F4->GetBinContent(1)));
  text_N7_other_F4->SetFillStyle(0);
  text_N7_other_F4->SetBorderSize(1);
  text_N7_other_F4->SetLineColor(0);



  // ===================================================================================

  // Get the chi^2 for each fit

  TPaveText *chiSquare_tt_F1 = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_tt_F1->AddText(TString::Format("Chi Square = %0.2f",ttframe_F1->chiSquare(4)));
  chiSquare_tt_F1->SetFillStyle(0);
  chiSquare_tt_F1->SetBorderSize(1);
  chiSquare_tt_F1->SetLineColor(0);
  TPaveText *chiSquare_tt_F2 = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_tt_F2->AddText(TString::Format("Chi Square = %0.2f",ttframe_F2->chiSquare(4)));
  chiSquare_tt_F2->SetFillStyle(0);
  chiSquare_tt_F2->SetBorderSize(1);
  chiSquare_tt_F2->SetLineColor(0);
  TPaveText *chiSquare_tt_F3 = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_tt_F3->AddText(TString::Format("Chi Square = %0.2f",ttframe_F3->chiSquare(4)));
  chiSquare_tt_F3->SetFillStyle(0);
  chiSquare_tt_F3->SetBorderSize(1);
  chiSquare_tt_F3->SetLineColor(0);
  TPaveText *chiSquare_tt_F4 = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_tt_F4->AddText(TString::Format("Chi Square = %0.2f",ttframe_F4->chiSquare(4)));
  chiSquare_tt_F4->SetFillStyle(0);
  chiSquare_tt_F4->SetBorderSize(1);
  chiSquare_tt_F4->SetLineColor(0);

  TPaveText *chiSquare_other_F1 = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_other_F1->AddText(TString::Format("Chi Square = %0.2f",otherframe_F1->chiSquare(4)));
  chiSquare_other_F1->SetFillStyle(0);
  chiSquare_other_F1->SetBorderSize(1);
  chiSquare_other_F1->SetLineColor(0);
  TPaveText *chiSquare_other_F2 = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_other_F2->AddText(TString::Format("Chi Square = %0.2f",otherframe_F2->chiSquare(4)));
  chiSquare_other_F2->SetFillStyle(0);
  chiSquare_other_F2->SetBorderSize(1);
  chiSquare_other_F2->SetLineColor(0);
  TPaveText *chiSquare_other_F3 = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_other_F3->AddText(TString::Format("Chi Square = %0.2f",otherframe_F3->chiSquare(4)));
  chiSquare_other_F3->SetFillStyle(0);
  chiSquare_other_F3->SetBorderSize(1);
  chiSquare_other_F3->SetLineColor(0);
  TPaveText *chiSquare_other_F4 = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_other_F4->AddText(TString::Format("Chi Square = %0.2f",otherframe_F4->chiSquare(4)));
  chiSquare_other_F4->SetFillStyle(0);
  chiSquare_other_F4->SetBorderSize(1);
  chiSquare_other_F4->SetLineColor(0);


  // ===================================================================================

  // Make pull plots of each fit
  // The pull is defined as (curve-histogram +/- error_on_histogram) / error_on_histogram
  //   so it is expected that for the case of symmetric errors the error bars on the pull are +/- 1. 

  RooHist* hpull_tt_F1 = ttframe_F1->pullHist();
  RooPlot* framePull_tt_F1 = w->var("nj")->frame(Title("Pull"));
  framePull_tt_F1->addPlotable(hpull_tt_F1,"P");

  RooHist* hpull_tt_F2 = ttframe_F2->pullHist();
  RooPlot* framePull_tt_F2 = w->var("nj")->frame(Title("Pull"));
  framePull_tt_F2->addPlotable(hpull_tt_F2,"P");

  RooHist* hpull_tt_F3 = ttframe_F3->pullHist();
  RooPlot* framePull_tt_F3 = w->var("nj")->frame(Title("Pull"));
  framePull_tt_F3->addPlotable(hpull_tt_F3,"P");

  RooHist* hpull_tt_F4 = ttframe_F4->pullHist();
  RooPlot* framePull_tt_F4 = w->var("nj")->frame(Title("Pull"));
  framePull_tt_F4->addPlotable(hpull_tt_F4,"P");


  RooHist* hpull_other_F1 = otherframe_F1->pullHist();
  RooPlot* framePull_other_F1 = w->var("nj")->frame(Title("Pull"));
  framePull_other_F1->addPlotable(hpull_other_F1,"P");

  RooHist* hpull_other_F2 = otherframe_F2->pullHist();
  RooPlot* framePull_other_F2 = w->var("nj")->frame(Title("Pull"));
  framePull_other_F2->addPlotable(hpull_other_F2,"P");

  RooHist* hpull_other_F3 = otherframe_F3->pullHist();
  RooPlot* framePull_other_F3 = w->var("nj")->frame(Title("Pull"));
  framePull_other_F3->addPlotable(hpull_other_F3,"P");

  RooHist* hpull_other_F4 = otherframe_F4->pullHist();
  RooPlot* framePull_other_F4 = w->var("nj")->frame(Title("Pull"));
  framePull_other_F4->addPlotable(hpull_other_F4,"P");


  // ===================================================================================

  // Make 2D hists of the correlation matrices
  TH2* hcorr_tt_F1 = r_tt_F1->correlationHist();
  TH2* hcorr_tt_F2 = r_tt_F2->correlationHist();
  TH2* hcorr_tt_F3 = r_tt_F3->correlationHist();
  TH2* hcorr_tt_F4 = r_tt_F4->correlationHist();

  TH2* hcorr_other_F1 = r_other_F1->correlationHist();
  TH2* hcorr_other_F2 = r_other_F2->correlationHist();
  TH2* hcorr_other_F3 = r_other_F3->correlationHist();
  TH2* hcorr_other_F4 = r_other_F4->correlationHist();


  // ===================================================================================

  // Create the summary canvases

  gStyle->SetPaintTextFormat("2.3f");

  TCanvas* c_tt_F1 = new TCanvas("c_tt_F1","tt F1",900,900);
  c_tt_F1->Divide(2,2);
  c_tt_F1->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  ttframe_F1->GetYaxis()->SetTitleOffset(2.0);
  ttframe_F1->Draw();
  //chiSquare_tt_F1->Draw("same");  
  text_N7_tt_F1->Draw("same");
  c_tt_F1->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_ttframe_F1->GetYaxis()->SetTitleOffset(1.4);
  clone_ttframe_F1->SetMinimum(0.1);
  clone_ttframe_F1->SetMaximum(100000);
  clone_ttframe_F1->remove("bkgMC_tt_F1_paramBox");
  clone_ttframe_F1->Draw();
  c_tt_F1->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_tt_F1->SetYTitle("(Fit-Data)/errData");
  framePull_tt_F1->GetYaxis()->SetTitleOffset(1.4);
  framePull_tt_F1->Draw();
  c_tt_F1->cd(4);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(1);
  hcorr_tt_F1->SetStats(0);
  hcorr_tt_F1->SetMarkerSize(2.4);
  hcorr_tt_F1->Draw("COLZ,TEXT");
  c_tt_F1->SaveAs("BkgFit_tt_F1.png");

  TCanvas* c_tt_F2 = new TCanvas("c_tt_F2","tt F2",900,900);
  c_tt_F2->Divide(2,2);
  c_tt_F2->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  ttframe_F2->GetYaxis()->SetTitleOffset(2.0);
  ttframe_F2->Draw();
  //chiSquare_tt_F2->Draw("same");
  text_N7_tt_F2->Draw("same");
  c_tt_F2->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_ttframe_F2->GetYaxis()->SetTitleOffset(1.4);
  clone_ttframe_F2->SetMinimum(0.1);
  clone_ttframe_F2->SetMaximum(100000);
  clone_ttframe_F2->remove("bkgMC_tt_F2_paramBox");
  clone_ttframe_F2->Draw();
  c_tt_F2->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_tt_F2->SetYTitle("(Fit-Data)/errData");
  framePull_tt_F2->GetYaxis()->SetTitleOffset(1.4);
  framePull_tt_F2->Draw();
  c_tt_F2->cd(4);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(1);
  hcorr_tt_F2->SetStats(0);
  hcorr_tt_F2->SetMarkerSize(2.4);
  hcorr_tt_F2->Draw("COLZ,TEXT");
  c_tt_F2->SaveAs("BkgFit_tt_F2.png");

  TCanvas* c_tt_F3 = new TCanvas("c_tt_F3","tt F3",900,900);
  c_tt_F3->Divide(2,2);
  c_tt_F3->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  ttframe_F3->GetYaxis()->SetTitleOffset(2.0);
  ttframe_F3->Draw();
  //chiSquare_tt_F3->Draw("same");
  text_N7_tt_F3->Draw("same");
  c_tt_F3->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_ttframe_F3->GetYaxis()->SetTitleOffset(1.4);
  clone_ttframe_F3->SetMinimum(0.1);
  clone_ttframe_F3->SetMaximum(100000);
  clone_ttframe_F3->remove("bkgMC_tt_F3_paramBox");
  clone_ttframe_F3->Draw();
  c_tt_F3->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_tt_F3->SetYTitle("(Fit-Data)/errData");
  framePull_tt_F3->GetYaxis()->SetTitleOffset(1.4);
  framePull_tt_F3->Draw();
  c_tt_F3->cd(4);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(1);
  hcorr_tt_F3->SetStats(0);
  hcorr_tt_F3->SetMarkerSize(2.4);
  hcorr_tt_F3->Draw("COLZ,TEXT");
  c_tt_F3->SaveAs("BkgFit_tt_F3.png");

  TCanvas* c_tt_F4 = new TCanvas("c_tt_F4","tt F4",900,900);
  c_tt_F4->Divide(2,2);
  c_tt_F4->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  ttframe_F4->GetYaxis()->SetTitleOffset(2.0);
  ttframe_F4->Draw();
  //chiSquare_tt_F4->Draw("same");
  text_N7_tt_F4->Draw("same");
  c_tt_F4->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_ttframe_F4->GetYaxis()->SetTitleOffset(1.4);
  clone_ttframe_F4->SetMinimum(0.1);
  clone_ttframe_F4->SetMaximum(100000);
  clone_ttframe_F4->remove("bkgMC_tt_F4_paramBox");
  clone_ttframe_F4->Draw();
  c_tt_F4->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_tt_F4->SetYTitle("(Fit-Data)/errData");
  framePull_tt_F4->GetYaxis()->SetTitleOffset(1.4);
  framePull_tt_F4->Draw();
  c_tt_F4->cd(4);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(1);
  hcorr_tt_F4->SetStats(0);
  hcorr_tt_F4->SetMarkerSize(2.4);
  hcorr_tt_F4->Draw("COLZ,TEXT");
  c_tt_F4->SaveAs("BkgFit_tt_F4.png");





  TCanvas* c_other_F1 = new TCanvas("c_other_F1","other F1",900,900);
  c_other_F1->Divide(2,2);
  c_other_F1->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  otherframe_F1->GetYaxis()->SetTitleOffset(2.0);
  otherframe_F1->Draw();
  //chiSquare_other_F1->Draw("same");
  text_N7_other_F1->Draw("same");
  c_other_F1->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_otherframe_F1->GetYaxis()->SetTitleOffset(1.4);
  clone_otherframe_F1->SetMinimum(0.1);
  clone_otherframe_F1->SetMaximum(100000);
  clone_otherframe_F1->remove("bkgMC_other_F1_paramBox");
  clone_otherframe_F1->Draw();
  c_other_F1->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_other_F1->SetYTitle("(Fit-Data)/errData");
  framePull_other_F1->GetYaxis()->SetTitleOffset(1.4);
  framePull_other_F1->Draw();
  c_other_F1->cd(4);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(1);
  hcorr_other_F1->SetStats(0);
  hcorr_other_F1->SetMarkerSize(2.4);
  hcorr_other_F1->Draw("COLZ,TEXT");
  c_other_F1->SaveAs("BkgFit_other_F1.png");

  TCanvas* c_other_F2 = new TCanvas("c_other_F2","other F2",900,900);
  c_other_F2->Divide(2,2);
  c_other_F2->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  otherframe_F2->GetYaxis()->SetTitleOffset(2.0);
  otherframe_F2->Draw();
  //chiSquare_other_F2->Draw("same");
  text_N7_other_F2->Draw("same");
  c_other_F2->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_otherframe_F2->GetYaxis()->SetTitleOffset(1.4);
  clone_otherframe_F2->SetMinimum(0.1);
  clone_otherframe_F2->SetMaximum(100000);
  clone_otherframe_F2->remove("bkgMC_other_F2_paramBox");
  clone_otherframe_F2->Draw();
  c_other_F2->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_other_F2->SetYTitle("(Fit-Data)/errData");
  framePull_other_F2->GetYaxis()->SetTitleOffset(1.4);
  framePull_other_F2->Draw();
  c_other_F2->cd(4);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(1);
  hcorr_other_F2->SetStats(0);
  hcorr_other_F2->SetMarkerSize(2.4);
  hcorr_other_F2->Draw("COLZ,TEXT");
  c_other_F2->SaveAs("BkgFit_other_F2.png");

  TCanvas* c_other_F3 = new TCanvas("c_other_F3","other F3",900,900);
  c_other_F3->Divide(2,2);
  c_other_F3->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  otherframe_F3->GetYaxis()->SetTitleOffset(2.0);
  otherframe_F3->Draw();
  //chiSquare_other_F3->Draw("same");
  text_N7_other_F3->Draw("same");
  c_other_F3->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_otherframe_F3->GetYaxis()->SetTitleOffset(1.4);
  clone_otherframe_F3->SetMinimum(0.1);
  clone_otherframe_F3->SetMaximum(100000);
  clone_otherframe_F3->remove("bkgMC_other_F3_paramBox");
  clone_otherframe_F3->Draw();
  c_other_F3->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_other_F3->SetYTitle("(Fit-Data)/errData");
  framePull_other_F3->GetYaxis()->SetTitleOffset(1.4);
  framePull_other_F3->Draw();
  c_other_F3->cd(4);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(1);
  hcorr_other_F3->SetStats(0);
  hcorr_other_F3->SetMarkerSize(2.4);
  hcorr_other_F3->Draw("COLZ,TEXT");
  c_other_F3->SaveAs("BkgFit_other_F3.png");

  TCanvas* c_other_F4 = new TCanvas("c_other_F4","other F4",900,900);
  c_other_F4->Divide(2,2);
  c_other_F4->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  otherframe_F4->GetYaxis()->SetTitleOffset(2.0);
  otherframe_F4->Draw();
  //chiSquare_other_F4->Draw("same");
  text_N7_other_F4->Draw("same");
  c_other_F4->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_otherframe_F4->GetYaxis()->SetTitleOffset(1.4);
  clone_otherframe_F4->SetMinimum(0.1);
  clone_otherframe_F4->SetMaximum(100000);
  clone_otherframe_F4->remove("bkgMC_other_F4_paramBox");
  clone_otherframe_F4->Draw();
  c_other_F4->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_other_F4->SetYTitle("(Fit-Data)/errData");
  framePull_other_F4->GetYaxis()->SetTitleOffset(1.4);
  framePull_other_F4->Draw();
  c_other_F4->cd(4);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(1);
  hcorr_other_F4->SetStats(0);
  hcorr_other_F4->SetMarkerSize(2.4);
  hcorr_other_F4->Draw("COLZ,TEXT");
  c_other_F4->SaveAs("BkgFit_other_F4.png");


  // ===================================================================================

  // Extract and print the correlation matrices

  const TMatrixDSym& cor_tt_F1 = r_tt_F1->correlationMatrix();
  const TMatrixDSym& cor_tt_F2 = r_tt_F2->correlationMatrix();
  const TMatrixDSym& cor_tt_F3 = r_tt_F3->correlationMatrix();
  const TMatrixDSym& cor_tt_F4 = r_tt_F4->correlationMatrix();

  const TMatrixDSym& cor_other_F1 = r_other_F1->correlationMatrix();
  const TMatrixDSym& cor_other_F2 = r_other_F2->correlationMatrix();
  const TMatrixDSym& cor_other_F3 = r_other_F3->correlationMatrix();
  const TMatrixDSym& cor_other_F4 = r_other_F4->correlationMatrix();
  
  cout << "======================= Correlation Matrices of Fit Results =====================" << endl;
  cout << "tt F1:" << endl;
  cor_tt_F1.Print();
  cout << "tt F2:" << endl;
  cor_tt_F2.Print();
  cout << "tt F3:" << endl;
  cor_tt_F3.Print();
  cout << "tt F4:" << endl;
  cor_tt_F4.Print();
  cout << "other F1:" << endl;
  cor_other_F1.Print();
  cout << "other F2:" << endl;
  cor_other_F2.Print();
  cout << "other F3:" << endl;
  cor_other_F3.Print();
  cout << "other F4:" << endl;
  cor_other_F4.Print();


  // ===================================================================================

  // Extract and print the post-fit parameters

  RooRealVar* par_p0_tt_F1 = (RooRealVar*) r_tt_F1->floatParsFinal().find("p0_tt_F1");
  RooRealVar* par_p0_tt_F2 = (RooRealVar*) r_tt_F2->floatParsFinal().find("p0_tt_F2");
  RooRealVar* par_p0_tt_F3 = (RooRealVar*) r_tt_F3->floatParsFinal().find("p0_tt_F3");
  RooRealVar* par_p0_tt_F4 = (RooRealVar*) r_tt_F4->floatParsFinal().find("p0_tt_F4");

  RooRealVar* par_p1_tt_F1 = (RooRealVar*) r_tt_F1->floatParsFinal().find("p1_tt_F1");
  RooRealVar* par_p1_tt_F2 = (RooRealVar*) r_tt_F2->floatParsFinal().find("p1_tt_F2");
  RooRealVar* par_p1_tt_F3 = (RooRealVar*) r_tt_F3->floatParsFinal().find("p1_tt_F3");
  RooRealVar* par_p1_tt_F4 = (RooRealVar*) r_tt_F4->floatParsFinal().find("p1_tt_F4");

  RooRealVar* par_p2_tt_F1 = (RooRealVar*) r_tt_F1->floatParsFinal().find("p2_tt_F1");
  RooRealVar* par_p2_tt_F2 = (RooRealVar*) r_tt_F2->floatParsFinal().find("p2_tt_F2");
  RooRealVar* par_p2_tt_F3 = (RooRealVar*) r_tt_F3->floatParsFinal().find("p2_tt_F3");
  RooRealVar* par_p2_tt_F4 = (RooRealVar*) r_tt_F4->floatParsFinal().find("p2_tt_F4");


  RooRealVar* par_p0_other_F1 = (RooRealVar*) r_other_F1->floatParsFinal().find("p0_other_F1");
  RooRealVar* par_p0_other_F2 = (RooRealVar*) r_other_F2->floatParsFinal().find("p0_other_F2");
  RooRealVar* par_p0_other_F3 = (RooRealVar*) r_other_F3->floatParsFinal().find("p0_other_F3");
  RooRealVar* par_p0_other_F4 = (RooRealVar*) r_other_F4->floatParsFinal().find("p0_other_F4");

  RooRealVar* par_p1_other_F1 = (RooRealVar*) r_other_F1->floatParsFinal().find("p1_other_F1");
  RooRealVar* par_p1_other_F2 = (RooRealVar*) r_other_F2->floatParsFinal().find("p1_other_F2");
  RooRealVar* par_p1_other_F3 = (RooRealVar*) r_other_F3->floatParsFinal().find("p1_other_F3");
  RooRealVar* par_p1_other_F4 = (RooRealVar*) r_other_F4->floatParsFinal().find("p1_other_F4");

  RooRealVar* par_p2_other_F1 = (RooRealVar*) r_other_F1->floatParsFinal().find("p2_other_F1");
  RooRealVar* par_p2_other_F2 = (RooRealVar*) r_other_F2->floatParsFinal().find("p2_other_F2");
  RooRealVar* par_p2_other_F3 = (RooRealVar*) r_other_F3->floatParsFinal().find("p2_other_F3");
  RooRealVar* par_p2_other_F4 = (RooRealVar*) r_other_F4->floatParsFinal().find("p2_other_F4");


  cout << "======================= Parameters of Fit Results =====================" << endl;
  cout << "Sample   " << "            p0                 p1                  p2" << endl;

  cout << "tt F1   " << "      " << TString::Format("%0.3f",par_p0_tt_F1->getVal()) << " +/- " << TString::Format("%0.3f",par_p0_tt_F1->getError()) << "    " << TString::Format("%0.3f",par_p1_tt_F1->getVal()) << " +/- " << TString::Format("%0.3f",par_p1_tt_F1->getError()) << "    " << TString::Format("%0.3f",par_p2_tt_F1->getVal()) << " +/- " << TString::Format("%0.3f",par_p2_tt_F1->getError()) << "    " << endl;

  cout << "tt F2   " << "      " << TString::Format("%0.3f",par_p0_tt_F2->getVal()) << " +/- " << TString::Format("%0.3f",par_p0_tt_F2->getError()) << "    " << TString::Format("%0.3f",par_p1_tt_F2->getVal()) << " +/- " << TString::Format("%0.3f",par_p1_tt_F2->getError()) << "    " << TString::Format("%0.3f",par_p2_tt_F2->getVal()) << " +/- " << TString::Format("%0.3f",par_p2_tt_F2->getError()) << "    " << endl;

  cout << "tt F3   " << "      " << TString::Format("%0.3f",par_p0_tt_F3->getVal()) << " +/- " << TString::Format("%0.3f",par_p0_tt_F3->getError()) << "    " << TString::Format("%0.3f",par_p1_tt_F3->getVal()) << " +/- " << TString::Format("%0.3f",par_p1_tt_F3->getError()) << "    " << TString::Format("%0.3f",par_p2_tt_F3->getVal()) << " +/- " << TString::Format("%0.3f",par_p2_tt_F3->getError()) << "    " << endl;

  cout << "tt F4   " << "      " << TString::Format("%0.3f",par_p0_tt_F4->getVal()) << " +/- " << TString::Format("%0.3f",par_p0_tt_F4->getError()) << "    " << TString::Format("%0.3f",par_p1_tt_F4->getVal()) << " +/- " << TString::Format("%0.3f",par_p1_tt_F4->getError()) << "    " << TString::Format("%0.3f",par_p2_tt_F4->getVal()) << " +/- " << TString::Format("%0.3f",par_p2_tt_F4->getError()) << "    " << endl;


  cout << "other F1" << "      " << TString::Format("%0.3f",par_p0_other_F1->getVal()) << " +/- " << TString::Format("%0.3f",par_p0_other_F1->getError()) << "    " << TString::Format("%0.3f",par_p1_other_F1->getVal()) << " +/- " << TString::Format("%0.3f",par_p1_other_F1->getError()) << "    " << TString::Format("%0.3f",par_p2_other_F1->getVal()) << " +/- " << TString::Format("%0.3f",par_p2_other_F1->getError()) << "    " << endl;

  cout << "other F2" << "      " << TString::Format("%0.3f",par_p0_other_F2->getVal()) << " +/- " << TString::Format("%0.3f",par_p0_other_F2->getError()) << "    " << TString::Format("%0.3f",par_p1_other_F2->getVal()) << " +/- " << TString::Format("%0.3f",par_p1_other_F2->getError()) << "    " << TString::Format("%0.3f",par_p2_other_F2->getVal()) << " +/- " << TString::Format("%0.3f",par_p2_other_F2->getError()) << "    " << endl;

  cout << "other F3" << "      " << TString::Format("%0.3f",par_p0_other_F3->getVal()) << " +/- " << TString::Format("%0.3f",par_p0_other_F3->getError()) << "    " << TString::Format("%0.3f",par_p1_other_F3->getVal()) << " +/- " << TString::Format("%0.3f",par_p1_other_F3->getError()) << "    " << TString::Format("%0.3f",par_p2_other_F3->getVal()) << " +/- " << TString::Format("%0.3f",par_p2_other_F3->getError()) << "    " << endl;

  cout << "other F4" << "      " << TString::Format("%0.3f",par_p0_other_F4->getVal()) << " +/- " << TString::Format("%0.3f",par_p0_other_F4->getError()) << "    " << TString::Format("%0.3f",par_p1_other_F4->getVal()) << " +/- " << TString::Format("%0.3f",par_p1_other_F4->getError()) << "    " << TString::Format("%0.3f",par_p2_other_F4->getVal()) << " +/- " << TString::Format("%0.3f",par_p2_other_F4->getError()) << "    " << endl;





  // The residual is defined as curve-histogram +/- error_on_histogram
  // The pull is defined as (curve-histogram +/- error_on_histogram) / error_on_histogram
  //   so it is expected that for the case of symmetric errors the error bars on the pull are +/- 1. 

  // I think the pull has the most useful information out of these two

  //new TCanvas("Test","Test",600,600);
  //RooHist* hpull = ttframe_F1->pullHist();
  //RooPlot* frameTest = w->var("nj")->frame(Title("Pull Dist"));
  //frameTest->addPlotable(hpull,"P");
  //frameTest->Draw();

  //new TCanvas("Test2","Test2",600,600);
  //RooHist* hresid = ttframe_F1->residHist();
  //RooPlot* frameTest2 = w->var("nj")->frame(Title("Resid Dist"));
  //frameTest2->addPlotable(hresid,"P");
  //frameTest2->Draw();




}

