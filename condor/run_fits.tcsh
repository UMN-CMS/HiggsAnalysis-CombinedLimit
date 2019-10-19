#!/bin/tcsh

set inputRoot2016 = $1
set inputRoot2017 = $2
set signalType = $3
set mass = $4
set year = $5
set dataType = $6
set doAsym = $7
set doFitDiag = $8
set doMulti = $9
set doImpact = $10
set inject = $11
set syst = $12
set base_dir = `pwd`

if ($syst == None) then
    set syst=""
endif

source /cvmfs/cms.cern.ch/cmsset_default.csh
setenv SCRAM_ARCH slc6_amd64_gcc530
tar -xf CMSSW_8_1_0.tar.gz
cd CMSSW_8_1_0/src/HiggsAnalysis/CombinedLimit
scram b ProjectRename
eval `scramv1 runtime -csh`
cp ${base_dir}/exestuff.tar.gz .
tar xzvf exestuff.tar.gz
mv exestuff/* .
setenv LD_LIBRARY_PATH ${PWD}:${LD_LIBRARY_PATH}
ls -l

mkdir ${inputRoot2016}
xrdcp root://cmseos.fnal.gov//store/user/lpcsusyhad/StealthStop/FitInputs/${inputRoot2016}/njets_for_Aron.root         ${inputRoot2016}/.
xrdcp root://cmseos.fnal.gov//store/user/lpcsusyhad/StealthStop/FitInputs/${inputRoot2016}/ttbar_systematics.root      ${inputRoot2016}/.
xrdcp root://cmseos.fnal.gov//store/user/lpcsusyhad/StealthStop/FitInputs/${inputRoot2016}/qcdcr-syst-parameters.root  ${inputRoot2016}/.

mkdir ${inputRoot2017}
xrdcp root://cmseos.fnal.gov//store/user/lpcsusyhad/StealthStop/FitInputs/${inputRoot2017}/njets_for_Aron.root         ${inputRoot2017}/.
xrdcp root://cmseos.fnal.gov//store/user/lpcsusyhad/StealthStop/FitInputs/${inputRoot2017}/ttbar_systematics.root      ${inputRoot2017}/.
xrdcp root://cmseos.fnal.gov//store/user/lpcsusyhad/StealthStop/FitInputs/${inputRoot2017}/qcdcr-syst-parameters.root  ${inputRoot2017}/.

eval `scramv1 runtime -csh`

combineCards.py Y16=Card2016.txt Y17=Card2017.txt > CardCombo.txt
root -l -q -b 'make_MVA_8bin_ws.C("2016","'${inputRoot2016}'","'${signalType}'","'${mass}'","'${dataType}'","'${syst}'")'
root -l -q -b 'make_MVA_8bin_ws.C("2017","'${inputRoot2017}'","'${signalType}'","'${mass}'","'${dataType}'","'${syst}'")'
text2workspace.py Card${year}.txt -o ws_${year}_${signalType}_${mass}.root -m ${mass} --keyword-value MODEL=${signalType}
set ws = ws_${year}_${signalType}_${mass}.root
set fitOptions = "${ws} -m ${mass} --keyword-value MODEL=${signalType} --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH"

if ($doAsym == 1) then
    combine -M AsymptoticLimits ${fitOptions} --verbose 2 --rMax 5                        -n ${year}                               > log_${year}${signalType}${mass}_Asymp.txt
    combine -M Significance     ${fitOptions} --verbose 2 --rMax 5 -t -1 --expectSignal=1 -n ${year}${signalType}${mass}_SignifExp > log_${year}${signalType}${mass}_Sign_sig.txt
    combine -M Significance     ${fitOptions} --verbose 2 --rMax 5                        -n ${year}${signalType}${mass}_SignifExp > log_${year}${signalType}${mass}_Sign_noSig.txt
endif
if ($doFitDiag == 1) then
    if ($inject == 0) then
        combine -M FitDiagnostics ${fitOptions} --verbose 2 --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n ${year}${signalType}${mass} > log_${year}${signalType}${mass}_FitDiag.txt
    else
        combine -M FitDiagnostics ${fitOptions} --verbose 2 --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n ${year}${signalType}${mass} -t -1 --toysFrequentist --expectSignal=${inject} > log_${year}${signalType}${mass}_FitDiag.txt
    endif
endif
if ($doMulti == 1) then
    combine -M MultiDimFit ${fitOptions} --verbose 0 --rMin -0.2 --rMax 2.0 --algo=grid --points=100 -n SCAN_r_wSig > log_${year}${signalType}${mass}_multiDim.txt
    rm log_${year}${signalType}${mass}_multiDim.txt
endif
if ($doImpact == 1) then
    ../../CombineHarvester/CombineTools/scripts/combineTool.py -M Impacts -d ${ws} -m ${mass} --doInitialFit --robustFit 1 --rMin -10 > log_step1.txt
    ../../CombineHarvester/CombineTools/scripts/combineTool.py -M Impacts -d ${ws} -m ${mass} --doFits --parallel 4 --rMin -10 > log_step2.txt
    ../../CombineHarvester/CombineTools/scripts/combineTool.py -M Impacts -d ${ws} -m ${mass} -o impacts_${year}${signalType}${mass}.json > log_step3.txt
    ../../CombineHarvester/CombineTools/scripts/plotImpacts.py -i impacts_${year}${signalType}${mass}.json -o impacts_${year}${signalType}${mass}_${dataType}
    rm higgsCombine_paramFit_Test_*root
    rm higgsCombine_initialFit_Test.MultiDimFit.*.root
    rm log_step1.txt log_step2.txt log_step3.txt
endif

ls -l

mv *.root ${base_dir}
mv log*.txt ${base_dir}
mv *.pdf ${base_dir}
mv *.json ${base_dir}

cd ${base_dir}
