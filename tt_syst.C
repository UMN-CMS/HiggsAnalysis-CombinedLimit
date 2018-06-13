// Make the tt shape systematic histograms
// Aron Soha
// June 5, 2018

#include "RooRealVar.h"
#include "RooFitResult.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
#include "TFile.h"

using namespace RooFit;

void tt_syst() {

  gStyle->SetOptStat(0);

  TFile* file = TFile::Open("njets_rebinned.root","UPDATE");

  // RooWorkspace *w = new RooWorkspace("w","w");
  // w->factory("nj[6.5,14.5]");
  // w->var("nj")->setBins(8);
  // RooArgSet vars(*w->var("nj"));

  // // tt ---------------------------------------------------------------------------------------

  // // F1
  // TH1* ttMC_th1_F1 = 0;
  // file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_TT",ttMC_th1_F1);

  // w->factory("p0_tt_F1[0.34,0.14,0.54]");
  // w->factory("p1_tt_F1[0.22,0.02,0.42]");
  // w->factory("p2_tt_F1[-0.32,-0.52,-0.12]");

  // w->factory(TString::Format("N7_tt_F1[%f,%f,%f]",ttMC_th1_F1->GetBinContent(1),ttMC_th1_F1->GetBinContent(1)-5000,ttMC_th1_F1->GetBinContent(1)+5000));
  
  // RooDataHist ttMC_hist_F1("ttMC_obs_F1","tt MC observed in signal region 1",vars,ttMC_th1_F1);
  // w->import(ttMC_hist_F1);
  // // shape for tt bkg MC
  // w->factory("RooNjetsPdf::bkgMC_tt_F1(nj,p0_tt_F1,p1_tt_F1,p2_tt_F1,N7_tt_F1)");
  // w->import(*w->pdf("bkgMC_tt_F1"));

  // RooAbsPdf* model_tt_F1 = w->pdf("bkgMC_tt_F1");
  // SumW2Error(kTRUE);
  // RooFitResult* r_tt_F1 = model_tt_F1->fitTo(ttMC_hist_F1,Save());
  // r_tt_F1->Print("V");

  // RooPlot* ttframe_F1 = w->var("nj")->frame(Title("njets tt F1 PDF"));
  // ttMC_hist_F1.plotOn(ttframe_F1);
  // model_tt_F1->plotOn(ttframe_F1);
  // model_tt_F1->paramOn(ttframe_F1,Layout(0.35,0.622912,0.773497));
  // ttframe_F1->getAttLine()->SetLineWidth(0);

  // new TCanvas("tt F1 fit result","tt F1 fit results",600,600);
  // gPad->SetLeftMargin(0.15);
  // ttframe_F1->GetYaxis()->SetTitleOffset(2.0);
  // ttframe_F1->Draw();


  // // variation 1, with min p0, min p1, min p2
  // w->factory("RooNjetsPdf::bkgMC_tt_F1_var1(nj,0.319,0.184,-0.397,N7_tt_F1)");
  // RooAbsPdf* model_tt_F1_var1 = w->pdf("bkgMC_tt_F1_var1");
  // model_tt_F1_var1->plotOn(ttframe_F1,LineStyle(kDashed),LineColor(kMagenta));

  // // variation 2, with max p0, max p1, max p2
  // w->factory("RooNjetsPdf::bkgMC_tt_F1_var2(nj,0.341,0.242,-0.187,N7_tt_F1)");
  // RooAbsPdf* model_tt_F1_var2 = w->pdf("bkgMC_tt_F1_var2");
  // model_tt_F1_var2->plotOn(ttframe_F1,LineStyle(kDashed),LineColor(kGreen));

  // // variation 3, with min p0, min p1, max p2
  // w->factory("RooNjetsPdf::bkgMC_tt_F1_var3(nj,0.319,0.184,-0.187,N7_tt_F1)");
  // RooAbsPdf* model_tt_F1_var3 = w->pdf("bkgMC_tt_F1_var3");
  // model_tt_F1_var3->plotOn(ttframe_F1,LineStyle(kDashed),LineColor(kRed));

  // // variation 4, with max p0, max p1, min p2
  // w->factory("RooNjetsPdf::bkgMC_tt_F1_var4(nj,0.341,0.242,-0.397,N7_tt_F1)");
  // RooAbsPdf* model_tt_F1_var4 = w->pdf("bkgMC_tt_F1_var4");
  // model_tt_F1_var4->plotOn(ttframe_F1,LineStyle(kDashed),LineColor(kYellow));

  // ttframe_F1->Draw();

  // =========================================================================

  // Add the three tt bkg Fisher samples together
  TH1* ttMC_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_TT",ttMC_th1_F1);
  TH1* ttMC_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_TT",ttMC_th1_F2);
  TH1* ttMC_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_TT",ttMC_th1_F3);
  TH1* ttMC_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_TT",ttMC_th1_F4);

  TH1D *tt_sum = (TH1D*)ttMC_th1_F1->Clone("tt_F1");
  TH1D *tt_F1 = (TH1D*)ttMC_th1_F1->Clone("tt_F1");
  TH1D *tt_F2 = (TH1D*)ttMC_th1_F2->Clone("tt_F2");
  TH1D *tt_F3 = (TH1D*)ttMC_th1_F3->Clone("tt_F3");
  TH1D *tt_F4 = (TH1D*)ttMC_th1_F4->Clone("tt_F4");

  if (tt_sum->GetSumw2N() == 0) tt_sum->Sumw2(kTRUE);
  if (tt_F1->GetSumw2N() == 0) tt_F1->Sumw2(kTRUE);
  if (tt_F2->GetSumw2N() == 0) tt_F2->Sumw2(kTRUE);
  if (tt_F3->GetSumw2N() == 0) tt_F3->Sumw2(kTRUE);
  if (tt_F4->GetSumw2N() == 0) tt_F4->Sumw2(kTRUE);

  tt_sum->Add(tt_sum,tt_F2);
  tt_sum->Add(tt_sum,tt_F3);
  tt_sum->Add(tt_sum,tt_F4);

  TH1D *tt_sum_n = (TH1D*)tt_sum->Clone("tt_sum_n");
  TH1D *tt_F1_n = (TH1D*)tt_F1->Clone("tt_F1_n");
  TH1D *tt_F2_n = (TH1D*)tt_F2->Clone("tt_F2_n");
  TH1D *tt_F3_n = (TH1D*)tt_F3->Clone("tt_F3_n");
  TH1D *tt_F4_n = (TH1D*)tt_F4->Clone("tt_F4_n");

  if (tt_sum_n->GetSumw2N() == 0) tt_sum_n->Sumw2(kTRUE);
  if (tt_F1_n->GetSumw2N() == 0) tt_F1_n->Sumw2(kTRUE);
  if (tt_F2_n->GetSumw2N() == 0) tt_F2_n->Sumw2(kTRUE);
  if (tt_F3_n->GetSumw2N() == 0) tt_F3_n->Sumw2(kTRUE);
  if (tt_F4_n->GetSumw2N() == 0) tt_F4_n->Sumw2(kTRUE);

  tt_sum_n->Scale(1/tt_sum_n->Integral());
  tt_F1_n->Scale(1/tt_F1_n->Integral());
  tt_F2_n->Scale(1/tt_F2_n->Integral());
  tt_F3_n->Scale(1/tt_F3_n->Integral());
  tt_F4_n->Scale(1/tt_F4_n->Integral());

  TCanvas *c1 = new TCanvas("NormDistros","Normalized Njets for sum and individual Fisher bins",800,800);
  c1->SetLogy();

  tt_sum_n->SetLineColor(kBlack);
  tt_sum_n->GetXaxis()->SetTitle("njets");
  tt_sum_n->SetTitle(0);
  tt_sum_n->Draw();
  tt_F1_n->SetLineColor(kRed);
  tt_F1_n->Draw("same");
  tt_F2_n->SetLineColor(kBlue);
  tt_F2_n->Draw("same");
  tt_F3_n->SetLineColor(kGreen);
  tt_F3_n->Draw("same");
  tt_F4_n->SetLineColor(kMagenta);
  tt_F4_n->Draw("same");

  TLegend *leg = new TLegend(0.50,0.68,0.88,0.88);
  leg->SetHeader("Normalized njets distributions");
  leg->AddEntry(tt_F1_n,"Fisher 1","l");
  leg->AddEntry(tt_F2_n,"Fisher 2","l");
  leg->AddEntry(tt_F3_n,"Fisher 3","l");
  leg->AddEntry(tt_F4_n,"Fisher 4","l");
  leg->AddEntry(tt_sum_n,"Sum","l");
  leg->Draw();

  c1->SaveAs("tt_Njets_norm.png");

  // For each fisher bin, ratio of normalized njets of that fisher bin to normalized njets of sum
  TCanvas *c2 = new TCanvas("Fractions","Ratio of Normalized njets",800,800);
  c2->Divide(2,2);

  TH1D *tt_F1_ratio = (TH1D*)tt_F1_n->Clone("tt_F1_ratio");
  TH1D *tt_F2_ratio = (TH1D*)tt_F2_n->Clone("tt_F2_ratio");
  TH1D *tt_F3_ratio = (TH1D*)tt_F3_n->Clone("tt_F3_ratio");
  TH1D *tt_F4_ratio = (TH1D*)tt_F4_n->Clone("tt_F4_ratio");

  if (tt_F1_ratio->GetSumw2N() == 0) tt_F1_ratio->Sumw2(kTRUE);
  if (tt_F2_ratio->GetSumw2N() == 0) tt_F2_ratio->Sumw2(kTRUE);
  if (tt_F3_ratio->GetSumw2N() == 0) tt_F3_ratio->Sumw2(kTRUE);
  if (tt_F4_ratio->GetSumw2N() == 0) tt_F4_ratio->Sumw2(kTRUE);

  tt_F1_ratio->Divide(tt_sum_n);
  tt_F2_ratio->Divide(tt_sum_n);
  tt_F3_ratio->Divide(tt_sum_n);
  tt_F4_ratio->Divide(tt_sum_n);

  c2->cd(1);  
  tt_F1_ratio->SetTitle("Ratio of Fisher 1 to Sum");
  tt_F1_ratio->GetXaxis()->SetTitle("njets");
  tt_F1_ratio->GetYaxis()->SetTitle("Fisher 1 / Sum");
  tt_F1_ratio->GetYaxis()->SetTitleOffset(1.5);
  tt_F1_ratio->Draw();
  c2->cd(2);
  tt_F2_ratio->SetTitle("Ratio of Fisher 2 to Sum");
  tt_F2_ratio->GetXaxis()->SetTitle("njets");
  tt_F2_ratio->GetYaxis()->SetTitle("Fisher 2 / Sum");
  tt_F2_ratio->GetYaxis()->SetTitleOffset(1.5);
  tt_F2_ratio->Draw();
  c2->cd(3);
  tt_F3_ratio->SetTitle("Ratio of Fisher 3 to Sum");
  tt_F3_ratio->GetXaxis()->SetTitle("njets");
  tt_F3_ratio->GetYaxis()->SetTitle("Fisher 3 / Sum");
  tt_F3_ratio->GetYaxis()->SetTitleOffset(1.5);
  tt_F3_ratio->Draw();
  c2->cd(4);
  tt_F4_ratio->SetTitle("Ratio of Fisher 4 to Sum");
  tt_F4_ratio->GetXaxis()->SetTitle("njets");
  tt_F4_ratio->GetYaxis()->SetTitle("Fisher 4 / Sum");
  tt_F4_ratio->GetYaxis()->SetTitleOffset(1.5);
  tt_F4_ratio->Draw();

  c2->SaveAs("tt_Njets_ratios.png");

  // Njets histograms for each fisher bin after adjusting by the above ratio
  TCanvas *c3 = new TCanvas("Adjusted","Adjusted njets, for systematic",800,800);
  c3->Divide(2,2);

  TH1D *tt_F1_adj = (TH1D*)ttMC_th1_F1->Clone("tt_F1_adj");
  TH1D *tt_F2_adj = (TH1D*)ttMC_th1_F2->Clone("tt_F2_adj");
  TH1D *tt_F3_adj = (TH1D*)ttMC_th1_F3->Clone("tt_F3_adj");
  TH1D *tt_F4_adj = (TH1D*)ttMC_th1_F4->Clone("tt_F4_adj");

  if (tt_F1_adj->GetSumw2N() == 0) tt_F1_adj->Sumw2(kTRUE);
  if (tt_F2_adj->GetSumw2N() == 0) tt_F2_adj->Sumw2(kTRUE);
  if (tt_F3_adj->GetSumw2N() == 0) tt_F3_adj->Sumw2(kTRUE);
  if (tt_F4_adj->GetSumw2N() == 0) tt_F4_adj->Sumw2(kTRUE);

  tt_F1_adj->Multiply(tt_F1_ratio);
  tt_F2_adj->Multiply(tt_F2_ratio);
  tt_F3_adj->Multiply(tt_F3_ratio);
  tt_F4_adj->Multiply(tt_F4_ratio);

  c3->cd(1);
  gPad->SetLogy();
  ttMC_th1_F1->SetTitle("Fisher 1");
  ttMC_th1_F1->GetXaxis()->SetTitle("njets");
  ttMC_th1_F1->SetLineColor(1);
  ttMC_th1_F1->Draw();
  tt_F1_adj->SetLineColor(kRed);
  tt_F1_adj->Draw("same");
  TLegend *leg_adj = new TLegend(0.50,0.68,0.88,0.88);
  //leg_adj->SetHeader("njets");
  leg_adj->AddEntry(ttMC_th1_F1,"Original","l");
  leg_adj->AddEntry(tt_F1_adj,"Scaled by ratio","l");
  leg_adj->Draw();
  c3->cd(2);  
  gPad->SetLogy();
  ttMC_th1_F2->SetTitle("Fisher 2");
  ttMC_th1_F3->GetXaxis()->SetTitle("njets");
  ttMC_th1_F2->SetLineColor(1);
  ttMC_th1_F2->Draw();
  tt_F2_adj->SetLineColor(kRed);
  tt_F2_adj->Draw("same");
  c3->cd(3);  
  gPad->SetLogy();
  ttMC_th1_F3->SetTitle("Fisher 3");
  ttMC_th1_F3->GetXaxis()->SetTitle("njets");
  ttMC_th1_F3->SetLineColor(1);
  ttMC_th1_F3->Draw();
  tt_F3_adj->SetLineColor(kRed);
  tt_F3_adj->Draw("same");
  c3->cd(4);  
  gPad->SetLogy();
  ttMC_th1_F4->SetTitle("Fisher 4");
  ttMC_th1_F4->GetXaxis()->SetTitle("njets");
  ttMC_th1_F4->SetLineColor(1);
  ttMC_th1_F4->Draw();
  tt_F4_adj->SetLineColor(kRed);
  tt_F4_adj->Draw("same");

  c3->SaveAs("tt_Njets_adjusted.png");

  // Njets histograms for each fisher bin after adjusting by the above ratio
  TCanvas *c4 = new TCanvas("Systematic","Systematic for njets",800,800);
  c4->Divide(2,2);

  TH1D *tt_F1_syst = (TH1D*)tt_F1_adj->Clone("tt_F1_syst");
  TH1D *tt_F2_syst = (TH1D*)tt_F2_adj->Clone("tt_F2_syst");
  TH1D *tt_F3_syst = (TH1D*)tt_F3_adj->Clone("tt_F3_syst");
  TH1D *tt_F4_syst = (TH1D*)tt_F4_adj->Clone("tt_F4_syst");

  if (tt_F1_syst->GetSumw2N() == 0) tt_F1_syst->Sumw2(kTRUE);
  if (tt_F2_syst->GetSumw2N() == 0) tt_F2_syst->Sumw2(kTRUE);
  if (tt_F3_syst->GetSumw2N() == 0) tt_F3_syst->Sumw2(kTRUE);
  if (tt_F4_syst->GetSumw2N() == 0) tt_F4_syst->Sumw2(kTRUE);

  tt_F1_syst->Add(ttMC_th1_F1,-1);
  tt_F2_syst->Add(ttMC_th1_F2,-1);
  tt_F3_syst->Add(ttMC_th1_F3,-1);
  tt_F4_syst->Add(ttMC_th1_F4,-1);

  c4->cd(1);
  tt_F1_syst->SetTitle("Systematic Shift for Fisher 1");
  tt_F1_syst->GetXaxis()->SetTitle("njets");
  tt_F1_syst->SetLineColor(1);
  tt_F1_syst->Draw();
  c4->cd(2);
  tt_F2_syst->SetTitle("Systematic Shift for Fisher 2");
  tt_F2_syst->GetXaxis()->SetTitle("njets");
  tt_F2_syst->SetLineColor(1);
  tt_F2_syst->Draw();
  c4->cd(3);
  tt_F3_syst->SetTitle("Systematic Shift for Fisher 3");
  tt_F3_syst->GetXaxis()->SetTitle("njets");
  tt_F3_syst->SetLineColor(1);
  tt_F3_syst->Draw();
  c4->cd(4);
  tt_F4_syst->SetTitle("Systematic Shift for Fisher 4");
  tt_F4_syst->GetXaxis()->SetTitle("njets");
  tt_F4_syst->SetLineColor(1);
  tt_F4_syst->Draw();

  c4->SaveAs("tt_Njets_syst.png");

  // Save the four histograms with the systematic shifts to the already open file
  file->cd();
  tt_F1_syst->Write();
  tt_F2_syst->Write();
  tt_F3_syst->Write();
  tt_F4_syst->Write();




  // DON'T FORGET TO SET SUMW2 before any important final calculations


}
