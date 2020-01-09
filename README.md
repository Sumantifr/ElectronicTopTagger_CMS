# ElectronicTopTagger_CMS
Code to implement electronic top tagger (arXiv: 1909.11041) in CMSSW

cmsrel CMSSW_10_5_0

cd CMSSW_10_5_0/src 

copy "CMSSW_10_5_0/src/L5_Cor" directory here

To compile the C++ code (EDAnalyzer), go to 

CMSSW_10_5_0/src/L5_Cor/Data/plugins

and run the following command -

scram b -j8

This will produce the .so file for execution by the python configuration file.

Finally go to 

CMSSW_10_5_0/src/L5_Cor/Data/test OR CMSSW_10_5_0/src/L5_Cor/MC/test

depending on you want to run on Data or MC, and run the python configuration file in the following way -

python JEC_MC_MINIAOD_cfg.py 

to check whether it works, and use

cmsRun -p JEC_MC_MINIAOD_cfg.py

to run the final code.
