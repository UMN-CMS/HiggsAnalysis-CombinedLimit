import ROOT
import optparse

def makeDataHisto(histRef, name, l, sys=[]):
    pseudoData = ROOT.TH1D(name, name, histRef.GetNbinsX(), histRef.GetBinLowEdge(1), histRef.GetBinLowEdge(1)+histRef.GetNbinsX())
    for bin in range(histRef.GetNbinsX()):
        sumdata = 0
        for h in l:
            d = h[1].GetBinContent(bin+1)
            if h[0].find("_TT_h_njets_pt30_1l") != -1 and len(sys)>0:
                for hs in sys:
                    d *= hs.GetBinContent(bin+1)
            sumdata += d
        pseudoData.SetBinContent(bin+1, int(round(sumdata)))
    return pseudoData    

def main():
    parser = optparse.OptionParser("usage: %prog [options]\n")
    parser.add_option('-d', dest='basedir', type='string', default='Keras_V1.2.8_Approval_SepOther_StatErrPlusFullDev', help="Path to input rootfiles")
    parser.add_option('--rootFile', dest='rootFile', type='string', default='pseudoData.root', help="Output root file")
    options, args = parser.parse_args()
    path = options.basedir
    outfile = path+"/"+options.rootFile

    bgNames = ["_TT_h_njets_pt30_1l", "_TTX_h_njets_pt30_1l", "_OTHER_h_njets_pt30_1l", "_QCD_h_njets_pt30_1l"]
    mvaBins = ["D1", "D2", "D3", "D4"]
    
    njets_for_Aron = ROOT.TFile.Open(path+"/njets_for_Aron.root")
    ttbar_sys = ROOT.TFile.Open(path+"/ttbar_systematics.root")
    newfile = ROOT.TFile.Open(outfile,"RECREATE")
    histRef = njets_for_Aron.Get("D1_TT_h_njets_pt30_1l")
    
    bgHistoListofList = []
    for mvaBin in mvaBins:
        bgHistoList = []
        for bgName in bgNames:
            bgHistoList.append( (mvaBin+bgName, njets_for_Aron.Get(mvaBin+bgName)) )
        bgHistoListofList.append( (mvaBin, bgHistoList) )
    
    newfile.cd()            
    for lMVA in bgHistoListofList:
        #makeDataHisto(histRef, lMVA[0]+"_pseudodata_h_njets_pt30_1l", lMVA[1]).Write()  
        makeDataHisto(histRef, lMVA[0]+"_pseudodata_qcdCR_h_njets_pt30_1l", lMVA[1], [ ttbar_sys.Get(lMVA[0]+"_qcdCR") ]).Write()
        makeDataHisto(histRef, lMVA[0]+"_pseudodata_2xqcdCR_h_njets_pt30_1l", lMVA[1], [ ttbar_sys.Get(lMVA[0]+"_qcdCR"), ttbar_sys.Get(lMVA[0]+"_qcdCR") ]).Write()
        makeDataHisto(histRef, lMVA[0]+"_pseudodata_JECUp_JERDown_FSR_h_njets_pt30_1l", lMVA[1], [ ttbar_sys.Get(lMVA[0]+"_JECUp"), ttbar_sys.Get(lMVA[0]+"_JERDown"), ttbar_sys.Get(lMVA[0]+"_FSR") ]).Write()

        sRPV350 = njets_for_Aron.Get(lMVA[0]+"_RPV_350_h_njets_pt30_1l")
        sRPV350.Scale(0.3)
        makeDataHisto(histRef, lMVA[0]+"_pseudodataS_0.3xRPV_350_h_njets_pt30_1l", lMVA[1]+[("RPV_350", sRPV350)]).Write()  

    newfile.Close()
    njets_for_Aron.Close()
    ttbar_sys.Close()

if __name__ == "__main__":
    main()
