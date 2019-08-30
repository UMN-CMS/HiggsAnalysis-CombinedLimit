#!/bin/tcsh

set inputRoot2016 = $1
set inputRoot2017 = $2
set signalType = $3
set mass = $4
set year = $5
set dataType = $6
set rVal = $7
set seed = $8
set numToys = $9
set iterations = $10
set doToyS = $11
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
xrdcp root://cmseos.fnal.gov//store/user/lpcsusyhad/StealthStop/FitInputs/${inputRoot2016}/njets_for_Aron.root     ${inputRoot2016}/.
xrdcp root://cmseos.fnal.gov//store/user/lpcsusyhad/StealthStop/FitInputs/${inputRoot2016}/ttbar_systematics.root  ${inputRoot2016}/.
xrdcp root://cmseos.fnal.gov//store/user/lpcsusyhad/StealthStop/FitInputs/${inputRoot2016}/qcdcr-syst-parameters.root  ${inputRoot2016}/.

mkdir ${inputRoot2017}
xrdcp root://cmseos.fnal.gov//store/user/lpcsusyhad/StealthStop/FitInputs/${inputRoot2017}/njets_for_Aron.root     ${inputRoot2017}/.
xrdcp root://cmseos.fnal.gov//store/user/lpcsusyhad/StealthStop/FitInputs/${inputRoot2017}/ttbar_systematics.root  ${inputRoot2017}/.
xrdcp root://cmseos.fnal.gov//store/user/lpcsusyhad/StealthStop/FitInputs/${inputRoot2017}/qcdcr-syst-parameters.root  ${inputRoot2017}/.

eval `scramv1 runtime -csh`

combineCards.py Y16=Card2016.txt Y17=Card2017.txt > CardCombo.txt
root -l -q -b 'make_MVA_8bin_ws.C("2016","'${inputRoot2016}'","'${signalType}'","'${mass}'","'${dataType}'","'${syst}'")'
root -l -q -b 'make_MVA_8bin_ws.C("2017","'${inputRoot2017}'","'${signalType}'","'${mass}'","'${dataType}'","'${syst}'")'
text2workspace.py Card${year}.txt -o ws_${year}_${signalType}_${mass}.root -m ${mass} --keyword-value MODEL=${signalType}

if ($doToyS == 1) then
    printf "\n\n Running sig. toys\n"
    combine -M HybridNew --LHCmode LHC-significance ws_${year}_${signalType}_${mass}.root -m ${mass} --keyword-value MODEL=${signalType} -n ${year} --saveToys --saveHybridResult -T ${numToys} -s ${seed} --fullBToys -i ${iterations} > log_tmp.txt
else
    printf "\n\n Running limit toys\n"
    combine -M HybridNew --LHCmode LHC-limits       ws_${year}_${signalType}_${mass}.root -m ${mass} --keyword-value MODEL=${signalType} -n ${year} --saveToys --saveHybridResult -T ${numToys} -s ${seed} --fullBToys --singlePoint ${rVal} --clsAcc 0 > log_tmp.txt 
endif

#removing log files because they can be larger than 1G
rm log_tmp.txt

mv *.root ${base_dir}
mv log*.txt ${base_dir}

cd ${base_dir}
