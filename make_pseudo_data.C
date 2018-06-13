void make_pseudo_data() {

  TFile* file = TFile::Open("njets_for_Aron.root");

  TH1* ttMC_th1_F1 = 0;
  file->GetObject("h_njets_pt30_1l_g1b_mbl_fisher1_TT",ttMC_th1_F1);
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


  for (int i=1; i<10; i++) {
    data_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i));
    data_th1_F1->SetBinError(i,TMath::Sqrt(data_th1_F1->GetBinContent(i)));

    dataS_SYY350_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i)+sigMC_SYY350_th1_F1->GetBinContent(i));
    dataS_SYY350_th1_F1->SetBinError(i,TMath::Sqrt(dataS_SYY350_th1_F1->GetBinContent(i)));

    dataS_SYY450_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i)+sigMC_SYY450_th1_F1->GetBinContent(i));
    dataS_SYY450_th1_F1->SetBinError(i,TMath::Sqrt(dataS_SYY450_th1_F1->GetBinContent(i)));

    dataS_SYY550_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i)+sigMC_SYY550_th1_F1->GetBinContent(i));
    dataS_SYY550_th1_F1->SetBinError(i,TMath::Sqrt(dataS_SYY550_th1_F1->GetBinContent(i)));

    dataS_SYY650_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i)+sigMC_SYY650_th1_F1->GetBinContent(i));
    dataS_SYY650_th1_F1->SetBinError(i,TMath::Sqrt(dataS_SYY650_th1_F1->GetBinContent(i)));

    dataS_SYY750_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i)+sigMC_SYY750_th1_F1->GetBinContent(i));
    dataS_SYY750_th1_F1->SetBinError(i,TMath::Sqrt(dataS_SYY750_th1_F1->GetBinContent(i)));

    dataS_SYY850_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i)+sigMC_SYY850_th1_F1->GetBinContent(i));
    dataS_SYY850_th1_F1->SetBinError(i,TMath::Sqrt(dataS_SYY850_th1_F1->GetBinContent(i)));

    dataS_RPV350_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i)+sigMC_RPV350_th1_F1->GetBinContent(i));
    dataS_RPV350_th1_F1->SetBinError(i,TMath::Sqrt(dataS_RPV350_th1_F1->GetBinContent(i)));

    dataS_RPV450_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i)+sigMC_RPV450_th1_F1->GetBinContent(i));
    dataS_RPV450_th1_F1->SetBinError(i,TMath::Sqrt(dataS_RPV450_th1_F1->GetBinContent(i)));

    dataS_RPV550_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i)+sigMC_RPV550_th1_F1->GetBinContent(i));
    dataS_RPV550_th1_F1->SetBinError(i,TMath::Sqrt(dataS_RPV550_th1_F1->GetBinContent(i)));

    dataS_RPV650_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i)+sigMC_RPV650_th1_F1->GetBinContent(i));
    dataS_RPV650_th1_F1->SetBinError(i,TMath::Sqrt(dataS_RPV650_th1_F1->GetBinContent(i)));

    dataS_RPV750_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i)+sigMC_RPV750_th1_F1->GetBinContent(i));
    dataS_RPV750_th1_F1->SetBinError(i,TMath::Sqrt(dataS_RPV750_th1_F1->GetBinContent(i)));

    dataS_RPV850_th1_F1->SetBinContent(i,ttMC_th1_F1->GetBinContent(i)+otherMC_th1_F1->GetBinContent(i)+sigMC_RPV850_th1_F1->GetBinContent(i));
    dataS_RPV850_th1_F1->SetBinError(i,TMath::Sqrt(dataS_RPV850_th1_F1->GetBinContent(i)));


    data_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i));
    data_th1_F2->SetBinError(i,TMath::Sqrt(data_th1_F2->GetBinContent(i)));

    dataS_SYY350_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i)+sigMC_SYY350_th1_F2->GetBinContent(i));
    dataS_SYY350_th1_F2->SetBinError(i,TMath::Sqrt(dataS_SYY350_th1_F2->GetBinContent(i)));

    dataS_SYY450_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i)+sigMC_SYY450_th1_F2->GetBinContent(i));
    dataS_SYY450_th1_F2->SetBinError(i,TMath::Sqrt(dataS_SYY450_th1_F2->GetBinContent(i)));

    dataS_SYY550_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i)+sigMC_SYY550_th1_F2->GetBinContent(i));
    dataS_SYY550_th1_F2->SetBinError(i,TMath::Sqrt(dataS_SYY550_th1_F2->GetBinContent(i)));

    dataS_SYY650_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i)+sigMC_SYY650_th1_F2->GetBinContent(i));
    dataS_SYY650_th1_F2->SetBinError(i,TMath::Sqrt(dataS_SYY650_th1_F2->GetBinContent(i)));

    dataS_SYY750_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i)+sigMC_SYY750_th1_F2->GetBinContent(i));
    dataS_SYY750_th1_F2->SetBinError(i,TMath::Sqrt(dataS_SYY750_th1_F2->GetBinContent(i)));

    dataS_SYY850_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i)+sigMC_SYY850_th1_F2->GetBinContent(i));
    dataS_SYY850_th1_F2->SetBinError(i,TMath::Sqrt(dataS_SYY850_th1_F2->GetBinContent(i)));

    dataS_RPV350_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i)+sigMC_RPV350_th1_F2->GetBinContent(i));
    dataS_RPV350_th1_F2->SetBinError(i,TMath::Sqrt(dataS_RPV350_th1_F2->GetBinContent(i)));

    dataS_RPV450_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i)+sigMC_RPV450_th1_F2->GetBinContent(i));
    dataS_RPV450_th1_F2->SetBinError(i,TMath::Sqrt(dataS_RPV450_th1_F2->GetBinContent(i)));

    dataS_RPV550_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i)+sigMC_RPV550_th1_F2->GetBinContent(i));
    dataS_RPV550_th1_F2->SetBinError(i,TMath::Sqrt(dataS_RPV550_th1_F2->GetBinContent(i)));

    dataS_RPV650_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i)+sigMC_RPV650_th1_F2->GetBinContent(i));
    dataS_RPV650_th1_F2->SetBinError(i,TMath::Sqrt(dataS_RPV650_th1_F2->GetBinContent(i)));

    dataS_RPV750_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i)+sigMC_RPV750_th1_F2->GetBinContent(i));
    dataS_RPV750_th1_F2->SetBinError(i,TMath::Sqrt(dataS_RPV750_th1_F2->GetBinContent(i)));

    dataS_RPV850_th1_F2->SetBinContent(i,ttMC_th1_F2->GetBinContent(i)+otherMC_th1_F2->GetBinContent(i)+sigMC_RPV850_th1_F2->GetBinContent(i));
    dataS_RPV850_th1_F2->SetBinError(i,TMath::Sqrt(dataS_RPV850_th1_F2->GetBinContent(i)));


    data_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i));
    data_th1_F3->SetBinError(i,TMath::Sqrt(data_th1_F3->GetBinContent(i)));

    dataS_SYY350_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i)+sigMC_SYY350_th1_F3->GetBinContent(i));
    dataS_SYY350_th1_F3->SetBinError(i,TMath::Sqrt(dataS_SYY350_th1_F3->GetBinContent(i)));

    dataS_SYY450_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i)+sigMC_SYY450_th1_F3->GetBinContent(i));
    dataS_SYY450_th1_F3->SetBinError(i,TMath::Sqrt(dataS_SYY450_th1_F3->GetBinContent(i)));

    dataS_SYY550_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i)+sigMC_SYY550_th1_F3->GetBinContent(i));
    dataS_SYY550_th1_F3->SetBinError(i,TMath::Sqrt(dataS_SYY550_th1_F3->GetBinContent(i)));

    dataS_SYY650_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i)+sigMC_SYY650_th1_F3->GetBinContent(i));
    dataS_SYY650_th1_F3->SetBinError(i,TMath::Sqrt(dataS_SYY650_th1_F3->GetBinContent(i)));

    dataS_SYY750_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i)+sigMC_SYY750_th1_F3->GetBinContent(i));
    dataS_SYY750_th1_F3->SetBinError(i,TMath::Sqrt(dataS_SYY750_th1_F3->GetBinContent(i)));

    dataS_SYY850_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i)+sigMC_SYY850_th1_F3->GetBinContent(i));
    dataS_SYY850_th1_F3->SetBinError(i,TMath::Sqrt(dataS_SYY850_th1_F3->GetBinContent(i)));

    dataS_RPV350_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i)+sigMC_RPV350_th1_F3->GetBinContent(i));
    dataS_RPV350_th1_F3->SetBinError(i,TMath::Sqrt(dataS_RPV350_th1_F3->GetBinContent(i)));

    dataS_RPV450_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i)+sigMC_RPV450_th1_F3->GetBinContent(i));
    dataS_RPV450_th1_F3->SetBinError(i,TMath::Sqrt(dataS_RPV450_th1_F3->GetBinContent(i)));

    dataS_RPV550_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i)+sigMC_RPV550_th1_F3->GetBinContent(i));
    dataS_RPV550_th1_F3->SetBinError(i,TMath::Sqrt(dataS_RPV550_th1_F3->GetBinContent(i)));

    dataS_RPV650_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i)+sigMC_RPV650_th1_F3->GetBinContent(i));
    dataS_RPV650_th1_F3->SetBinError(i,TMath::Sqrt(dataS_RPV650_th1_F3->GetBinContent(i)));

    dataS_RPV750_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i)+sigMC_RPV750_th1_F3->GetBinContent(i));
    dataS_RPV750_th1_F3->SetBinError(i,TMath::Sqrt(dataS_RPV750_th1_F3->GetBinContent(i)));

    dataS_RPV850_th1_F3->SetBinContent(i,ttMC_th1_F3->GetBinContent(i)+otherMC_th1_F3->GetBinContent(i)+sigMC_RPV850_th1_F3->GetBinContent(i));
    dataS_RPV850_th1_F3->SetBinError(i,TMath::Sqrt(dataS_RPV850_th1_F3->GetBinContent(i)));


    data_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i));
    data_th1_F4->SetBinError(i,TMath::Sqrt(data_th1_F4->GetBinContent(i)));

    dataS_SYY350_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i)+sigMC_SYY350_th1_F4->GetBinContent(i));
    dataS_SYY350_th1_F4->SetBinError(i,TMath::Sqrt(dataS_SYY350_th1_F4->GetBinContent(i)));

    dataS_SYY450_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i)+sigMC_SYY450_th1_F4->GetBinContent(i));
    dataS_SYY450_th1_F4->SetBinError(i,TMath::Sqrt(dataS_SYY450_th1_F4->GetBinContent(i)));

    dataS_SYY550_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i)+sigMC_SYY550_th1_F4->GetBinContent(i));
    dataS_SYY550_th1_F4->SetBinError(i,TMath::Sqrt(dataS_SYY550_th1_F4->GetBinContent(i)));

    dataS_SYY650_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i)+sigMC_SYY650_th1_F4->GetBinContent(i));
    dataS_SYY650_th1_F4->SetBinError(i,TMath::Sqrt(dataS_SYY650_th1_F4->GetBinContent(i)));

    dataS_SYY750_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i)+sigMC_SYY750_th1_F4->GetBinContent(i));
    dataS_SYY750_th1_F4->SetBinError(i,TMath::Sqrt(dataS_SYY750_th1_F4->GetBinContent(i)));

    dataS_SYY850_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i)+sigMC_SYY850_th1_F4->GetBinContent(i));
    dataS_SYY850_th1_F4->SetBinError(i,TMath::Sqrt(dataS_SYY850_th1_F4->GetBinContent(i)));

    dataS_RPV350_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i)+sigMC_RPV350_th1_F4->GetBinContent(i));
    dataS_RPV350_th1_F4->SetBinError(i,TMath::Sqrt(dataS_RPV350_th1_F4->GetBinContent(i)));

    dataS_RPV450_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i)+sigMC_RPV450_th1_F4->GetBinContent(i));
    dataS_RPV450_th1_F4->SetBinError(i,TMath::Sqrt(dataS_RPV450_th1_F4->GetBinContent(i)));

    dataS_RPV550_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i)+sigMC_RPV550_th1_F4->GetBinContent(i));
    dataS_RPV550_th1_F4->SetBinError(i,TMath::Sqrt(dataS_RPV550_th1_F4->GetBinContent(i)));

    dataS_RPV650_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i)+sigMC_RPV650_th1_F4->GetBinContent(i));
    dataS_RPV650_th1_F4->SetBinError(i,TMath::Sqrt(dataS_RPV650_th1_F4->GetBinContent(i)));

    dataS_RPV750_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i)+sigMC_RPV750_th1_F4->GetBinContent(i));
    dataS_RPV750_th1_F4->SetBinError(i,TMath::Sqrt(dataS_RPV750_th1_F4->GetBinContent(i)));

    dataS_RPV850_th1_F4->SetBinContent(i,ttMC_th1_F4->GetBinContent(i)+otherMC_th1_F4->GetBinContent(i)+sigMC_RPV850_th1_F4->GetBinContent(i));
    dataS_RPV850_th1_F4->SetBinError(i,TMath::Sqrt(dataS_RPV850_th1_F4->GetBinContent(i)));



  }

  TFile *fOut = new TFile("njets_with_exact_pseudo_data.root","RECREATE");
  fOut->cd();

  ttMC_th1_F1->Write();
  otherMC_th1_F1->Write();
  sigMC_SYY350_th1_F1->Write();
  sigMC_SYY450_th1_F1->Write();
  sigMC_SYY550_th1_F1->Write();
  sigMC_SYY650_th1_F1->Write();
  sigMC_SYY750_th1_F1->Write();
  sigMC_SYY850_th1_F1->Write();
  sigMC_RPV350_th1_F1->Write();
  sigMC_RPV450_th1_F1->Write();
  sigMC_RPV550_th1_F1->Write();
  sigMC_RPV650_th1_F1->Write();
  sigMC_RPV750_th1_F1->Write();
  sigMC_RPV850_th1_F1->Write();
  data_th1_F1->Write();
  dataS_SYY350_th1_F1->Write();
  dataS_SYY450_th1_F1->Write();
  dataS_SYY550_th1_F1->Write();
  dataS_SYY650_th1_F1->Write();
  dataS_SYY750_th1_F1->Write();
  dataS_SYY850_th1_F1->Write();
  dataS_RPV350_th1_F1->Write();
  dataS_RPV450_th1_F1->Write();
  dataS_RPV550_th1_F1->Write();
  dataS_RPV650_th1_F1->Write();
  dataS_RPV750_th1_F1->Write();
  dataS_RPV850_th1_F1->Write();

  ttMC_th1_F2->Write();
  otherMC_th1_F2->Write();
  sigMC_SYY350_th1_F2->Write();
  sigMC_SYY450_th1_F2->Write();
  sigMC_SYY550_th1_F2->Write();
  sigMC_SYY650_th1_F2->Write();
  sigMC_SYY750_th1_F2->Write();
  sigMC_SYY850_th1_F2->Write();
  sigMC_RPV350_th1_F2->Write();
  sigMC_RPV450_th1_F2->Write();
  sigMC_RPV550_th1_F2->Write();
  sigMC_RPV650_th1_F2->Write();
  sigMC_RPV750_th1_F2->Write();
  sigMC_RPV850_th1_F2->Write();
  data_th1_F2->Write();
  dataS_SYY350_th1_F2->Write();
  dataS_SYY450_th1_F2->Write();
  dataS_SYY550_th1_F2->Write();
  dataS_SYY650_th1_F2->Write();
  dataS_SYY750_th1_F2->Write();
  dataS_SYY850_th1_F2->Write();
  dataS_RPV350_th1_F2->Write();
  dataS_RPV450_th1_F2->Write();
  dataS_RPV550_th1_F2->Write();
  dataS_RPV650_th1_F2->Write();
  dataS_RPV750_th1_F2->Write();
  dataS_RPV850_th1_F2->Write();

  ttMC_th1_F3->Write();
  otherMC_th1_F3->Write();
  sigMC_SYY350_th1_F3->Write();
  sigMC_SYY450_th1_F3->Write();
  sigMC_SYY550_th1_F3->Write();
  sigMC_SYY650_th1_F3->Write();
  sigMC_SYY750_th1_F3->Write();
  sigMC_SYY850_th1_F3->Write();
  sigMC_RPV350_th1_F3->Write();
  sigMC_RPV450_th1_F3->Write();
  sigMC_RPV550_th1_F3->Write();
  sigMC_RPV650_th1_F3->Write();
  sigMC_RPV750_th1_F3->Write();
  sigMC_RPV850_th1_F3->Write();
  data_th1_F3->Write();
  dataS_SYY350_th1_F3->Write();
  dataS_SYY450_th1_F3->Write();
  dataS_SYY550_th1_F3->Write();
  dataS_SYY650_th1_F3->Write();
  dataS_SYY750_th1_F3->Write();
  dataS_SYY850_th1_F3->Write();
  dataS_RPV350_th1_F3->Write();
  dataS_RPV450_th1_F3->Write();
  dataS_RPV550_th1_F3->Write();
  dataS_RPV650_th1_F3->Write();
  dataS_RPV750_th1_F3->Write();
  dataS_RPV850_th1_F3->Write();

  ttMC_th1_F4->Write();
  otherMC_th1_F4->Write();
  sigMC_SYY350_th1_F4->Write();
  sigMC_SYY450_th1_F4->Write();
  sigMC_SYY550_th1_F4->Write();
  sigMC_SYY650_th1_F4->Write();
  sigMC_SYY750_th1_F4->Write();
  sigMC_SYY850_th1_F4->Write();
  sigMC_RPV350_th1_F4->Write();
  sigMC_RPV450_th1_F4->Write();
  sigMC_RPV550_th1_F4->Write();
  sigMC_RPV650_th1_F4->Write();
  sigMC_RPV750_th1_F4->Write();
  sigMC_RPV850_th1_F4->Write();
  data_th1_F4->Write();
  dataS_SYY350_th1_F4->Write();
  dataS_SYY450_th1_F4->Write();
  dataS_SYY550_th1_F4->Write();
  dataS_SYY650_th1_F4->Write();
  dataS_SYY750_th1_F4->Write();
  dataS_SYY850_th1_F4->Write();
  dataS_RPV350_th1_F4->Write();
  dataS_RPV450_th1_F4->Write();
  dataS_RPV550_th1_F4->Write();
  dataS_RPV650_th1_F4->Write();
  dataS_RPV750_th1_F4->Write();
  dataS_RPV850_th1_F4->Write();
}
