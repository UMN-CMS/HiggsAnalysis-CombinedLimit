#!/bin/bash 

echo '-- Starting 2017'

echo '--- Running over systematic , with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "", true, true)'
text2workspace.py Card2017_shapesys.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_nom_shared 2017

echo '--- Running over systematic , with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "", false, true)'
text2workspace.py Card2017_shapesys_sep.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_nom_sep 2017

echo '--- Running over systematic _JECUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_JECUp", true, true)'
text2workspace.py Card2017_shapesys.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_JECUp_shared 2017

echo '--- Running over systematic _JECUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_JECUp", false, true)'
text2workspace.py Card2017_shapesys_sep.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_JECUp_sep 2017

echo '--- Running over systematic _JECDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_JECDown", true, true)'
text2workspace.py Card2017_shapesys.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_JECDown_shared 2017

echo '--- Running over systematic _JECDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_JECDown", false, true)'
text2workspace.py Card2017_shapesys_sep.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_JECDown_sep 2017

echo '--- Running over systematic _JERUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_JERUp", true, true)'
text2workspace.py Card2017_shapesys.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_JERUp_shared 2017

echo '--- Running over systematic _JERUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_JERUp", false, true)'
text2workspace.py Card2017_shapesys_sep.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_JERUp_sep 2017

echo '--- Running over systematic _JERDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_JERDown", true, true)'
text2workspace.py Card2017_shapesys.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_JERDown_shared 2017

echo '--- Running over systematic _JERDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_JERDown", false, true)'
text2workspace.py Card2017_shapesys_sep.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_JERDown_sep 2017

echo '--- Running over systematic _fsrUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_fsrUp", true, true)'
text2workspace.py Card2017_shapesys.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_FSRUp_shared 2017

echo '--- Running over systematic _fsrUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_fsrUp", false, true)'
text2workspace.py Card2017_shapesys_sep.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_FSRUp_sep 2017

echo '--- Running over systematic _fsrDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_fsrDown", true, true)'
text2workspace.py Card2017_shapesys.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_FSRDown_shared 2017

echo '--- Running over systematic _fsrDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_fsrDown", false, true)'
text2workspace.py Card2017_shapesys_sep.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_FSRDown_sep 2017

echo '--- Running over systematic _isrUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_isrUp", true, true)'
text2workspace.py Card2017_shapesys.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_ISRUp_shared 2017

echo '--- Running over systematic _isrUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_isrUp", false, true)'
text2workspace.py Card2017_shapesys_sep.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_ISRUp_sep 2017

echo '--- Running over systematic _isrDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_isrDown", true, true)'
text2workspace.py Card2017_shapesys.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_ISRDown_shared 2017

echo '--- Running over systematic _isrDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2017", "Keras_2017_v1.1", "RPV", "550", "TT", "_isrDown", false, true)'
text2workspace.py Card2017_shapesys_sep.txt -o ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2017_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2017RPV550 > log_2017RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2017_ISRDown_sep 2017














echo '-- Starting 2016'


echo '--- Running over systematic , with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT", "", true, true)'
text2workspace.py Card2016_shapesys.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_nom_shared 2016

echo '--- Running over systematic , with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT", "", false, true)'
text2workspace.py Card2016_shapesys_sep.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_nom_sep 2016

echo '--- Running over systematic _JECUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT", "_JECUp", true, true)'
text2workspace.py Card2016_shapesys.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_JECUp_shared 2016

echo '--- Running over systematic _JECUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT", "_JECUp", false, true)'
text2workspace.py Card2016_shapesys_sep.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_JECUp_sep 2016

echo '--- Running over systematic _JECDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT", "_JECDown", true, true)'
text2workspace.py Card2016_shapesys.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_JECDown_shared 2016

echo '--- Running over systematic _JECDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT", "_JECDown", false, true)'
text2workspace.py Card2016_shapesys_sep.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_JECDown_sep 2016

echo '--- Running over systematic _JERUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT", "_JERUp", true, true)'
text2workspace.py Card2016_shapesys.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_JERUp_shared 2016

echo '--- Running over systematic _JERUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT", "_JERUp", false, true)'
text2workspace.py Card2016_shapesys_sep.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_JERUp_sep 2016

echo '--- Running over systematic _JERDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT", "_JERDown", true, true)'
text2workspace.py Card2016_shapesys.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_JERDown_shared 2016

echo '--- Running over systematic _JERDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT", "_JERDown", false, true)'
text2workspace.py Card2016_shapesys_sep.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_JERDown_sep 2016




echo '--- Running over systematic , with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT_isrUp", "", true, true)'
text2workspace.py Card2016_shapesys.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_ISRUp_shared 2016

echo '--- Running over systematic , with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT_isrUp", "", false, true)'
text2workspace.py Card2016_shapesys_sep.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_ISRUp_sep 2016

echo '--- Running over systematic , with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT_isrDown", "", true, true)'
text2workspace.py Card2016_shapesys.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_ISRDown_shared 2016

echo '--- Running over systematic , with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT_isrDown", "", false, true)'
text2workspace.py Card2016_shapesys_sep.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_ISRDown_sep 2016



echo '--- Running over systematic , with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT_fsrUp", "", true, true)'
text2workspace.py Card2016_shapesys.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_FSRUp_shared 2016

echo '--- Running over systematic , with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT_fsrUp", "", false, true)'
text2workspace.py Card2016_shapesys_sep.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_FSRUp_sep 2016

echo '--- Running over systematic , with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT_fsrDown", "", true, true)'
text2workspace.py Card2016_shapesys.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_FSRDown_shared 2016

echo '--- Running over systematic , with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2016", "Keras_2016_v1.1", "RPV", "550", "TT_fsrDown", "", false, true)'
text2workspace.py Card2016_shapesys_sep.txt -o ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2016_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2016RPV550 > log_2016RPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2016_FSRDown_sep 2016
























echo '-- Starting 2018pre'

echo '--- Running over systematic , with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "", true, true)'
text2workspace.py Card2018pre_shapesys.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_nom_shared 2018pre

echo '--- Running over systematic , with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "", false, true)'
text2workspace.py Card2018pre_shapesys_sep.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_nom_sep 2018pre

echo '--- Running over systematic _JECUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_JECUp", true, true)'
text2workspace.py Card2018pre_shapesys.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_JECUp_shared 2018pre

echo '--- Running over systematic _JECUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_JECUp", false, true)'
text2workspace.py Card2018pre_shapesys_sep.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_JECUp_sep 2018pre

echo '--- Running over systematic _JECDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_JECDown", true, true)'
text2workspace.py Card2018pre_shapesys.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_JECDown_shared 2018pre

echo '--- Running over systematic _JECDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_JECDown", false, true)'
text2workspace.py Card2018pre_shapesys_sep.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_JECDown_sep 2018pre

echo '--- Running over systematic _JERUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_JERUp", true, true)'
text2workspace.py Card2018pre_shapesys.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_JERUp_shared 2018pre

echo '--- Running over systematic _JERUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_JERUp", false, true)'
text2workspace.py Card2018pre_shapesys_sep.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_JERUp_sep 2018pre

echo '--- Running over systematic _JERDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_JERDown", true, true)'
text2workspace.py Card2018pre_shapesys.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_JERDown_shared 2018pre

echo '--- Running over systematic _JERDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_JERDown", false, true)'
text2workspace.py Card2018pre_shapesys_sep.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_JERDown_sep 2018pre

echo '--- Running over systematic _fsrUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_fsrUp", true, true)'
text2workspace.py Card2018pre_shapesys.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_FSRUp_shared 2018pre

echo '--- Running over systematic _fsrUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_fsrUp", false, true)'
text2workspace.py Card2018pre_shapesys_sep.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_FSRUp_sep 2018pre

echo '--- Running over systematic _fsrDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_fsrDown", true, true)'
text2workspace.py Card2018pre_shapesys.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_FSRDown_shared 2018pre

echo '--- Running over systematic _fsrDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_fsrDown", false, true)'
text2workspace.py Card2018pre_shapesys_sep.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_FSRDown_sep 2018pre

echo '--- Running over systematic _isrUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_isrUp", true, true)'
text2workspace.py Card2018pre_shapesys.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_ISRUp_shared 2018pre

echo '--- Running over systematic _isrUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_isrUp", false, true)'
text2workspace.py Card2018pre_shapesys_sep.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_ISRUp_sep 2018pre

echo '--- Running over systematic _isrDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_isrDown", true, true)'
text2workspace.py Card2018pre_shapesys.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_ISRDown_shared 2018pre

echo '--- Running over systematic _isrDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018pre", "Keras_2018pre_v1.0", "RPV", "550", "TT", "_isrDown", false, true)'
text2workspace.py Card2018pre_shapesys_sep.txt -o ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018pre_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018preRPV550 > log_2018preRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018pre_ISRDown_sep 2018pre























echo '-- Starting 2018post'

echo '--- Running over systematic , with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "", true, true)'
text2workspace.py Card2018post_shapesys.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_nom_shared 2018post

echo '--- Running over systematic , with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "", false, true)'
text2workspace.py Card2018post_shapesys_sep.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_nom_sep 2018post

echo '--- Running over systematic _JECUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_JECUp", true, true)'
text2workspace.py Card2018post_shapesys.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_JECUp_shared 2018post

echo '--- Running over systematic _JECUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_JECUp", false, true)'
text2workspace.py Card2018post_shapesys_sep.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_JECUp_sep 2018post

echo '--- Running over systematic _JECDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_JECDown", true, true)'
text2workspace.py Card2018post_shapesys.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_JECDown_shared 2018post

echo '--- Running over systematic _JECDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_JECDown", false, true)'
text2workspace.py Card2018post_shapesys_sep.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_JECDown_sep 2018post

echo '--- Running over systematic _JERUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_JERUp", true, true)'
text2workspace.py Card2018post_shapesys.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_JERUp_shared 2018post

echo '--- Running over systematic _JERUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_JERUp", false, true)'
text2workspace.py Card2018post_shapesys_sep.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_JERUp_sep 2018post

echo '--- Running over systematic _JERDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_JERDown", true, true)'
text2workspace.py Card2018post_shapesys.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_JERDown_shared 2018post

echo '--- Running over systematic _JERDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_JERDown", false, true)'
text2workspace.py Card2018post_shapesys_sep.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_JERDown_sep 2018post

echo '--- Running over systematic _fsrUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_fsrUp", true, true)'
text2workspace.py Card2018post_shapesys.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_FSRUp_shared 2018post

echo '--- Running over systematic _fsrUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_fsrUp", false, true)'
text2workspace.py Card2018post_shapesys_sep.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_FSRUp_sep 2018post

echo '--- Running over systematic _fsrDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_fsrDown", true, true)'
text2workspace.py Card2018post_shapesys.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_FSRDown_shared 2018post

echo '--- Running over systematic _fsrDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_fsrDown", false, true)'
text2workspace.py Card2018post_shapesys_sep.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_FSRDown_sep 2018post

echo '--- Running over systematic _isrUp, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_isrUp", true, true)'
text2workspace.py Card2018post_shapesys.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_ISRUp_shared 2018post

echo '--- Running over systematic _isrUp, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_isrUp", false, true)'
text2workspace.py Card2018post_shapesys_sep.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_ISRUp_sep 2018post

echo '--- Running over systematic _isrDown, with shared parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_isrDown", true, true)'
text2workspace.py Card2018post_shapesys.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_ISRDown_shared 2018post

echo '--- Running over systematic _isrDown, with separate parameters' 
root -l -q 'make_MVA_8bin_ws.C("2018post", "Keras_2018post_v1.0", "RPV", "550", "TT", "_isrDown", false, true)'
text2workspace.py Card2018post_shapesys_sep.txt -o ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV 
combine -M FitDiagnostics ws_2018post_RPV_550.root -m 550 --keyword-value MODEL=RPV --verbose 2 --cminDefaultMinimizerStrategy 1 --cminFallbackAlgo Minuit2,Migrad,0:0.1 --cminFallbackAlgo Minuit2,Migrad,1:1.0 --cminFallbackAlgo Minuit2,Migrad,0:1.0 --X-rtd MINIMIZER_MaxCalls=999999999 --X-rtd MINIMIZER_analytic --X-rtd FAST_VERTICAL_MORPH --rMax 5 --robustFit=1 --plots --saveShapes --saveNormalizations -n 2018postRPV550 > log_2018postRPV550_FitDiag.txt
./stash_fits.sh Approval_StatErrPlusFullDev_12JetFix_2018post_ISRDown_sep 2018post

