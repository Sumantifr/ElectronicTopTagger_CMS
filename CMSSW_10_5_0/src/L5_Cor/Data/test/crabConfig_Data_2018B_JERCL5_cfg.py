from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'crab_L5JERC_SingleMuon_2018B_Autumn18_JECV19'
config.General.workArea = 'crab_L5JERC_SingleMuon_2018B_Autumn18_JECV19'
config.General.transferOutputs = True
config.General.transferLogs = True
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'JEC_Data_2018B_MINIAOD_cfg.py' 
config.JobType.inputFiles = ['Autumn18_RunB_V19_DATA','Autumn18_V7_MC_SF_AK8PFPuppi.txt','Autumn18_V7_MC_SF_AK4PFchs.txt','Autumn18_V7_MC_PtResolution_AK4PFchs.txt','Autumn18_V7_MC_PtResolution_AK8PFPuppi.txt']
config.JobType.disableAutomaticOutputCollection = True
config.JobType.outputFiles = ['hist_jerc_l5.root','rootuple_jerc_l5.root']
config.JobType.maxJobRuntimeMin = 2700
#config.JobType.maxMemoryMB = 2480
config.JobType.allowUndistributedCMSSW = True
config.Data.inputDataset = '/SingleMuon/Run2018B-17Sep2018-v1/MINIAOD'
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 10 
config.Data.lumiMask ='/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/ReReco/Cert_314472-325175_13TeV_17SeptEarlyReReco2018ABC_PromptEraD_Collisions18_JSON.txt'
#config.Data.runRange = '258214-258287' # '193093-194075'
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = False
#config.Data.publishDataName = 'May2015_Data_analysis'

config.Site.storageSite = 'T2_IN_TIFR'
#config.Site.whitelist = ["T2_IN_TIFR"]
