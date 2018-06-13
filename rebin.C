void rebin() {

  //TFile* file = TFile::Open("njets_for_Aron.root");
  TFile* file = TFile::Open("njets_with_exact_pseudo_data.root");

  TH1* ttMC_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_TT",ttMC_th1_F1);
  //TH1* qcdMC_th1_F1 = 0;
  //file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_qcd",qcdMC_th1_F1);
  TH1* otherMC_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_other",otherMC_th1_F1);
  TH1* sigMC_SYY350_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_SYY 350",sigMC_SYY350_th1_F1);
  TH1* sigMC_SYY450_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_SYY 450",sigMC_SYY450_th1_F1);
  TH1* sigMC_SYY550_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_SYY 550",sigMC_SYY550_th1_F1);
  TH1* sigMC_SYY650_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_SYY 650",sigMC_SYY650_th1_F1);
  TH1* sigMC_SYY750_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_SYY 750",sigMC_SYY750_th1_F1);
  TH1* sigMC_SYY850_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_SYY 850",sigMC_SYY850_th1_F1);
  TH1* sigMC_RPV350_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 350",sigMC_RPV350_th1_F1);
  TH1* sigMC_RPV450_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 450",sigMC_RPV450_th1_F1);
  TH1* sigMC_RPV550_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 550",sigMC_RPV550_th1_F1);
  TH1* sigMC_RPV650_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 650",sigMC_RPV650_th1_F1);
  TH1* sigMC_RPV750_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 750",sigMC_RPV750_th1_F1);
  TH1* sigMC_RPV850_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 850",sigMC_RPV850_th1_F1);
  TH1* data_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodata",data_th1_F1);
  TH1* dataS_SYY350_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 350",dataS_SYY350_th1_F1);
  TH1* dataS_SYY450_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 450",dataS_SYY450_th1_F1);
  TH1* dataS_SYY550_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 550",dataS_SYY550_th1_F1);
  TH1* dataS_SYY650_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 650",dataS_SYY650_th1_F1);
  TH1* dataS_SYY750_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 750",dataS_SYY750_th1_F1);
  TH1* dataS_SYY850_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 850",dataS_SYY850_th1_F1);
  TH1* dataS_RPV350_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 350",dataS_RPV350_th1_F1);
  TH1* dataS_RPV450_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 450",dataS_RPV450_th1_F1);
  TH1* dataS_RPV550_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 550",dataS_RPV550_th1_F1);
  TH1* dataS_RPV650_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 650",dataS_RPV650_th1_F1);
  TH1* dataS_RPV750_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 750",dataS_RPV750_th1_F1);
  TH1* dataS_RPV850_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 850",dataS_RPV850_th1_F1);

  TH1* ttMC_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_TT",ttMC_th1_F2);
  //TH1* qcdMC_th1_F2 = 0;
  //file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_qcd",qcdMC_th1_F2);
  TH1* otherMC_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_other",otherMC_th1_F2);
  TH1* sigMC_SYY350_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_SYY 350",sigMC_SYY350_th1_F2);
  TH1* sigMC_SYY450_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_SYY 450",sigMC_SYY450_th1_F2);
  TH1* sigMC_SYY550_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_SYY 550",sigMC_SYY550_th1_F2);
  TH1* sigMC_SYY650_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_SYY 650",sigMC_SYY650_th1_F2);
  TH1* sigMC_SYY750_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_SYY 750",sigMC_SYY750_th1_F2);
  TH1* sigMC_SYY850_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_SYY 850",sigMC_SYY850_th1_F2);
  TH1* sigMC_RPV350_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 350",sigMC_RPV350_th1_F2);
  TH1* sigMC_RPV450_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 450",sigMC_RPV450_th1_F2);
  TH1* sigMC_RPV550_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 550",sigMC_RPV550_th1_F2);
  TH1* sigMC_RPV650_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 650",sigMC_RPV650_th1_F2);
  TH1* sigMC_RPV750_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 750",sigMC_RPV750_th1_F2);
  TH1* sigMC_RPV850_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 850",sigMC_RPV850_th1_F2);
  TH1* data_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodata",data_th1_F2);
  TH1* dataS_SYY350_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 350",dataS_SYY350_th1_F2);
  TH1* dataS_SYY450_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 450",dataS_SYY450_th1_F2);
  TH1* dataS_SYY550_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 550",dataS_SYY550_th1_F2);
  TH1* dataS_SYY650_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 650",dataS_SYY650_th1_F2);
  TH1* dataS_SYY750_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 750",dataS_SYY750_th1_F2);
  TH1* dataS_SYY850_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 850",dataS_SYY850_th1_F2);
  TH1* dataS_RPV350_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 350",dataS_RPV350_th1_F2);
  TH1* dataS_RPV450_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 450",dataS_RPV450_th1_F2);
  TH1* dataS_RPV550_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 550",dataS_RPV550_th1_F2);
  TH1* dataS_RPV650_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 650",dataS_RPV650_th1_F2);
  TH1* dataS_RPV750_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 750",dataS_RPV750_th1_F2);
  TH1* dataS_RPV850_th1_F2 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 850",dataS_RPV850_th1_F2);

  TH1* ttMC_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_TT",ttMC_th1_F3);
  //TH1* qcdMC_th1_F3 = 0;
  //file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_qcd",qcdMC_th1_F3);
  TH1* otherMC_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_other",otherMC_th1_F3);
  TH1* sigMC_SYY350_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_SYY 350",sigMC_SYY350_th1_F3);
  TH1* sigMC_SYY450_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_SYY 450",sigMC_SYY450_th1_F3);
  TH1* sigMC_SYY550_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_SYY 550",sigMC_SYY550_th1_F3);
  TH1* sigMC_SYY650_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_SYY 650",sigMC_SYY650_th1_F3);
  TH1* sigMC_SYY750_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_SYY 750",sigMC_SYY750_th1_F3);
  TH1* sigMC_SYY850_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_SYY 850",sigMC_SYY850_th1_F3);
  TH1* sigMC_RPV350_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_RPV 350",sigMC_RPV350_th1_F3);
  TH1* sigMC_RPV450_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_RPV 450",sigMC_RPV450_th1_F3);
  TH1* sigMC_RPV550_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_RPV 550",sigMC_RPV550_th1_F3);
  TH1* sigMC_RPV650_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_RPV 650",sigMC_RPV650_th1_F3);
  TH1* sigMC_RPV750_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_RPV 750",sigMC_RPV750_th1_F3);
  TH1* sigMC_RPV850_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_RPV 850",sigMC_RPV850_th1_F3);
  TH1* data_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodata",data_th1_F3);
  TH1* dataS_SYY350_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 350",dataS_SYY350_th1_F3);
  TH1* dataS_SYY450_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 450",dataS_SYY450_th1_F3);
  TH1* dataS_SYY550_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 550",dataS_SYY550_th1_F3);
  TH1* dataS_SYY650_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 650",dataS_SYY650_th1_F3);
  TH1* dataS_SYY750_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 750",dataS_SYY750_th1_F3);
  TH1* dataS_SYY850_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 850",dataS_SYY850_th1_F3);
  TH1* dataS_RPV350_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 350",dataS_RPV350_th1_F3);
  TH1* dataS_RPV450_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 450",dataS_RPV450_th1_F3);
  TH1* dataS_RPV550_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 550",dataS_RPV550_th1_F3);
  TH1* dataS_RPV650_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 650",dataS_RPV650_th1_F3);
  TH1* dataS_RPV750_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 750",dataS_RPV750_th1_F3);
  TH1* dataS_RPV850_th1_F3 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 850",dataS_RPV850_th1_F3);

  TH1* ttMC_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_TT",ttMC_th1_F4);
  //TH1* qcdMC_th1_F4 = 0;
  //file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_qcd",qcdMC_th1_F4);
  TH1* otherMC_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_other",otherMC_th1_F4);
  TH1* sigMC_SYY350_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_SYY 350",sigMC_SYY350_th1_F4);
  TH1* sigMC_SYY450_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_SYY 450",sigMC_SYY450_th1_F4);
  TH1* sigMC_SYY550_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_SYY 550",sigMC_SYY550_th1_F4);
  TH1* sigMC_SYY650_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_SYY 650",sigMC_SYY650_th1_F4);
  TH1* sigMC_SYY750_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_SYY 750",sigMC_SYY750_th1_F4);
  TH1* sigMC_SYY850_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_SYY 850",sigMC_SYY850_th1_F4);
  TH1* sigMC_RPV350_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 350",sigMC_RPV350_th1_F4);
  TH1* sigMC_RPV450_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 450",sigMC_RPV450_th1_F4);
  TH1* sigMC_RPV550_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 550",sigMC_RPV550_th1_F4);
  TH1* sigMC_RPV650_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 650",sigMC_RPV650_th1_F4);
  TH1* sigMC_RPV750_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 750",sigMC_RPV750_th1_F4);
  TH1* sigMC_RPV850_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 850",sigMC_RPV850_th1_F4);
  TH1* data_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodata",data_th1_F4);
  TH1* dataS_SYY350_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 350",dataS_SYY350_th1_F4);
  TH1* dataS_SYY450_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 450",dataS_SYY450_th1_F4);
  TH1* dataS_SYY550_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 550",dataS_SYY550_th1_F4);
  TH1* dataS_SYY650_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 650",dataS_SYY650_th1_F4);
  TH1* dataS_SYY750_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 750",dataS_SYY750_th1_F4);
  TH1* dataS_SYY850_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 850",dataS_SYY850_th1_F4);
  TH1* dataS_RPV350_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 350",dataS_RPV350_th1_F4);
  TH1* dataS_RPV450_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 450",dataS_RPV450_th1_F4);
  TH1* dataS_RPV550_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 550",dataS_RPV550_th1_F4);
  TH1* dataS_RPV650_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 650",dataS_RPV650_th1_F4);
  TH1* dataS_RPV750_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 750",dataS_RPV750_th1_F4);
  TH1* dataS_RPV850_th1_F4 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 850",dataS_RPV850_th1_F4);


  TH1D* F1_ttMC_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_TT","h_njets_pt30_1l_g1b_mbl_fisher1_TT",8,6.5,14.5);
  TH1D* F1_otherMC_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_other","h_njets_pt30_1l_g1b_mbl_fisher1_other",8,6.5,14.5);
  TH1D* F1_sigMC_SYY350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_SYY 350","h_njets_pt30_1l_g1b_mbl_fisher1_SYY 350",8,6.5,14.5);
  TH1D* F1_sigMC_SYY450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_SYY 450","h_njets_pt30_1l_g1b_mbl_fisher1_SYY 450",8,6.5,14.5);
  TH1D* F1_sigMC_SYY550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_SYY 550","h_njets_pt30_1l_g1b_mbl_fisher1_SYY 550",8,6.5,14.5);
  TH1D* F1_sigMC_SYY650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_SYY 650","h_njets_pt30_1l_g1b_mbl_fisher1_SYY 650",8,6.5,14.5);
  TH1D* F1_sigMC_SYY750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_SYY 750","h_njets_pt30_1l_g1b_mbl_fisher1_SYY 750",8,6.5,14.5);
  TH1D* F1_sigMC_SYY850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_SYY 850","h_njets_pt30_1l_g1b_mbl_fisher1_SYY 850",8,6.5,14.5);
  TH1D* F1_sigMC_RPV350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 350","h_njets_pt30_1l_g1b_mbl_fisher1_RPV 350",8,6.5,14.5);
  TH1D* F1_sigMC_RPV450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 450","h_njets_pt30_1l_g1b_mbl_fisher1_RPV 450",8,6.5,14.5);
  TH1D* F1_sigMC_RPV550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 550","h_njets_pt30_1l_g1b_mbl_fisher1_RPV 550",8,6.5,14.5);
  TH1D* F1_sigMC_RPV650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 650","h_njets_pt30_1l_g1b_mbl_fisher1_RPV 650",8,6.5,14.5);
  TH1D* F1_sigMC_RPV750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 750","h_njets_pt30_1l_g1b_mbl_fisher1_RPV 750",8,6.5,14.5);
  TH1D* F1_sigMC_RPV850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_RPV 850","h_njets_pt30_1l_g1b_mbl_fisher1_RPV 850",8,6.5,14.5);
  TH1D* F1_data_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodata","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodata",8,6.5,14.5);
  TH1D* F1_dataS_SYY350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 350","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 350",8,6.5,14.5);
  TH1D* F1_dataS_SYY450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 450","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 450",8,6.5,14.5);
  TH1D* F1_dataS_SYY550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 550","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 550",8,6.5,14.5);
  TH1D* F1_dataS_SYY650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 650","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 650",8,6.5,14.5);
  TH1D* F1_dataS_SYY750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 750","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 750",8,6.5,14.5);
  TH1D* F1_dataS_SYY850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 850","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_SYY 850",8,6.5,14.5);
  TH1D* F1_dataS_RPV350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 350","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 350",8,6.5,14.5);
  TH1D* F1_dataS_RPV450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 450","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 450",8,6.5,14.5);
  TH1D* F1_dataS_RPV550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 550","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 550",8,6.5,14.5);
  TH1D* F1_dataS_RPV650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 650","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 650",8,6.5,14.5);
  TH1D* F1_dataS_RPV750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 750","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 750",8,6.5,14.5);
  TH1D* F1_dataS_RPV850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 850","h_njets_pt30_1l_g1b_mbl_fisher1_pseudodataS_RPV 850",8,6.5,14.5);

  TH1D* F2_ttMC_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_TT","h_njets_pt30_1l_g1b_mbl_fisher2_TT",8,6.5,14.5);
  TH1D* F2_otherMC_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_other","h_njets_pt30_1l_g1b_mbl_fisher2_other",8,6.5,14.5);
  TH1D* F2_sigMC_SYY350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_SYY 350","h_njets_pt30_1l_g1b_mbl_fisher2_SYY 350",8,6.5,14.5);
  TH1D* F2_sigMC_SYY450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_SYY 450","h_njets_pt30_1l_g1b_mbl_fisher2_SYY 450",8,6.5,14.5);
  TH1D* F2_sigMC_SYY550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_SYY 550","h_njets_pt30_1l_g1b_mbl_fisher2_SYY 550",8,6.5,14.5);
  TH1D* F2_sigMC_SYY650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_SYY 650","h_njets_pt30_1l_g1b_mbl_fisher2_SYY 650",8,6.5,14.5);
  TH1D* F2_sigMC_SYY750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_SYY 750","h_njets_pt30_1l_g1b_mbl_fisher2_SYY 750",8,6.5,14.5);
  TH1D* F2_sigMC_SYY850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_SYY 850","h_njets_pt30_1l_g1b_mbl_fisher2_SYY 850",8,6.5,14.5);
  TH1D* F2_sigMC_RPV350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 350","h_njets_pt30_1l_g1b_mbl_fisher2_RPV 350",8,6.5,14.5);
  TH1D* F2_sigMC_RPV450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 450","h_njets_pt30_1l_g1b_mbl_fisher2_RPV 450",8,6.5,14.5);
  TH1D* F2_sigMC_RPV550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 550","h_njets_pt30_1l_g1b_mbl_fisher2_RPV 550",8,6.5,14.5);
  TH1D* F2_sigMC_RPV650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 650","h_njets_pt30_1l_g1b_mbl_fisher2_RPV 650",8,6.5,14.5);
  TH1D* F2_sigMC_RPV750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 750","h_njets_pt30_1l_g1b_mbl_fisher2_RPV 750",8,6.5,14.5);
  TH1D* F2_sigMC_RPV850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_RPV 850","h_njets_pt30_1l_g1b_mbl_fisher2_RPV 850",8,6.5,14.5);
  TH1D* F2_data_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodata","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodata",8,6.5,14.5);
  TH1D* F2_dataS_SYY350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 350","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 350",8,6.5,14.5);
  TH1D* F2_dataS_SYY450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 450","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 450",8,6.5,14.5);
  TH1D* F2_dataS_SYY550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 550","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 550",8,6.5,14.5);
  TH1D* F2_dataS_SYY650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 650","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 650",8,6.5,14.5);
  TH1D* F2_dataS_SYY750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 750","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 750",8,6.5,14.5);
  TH1D* F2_dataS_SYY850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 850","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_SYY 850",8,6.5,14.5);
  TH1D* F2_dataS_RPV350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 350","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 350",8,6.5,14.5);
  TH1D* F2_dataS_RPV450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 450","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 450",8,6.5,14.5);
  TH1D* F2_dataS_RPV550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 550","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 550",8,6.5,14.5);
  TH1D* F2_dataS_RPV650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 650","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 650",8,6.5,14.5);
  TH1D* F2_dataS_RPV750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 750","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 750",8,6.5,14.5);
  TH1D* F2_dataS_RPV850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 850","h_njets_pt30_1l_g1b_mbl_fisher2_pseudodataS_RPV 850",8,6.5,14.5);

  TH1D* F3_ttMC_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_TT","h_njets_pt30_1l_g1b_mbl_fisher3_TT",8,6.5,14.5);
  TH1D* F3_otherMC_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_other","h_njets_pt30_1l_g1b_mbl_fisher3_other",8,6.5,14.5);
  TH1D* F3_sigMC_SYY350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_SYY 350","h_njets_pt30_1l_g1b_mbl_fisher3_SYY 350",8,6.5,14.5);
  TH1D* F3_sigMC_SYY450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_SYY 450","h_njets_pt30_1l_g1b_mbl_fisher3_SYY 450",8,6.5,14.5);
  TH1D* F3_sigMC_SYY550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_SYY 550","h_njets_pt30_1l_g1b_mbl_fisher3_SYY 550",8,6.5,14.5);
  TH1D* F3_sigMC_SYY650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_SYY 650","h_njets_pt30_1l_g1b_mbl_fisher3_SYY 650",8,6.5,14.5);
  TH1D* F3_sigMC_SYY750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_SYY 750","h_njets_pt30_1l_g1b_mbl_fisher3_SYY 750",8,6.5,14.5);
  TH1D* F3_sigMC_SYY850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_SYY 850","h_njets_pt30_1l_g1b_mbl_fisher3_SYY 850",8,6.5,14.5);
  TH1D* F3_sigMC_RPV350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_RPV 350","h_njets_pt30_1l_g1b_mbl_fisher3_RPV 350",8,6.5,14.5);
  TH1D* F3_sigMC_RPV450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_RPV 450","h_njets_pt30_1l_g1b_mbl_fisher3_RPV 450",8,6.5,14.5);
  TH1D* F3_sigMC_RPV550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_RPV 550","h_njets_pt30_1l_g1b_mbl_fisher3_RPV 550",8,6.5,14.5);
  TH1D* F3_sigMC_RPV650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_RPV 650","h_njets_pt30_1l_g1b_mbl_fisher3_RPV 650",8,6.5,14.5);
  TH1D* F3_sigMC_RPV750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_RPV 750","h_njets_pt30_1l_g1b_mbl_fisher3_RPV 750",8,6.5,14.5);
  TH1D* F3_sigMC_RPV850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_RPV 850","h_njets_pt30_1l_g1b_mbl_fisher3_RPV 850",8,6.5,14.5);
  TH1D* F3_data_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodata","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodata",8,6.5,14.5);
  TH1D* F3_dataS_SYY350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 350","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 350",8,6.5,14.5);
  TH1D* F3_dataS_SYY450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 450","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 450",8,6.5,14.5);
  TH1D* F3_dataS_SYY550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 550","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 550",8,6.5,14.5);
  TH1D* F3_dataS_SYY650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 650","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 650",8,6.5,14.5);
  TH1D* F3_dataS_SYY750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 750","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 750",8,6.5,14.5);
  TH1D* F3_dataS_SYY850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 850","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_SYY 850",8,6.5,14.5);
  TH1D* F3_dataS_RPV350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 350","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 350",8,6.5,14.5);
  TH1D* F3_dataS_RPV450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 450","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 450",8,6.5,14.5);
  TH1D* F3_dataS_RPV550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 550","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 550",8,6.5,14.5);
  TH1D* F3_dataS_RPV650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 650","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 650",8,6.5,14.5);
  TH1D* F3_dataS_RPV750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 750","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 750",8,6.5,14.5);
  TH1D* F3_dataS_RPV850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 850","h_njets_pt30_1l_g1b_mbl_fisher3_pseudodataS_RPV 850",8,6.5,14.5);

  TH1D* F4_ttMC_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_TT","h_njets_pt30_1l_g1b_mbl_fisher4_TT",8,6.5,14.5);
  TH1D* F4_otherMC_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_other","h_njets_pt30_1l_g1b_mbl_fisher4_other",8,6.5,14.5);
  TH1D* F4_sigMC_SYY350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_SYY 350","h_njets_pt30_1l_g1b_mbl_fisher4_SYY 350",8,6.5,14.5);
  TH1D* F4_sigMC_SYY450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_SYY 450","h_njets_pt30_1l_g1b_mbl_fisher4_SYY 450",8,6.5,14.5);
  TH1D* F4_sigMC_SYY550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_SYY 550","h_njets_pt30_1l_g1b_mbl_fisher4_SYY 550",8,6.5,14.5);
  TH1D* F4_sigMC_SYY650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_SYY 650","h_njets_pt30_1l_g1b_mbl_fisher4_SYY 650",8,6.5,14.5);
  TH1D* F4_sigMC_SYY750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_SYY 750","h_njets_pt30_1l_g1b_mbl_fisher4_SYY 750",8,6.5,14.5);
  TH1D* F4_sigMC_SYY850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_SYY 850","h_njets_pt30_1l_g1b_mbl_fisher4_SYY 850",8,6.5,14.5);
  TH1D* F4_sigMC_RPV350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 350","h_njets_pt30_1l_g1b_mbl_fisher4_RPV 350",8,6.5,14.5);
  TH1D* F4_sigMC_RPV450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 450","h_njets_pt30_1l_g1b_mbl_fisher4_RPV 450",8,6.5,14.5);
  TH1D* F4_sigMC_RPV550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 550","h_njets_pt30_1l_g1b_mbl_fisher4_RPV 550",8,6.5,14.5);
  TH1D* F4_sigMC_RPV650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 650","h_njets_pt30_1l_g1b_mbl_fisher4_RPV 650",8,6.5,14.5);
  TH1D* F4_sigMC_RPV750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 750","h_njets_pt30_1l_g1b_mbl_fisher4_RPV 750",8,6.5,14.5);
  TH1D* F4_sigMC_RPV850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_RPV 850","h_njets_pt30_1l_g1b_mbl_fisher4_RPV 850",8,6.5,14.5);
  TH1D* F4_data_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodata","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodata",8,6.5,14.5);
  TH1D* F4_dataS_SYY350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 350","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 350",8,6.5,14.5);
  TH1D* F4_dataS_SYY450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 450","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 450",8,6.5,14.5);
  TH1D* F4_dataS_SYY550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 550","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 550",8,6.5,14.5);
  TH1D* F4_dataS_SYY650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 650","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 650",8,6.5,14.5);
  TH1D* F4_dataS_SYY750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 750","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 750",8,6.5,14.5);
  TH1D* F4_dataS_SYY850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 850","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_SYY 850",8,6.5,14.5);
  TH1D* F4_dataS_RPV350_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 350","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 350",8,6.5,14.5);
  TH1D* F4_dataS_RPV450_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 450","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 450",8,6.5,14.5);
  TH1D* F4_dataS_RPV550_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 550","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 550",8,6.5,14.5);
  TH1D* F4_dataS_RPV650_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 650","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 650",8,6.5,14.5);
  TH1D* F4_dataS_RPV750_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 750","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 750",8,6.5,14.5);
  TH1D* F4_dataS_RPV850_new = new TH1D("h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 850","h_njets_pt30_1l_g1b_mbl_fisher4_pseudodataS_RPV 850",8,6.5,14.5);

  double F1_ttMC_norm = 0;
  double F1_otherMC_norm = 0;
  double F1_sigMC_SYY350_norm = 0;
  double F1_sigMC_SYY450_norm = 0;
  double F1_sigMC_SYY550_norm = 0;
  double F1_sigMC_SYY650_norm = 0;
  double F1_sigMC_SYY750_norm = 0;
  double F1_sigMC_SYY850_norm = 0;
  double F1_sigMC_RPV350_norm = 0;
  double F1_sigMC_RPV450_norm = 0;
  double F1_sigMC_RPV550_norm = 0;
  double F1_sigMC_RPV650_norm = 0;
  double F1_sigMC_RPV750_norm = 0;
  double F1_sigMC_RPV850_norm = 0;
  double F1_data_norm = 0;
  double F1_dataS_SYY350_norm = 0;
  double F1_dataS_SYY450_norm = 0;
  double F1_dataS_SYY550_norm = 0;
  double F1_dataS_SYY650_norm = 0;
  double F1_dataS_SYY750_norm = 0;
  double F1_dataS_SYY850_norm = 0;
  double F1_dataS_RPV350_norm = 0;
  double F1_dataS_RPV450_norm = 0;
  double F1_dataS_RPV550_norm = 0;
  double F1_dataS_RPV650_norm = 0;
  double F1_dataS_RPV750_norm = 0;
  double F1_dataS_RPV850_norm = 0;

  double F2_ttMC_norm = 0;
  double F2_otherMC_norm = 0;
  double F2_sigMC_SYY350_norm = 0;
  double F2_sigMC_SYY450_norm = 0;
  double F2_sigMC_SYY550_norm = 0;
  double F2_sigMC_SYY650_norm = 0;
  double F2_sigMC_SYY750_norm = 0;
  double F2_sigMC_SYY850_norm = 0;
  double F2_sigMC_RPV350_norm = 0;
  double F2_sigMC_RPV450_norm = 0;
  double F2_sigMC_RPV550_norm = 0;
  double F2_sigMC_RPV650_norm = 0;
  double F2_sigMC_RPV750_norm = 0;
  double F2_sigMC_RPV850_norm = 0;
  double F2_data_norm = 0;
  double F2_dataS_SYY350_norm = 0;
  double F2_dataS_SYY450_norm = 0;
  double F2_dataS_SYY550_norm = 0;
  double F2_dataS_SYY650_norm = 0;
  double F2_dataS_SYY750_norm = 0;
  double F2_dataS_SYY850_norm = 0;
  double F2_dataS_RPV350_norm = 0;
  double F2_dataS_RPV450_norm = 0;
  double F2_dataS_RPV550_norm = 0;
  double F2_dataS_RPV650_norm = 0;
  double F2_dataS_RPV750_norm = 0;
  double F2_dataS_RPV850_norm = 0;

  double F3_ttMC_norm = 0;
  double F3_otherMC_norm = 0;
  double F3_sigMC_SYY350_norm = 0;
  double F3_sigMC_SYY450_norm = 0;
  double F3_sigMC_SYY550_norm = 0;
  double F3_sigMC_SYY650_norm = 0;
  double F3_sigMC_SYY750_norm = 0;
  double F3_sigMC_SYY850_norm = 0;
  double F3_sigMC_RPV350_norm = 0;
  double F3_sigMC_RPV450_norm = 0;
  double F3_sigMC_RPV550_norm = 0;
  double F3_sigMC_RPV650_norm = 0;
  double F3_sigMC_RPV750_norm = 0;
  double F3_sigMC_RPV850_norm = 0;
  double F3_data_norm = 0;
  double F3_dataS_SYY350_norm = 0;
  double F3_dataS_SYY450_norm = 0;
  double F3_dataS_SYY550_norm = 0;
  double F3_dataS_SYY650_norm = 0;
  double F3_dataS_SYY750_norm = 0;
  double F3_dataS_SYY850_norm = 0;
  double F3_dataS_RPV350_norm = 0;
  double F3_dataS_RPV450_norm = 0;
  double F3_dataS_RPV550_norm = 0;
  double F3_dataS_RPV650_norm = 0;
  double F3_dataS_RPV750_norm = 0;
  double F3_dataS_RPV850_norm = 0;

  double F4_ttMC_norm = 0;
  double F4_otherMC_norm = 0;
  double F4_sigMC_SYY350_norm = 0;
  double F4_sigMC_SYY450_norm = 0;
  double F4_sigMC_SYY550_norm = 0;
  double F4_sigMC_SYY650_norm = 0;
  double F4_sigMC_SYY750_norm = 0;
  double F4_sigMC_SYY850_norm = 0;
  double F4_sigMC_RPV350_norm = 0;
  double F4_sigMC_RPV450_norm = 0;
  double F4_sigMC_RPV550_norm = 0;
  double F4_sigMC_RPV650_norm = 0;
  double F4_sigMC_RPV750_norm = 0;
  double F4_sigMC_RPV850_norm = 0;
  double F4_data_norm = 0;
  double F4_dataS_SYY350_norm = 0;
  double F4_dataS_SYY450_norm = 0;
  double F4_dataS_SYY550_norm = 0;
  double F4_dataS_SYY650_norm = 0;
  double F4_dataS_SYY750_norm = 0;
  double F4_dataS_SYY850_norm = 0;
  double F4_dataS_RPV350_norm = 0;
  double F4_dataS_RPV450_norm = 0;
  double F4_dataS_RPV550_norm = 0;
  double F4_dataS_RPV650_norm = 0;
  double F4_dataS_RPV750_norm = 0;
  double F4_dataS_RPV850_norm = 0;

  for (int i=1; i<9; i++) {
    F1_ttMC_new->SetBinContent(i,ttMC_th1_F1->GetBinContent(i+1));
    F1_ttMC_new->SetBinError(i,ttMC_th1_F1->GetBinError(i+1));
    F1_ttMC_norm+=F1_ttMC_new->GetBinContent(i);

    F1_otherMC_new->SetBinContent(i,otherMC_th1_F1->GetBinContent(i+1));
    F1_otherMC_new->SetBinError(i,otherMC_th1_F1->GetBinError(i+1));
    F1_otherMC_norm+=F1_otherMC_new->GetBinContent(i);

    F1_sigMC_SYY350_new->SetBinContent(i,sigMC_SYY350_th1_F1->GetBinContent(i+1));
    F1_sigMC_SYY350_new->SetBinError(i,sigMC_SYY350_th1_F1->GetBinError(i+1));
    F1_sigMC_SYY350_norm+=F1_sigMC_SYY350_new->GetBinContent(i);

    F1_sigMC_SYY450_new->SetBinContent(i,sigMC_SYY450_th1_F1->GetBinContent(i+1));
    F1_sigMC_SYY450_new->SetBinError(i,sigMC_SYY450_th1_F1->GetBinError(i+1));
    F1_sigMC_SYY450_norm+=F1_sigMC_SYY450_new->GetBinContent(i);

    F1_sigMC_SYY550_new->SetBinContent(i,sigMC_SYY550_th1_F1->GetBinContent(i+1));
    F1_sigMC_SYY550_new->SetBinError(i,sigMC_SYY550_th1_F1->GetBinError(i+1));
    F1_sigMC_SYY550_norm+=F1_sigMC_SYY550_new->GetBinContent(i);

    F1_sigMC_SYY650_new->SetBinContent(i,sigMC_SYY650_th1_F1->GetBinContent(i+1));
    F1_sigMC_SYY650_new->SetBinError(i,sigMC_SYY650_th1_F1->GetBinError(i+1));
    F1_sigMC_SYY650_norm+=F1_sigMC_SYY650_new->GetBinContent(i);

    F1_sigMC_SYY750_new->SetBinContent(i,sigMC_SYY750_th1_F1->GetBinContent(i+1));
    F1_sigMC_SYY750_new->SetBinError(i,sigMC_SYY750_th1_F1->GetBinError(i+1));
    F1_sigMC_SYY750_norm+=F1_sigMC_SYY750_new->GetBinContent(i);

    F1_sigMC_SYY850_new->SetBinContent(i,sigMC_SYY850_th1_F1->GetBinContent(i+1));
    F1_sigMC_SYY850_new->SetBinError(i,sigMC_SYY850_th1_F1->GetBinError(i+1));
    F1_sigMC_SYY850_norm+=F1_sigMC_SYY850_new->GetBinContent(i);

    F1_sigMC_RPV350_new->SetBinContent(i,sigMC_RPV350_th1_F1->GetBinContent(i+1));
    F1_sigMC_RPV350_new->SetBinError(i,sigMC_RPV350_th1_F1->GetBinError(i+1));
    F1_sigMC_RPV350_norm+=F1_sigMC_RPV350_new->GetBinContent(i);

    F1_sigMC_RPV450_new->SetBinContent(i,sigMC_RPV450_th1_F1->GetBinContent(i+1));
    F1_sigMC_RPV450_new->SetBinError(i,sigMC_RPV450_th1_F1->GetBinError(i+1));
    F1_sigMC_RPV450_norm+=F1_sigMC_RPV450_new->GetBinContent(i);

    F1_sigMC_RPV550_new->SetBinContent(i,sigMC_RPV550_th1_F1->GetBinContent(i+1));
    F1_sigMC_RPV550_new->SetBinError(i,sigMC_RPV550_th1_F1->GetBinError(i+1));
    F1_sigMC_RPV550_norm+=F1_sigMC_RPV550_new->GetBinContent(i);

    F1_sigMC_RPV650_new->SetBinContent(i,sigMC_RPV650_th1_F1->GetBinContent(i+1));
    F1_sigMC_RPV650_new->SetBinError(i,sigMC_RPV650_th1_F1->GetBinError(i+1));
    F1_sigMC_RPV650_norm+=F1_sigMC_RPV650_new->GetBinContent(i);

    F1_sigMC_RPV750_new->SetBinContent(i,sigMC_RPV750_th1_F1->GetBinContent(i+1));
    F1_sigMC_RPV750_new->SetBinError(i,sigMC_RPV750_th1_F1->GetBinError(i+1));
    F1_sigMC_RPV750_norm+=F1_sigMC_RPV750_new->GetBinContent(i);

    F1_sigMC_RPV850_new->SetBinContent(i,sigMC_RPV850_th1_F1->GetBinContent(i+1));
    F1_sigMC_RPV850_new->SetBinError(i,sigMC_RPV850_th1_F1->GetBinError(i+1));
    F1_sigMC_RPV850_norm+=F1_sigMC_RPV850_new->GetBinContent(i);

    F1_data_new->SetBinContent(i,data_th1_F1->GetBinContent(i+1));
    F1_data_new->SetBinError(i,data_th1_F1->GetBinError(i+1));
    F1_data_norm+=F1_data_new->GetBinContent(i);

    F1_dataS_SYY350_new->SetBinContent(i,dataS_SYY350_th1_F1->GetBinContent(i+1));
    F1_dataS_SYY350_new->SetBinError(i,dataS_SYY350_th1_F1->GetBinError(i+1));
    F1_dataS_SYY350_norm+=F1_dataS_SYY350_new->GetBinContent(i);

    F1_dataS_SYY450_new->SetBinContent(i,dataS_SYY450_th1_F1->GetBinContent(i+1));
    F1_dataS_SYY450_new->SetBinError(i,dataS_SYY450_th1_F1->GetBinError(i+1));
    F1_dataS_SYY450_norm+=F1_dataS_SYY450_new->GetBinContent(i);

    F1_dataS_SYY550_new->SetBinContent(i,dataS_SYY550_th1_F1->GetBinContent(i+1));
    F1_dataS_SYY550_new->SetBinError(i,dataS_SYY550_th1_F1->GetBinError(i+1));
    F1_dataS_SYY550_norm+=F1_dataS_SYY550_new->GetBinContent(i);

    F1_dataS_SYY650_new->SetBinContent(i,dataS_SYY650_th1_F1->GetBinContent(i+1));
    F1_dataS_SYY650_new->SetBinError(i,dataS_SYY650_th1_F1->GetBinError(i+1));
    F1_dataS_SYY650_norm+=F1_dataS_SYY650_new->GetBinContent(i);

    F1_dataS_SYY750_new->SetBinContent(i,dataS_SYY750_th1_F1->GetBinContent(i+1));
    F1_dataS_SYY750_new->SetBinError(i,dataS_SYY750_th1_F1->GetBinError(i+1));
    F1_dataS_SYY750_norm+=F1_dataS_SYY750_new->GetBinContent(i);

    F1_dataS_SYY850_new->SetBinContent(i,dataS_SYY850_th1_F1->GetBinContent(i+1));
    F1_dataS_SYY850_new->SetBinError(i,dataS_SYY850_th1_F1->GetBinError(i+1));
    F1_dataS_SYY850_norm+=F1_dataS_SYY850_new->GetBinContent(i);

    F1_dataS_RPV350_new->SetBinContent(i,dataS_RPV350_th1_F1->GetBinContent(i+1));
    F1_dataS_RPV350_new->SetBinError(i,dataS_RPV350_th1_F1->GetBinError(i+1));
    F1_dataS_RPV350_norm+=F1_dataS_RPV350_new->GetBinContent(i);

    F1_dataS_RPV450_new->SetBinContent(i,dataS_RPV450_th1_F1->GetBinContent(i+1));
    F1_dataS_RPV450_new->SetBinError(i,dataS_RPV450_th1_F1->GetBinError(i+1));
    F1_dataS_RPV450_norm+=F1_dataS_RPV450_new->GetBinContent(i);

    F1_dataS_RPV550_new->SetBinContent(i,dataS_RPV550_th1_F1->GetBinContent(i+1));
    F1_dataS_RPV550_new->SetBinError(i,dataS_RPV550_th1_F1->GetBinError(i+1));
    F1_dataS_RPV550_norm+=F1_dataS_RPV550_new->GetBinContent(i);

    F1_dataS_RPV650_new->SetBinContent(i,dataS_RPV650_th1_F1->GetBinContent(i+1));
    F1_dataS_RPV650_new->SetBinError(i,dataS_RPV650_th1_F1->GetBinError(i+1));
    F1_dataS_RPV650_norm+=F1_dataS_RPV650_new->GetBinContent(i);

    F1_dataS_RPV750_new->SetBinContent(i,dataS_RPV750_th1_F1->GetBinContent(i+1));
    F1_dataS_RPV750_new->SetBinError(i,dataS_RPV750_th1_F1->GetBinError(i+1));
    F1_dataS_RPV750_norm+=F1_dataS_RPV750_new->GetBinContent(i);

    F1_dataS_RPV850_new->SetBinContent(i,dataS_RPV850_th1_F1->GetBinContent(i+1));
    F1_dataS_RPV850_new->SetBinError(i,dataS_RPV850_th1_F1->GetBinError(i+1));
    F1_dataS_RPV850_norm+=F1_dataS_RPV850_new->GetBinContent(i);







    F2_ttMC_new->SetBinContent(i,ttMC_th1_F2->GetBinContent(i+1));
    F2_ttMC_new->SetBinError(i,ttMC_th1_F2->GetBinError(i+1));
    F2_ttMC_norm+=F2_ttMC_new->GetBinContent(i);

    F2_otherMC_new->SetBinContent(i,otherMC_th1_F2->GetBinContent(i+1));
    F2_otherMC_new->SetBinError(i,otherMC_th1_F2->GetBinError(i+1));
    F2_otherMC_norm+=F2_otherMC_new->GetBinContent(i);

    F2_sigMC_SYY350_new->SetBinContent(i,sigMC_SYY350_th1_F2->GetBinContent(i+1));
    F2_sigMC_SYY350_new->SetBinError(i,sigMC_SYY350_th1_F2->GetBinError(i+1));
    F2_sigMC_SYY350_norm+=F2_sigMC_SYY350_new->GetBinContent(i);

    F2_sigMC_SYY450_new->SetBinContent(i,sigMC_SYY450_th1_F2->GetBinContent(i+1));
    F2_sigMC_SYY450_new->SetBinError(i,sigMC_SYY450_th1_F2->GetBinError(i+1));
    F2_sigMC_SYY450_norm+=F2_sigMC_SYY450_new->GetBinContent(i);

    F2_sigMC_SYY550_new->SetBinContent(i,sigMC_SYY550_th1_F2->GetBinContent(i+1));
    F2_sigMC_SYY550_new->SetBinError(i,sigMC_SYY550_th1_F2->GetBinError(i+1));
    F2_sigMC_SYY550_norm+=F2_sigMC_SYY550_new->GetBinContent(i);

    F2_sigMC_SYY650_new->SetBinContent(i,sigMC_SYY650_th1_F2->GetBinContent(i+1));
    F2_sigMC_SYY650_new->SetBinError(i,sigMC_SYY650_th1_F2->GetBinError(i+1));
    F2_sigMC_SYY650_norm+=F2_sigMC_SYY650_new->GetBinContent(i);

    F2_sigMC_SYY750_new->SetBinContent(i,sigMC_SYY750_th1_F2->GetBinContent(i+1));
    F2_sigMC_SYY750_new->SetBinError(i,sigMC_SYY750_th1_F2->GetBinError(i+1));
    F2_sigMC_SYY750_norm+=F2_sigMC_SYY750_new->GetBinContent(i);

    F2_sigMC_SYY850_new->SetBinContent(i,sigMC_SYY850_th1_F2->GetBinContent(i+1));
    F2_sigMC_SYY850_new->SetBinError(i,sigMC_SYY850_th1_F2->GetBinError(i+1));
    F2_sigMC_SYY850_norm+=F2_sigMC_SYY850_new->GetBinContent(i);

    F2_sigMC_RPV350_new->SetBinContent(i,sigMC_RPV350_th1_F2->GetBinContent(i+1));
    F2_sigMC_RPV350_new->SetBinError(i,sigMC_RPV350_th1_F2->GetBinError(i+1));
    F2_sigMC_RPV350_norm+=F2_sigMC_RPV350_new->GetBinContent(i);

    F2_sigMC_RPV450_new->SetBinContent(i,sigMC_RPV450_th1_F2->GetBinContent(i+1));
    F2_sigMC_RPV450_new->SetBinError(i,sigMC_RPV450_th1_F2->GetBinError(i+1));
    F2_sigMC_RPV450_norm+=F2_sigMC_RPV450_new->GetBinContent(i);

    F2_sigMC_RPV550_new->SetBinContent(i,sigMC_RPV550_th1_F2->GetBinContent(i+1));
    F2_sigMC_RPV550_new->SetBinError(i,sigMC_RPV550_th1_F2->GetBinError(i+1));
    F2_sigMC_RPV550_norm+=F2_sigMC_RPV550_new->GetBinContent(i);

    F2_sigMC_RPV650_new->SetBinContent(i,sigMC_RPV650_th1_F2->GetBinContent(i+1));
    F2_sigMC_RPV650_new->SetBinError(i,sigMC_RPV650_th1_F2->GetBinError(i+1));
    F2_sigMC_RPV650_norm+=F2_sigMC_RPV650_new->GetBinContent(i);

    F2_sigMC_RPV750_new->SetBinContent(i,sigMC_RPV750_th1_F2->GetBinContent(i+1));
    F2_sigMC_RPV750_new->SetBinError(i,sigMC_RPV750_th1_F2->GetBinError(i+1));
    F2_sigMC_RPV750_norm+=F2_sigMC_RPV750_new->GetBinContent(i);

    F2_sigMC_RPV850_new->SetBinContent(i,sigMC_RPV850_th1_F2->GetBinContent(i+1));
    F2_sigMC_RPV850_new->SetBinError(i,sigMC_RPV850_th1_F2->GetBinError(i+1));
    F2_sigMC_RPV850_norm+=F2_sigMC_RPV850_new->GetBinContent(i);

    F2_data_new->SetBinContent(i,data_th1_F2->GetBinContent(i+1));
    F2_data_new->SetBinError(i,data_th1_F2->GetBinError(i+1));
    F2_data_norm+=F2_data_new->GetBinContent(i);

    F2_dataS_SYY350_new->SetBinContent(i,dataS_SYY350_th1_F2->GetBinContent(i+1));
    F2_dataS_SYY350_new->SetBinError(i,dataS_SYY350_th1_F2->GetBinError(i+1));
    F2_dataS_SYY350_norm+=F2_dataS_SYY350_new->GetBinContent(i);

    F2_dataS_SYY450_new->SetBinContent(i,dataS_SYY450_th1_F2->GetBinContent(i+1));
    F2_dataS_SYY450_new->SetBinError(i,dataS_SYY450_th1_F2->GetBinError(i+1));
    F2_dataS_SYY450_norm+=F2_dataS_SYY450_new->GetBinContent(i);

    F2_dataS_SYY550_new->SetBinContent(i,dataS_SYY550_th1_F2->GetBinContent(i+1));
    F2_dataS_SYY550_new->SetBinError(i,dataS_SYY550_th1_F2->GetBinError(i+1));
    F2_dataS_SYY550_norm+=F2_dataS_SYY550_new->GetBinContent(i);

    F2_dataS_SYY650_new->SetBinContent(i,dataS_SYY650_th1_F2->GetBinContent(i+1));
    F2_dataS_SYY650_new->SetBinError(i,dataS_SYY650_th1_F2->GetBinError(i+1));
    F2_dataS_SYY650_norm+=F2_dataS_SYY650_new->GetBinContent(i);

    F2_dataS_SYY750_new->SetBinContent(i,dataS_SYY750_th1_F2->GetBinContent(i+1));
    F2_dataS_SYY750_new->SetBinError(i,dataS_SYY750_th1_F2->GetBinError(i+1));
    F2_dataS_SYY750_norm+=F2_dataS_SYY750_new->GetBinContent(i);

    F2_dataS_SYY850_new->SetBinContent(i,dataS_SYY850_th1_F2->GetBinContent(i+1));
    F2_dataS_SYY850_new->SetBinError(i,dataS_SYY850_th1_F2->GetBinError(i+1));
    F2_dataS_SYY850_norm+=F2_dataS_SYY850_new->GetBinContent(i);

    F2_dataS_RPV350_new->SetBinContent(i,dataS_RPV350_th1_F2->GetBinContent(i+1));
    F2_dataS_RPV350_new->SetBinError(i,dataS_RPV350_th1_F2->GetBinError(i+1));
    F2_dataS_RPV350_norm+=F2_dataS_RPV350_new->GetBinContent(i);

    F2_dataS_RPV450_new->SetBinContent(i,dataS_RPV450_th1_F2->GetBinContent(i+1));
    F2_dataS_RPV450_new->SetBinError(i,dataS_RPV450_th1_F2->GetBinError(i+1));
    F2_dataS_RPV450_norm+=F2_dataS_RPV450_new->GetBinContent(i);

    F2_dataS_RPV550_new->SetBinContent(i,dataS_RPV550_th1_F2->GetBinContent(i+1));
    F2_dataS_RPV550_new->SetBinError(i,dataS_RPV550_th1_F2->GetBinError(i+1));
    F2_dataS_RPV550_norm+=F2_dataS_RPV550_new->GetBinContent(i);

    F2_dataS_RPV650_new->SetBinContent(i,dataS_RPV650_th1_F2->GetBinContent(i+1));
    F2_dataS_RPV650_new->SetBinError(i,dataS_RPV650_th1_F2->GetBinError(i+1));
    F2_dataS_RPV650_norm+=F2_dataS_RPV650_new->GetBinContent(i);

    F2_dataS_RPV750_new->SetBinContent(i,dataS_RPV750_th1_F2->GetBinContent(i+1));
    F2_dataS_RPV750_new->SetBinError(i,dataS_RPV750_th1_F2->GetBinError(i+1));
    F2_dataS_RPV750_norm+=F2_dataS_RPV750_new->GetBinContent(i);

    F2_dataS_RPV850_new->SetBinContent(i,dataS_RPV850_th1_F2->GetBinContent(i+1));
    F2_dataS_RPV850_new->SetBinError(i,dataS_RPV850_th1_F2->GetBinError(i+1));
    F2_dataS_RPV850_norm+=F2_dataS_RPV850_new->GetBinContent(i);






    F3_ttMC_new->SetBinContent(i,ttMC_th1_F3->GetBinContent(i+1));
    F3_ttMC_new->SetBinError(i,ttMC_th1_F3->GetBinError(i+1));
    F3_ttMC_norm+=F3_ttMC_new->GetBinContent(i);

    F3_otherMC_new->SetBinContent(i,otherMC_th1_F3->GetBinContent(i+1));
    F3_otherMC_new->SetBinError(i,otherMC_th1_F3->GetBinError(i+1));
    F3_otherMC_norm+=F3_otherMC_new->GetBinContent(i);

    F3_sigMC_SYY350_new->SetBinContent(i,sigMC_SYY350_th1_F3->GetBinContent(i+1));
    F3_sigMC_SYY350_new->SetBinError(i,sigMC_SYY350_th1_F3->GetBinError(i+1));
    F3_sigMC_SYY350_norm+=F3_sigMC_SYY350_new->GetBinContent(i);

    F3_sigMC_SYY450_new->SetBinContent(i,sigMC_SYY450_th1_F3->GetBinContent(i+1));
    F3_sigMC_SYY450_new->SetBinError(i,sigMC_SYY450_th1_F3->GetBinError(i+1));
    F3_sigMC_SYY450_norm+=F3_sigMC_SYY450_new->GetBinContent(i);

    F3_sigMC_SYY550_new->SetBinContent(i,sigMC_SYY550_th1_F3->GetBinContent(i+1));
    F3_sigMC_SYY550_new->SetBinError(i,sigMC_SYY550_th1_F3->GetBinError(i+1));
    F3_sigMC_SYY550_norm+=F3_sigMC_SYY550_new->GetBinContent(i);

    F3_sigMC_SYY650_new->SetBinContent(i,sigMC_SYY650_th1_F3->GetBinContent(i+1));
    F3_sigMC_SYY650_new->SetBinError(i,sigMC_SYY650_th1_F3->GetBinError(i+1));
    F3_sigMC_SYY650_norm+=F3_sigMC_SYY650_new->GetBinContent(i);

    F3_sigMC_SYY750_new->SetBinContent(i,sigMC_SYY750_th1_F3->GetBinContent(i+1));
    F3_sigMC_SYY750_new->SetBinError(i,sigMC_SYY750_th1_F3->GetBinError(i+1));
    F3_sigMC_SYY750_norm+=F3_sigMC_SYY750_new->GetBinContent(i);

    F3_sigMC_SYY850_new->SetBinContent(i,sigMC_SYY850_th1_F3->GetBinContent(i+1));
    F3_sigMC_SYY850_new->SetBinError(i,sigMC_SYY850_th1_F3->GetBinError(i+1));
    F3_sigMC_SYY850_norm+=F3_sigMC_SYY850_new->GetBinContent(i);

    F3_sigMC_RPV350_new->SetBinContent(i,sigMC_RPV350_th1_F3->GetBinContent(i+1));
    F3_sigMC_RPV350_new->SetBinError(i,sigMC_RPV350_th1_F3->GetBinError(i+1));
    F3_sigMC_RPV350_norm+=F3_sigMC_RPV350_new->GetBinContent(i);

    F3_sigMC_RPV450_new->SetBinContent(i,sigMC_RPV450_th1_F3->GetBinContent(i+1));
    F3_sigMC_RPV450_new->SetBinError(i,sigMC_RPV450_th1_F3->GetBinError(i+1));
    F3_sigMC_RPV450_norm+=F3_sigMC_RPV450_new->GetBinContent(i);

    F3_sigMC_RPV550_new->SetBinContent(i,sigMC_RPV550_th1_F3->GetBinContent(i+1));
    F3_sigMC_RPV550_new->SetBinError(i,sigMC_RPV550_th1_F3->GetBinError(i+1));
    F3_sigMC_RPV550_norm+=F3_sigMC_RPV550_new->GetBinContent(i);

    F3_sigMC_RPV650_new->SetBinContent(i,sigMC_RPV650_th1_F3->GetBinContent(i+1));
    F3_sigMC_RPV650_new->SetBinError(i,sigMC_RPV650_th1_F3->GetBinError(i+1));
    F3_sigMC_RPV650_norm+=F3_sigMC_RPV650_new->GetBinContent(i);

    F3_sigMC_RPV750_new->SetBinContent(i,sigMC_RPV750_th1_F3->GetBinContent(i+1));
    F3_sigMC_RPV750_new->SetBinError(i,sigMC_RPV750_th1_F3->GetBinError(i+1));
    F3_sigMC_RPV750_norm+=F3_sigMC_RPV750_new->GetBinContent(i);

    F3_sigMC_RPV850_new->SetBinContent(i,sigMC_RPV850_th1_F3->GetBinContent(i+1));
    F3_sigMC_RPV850_new->SetBinError(i,sigMC_RPV850_th1_F3->GetBinError(i+1));
    F3_sigMC_RPV850_norm+=F3_sigMC_RPV850_new->GetBinContent(i);

    F3_data_new->SetBinContent(i,data_th1_F3->GetBinContent(i+1));
    F3_data_new->SetBinError(i,data_th1_F3->GetBinError(i+1));
    F3_data_norm+=F3_data_new->GetBinContent(i);

    F3_dataS_SYY350_new->SetBinContent(i,dataS_SYY350_th1_F3->GetBinContent(i+1));
    F3_dataS_SYY350_new->SetBinError(i,dataS_SYY350_th1_F3->GetBinError(i+1));
    F3_dataS_SYY350_norm+=F3_dataS_SYY350_new->GetBinContent(i);

    F3_dataS_SYY450_new->SetBinContent(i,dataS_SYY450_th1_F3->GetBinContent(i+1));
    F3_dataS_SYY450_new->SetBinError(i,dataS_SYY450_th1_F3->GetBinError(i+1));
    F3_dataS_SYY450_norm+=F3_dataS_SYY450_new->GetBinContent(i);

    F3_dataS_SYY550_new->SetBinContent(i,dataS_SYY550_th1_F3->GetBinContent(i+1));
    F3_dataS_SYY550_new->SetBinError(i,dataS_SYY550_th1_F3->GetBinError(i+1));
    F3_dataS_SYY550_norm+=F3_dataS_SYY550_new->GetBinContent(i);

    F3_dataS_SYY650_new->SetBinContent(i,dataS_SYY650_th1_F3->GetBinContent(i+1));
    F3_dataS_SYY650_new->SetBinError(i,dataS_SYY650_th1_F3->GetBinError(i+1));
    F3_dataS_SYY650_norm+=F3_dataS_SYY650_new->GetBinContent(i);

    F3_dataS_SYY750_new->SetBinContent(i,dataS_SYY750_th1_F3->GetBinContent(i+1));
    F3_dataS_SYY750_new->SetBinError(i,dataS_SYY750_th1_F3->GetBinError(i+1));
    F3_dataS_SYY750_norm+=F3_dataS_SYY750_new->GetBinContent(i);

    F3_dataS_SYY850_new->SetBinContent(i,dataS_SYY850_th1_F3->GetBinContent(i+1));
    F3_dataS_SYY850_new->SetBinError(i,dataS_SYY850_th1_F3->GetBinError(i+1));
    F3_dataS_SYY850_norm+=F3_dataS_SYY850_new->GetBinContent(i);

    F3_dataS_RPV350_new->SetBinContent(i,dataS_RPV350_th1_F3->GetBinContent(i+1));
    F3_dataS_RPV350_new->SetBinError(i,dataS_RPV350_th1_F3->GetBinError(i+1));
    F3_dataS_RPV350_norm+=F3_dataS_RPV350_new->GetBinContent(i);

    F3_dataS_RPV450_new->SetBinContent(i,dataS_RPV450_th1_F3->GetBinContent(i+1));
    F3_dataS_RPV450_new->SetBinError(i,dataS_RPV450_th1_F3->GetBinError(i+1));
    F3_dataS_RPV450_norm+=F3_dataS_RPV450_new->GetBinContent(i);

    F3_dataS_RPV550_new->SetBinContent(i,dataS_RPV550_th1_F3->GetBinContent(i+1));
    F3_dataS_RPV550_new->SetBinError(i,dataS_RPV550_th1_F3->GetBinError(i+1));
    F3_dataS_RPV550_norm+=F3_dataS_RPV550_new->GetBinContent(i);

    F3_dataS_RPV650_new->SetBinContent(i,dataS_RPV650_th1_F3->GetBinContent(i+1));
    F3_dataS_RPV650_new->SetBinError(i,dataS_RPV650_th1_F3->GetBinError(i+1));
    F3_dataS_RPV650_norm+=F3_dataS_RPV650_new->GetBinContent(i);

    F3_dataS_RPV750_new->SetBinContent(i,dataS_RPV750_th1_F3->GetBinContent(i+1));
    F3_dataS_RPV750_new->SetBinError(i,dataS_RPV750_th1_F3->GetBinError(i+1));
    F3_dataS_RPV750_norm+=F3_dataS_RPV750_new->GetBinContent(i);

    F3_dataS_RPV850_new->SetBinContent(i,dataS_RPV850_th1_F3->GetBinContent(i+1));
    F3_dataS_RPV850_new->SetBinError(i,dataS_RPV850_th1_F3->GetBinError(i+1));
    F3_dataS_RPV850_norm+=F3_dataS_RPV850_new->GetBinContent(i);






    F4_ttMC_new->SetBinContent(i,ttMC_th1_F4->GetBinContent(i+1));
    F4_ttMC_new->SetBinError(i,ttMC_th1_F4->GetBinError(i+1));
    F4_ttMC_norm+=F4_ttMC_new->GetBinContent(i);

    F4_otherMC_new->SetBinContent(i,otherMC_th1_F4->GetBinContent(i+1));
    F4_otherMC_new->SetBinError(i,otherMC_th1_F4->GetBinError(i+1));
    F4_otherMC_norm+=F4_otherMC_new->GetBinContent(i);

    F4_sigMC_SYY350_new->SetBinContent(i,sigMC_SYY350_th1_F4->GetBinContent(i+1));
    F4_sigMC_SYY350_new->SetBinError(i,sigMC_SYY350_th1_F4->GetBinError(i+1));
    F4_sigMC_SYY350_norm+=F4_sigMC_SYY350_new->GetBinContent(i);

    F4_sigMC_SYY450_new->SetBinContent(i,sigMC_SYY450_th1_F4->GetBinContent(i+1));
    F4_sigMC_SYY450_new->SetBinError(i,sigMC_SYY450_th1_F4->GetBinError(i+1));
    F4_sigMC_SYY450_norm+=F4_sigMC_SYY450_new->GetBinContent(i);

    F4_sigMC_SYY550_new->SetBinContent(i,sigMC_SYY550_th1_F4->GetBinContent(i+1));
    F4_sigMC_SYY550_new->SetBinError(i,sigMC_SYY550_th1_F4->GetBinError(i+1));
    F4_sigMC_SYY550_norm+=F4_sigMC_SYY550_new->GetBinContent(i);

    F4_sigMC_SYY650_new->SetBinContent(i,sigMC_SYY650_th1_F4->GetBinContent(i+1));
    F4_sigMC_SYY650_new->SetBinError(i,sigMC_SYY650_th1_F4->GetBinError(i+1));
    F4_sigMC_SYY650_norm+=F4_sigMC_SYY650_new->GetBinContent(i);

    F4_sigMC_SYY750_new->SetBinContent(i,sigMC_SYY750_th1_F4->GetBinContent(i+1));
    F4_sigMC_SYY750_new->SetBinError(i,sigMC_SYY750_th1_F4->GetBinError(i+1));
    F4_sigMC_SYY750_norm+=F4_sigMC_SYY750_new->GetBinContent(i);

    F4_sigMC_SYY850_new->SetBinContent(i,sigMC_SYY850_th1_F4->GetBinContent(i+1));
    F4_sigMC_SYY850_new->SetBinError(i,sigMC_SYY850_th1_F4->GetBinError(i+1));
    F4_sigMC_SYY850_norm+=F4_sigMC_SYY850_new->GetBinContent(i);

    F4_sigMC_RPV350_new->SetBinContent(i,sigMC_RPV350_th1_F4->GetBinContent(i+1));
    F4_sigMC_RPV350_new->SetBinError(i,sigMC_RPV350_th1_F4->GetBinError(i+1));
    F4_sigMC_RPV350_norm+=F4_sigMC_RPV350_new->GetBinContent(i);

    F4_sigMC_RPV450_new->SetBinContent(i,sigMC_RPV450_th1_F4->GetBinContent(i+1));
    F4_sigMC_RPV450_new->SetBinError(i,sigMC_RPV450_th1_F4->GetBinError(i+1));
    F4_sigMC_RPV450_norm+=F4_sigMC_RPV450_new->GetBinContent(i);

    F4_sigMC_RPV550_new->SetBinContent(i,sigMC_RPV550_th1_F4->GetBinContent(i+1));
    F4_sigMC_RPV550_new->SetBinError(i,sigMC_RPV550_th1_F4->GetBinError(i+1));
    F4_sigMC_RPV550_norm+=F4_sigMC_RPV550_new->GetBinContent(i);

    F4_sigMC_RPV650_new->SetBinContent(i,sigMC_RPV650_th1_F4->GetBinContent(i+1));
    F4_sigMC_RPV650_new->SetBinError(i,sigMC_RPV650_th1_F4->GetBinError(i+1));
    F4_sigMC_RPV650_norm+=F4_sigMC_RPV650_new->GetBinContent(i);

    F4_sigMC_RPV750_new->SetBinContent(i,sigMC_RPV750_th1_F4->GetBinContent(i+1));
    F4_sigMC_RPV750_new->SetBinError(i,sigMC_RPV750_th1_F4->GetBinError(i+1));
    F4_sigMC_RPV750_norm+=F4_sigMC_RPV750_new->GetBinContent(i);

    F4_sigMC_RPV850_new->SetBinContent(i,sigMC_RPV850_th1_F4->GetBinContent(i+1));
    F4_sigMC_RPV850_new->SetBinError(i,sigMC_RPV850_th1_F4->GetBinError(i+1));
    F4_sigMC_RPV850_norm+=F4_sigMC_RPV850_new->GetBinContent(i);

    F4_data_new->SetBinContent(i,data_th1_F4->GetBinContent(i+1));
    F4_data_new->SetBinError(i,data_th1_F4->GetBinError(i+1));
    F4_data_norm+=F4_data_new->GetBinContent(i);

    F4_dataS_SYY350_new->SetBinContent(i,dataS_SYY350_th1_F4->GetBinContent(i+1));
    F4_dataS_SYY350_new->SetBinError(i,dataS_SYY350_th1_F4->GetBinError(i+1));
    F4_dataS_SYY350_norm+=F4_dataS_SYY350_new->GetBinContent(i);

    F4_dataS_SYY450_new->SetBinContent(i,dataS_SYY450_th1_F4->GetBinContent(i+1));
    F4_dataS_SYY450_new->SetBinError(i,dataS_SYY450_th1_F4->GetBinError(i+1));
    F4_dataS_SYY450_norm+=F4_dataS_SYY450_new->GetBinContent(i);

    F4_dataS_SYY550_new->SetBinContent(i,dataS_SYY550_th1_F4->GetBinContent(i+1));
    F4_dataS_SYY550_new->SetBinError(i,dataS_SYY550_th1_F4->GetBinError(i+1));
    F4_dataS_SYY550_norm+=F4_dataS_SYY550_new->GetBinContent(i);

    F4_dataS_SYY650_new->SetBinContent(i,dataS_SYY650_th1_F4->GetBinContent(i+1));
    F4_dataS_SYY650_new->SetBinError(i,dataS_SYY650_th1_F4->GetBinError(i+1));
    F4_dataS_SYY650_norm+=F4_dataS_SYY650_new->GetBinContent(i);

    F4_dataS_SYY750_new->SetBinContent(i,dataS_SYY750_th1_F4->GetBinContent(i+1));
    F4_dataS_SYY750_new->SetBinError(i,dataS_SYY750_th1_F4->GetBinError(i+1));
    F4_dataS_SYY750_norm+=F4_dataS_SYY750_new->GetBinContent(i);

    F4_dataS_SYY850_new->SetBinContent(i,dataS_SYY850_th1_F4->GetBinContent(i+1));
    F4_dataS_SYY850_new->SetBinError(i,dataS_SYY850_th1_F4->GetBinError(i+1));
    F4_dataS_SYY850_norm+=F4_dataS_SYY850_new->GetBinContent(i);

    F4_dataS_RPV350_new->SetBinContent(i,dataS_RPV350_th1_F4->GetBinContent(i+1));
    F4_dataS_RPV350_new->SetBinError(i,dataS_RPV350_th1_F4->GetBinError(i+1));
    F4_dataS_RPV350_norm+=F4_dataS_RPV350_new->GetBinContent(i);

    F4_dataS_RPV450_new->SetBinContent(i,dataS_RPV450_th1_F4->GetBinContent(i+1));
    F4_dataS_RPV450_new->SetBinError(i,dataS_RPV450_th1_F4->GetBinError(i+1));
    F4_dataS_RPV450_norm+=F4_dataS_RPV450_new->GetBinContent(i);

    F4_dataS_RPV550_new->SetBinContent(i,dataS_RPV550_th1_F4->GetBinContent(i+1));
    F4_dataS_RPV550_new->SetBinError(i,dataS_RPV550_th1_F4->GetBinError(i+1));
    F4_dataS_RPV550_norm+=F4_dataS_RPV550_new->GetBinContent(i);

    F4_dataS_RPV650_new->SetBinContent(i,dataS_RPV650_th1_F4->GetBinContent(i+1));
    F4_dataS_RPV650_new->SetBinError(i,dataS_RPV650_th1_F4->GetBinError(i+1));
    F4_dataS_RPV650_norm+=F4_dataS_RPV650_new->GetBinContent(i);

    F4_dataS_RPV750_new->SetBinContent(i,dataS_RPV750_th1_F4->GetBinContent(i+1));
    F4_dataS_RPV750_new->SetBinError(i,dataS_RPV750_th1_F4->GetBinError(i+1));
    F4_dataS_RPV750_norm+=F4_dataS_RPV750_new->GetBinContent(i);

    F4_dataS_RPV850_new->SetBinContent(i,dataS_RPV850_th1_F4->GetBinContent(i+1));
    F4_dataS_RPV850_new->SetBinError(i,dataS_RPV850_th1_F4->GetBinError(i+1));
    F4_dataS_RPV850_norm+=F4_dataS_RPV850_new->GetBinContent(i);

  }

  TFile *fOut = new TFile("njets_rebinned.root","RECREATE");
  fOut->cd();

  F1_ttMC_new->Write();
  F1_otherMC_new->Write();
  F1_sigMC_SYY350_new->Write();
  F1_sigMC_SYY450_new->Write();
  F1_sigMC_SYY550_new->Write();
  F1_sigMC_SYY650_new->Write();
  F1_sigMC_SYY750_new->Write();
  F1_sigMC_SYY850_new->Write();
  F1_sigMC_RPV350_new->Write();
  F1_sigMC_RPV450_new->Write();
  F1_sigMC_RPV550_new->Write();
  F1_sigMC_RPV650_new->Write();
  F1_sigMC_RPV750_new->Write();
  F1_sigMC_RPV850_new->Write();
  F1_data_new->Write();
  F1_dataS_SYY350_new->Write();
  F1_dataS_SYY450_new->Write();
  F1_dataS_SYY550_new->Write();
  F1_dataS_SYY650_new->Write();
  F1_dataS_SYY750_new->Write();
  F1_dataS_SYY850_new->Write();
  F1_dataS_RPV350_new->Write();
  F1_dataS_RPV450_new->Write();
  F1_dataS_RPV550_new->Write();
  F1_dataS_RPV650_new->Write();
  F1_dataS_RPV750_new->Write();
  F1_dataS_RPV850_new->Write();

  F2_ttMC_new->Write();
  F2_otherMC_new->Write();
  F2_sigMC_SYY350_new->Write();
  F2_sigMC_SYY450_new->Write();
  F2_sigMC_SYY550_new->Write();
  F2_sigMC_SYY650_new->Write();
  F2_sigMC_SYY750_new->Write();
  F2_sigMC_SYY850_new->Write();
  F2_sigMC_RPV350_new->Write();
  F2_sigMC_RPV450_new->Write();
  F2_sigMC_RPV550_new->Write();
  F2_sigMC_RPV650_new->Write();
  F2_sigMC_RPV750_new->Write();
  F2_sigMC_RPV850_new->Write();
  F2_data_new->Write();
  F2_dataS_SYY350_new->Write();
  F2_dataS_SYY450_new->Write();
  F2_dataS_SYY550_new->Write();
  F2_dataS_SYY650_new->Write();
  F2_dataS_SYY750_new->Write();
  F2_dataS_SYY850_new->Write();
  F2_dataS_RPV350_new->Write();
  F2_dataS_RPV450_new->Write();
  F2_dataS_RPV550_new->Write();
  F2_dataS_RPV650_new->Write();
  F2_dataS_RPV750_new->Write();
  F2_dataS_RPV850_new->Write();

  F3_ttMC_new->Write();
  F3_otherMC_new->Write();
  F3_sigMC_SYY350_new->Write();
  F3_sigMC_SYY450_new->Write();
  F3_sigMC_SYY550_new->Write();
  F3_sigMC_SYY650_new->Write();
  F3_sigMC_SYY750_new->Write();
  F3_sigMC_SYY850_new->Write();
  F3_sigMC_RPV350_new->Write();
  F3_sigMC_RPV450_new->Write();
  F3_sigMC_RPV550_new->Write();
  F3_sigMC_RPV650_new->Write();
  F3_sigMC_RPV750_new->Write();
  F3_sigMC_RPV850_new->Write();
  F3_data_new->Write();
  F3_dataS_SYY350_new->Write();
  F3_dataS_SYY450_new->Write();
  F3_dataS_SYY550_new->Write();
  F3_dataS_SYY650_new->Write();
  F3_dataS_SYY750_new->Write();
  F3_dataS_SYY850_new->Write();
  F3_dataS_RPV350_new->Write();
  F3_dataS_RPV450_new->Write();
  F3_dataS_RPV550_new->Write();
  F3_dataS_RPV650_new->Write();
  F3_dataS_RPV750_new->Write();
  F3_dataS_RPV850_new->Write();

  F4_ttMC_new->Write();
  F4_otherMC_new->Write();
  F4_sigMC_SYY350_new->Write();
  F4_sigMC_SYY450_new->Write();
  F4_sigMC_SYY550_new->Write();
  F4_sigMC_SYY650_new->Write();
  F4_sigMC_SYY750_new->Write();
  F4_sigMC_SYY850_new->Write();
  F4_sigMC_RPV350_new->Write();
  F4_sigMC_RPV450_new->Write();
  F4_sigMC_RPV550_new->Write();
  F4_sigMC_RPV650_new->Write();
  F4_sigMC_RPV750_new->Write();
  F4_sigMC_RPV850_new->Write();
  F4_data_new->Write();
  F4_dataS_SYY350_new->Write();
  F4_dataS_SYY450_new->Write();
  F4_dataS_SYY550_new->Write();
  F4_dataS_SYY650_new->Write();
  F4_dataS_SYY750_new->Write();
  F4_dataS_SYY850_new->Write();
  F4_dataS_RPV350_new->Write();
  F4_dataS_RPV450_new->Write();
  F4_dataS_RPV550_new->Write();
  F4_dataS_RPV650_new->Write();
  F4_dataS_RPV750_new->Write();
  F4_dataS_RPV850_new->Write();


  cout << "=== Normalizations ===" << endl;
  cout << endl;
  cout << "--- Fisher 1 ---" << endl;
  cout << "ttMC         : " << F1_ttMC_norm << endl;
  cout << "otherMC      : " << F1_otherMC_norm << endl;
  cout << "sigMC SYY350 : " << F1_sigMC_SYY350_norm << endl;
  cout << "sigMC SYY450 : " << F1_sigMC_SYY450_norm << endl;
  cout << "sigMC SYY550 : " << F1_sigMC_SYY550_norm << endl;
  cout << "sigMC SYY650 : " << F1_sigMC_SYY650_norm << endl;
  cout << "sigMC SYY750 : " << F1_sigMC_SYY750_norm << endl;
  cout << "sigMC SYY850 : " << F1_sigMC_SYY850_norm << endl;
  cout << "sigMC RPV350 : " << F1_sigMC_RPV350_norm << endl;
  cout << "sigMC RPV450 : " << F1_sigMC_RPV450_norm << endl;
  cout << "sigMC RPV550 : " << F1_sigMC_RPV550_norm << endl;
  cout << "sigMC RPV650 : " << F1_sigMC_RPV650_norm << endl;
  cout << "sigMC RPV750 : " << F1_sigMC_RPV750_norm << endl;
  cout << "sigMC RPV850 : " << F1_sigMC_RPV850_norm << endl;
  cout << "data         : " << F1_data_norm << endl;
  cout << "dataS SYY350 : " << F1_dataS_SYY350_norm << endl;
  cout << "dataS SYY450 : " << F1_dataS_SYY450_norm << endl;
  cout << "dataS SYY550 : " << F1_dataS_SYY550_norm << endl;
  cout << "dataS SYY650 : " << F1_dataS_SYY650_norm << endl;
  cout << "dataS SYY750 : " << F1_dataS_SYY750_norm << endl;
  cout << "dataS SYY850 : " << F1_dataS_SYY850_norm << endl;
  cout << "dataS RPV350 : " << F1_dataS_RPV350_norm << endl;
  cout << "dataS RPV450 : " << F1_dataS_RPV450_norm << endl;
  cout << "dataS RPV550 : " << F1_dataS_RPV550_norm << endl;
  cout << "dataS RPV650 : " << F1_dataS_RPV650_norm << endl;
  cout << "dataS RPV750 : " << F1_dataS_RPV750_norm << endl;
  cout << "dataS RPV850 : " << F1_dataS_RPV850_norm << endl;
  cout << endl;
  cout << "--- Fisher 2 ---" << endl;
  cout << "ttMC         : " << F2_ttMC_norm << endl;
  cout << "otherMC      : " << F2_otherMC_norm << endl;
  cout << "sigMC SYY350 : " << F2_sigMC_SYY350_norm << endl;
  cout << "sigMC SYY450 : " << F2_sigMC_SYY450_norm << endl;
  cout << "sigMC SYY550 : " << F2_sigMC_SYY550_norm << endl;
  cout << "sigMC SYY650 : " << F2_sigMC_SYY650_norm << endl;
  cout << "sigMC SYY750 : " << F2_sigMC_SYY750_norm << endl;
  cout << "sigMC SYY850 : " << F2_sigMC_SYY850_norm << endl;
  cout << "sigMC RPV350 : " << F2_sigMC_RPV350_norm << endl;
  cout << "sigMC RPV450 : " << F2_sigMC_RPV450_norm << endl;
  cout << "sigMC RPV550 : " << F2_sigMC_RPV550_norm << endl;
  cout << "sigMC RPV650 : " << F2_sigMC_RPV650_norm << endl;
  cout << "sigMC RPV750 : " << F2_sigMC_RPV750_norm << endl;
  cout << "sigMC RPV850 : " << F2_sigMC_RPV850_norm << endl;
  cout << "data         : " << F2_data_norm << endl;
  cout << "dataS SYY350 : " << F2_dataS_SYY350_norm << endl;
  cout << "dataS SYY450 : " << F2_dataS_SYY450_norm << endl;
  cout << "dataS SYY550 : " << F2_dataS_SYY550_norm << endl;
  cout << "dataS SYY650 : " << F2_dataS_SYY650_norm << endl;
  cout << "dataS SYY750 : " << F2_dataS_SYY750_norm << endl;
  cout << "dataS SYY850 : " << F2_dataS_SYY850_norm << endl;
  cout << "dataS RPV350 : " << F2_dataS_RPV350_norm << endl;
  cout << "dataS RPV450 : " << F2_dataS_RPV450_norm << endl;
  cout << "dataS RPV550 : " << F2_dataS_RPV550_norm << endl;
  cout << "dataS RPV650 : " << F2_dataS_RPV650_norm << endl;
  cout << "dataS RPV750 : " << F2_dataS_RPV750_norm << endl;
  cout << "dataS RPV850 : " << F2_dataS_RPV850_norm << endl;
  cout << endl;
  cout << "--- Fisher 3 ---" << endl;
  cout << "ttMC         : " << F3_ttMC_norm << endl;
  cout << "otherMC      : " << F3_otherMC_norm << endl;
  cout << "sigMC SYY350 : " << F3_sigMC_SYY350_norm << endl;
  cout << "sigMC SYY450 : " << F3_sigMC_SYY450_norm << endl;
  cout << "sigMC SYY550 : " << F3_sigMC_SYY550_norm << endl;
  cout << "sigMC SYY650 : " << F3_sigMC_SYY650_norm << endl;
  cout << "sigMC SYY750 : " << F3_sigMC_SYY750_norm << endl;
  cout << "sigMC SYY850 : " << F3_sigMC_SYY850_norm << endl;
  cout << "sigMC RPV350 : " << F3_sigMC_RPV350_norm << endl;
  cout << "sigMC RPV450 : " << F3_sigMC_RPV450_norm << endl;
  cout << "sigMC RPV550 : " << F3_sigMC_RPV550_norm << endl;
  cout << "sigMC RPV650 : " << F3_sigMC_RPV650_norm << endl;
  cout << "sigMC RPV750 : " << F3_sigMC_RPV750_norm << endl;
  cout << "sigMC RPV850 : " << F3_sigMC_RPV850_norm << endl;
  cout << "data         : " << F3_data_norm << endl;
  cout << "dataS SYY350 : " << F3_dataS_SYY350_norm << endl;
  cout << "dataS SYY450 : " << F3_dataS_SYY450_norm << endl;
  cout << "dataS SYY550 : " << F3_dataS_SYY550_norm << endl;
  cout << "dataS SYY650 : " << F3_dataS_SYY650_norm << endl;
  cout << "dataS SYY750 : " << F3_dataS_SYY750_norm << endl;
  cout << "dataS SYY850 : " << F3_dataS_SYY850_norm << endl;
  cout << "dataS RPV350 : " << F3_dataS_RPV350_norm << endl;
  cout << "dataS RPV450 : " << F3_dataS_RPV450_norm << endl;
  cout << "dataS RPV550 : " << F3_dataS_RPV550_norm << endl;
  cout << "dataS RPV650 : " << F3_dataS_RPV650_norm << endl;
  cout << "dataS RPV750 : " << F3_dataS_RPV750_norm << endl;
  cout << "dataS RPV850 : " << F3_dataS_RPV850_norm << endl;
  cout << endl;
  cout << "--- Fisher 4 ---" << endl;
  cout << "ttMC         : " << F4_ttMC_norm << endl;
  cout << "otherMC      : " << F4_otherMC_norm << endl;
  cout << "sigMC SYY350 : " << F4_sigMC_SYY350_norm << endl;
  cout << "sigMC SYY450 : " << F4_sigMC_SYY450_norm << endl;
  cout << "sigMC SYY550 : " << F4_sigMC_SYY550_norm << endl;
  cout << "sigMC SYY650 : " << F4_sigMC_SYY650_norm << endl;
  cout << "sigMC SYY750 : " << F4_sigMC_SYY750_norm << endl;
  cout << "sigMC SYY850 : " << F4_sigMC_SYY850_norm << endl;
  cout << "sigMC RPV350 : " << F4_sigMC_RPV350_norm << endl;
  cout << "sigMC RPV450 : " << F4_sigMC_RPV450_norm << endl;
  cout << "sigMC RPV550 : " << F4_sigMC_RPV550_norm << endl;
  cout << "sigMC RPV650 : " << F4_sigMC_RPV650_norm << endl;
  cout << "sigMC RPV750 : " << F4_sigMC_RPV750_norm << endl;
  cout << "sigMC RPV850 : " << F4_sigMC_RPV850_norm << endl;
  cout << "data         : " << F4_data_norm << endl;
  cout << "dataS SYY350 : " << F4_dataS_SYY350_norm << endl;
  cout << "dataS SYY450 : " << F4_dataS_SYY450_norm << endl;
  cout << "dataS SYY550 : " << F4_dataS_SYY550_norm << endl;
  cout << "dataS SYY650 : " << F4_dataS_SYY650_norm << endl;
  cout << "dataS SYY750 : " << F4_dataS_SYY750_norm << endl;
  cout << "dataS SYY850 : " << F4_dataS_SYY850_norm << endl;
  cout << "dataS RPV350 : " << F4_dataS_RPV350_norm << endl;
  cout << "dataS RPV450 : " << F4_dataS_RPV450_norm << endl;
  cout << "dataS RPV550 : " << F4_dataS_RPV550_norm << endl;
  cout << "dataS RPV650 : " << F4_dataS_RPV650_norm << endl;
  cout << "dataS RPV750 : " << F4_dataS_RPV750_norm << endl;
  cout << "dataS RPV850 : " << F4_dataS_RPV850_norm << endl;
  cout << endl;

}
