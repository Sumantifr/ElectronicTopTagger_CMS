from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'crab_L5JERC_QCD_BEnriched_MG_100to200_CP5_Autumn18_JECV19'
config.General.workArea = 'crab_L5JERC_QCD_MG_BEnriched_100to200_CP5_Autumn18_JECV19'
config.General.transferOutputs = True
config.General.transferLogs = True
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'JEC_MC_MINIAOD_cfg.py' ##'Run_QCD_test_data-cfg.py'
config.JobType.inputFiles = ['Autumn18_V19_MC','Autumn18_V7_MC_SF_AK8PFPuppi.txt','Autumn18_V7_MC_SF_AK4PFchs.txt','Autumn18_V7_MC_PtResolution_AK4PFchs.txt','Autumn18_V7_MC_PtResolution_AK8PFPuppi.txt']
config.JobType.disableAutomaticOutputCollection = True
config.JobType.outputFiles = ['hist_jerc_l5.root','rootuple_jerc_l5.root']
#config.JobType.maxJobRuntimeMin = 2700
#config.JobType.maxMemoryMB = 2480
config.JobType.allowUndistributedCMSSW = True
config.Data.inputDataset = '/QCD_bEnriched_HT100to200_TuneCP5_13TeV-madgraph-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM'
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 5
#config.Data.lumiMask ='/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Reprocessing/Cert_13TeV_16Dec2015ReReco_Collisions15_25ns_JSON_v2.txt'
#config.Data.runRange = '258214-258287' # '193093-194075'
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = False
#config.Data.publishDataName = 'May2015_Data_analysis'

config.Site.storageSite = 'T2_IN_TIFR'
#config.Site.whitelist = ["T2_IN_TIFR"]
