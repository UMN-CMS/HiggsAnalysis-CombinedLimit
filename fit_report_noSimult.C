// Macro for summarizing and plotting results of full fit
//  but without simultaneous fit to tt or other background MC
// Aron Soha
// April 23, 2018

#include "RooRealVar.h"
#include "RooFitResult.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
#include "TFile.h"
#include "TH2.h"

using namespace RooFit;

void fit_report_noSimult() {

 TFile* fullfile = TFile::Open("fitDiagnostics.root");

  RooWorkspace *w = new RooWorkspace("w","w");
  w->factory("nj_F1[6.5,14.5]");
  w->var("nj_F1")->setBins(8);
  w->factory("nj_F2[6.5,14.5]");
  w->var("nj_F2")->setBins(8);
  w->factory("nj_F3[6.5,14.5]");
  w->var("nj_F3")->setBins(8);
  w->factory("nj_F4[6.5,14.5]");
  w->var("nj_F4")->setBins(8);

  // ===================================================================================

  RooPlot* sigF1_nj_F1_prefit = 0;
  fullfile->GetObject("sigF1_nj_F1_prefit",sigF1_nj_F1_prefit);
  RooPlot* sigF1_nj_F1_fit_s = 0;
  fullfile->GetObject("sigF1_nj_F1_fit_s",sigF1_nj_F1_fit_s);
  RooPlot* sigF1_nj_F1_fit_b = 0;
  fullfile->GetObject("sigF1_nj_F1_fit_b",sigF1_nj_F1_fit_b);

  RooPlot* sigF2_nj_F2_prefit = 0;
  fullfile->GetObject("sigF2_nj_F2_prefit",sigF2_nj_F2_prefit);
  RooPlot* sigF2_nj_F2_fit_s = 0;
  fullfile->GetObject("sigF2_nj_F2_fit_s",sigF2_nj_F2_fit_s);
  RooPlot* sigF2_nj_F2_fit_b = 0;
  fullfile->GetObject("sigF2_nj_F2_fit_b",sigF2_nj_F2_fit_b);

  RooPlot* sigF3_nj_F3_prefit = 0;
  fullfile->GetObject("sigF3_nj_F3_prefit",sigF3_nj_F3_prefit);
  RooPlot* sigF3_nj_F3_fit_s = 0;
  fullfile->GetObject("sigF3_nj_F3_fit_s",sigF3_nj_F3_fit_s);
  RooPlot* sigF3_nj_F3_fit_b = 0;
  fullfile->GetObject("sigF3_nj_F3_fit_b",sigF3_nj_F3_fit_b);

  RooPlot* sigF4_nj_F4_prefit = 0;
  fullfile->GetObject("sigF4_nj_F4_prefit",sigF4_nj_F4_prefit);
  RooPlot* sigF4_nj_F4_fit_s = 0;
  fullfile->GetObject("sigF4_nj_F4_fit_s",sigF4_nj_F4_fit_s);
  RooPlot* sigF4_nj_F4_fit_b = 0;
  fullfile->GetObject("sigF4_nj_F4_fit_b",sigF4_nj_F4_fit_b);

  // Clone the fit result frames, so that I can plot a log version without the fit params
  RooPlot* clone_sigF1_prefit_frame = (RooPlot*)sigF1_nj_F1_prefit->Clone("sigF1_prefit_frame");
  RooPlot* clone_sigF1_fit_frame = (RooPlot*)sigF1_nj_F1_fit_s->Clone("sigF1_fit_frame");
  RooPlot* clone_sigF1_fitb_frame = (RooPlot*)sigF1_nj_F1_fit_b->Clone("sigF1_fitb_frame");

  RooPlot* clone_sigF2_prefit_frame = (RooPlot*)sigF2_nj_F2_prefit->Clone("sigF2_prefit_frame");
  RooPlot* clone_sigF2_fit_frame = (RooPlot*)sigF2_nj_F2_fit_s->Clone("sigF2_fit_frame");
  RooPlot* clone_sigF2_fitb_frame = (RooPlot*)sigF2_nj_F2_fit_b->Clone("sigF2_fitb_frame");

  RooPlot* clone_sigF3_prefit_frame = (RooPlot*)sigF3_nj_F3_prefit->Clone("sigF3_prefit_frame");
  RooPlot* clone_sigF3_fit_frame = (RooPlot*)sigF3_nj_F3_fit_s->Clone("sigF3_fit_frame");
  RooPlot* clone_sigF3_fitb_frame = (RooPlot*)sigF3_nj_F3_fit_b->Clone("sigF3_fitb_frame");

  RooPlot* clone_sigF4_prefit_frame = (RooPlot*)sigF4_nj_F4_prefit->Clone("sigF4_prefit_frame");
  RooPlot* clone_sigF4_fit_frame = (RooPlot*)sigF4_nj_F4_fit_s->Clone("sigF4_fit_frame");
  RooPlot* clone_sigF4_fitb_frame = (RooPlot*)sigF4_nj_F4_fit_b->Clone("sigF4_fitb_frame");

  // ===================================================================================

  // Get the N6 for each fit

  //TPaveText *text_N6_tt_F1 = new TPaveText(0.352682,0.785388,0.626392,0.875761,"blNDC");
  //text_N6_tt_F1->AddText(TString::Format("N6 = %.1f",full_ttMC_th1_F1->GetBinContent(1)));
  //text_N6_tt_F1->SetFillStyle(0);
  //text_N6_tt_F1->SetBorderSize(1);
  //text_N6_tt_F1->SetLineColor(0);

  // ===================================================================================

  // Get the chi^2 for each fit

  TPaveText *chiSquare_sigF1_prefit = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_sigF1_prefit->AddText(TString::Format("Chi Square = %0.2f",sigF1_nj_F1_prefit->chiSquare()));
  chiSquare_sigF1_prefit->SetFillStyle(0);
  chiSquare_sigF1_prefit->SetBorderSize(1);
  chiSquare_sigF1_prefit->SetLineColor(0);

  TPaveText *chiSquare_sigF1_fit = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_sigF1_fit->AddText(TString::Format("Chi Square = %0.2f",sigF1_nj_F1_fit_s->chiSquare()));
  chiSquare_sigF1_fit->SetFillStyle(0);
  chiSquare_sigF1_fit->SetBorderSize(1);
  chiSquare_sigF1_fit->SetLineColor(0);

  TPaveText *chiSquare_sigF1_fitb = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_sigF1_fitb->AddText(TString::Format("Chi Square = %0.2f",sigF1_nj_F1_fit_b->chiSquare()));
  chiSquare_sigF1_fitb->SetFillStyle(0);
  chiSquare_sigF1_fitb->SetBorderSize(1);
  chiSquare_sigF1_fitb->SetLineColor(0);


  TPaveText *chiSquare_sigF2_prefit = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_sigF2_prefit->AddText(TString::Format("Chi Square = %0.2f",sigF2_nj_F2_prefit->chiSquare()));
  chiSquare_sigF2_prefit->SetFillStyle(0);
  chiSquare_sigF2_prefit->SetBorderSize(1);
  chiSquare_sigF2_prefit->SetLineColor(0);

  TPaveText *chiSquare_sigF2_fit = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_sigF2_fit->AddText(TString::Format("Chi Square = %0.2f",sigF2_nj_F2_fit_s->chiSquare()));
  chiSquare_sigF2_fit->SetFillStyle(0);
  chiSquare_sigF2_fit->SetBorderSize(1);
  chiSquare_sigF2_fit->SetLineColor(0);

  TPaveText *chiSquare_sigF2_fitb = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_sigF2_fitb->AddText(TString::Format("Chi Square = %0.2f",sigF2_nj_F2_fit_b->chiSquare()));
  chiSquare_sigF2_fitb->SetFillStyle(0);
  chiSquare_sigF2_fitb->SetBorderSize(1);
  chiSquare_sigF2_fitb->SetLineColor(0);


  TPaveText *chiSquare_sigF3_prefit = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_sigF3_prefit->AddText(TString::Format("Chi Square = %0.2f",sigF3_nj_F3_prefit->chiSquare()));
  chiSquare_sigF3_prefit->SetFillStyle(0);
  chiSquare_sigF3_prefit->SetBorderSize(1);
  chiSquare_sigF3_prefit->SetLineColor(0);

  TPaveText *chiSquare_sigF3_fit = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_sigF3_fit->AddText(TString::Format("Chi Square = %0.2f",sigF3_nj_F3_fit_s->chiSquare()));
  chiSquare_sigF3_fit->SetFillStyle(0);
  chiSquare_sigF3_fit->SetBorderSize(1);
  chiSquare_sigF3_fit->SetLineColor(0);

  TPaveText *chiSquare_sigF3_fitb = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_sigF3_fitb->AddText(TString::Format("Chi Square = %0.2f",sigF3_nj_F3_fit_b->chiSquare()));
  chiSquare_sigF3_fitb->SetFillStyle(0);
  chiSquare_sigF3_fitb->SetBorderSize(1);
  chiSquare_sigF3_fitb->SetLineColor(0);


  TPaveText *chiSquare_sigF4_prefit = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_sigF4_prefit->AddText(TString::Format("Chi Square = %0.2f",sigF4_nj_F4_prefit->chiSquare()));
  chiSquare_sigF4_prefit->SetFillStyle(0);
  chiSquare_sigF4_prefit->SetBorderSize(1);
  chiSquare_sigF4_prefit->SetLineColor(0);

  TPaveText *chiSquare_sigF4_fit = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_sigF4_fit->AddText(TString::Format("Chi Square = %0.2f",sigF4_nj_F4_fit_s->chiSquare()));
  chiSquare_sigF4_fit->SetFillStyle(0);
  chiSquare_sigF4_fit->SetBorderSize(1);
  chiSquare_sigF4_fit->SetLineColor(0);

  TPaveText *chiSquare_sigF4_fitb = new TPaveText(0.351476,0.492295,0.701791,0.582667,"blNDC");
  chiSquare_sigF4_fitb->AddText(TString::Format("Chi Square = %0.2f",sigF4_nj_F4_fit_b->chiSquare()));
  chiSquare_sigF4_fitb->SetFillStyle(0);
  chiSquare_sigF4_fitb->SetBorderSize(1);
  chiSquare_sigF4_fitb->SetLineColor(0);


  // ===================================================================================

  // Make pull plots of each fit
  // The pull is defined as (curve-histogram +/- error_on_histogram) / error_on_histogram
  //   so it is expected that for the case of symmetric errors the error bars on the pull are +/- 1. 

  RooHist* hpull_sigF1_prefit = sigF1_nj_F1_prefit->pullHist();
  RooPlot* framePull_sigF1_prefit = w->var("nj_F1")->frame(Title("Pull"));
  framePull_sigF1_prefit->addPlotable(hpull_sigF1_prefit,"P");

  RooHist* hpull_sigF1_fit = sigF1_nj_F1_fit_s->pullHist();
  RooPlot* framePull_sigF1_fit = w->var("nj_F1")->frame(Title("Pull"));
  framePull_sigF1_fit->addPlotable(hpull_sigF1_fit,"P");

  RooHist* hpull_sigF1_fitb = sigF1_nj_F1_fit_b->pullHist();
  RooPlot* framePull_sigF1_fitb = w->var("nj_F1")->frame(Title("Pull"));
  framePull_sigF1_fitb->addPlotable(hpull_sigF1_fitb,"P");


  RooHist* hpull_sigF2_prefit = sigF2_nj_F2_prefit->pullHist();
  RooPlot* framePull_sigF2_prefit = w->var("nj_F2")->frame(Title("Pull"));
  framePull_sigF2_prefit->addPlotable(hpull_sigF2_prefit,"P");

  RooHist* hpull_sigF2_fit = sigF2_nj_F2_fit_s->pullHist();
  RooPlot* framePull_sigF2_fit = w->var("nj_F2")->frame(Title("Pull"));
  framePull_sigF2_fit->addPlotable(hpull_sigF2_fit,"P");

  RooHist* hpull_sigF2_fitb = sigF2_nj_F2_fit_b->pullHist();
  RooPlot* framePull_sigF2_fitb = w->var("nj_F2")->frame(Title("Pull"));
  framePull_sigF2_fitb->addPlotable(hpull_sigF2_fitb,"P");


  RooHist* hpull_sigF3_prefit = sigF3_nj_F3_prefit->pullHist();
  RooPlot* framePull_sigF3_prefit = w->var("nj_F3")->frame(Title("Pull"));
  framePull_sigF3_prefit->addPlotable(hpull_sigF3_prefit,"P");

  RooHist* hpull_sigF3_fit = sigF3_nj_F3_fit_s->pullHist();
  RooPlot* framePull_sigF3_fit = w->var("nj_F3")->frame(Title("Pull"));
  framePull_sigF3_fit->addPlotable(hpull_sigF3_fit,"P");

  RooHist* hpull_sigF3_fitb = sigF3_nj_F3_fit_b->pullHist();
  RooPlot* framePull_sigF3_fitb = w->var("nj_F3")->frame(Title("Pull"));
  framePull_sigF3_fitb->addPlotable(hpull_sigF3_fitb,"P");


  RooHist* hpull_sigF4_prefit = sigF4_nj_F4_prefit->pullHist();
  RooPlot* framePull_sigF4_prefit = w->var("nj_F4")->frame(Title("Pull"));
  framePull_sigF4_prefit->addPlotable(hpull_sigF4_prefit,"P");

  RooHist* hpull_sigF4_fit = sigF4_nj_F4_fit_s->pullHist();
  RooPlot* framePull_sigF4_fit = w->var("nj_F4")->frame(Title("Pull"));
  framePull_sigF4_fit->addPlotable(hpull_sigF4_fit,"P");

  RooHist* hpull_sigF4_fitb = sigF4_nj_F4_fit_b->pullHist();
  RooPlot* framePull_sigF4_fitb = w->var("nj_F4")->frame(Title("Pull"));
  framePull_sigF4_fitb->addPlotable(hpull_sigF4_fitb,"P");


  // ===================================================================================

  RooFitResult* fit_s = 0;
  fullfile->GetObject("fit_s",fit_s);
  RooFitResult* fit_b = 0;
  fullfile->GetObject("fit_b",fit_b);

  // Make 2D hists of the correlation matrices
  TH2* hcorr_fit = fit_s->correlationHist();
  TH2* hcorr_fitb = fit_b->correlationHist();


  // ===================================================================================

  // Create the summary canvases

  gStyle->SetPaintTextFormat("2.3f");

  // ------------ F1 -----------

  TCanvas* c_sigF1_prefit = new TCanvas("c_sigF1_prefit","Signal F1 prefit",900,900);
  c_sigF1_prefit->Divide(2,2);
  c_sigF1_prefit->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  sigF1_nj_F1_prefit->GetYaxis()->SetTitleOffset(2.0);
  sigF1_nj_F1_prefit->Draw();
  chiSquare_sigF1_prefit->Draw("same");  
  //text_N6_tt_F1->Draw("same");
  c_sigF1_prefit->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_sigF1_prefit_frame->GetYaxis()->SetTitleOffset(1.4);
  clone_sigF1_prefit_frame->SetMinimum(0.1);
  clone_sigF1_prefit_frame->SetMaximum(100000);
  //clone_sigF1_prefit_frame->remove("bkgMC_tt_F1_paramBox");
  clone_sigF1_prefit_frame->Draw();
  c_sigF1_prefit->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_sigF1_prefit->SetYTitle("(Fit-Data)/errData");
  framePull_sigF1_prefit->GetYaxis()->SetTitleOffset(1.4);
  framePull_sigF1_prefit->Draw();
  //c_sigF1_prefit->cd(4);
  //gPad->SetLeftMargin(0.15);
  //gPad->SetRightMargin(0.15);
  //gStyle->SetOptTitle(1);
  //hcorr_sigF1_prefit->SetStats(0);
  //hcorr_sigF1_prefit->SetMarkerSize(2.4);
  //hcorr_sigF1_prefit->Draw("COLZ,TEXT");
  c_sigF1_prefit->SaveAs("fit_report_sigF1_prefit.png");

  TCanvas* c_sigF1_fit = new TCanvas("c_sigF1_fit","Signal F1 fit",900,900);
  c_sigF1_fit->Divide(2,2);
  c_sigF1_fit->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  sigF1_nj_F1_fit_s->GetYaxis()->SetTitleOffset(2.0);
  sigF1_nj_F1_fit_s->Draw();
  chiSquare_sigF1_fit->Draw("same");  
  //text_N6_tt_F1->Draw("same");
  c_sigF1_fit->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_sigF1_fit_frame->GetYaxis()->SetTitleOffset(1.4);
  clone_sigF1_fit_frame->SetMinimum(0.1);
  clone_sigF1_fit_frame->SetMaximum(100000);
  //clone_sigF1_fit_frame->remove("bkgMC_tt_F1_paramBox");
  clone_sigF1_fit_frame->Draw();
  c_sigF1_fit->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_sigF1_fit->SetYTitle("(Fit-Data)/errData");
  framePull_sigF1_fit->GetYaxis()->SetTitleOffset(1.4);
  framePull_sigF1_fit->Draw();
  //c_sigF1_fit->cd(4);
  //gPad->SetLeftMargin(0.15);
  //gPad->SetRightMargin(0.15);
  //gStyle->SetOptTitle(1);
  //hcorr_sigF1_fit->SetStats(0);
  //hcorr_sigF1_fit->SetMarkerSize(2.4);
  //hcorr_sigF1_fit->Draw("COLZ,TEXT");
  c_sigF1_fit->SaveAs("fit_report_sigF1_fit.png");

  TCanvas* c_sigF1_fitb = new TCanvas("c_sigF1_fitb","F1 fit bkg only",900,900);
  c_sigF1_fitb->Divide(2,2);
  c_sigF1_fitb->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  sigF1_nj_F1_fit_b->GetYaxis()->SetTitleOffset(2.0);
  sigF1_nj_F1_fit_b->Draw();
  chiSquare_sigF1_fitb->Draw("same");  
  //text_N6_tt_F1->Draw("same");
  c_sigF1_fitb->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_sigF1_fitb_frame->GetYaxis()->SetTitleOffset(1.4);
  clone_sigF1_fitb_frame->SetMinimum(0.1);
  clone_sigF1_fitb_frame->SetMaximum(100000);
  //clone_sigF1_fit_frame->remove("bkgMC_tt_F1_paramBox");
  clone_sigF1_fitb_frame->Draw();
  c_sigF1_fitb->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_sigF1_fitb->SetYTitle("(Fit-Data)/errData");
  framePull_sigF1_fitb->GetYaxis()->SetTitleOffset(1.4);
  framePull_sigF1_fitb->Draw();
  //c_sigF1_fitb->cd(4);
  //gPad->SetLeftMargin(0.15);
  //gPad->SetRightMargin(0.15);
  //gStyle->SetOptTitle(1);
  //hcorr_sigF1_fitb->SetStats(0);
  //hcorr_sigF1_fitb->SetMarkerSize(2.4);
  //hcorr_sigF1_fitb->Draw("COLZ,TEXT");
  c_sigF1_fitb->SaveAs("fit_report_sigF1_fitb.png");


  // ------------ F2 -----------

  TCanvas* c_sigF2_prefit = new TCanvas("c_sigF2_prefit","Signal F2 prefit",900,900);
  c_sigF2_prefit->Divide(2,2);
  c_sigF2_prefit->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  sigF2_nj_F2_prefit->GetYaxis()->SetTitleOffset(2.0);
  sigF2_nj_F2_prefit->Draw();
  chiSquare_sigF2_prefit->Draw("same");  
  //text_N6_tt_F2->Draw("same");
  c_sigF2_prefit->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_sigF2_prefit_frame->GetYaxis()->SetTitleOffset(1.4);
  clone_sigF2_prefit_frame->SetMinimum(0.1);
  clone_sigF2_prefit_frame->SetMaximum(100000);
  //clone_sigF2_prefit_frame->remove("bkgMC_tt_F2_paramBox");
  clone_sigF2_prefit_frame->Draw();
  c_sigF2_prefit->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_sigF2_prefit->SetYTitle("(Fit-Data)/errData");
  framePull_sigF2_prefit->GetYaxis()->SetTitleOffset(1.4);
  framePull_sigF2_prefit->Draw();
  //c_sigF2_prefit->cd(4);
  //gPad->SetLeftMargin(0.15);
  //gPad->SetRightMargin(0.15);
  //gStyle->SetOptTitle(1);
  //hcorr_sigF2_prefit->SetStats(0);
  //hcorr_sigF2_prefit->SetMarkerSize(2.4);
  //hcorr_sigF2_prefit->Draw("COLZ,TEXT");
  c_sigF2_prefit->SaveAs("fit_report_sigF2_prefit.png");

  TCanvas* c_sigF2_fit = new TCanvas("c_sigF2_fit","Signal F2 fit",900,900);
  c_sigF2_fit->Divide(2,2);
  c_sigF2_fit->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  sigF2_nj_F2_fit_s->GetYaxis()->SetTitleOffset(2.0);
  sigF2_nj_F2_fit_s->Draw();
  chiSquare_sigF2_fit->Draw("same");  
  //text_N6_tt_F2->Draw("same");
  c_sigF2_fit->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_sigF2_fit_frame->GetYaxis()->SetTitleOffset(1.4);
  clone_sigF2_fit_frame->SetMinimum(0.1);
  clone_sigF2_fit_frame->SetMaximum(100000);
  //clone_sigF2_fit_frame->remove("bkgMC_tt_F2_paramBox");
  clone_sigF2_fit_frame->Draw();
  c_sigF2_fit->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_sigF2_fit->SetYTitle("(Fit-Data)/errData");
  framePull_sigF2_fit->GetYaxis()->SetTitleOffset(1.4);
  framePull_sigF2_fit->Draw();
  //c_sigF2_fit->cd(4);
  //gPad->SetLeftMargin(0.15);
  //gPad->SetRightMargin(0.15);
  //gStyle->SetOptTitle(1);
  //hcorr_sigF2_fit->SetStats(0);
  //hcorr_sigF2_fit->SetMarkerSize(2.4);
  //hcorr_sigF2_fit->Draw("COLZ,TEXT");
  c_sigF2_fit->SaveAs("fit_report_sigF2_fit.png");

  TCanvas* c_sigF2_fitb = new TCanvas("c_sigF2_fitb","F2 fit bkg only",900,900);
  c_sigF2_fitb->Divide(2,2);
  c_sigF2_fitb->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  sigF2_nj_F2_fit_b->GetYaxis()->SetTitleOffset(2.0);
  sigF2_nj_F2_fit_b->Draw();
  chiSquare_sigF2_fitb->Draw("same");  
  //text_N6_tt_F2->Draw("same");
  c_sigF2_fitb->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_sigF2_fitb_frame->GetYaxis()->SetTitleOffset(1.4);
  clone_sigF2_fitb_frame->SetMinimum(0.1);
  clone_sigF2_fitb_frame->SetMaximum(100000);
  //clone_sigF2_fit_frame->remove("bkgMC_tt_F2_paramBox");
  clone_sigF2_fitb_frame->Draw();
  c_sigF2_fitb->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_sigF2_fitb->SetYTitle("(Fit-Data)/errData");
  framePull_sigF2_fitb->GetYaxis()->SetTitleOffset(1.4);
  framePull_sigF2_fitb->Draw();
  //c_sigF2_fitb->cd(4);
  //gPad->SetLeftMargin(0.15);
  //gPad->SetRightMargin(0.15);
  //gStyle->SetOptTitle(1);
  //hcorr_sigF2_fitb->SetStats(0);
  //hcorr_sigF2_fitb->SetMarkerSize(2.4);
  //hcorr_sigF2_fitb->Draw("COLZ,TEXT");
  c_sigF2_fitb->SaveAs("fit_report_sigF2_fitb.png");


  // ------------ F3 -----------

  TCanvas* c_sigF3_prefit = new TCanvas("c_sigF3_prefit","Signal F3 prefit",900,900);
  c_sigF3_prefit->Divide(2,2);
  c_sigF3_prefit->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  sigF3_nj_F3_prefit->GetYaxis()->SetTitleOffset(2.0);
  sigF3_nj_F3_prefit->Draw();
  chiSquare_sigF3_prefit->Draw("same");  
  //text_N6_tt_F3->Draw("same");
  c_sigF3_prefit->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_sigF3_prefit_frame->GetYaxis()->SetTitleOffset(1.4);
  clone_sigF3_prefit_frame->SetMinimum(0.1);
  clone_sigF3_prefit_frame->SetMaximum(100000);
  //clone_sigF3_prefit_frame->remove("bkgMC_tt_F3_paramBox");
  clone_sigF3_prefit_frame->Draw();
  c_sigF3_prefit->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_sigF3_prefit->SetYTitle("(Fit-Data)/errData");
  framePull_sigF3_prefit->GetYaxis()->SetTitleOffset(1.4);
  framePull_sigF3_prefit->Draw();
  //c_sigF3_prefit->cd(4);
  //gPad->SetLeftMargin(0.15);
  //gPad->SetRightMargin(0.15);
  //gStyle->SetOptTitle(1);
  //hcorr_sigF3_prefit->SetStats(0);
  //hcorr_sigF3_prefit->SetMarkerSize(2.4);
  //hcorr_sigF3_prefit->Draw("COLZ,TEXT");
  c_sigF3_prefit->SaveAs("fit_report_sigF3_prefit.png");

  TCanvas* c_sigF3_fit = new TCanvas("c_sigF3_fit","Signal F3 fit",900,900);
  c_sigF3_fit->Divide(2,2);
  c_sigF3_fit->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  sigF3_nj_F3_fit_s->GetYaxis()->SetTitleOffset(2.0);
  sigF3_nj_F3_fit_s->Draw();
  chiSquare_sigF3_fit->Draw("same");  
  //text_N6_tt_F3->Draw("same");
  c_sigF3_fit->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_sigF3_fit_frame->GetYaxis()->SetTitleOffset(1.4);
  clone_sigF3_fit_frame->SetMinimum(0.1);
  clone_sigF3_fit_frame->SetMaximum(100000);
  //clone_sigF3_fit_frame->remove("bkgMC_tt_F3_paramBox");
  clone_sigF3_fit_frame->Draw();
  c_sigF3_fit->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_sigF3_fit->SetYTitle("(Fit-Data)/errData");
  framePull_sigF3_fit->GetYaxis()->SetTitleOffset(1.4);
  framePull_sigF3_fit->Draw();
  //c_sigF3_fit->cd(4);
  //gPad->SetLeftMargin(0.15);
  //gPad->SetRightMargin(0.15);
  //gStyle->SetOptTitle(1);
  //hcorr_sigF3_fit->SetStats(0);
  //hcorr_sigF3_fit->SetMarkerSize(2.4);
  //hcorr_sigF3_fit->Draw("COLZ,TEXT");
  c_sigF3_fit->SaveAs("fit_report_sigF3_fit.png");

  TCanvas* c_sigF3_fitb = new TCanvas("c_sigF3_fitb","F3 fit bkg only",900,900);
  c_sigF3_fitb->Divide(2,2);
  c_sigF3_fitb->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  sigF3_nj_F3_fit_b->GetYaxis()->SetTitleOffset(2.0);
  sigF3_nj_F3_fit_b->Draw();
  chiSquare_sigF3_fitb->Draw("same");  
  //text_N6_tt_F3->Draw("same");
  c_sigF3_fitb->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_sigF3_fitb_frame->GetYaxis()->SetTitleOffset(1.4);
  clone_sigF3_fitb_frame->SetMinimum(0.1);
  clone_sigF3_fitb_frame->SetMaximum(100000);
  //clone_sigF3_fit_frame->remove("bkgMC_tt_F3_paramBox");
  clone_sigF3_fitb_frame->Draw();
  c_sigF3_fitb->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_sigF3_fitb->SetYTitle("(Fit-Data)/errData");
  framePull_sigF3_fitb->GetYaxis()->SetTitleOffset(1.4);
  framePull_sigF3_fitb->Draw();
  //c_sigF3_fitb->cd(4);
  //gPad->SetLeftMargin(0.15);
  //gPad->SetRightMargin(0.15);
  //gStyle->SetOptTitle(1);
  //hcorr_sigF3_fitb->SetStats(0);
  //hcorr_sigF3_fitb->SetMarkerSize(2.4);
  //hcorr_sigF3_fitb->Draw("COLZ,TEXT");
  c_sigF3_fitb->SaveAs("fit_report_sigF3_fitb.png");


  // ------------ F4 -----------

  TCanvas* c_sigF4_prefit = new TCanvas("c_sigF4_prefit","Signal F4 prefit",900,900);
  c_sigF4_prefit->Divide(2,2);
  c_sigF4_prefit->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  sigF4_nj_F4_prefit->GetYaxis()->SetTitleOffset(2.0);
  sigF4_nj_F4_prefit->Draw();
  chiSquare_sigF4_prefit->Draw("same");  
  //text_N6_tt_F4->Draw("same");
  c_sigF4_prefit->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_sigF4_prefit_frame->GetYaxis()->SetTitleOffset(1.4);
  clone_sigF4_prefit_frame->SetMinimum(0.1);
  clone_sigF4_prefit_frame->SetMaximum(100000);
  //clone_sigF4_prefit_frame->remove("bkgMC_tt_F4_paramBox");
  clone_sigF4_prefit_frame->Draw();
  c_sigF4_prefit->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_sigF4_prefit->SetYTitle("(Fit-Data)/errData");
  framePull_sigF4_prefit->GetYaxis()->SetTitleOffset(1.4);
  framePull_sigF4_prefit->Draw();
  //c_sigF4_prefit->cd(4);
  //gPad->SetLeftMargin(0.15);
  //gPad->SetRightMargin(0.15);
  //gStyle->SetOptTitle(1);
  //hcorr_sigF4_prefit->SetStats(0);
  //hcorr_sigF4_prefit->SetMarkerSize(2.4);
  //hcorr_sigF4_prefit->Draw("COLZ,TEXT");
  c_sigF4_prefit->SaveAs("fit_report_sigF4_prefit.png");

  TCanvas* c_sigF4_fit = new TCanvas("c_sigF4_fit","Signal F4 fit",900,900);
  c_sigF4_fit->Divide(2,2);
  c_sigF4_fit->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  sigF4_nj_F4_fit_s->GetYaxis()->SetTitleOffset(2.0);
  sigF4_nj_F4_fit_s->Draw();
  chiSquare_sigF4_fit->Draw("same");  
  //text_N6_tt_F4->Draw("same");
  c_sigF4_fit->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_sigF4_fit_frame->GetYaxis()->SetTitleOffset(1.4);
  clone_sigF4_fit_frame->SetMinimum(0.1);
  clone_sigF4_fit_frame->SetMaximum(100000);
  //clone_sigF4_fit_frame->remove("bkgMC_tt_F4_paramBox");
  clone_sigF4_fit_frame->Draw();
  c_sigF4_fit->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_sigF4_fit->SetYTitle("(Fit-Data)/errData");
  framePull_sigF4_fit->GetYaxis()->SetTitleOffset(1.4);
  framePull_sigF4_fit->Draw();
  //c_sigF4_fit->cd(4);
  //gPad->SetLeftMargin(0.15);
  //gPad->SetRightMargin(0.15);
  //gStyle->SetOptTitle(1);
  //hcorr_sigF4_fit->SetStats(0);
  //hcorr_sigF4_fit->SetMarkerSize(2.4);
  //hcorr_sigF4_fit->Draw("COLZ,TEXT");
  c_sigF4_fit->SaveAs("fit_report_sigF4_fit.png");

  TCanvas* c_sigF4_fitb = new TCanvas("c_sigF4_fitb","F4 fit bkg only",900,900);
  c_sigF4_fitb->Divide(2,2);
  c_sigF4_fitb->cd(1);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  sigF4_nj_F4_fit_b->GetYaxis()->SetTitleOffset(2.0);
  sigF4_nj_F4_fit_b->Draw();
  chiSquare_sigF4_fitb->Draw("same");  
  //text_N6_tt_F4->Draw("same");
  c_sigF4_fitb->cd(2);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(0);
  gPad->SetLogy();
  clone_sigF4_fitb_frame->GetYaxis()->SetTitleOffset(1.4);
  clone_sigF4_fitb_frame->SetMinimum(0.1);
  clone_sigF4_fitb_frame->SetMaximum(100000);
  //clone_sigF4_fit_frame->remove("bkgMC_tt_F4_paramBox");
  clone_sigF4_fitb_frame->Draw();
  c_sigF4_fitb->cd(3);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  framePull_sigF4_fitb->SetYTitle("(Fit-Data)/errData");
  framePull_sigF4_fitb->GetYaxis()->SetTitleOffset(1.4);
  framePull_sigF4_fitb->Draw();
  //c_sigF4_fitb->cd(4);
  //gPad->SetLeftMargin(0.15);
  //gPad->SetRightMargin(0.15);
  //gStyle->SetOptTitle(1);
  //hcorr_sigF4_fitb->SetStats(0);
  //hcorr_sigF4_fitb->SetMarkerSize(2.4);
  //hcorr_sigF4_fitb->Draw("COLZ,TEXT");
  c_sigF4_fitb->SaveAs("fit_report_sigF4_fitb.png");



  TCanvas* c_fit_s_corr = new TCanvas("c_fit_s_corr","signal region correlation matrix",900,900);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(1);
  hcorr_fit->SetStats(0);
  hcorr_fit->SetMarkerSize(1.0);
  hcorr_fit->Draw("COLZ,TEXT");
  c_fit_s_corr->SaveAs("fit_report_correlation.png");


  TCanvas* c_fit_b_corr = new TCanvas("c_fit_b_corr","signal region correlation matrix bkg only",900,900);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  gStyle->SetOptTitle(1);
  hcorr_fitb->SetStats(0);
  hcorr_fitb->SetMarkerSize(1.0);
  hcorr_fitb->Draw("COLZ,TEXT");
  c_fit_b_corr->SaveAs("fit_report_correlation_b.png");

}
