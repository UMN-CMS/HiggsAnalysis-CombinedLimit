HiggsAnalysis-CombinedLimit
===========================

### Official documentation

[Manual to run combine](https://github.com/cms-analysis/HiggsAnalysis-CombinedLimit/wiki)

### Standalone compilation in `lxplus`
```
git clone https://github.com/cms-analysis/HiggsAnalysis-CombinedLimit.git HiggsAnalysis/CombinedLimit
cd HiggsAnalysis/CombinedLimit
source env_standalone.sh 
make -j 8; make # second make fixes compilation error of first
```

### Stealth Stop Group Setup `(LPC)`
```
bash
source /cvmfs/cms.cern.ch/cmsset_default.sh 
export SCRAM_ARCH=slc6_amd64_gcc530
cmsrel CMSSW_8_1_0
cd CMSSW_8_1_0/src
cmsenv
git clone git@github.com:StealthStop/HiggsAnalysis-CombinedLimit.git HiggsAnalysis/CombinedLimit
cd $CMSSW_BASE/src/HiggsAnalysis/CombinedLimit
scram b clean
scram b -j8
```

### Example

To make the RooFit workspace for combine.  The workspace goes into
a file called MVA_RPV_550_ws.root.  Can substitute other versions, models, and mass points.
```
root -l -q 'make_MVA_8bin_ws.C("Keras_V1.2.4","RPV","550")'
```

Calculate quick asymptotic limits.  Outputs a file called
higgsCombineTest.AsymptoticLimits.mH550.MODELRPV.root
which contains the expected (and observed) limits.
```
combine -M AsymptoticLimits TestCard.txt -m 550 --keyword-value MODEL=RPV
```

Calculate the significance using the asimov dataset and expected signal strength of 1.
Significance is printed to screen and is available in the file
higgsCombineTest.Significance.mH550.MODELRPV.root
```
combine -M Significance TestCard.txt -t -1 --expectSignal=1 -m 550 --keyword-value MODEL=RPV
```

Run the fit and produce a root file called fitDiagnostics.root that contains RooPlots and RooFitResults,
as well as a file called higgsCombineTest.FitDiagnostics.mH550.MODELRPV.root that has the signal strength.
```
combine -M FitDiagnostics TestCard.txt --plots --saveShapes --saveNormalizations
```

Produce formatted plots of fit results for each MVA bin:
```
root -q -l fit_report_ESM.C
```

Print the parameters resulting from the fit:
```
python test/diffNuisances.py --all --abs fitDiagnostics.root
```

To make a limit plot:
```
root -l -q makePlots.C+
```

Background-only fits to tt background, before and after systematic variations:
```
root -l
.x make_BkgOnly_ws.C("_btgUp");
combine -M FitDiagnostics RPV_550_BkgOnlyCard.txt --plots --saveShapes --saveNormalizations -n _btgUp
root -l fitDiagnostics_btgUp.root
shapes_fit_b->cd();
D1->cd();
TT->Draw();
etc.
```
