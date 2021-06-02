ifeq ($(strip $(AnalysisDataAuto)),)
AnalysisDataAuto := self/src/Analysis/Data/plugins
PLUGINS:=yes
AnalysisDataAuto_files := $(patsubst src/Analysis/Data/plugins/%,%,$(wildcard $(foreach dir,src/Analysis/Data/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
AnalysisDataAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/Analysis/Data/plugins/BuildFile
AnalysisDataAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/ParticleFlowCandidate DataFormats/JetReco DataFormats/METReco CommonTools/UtilAlgos CommonTools/RecoAlgos DataFormats/CLHEP DataFormats/Common DataFormats/Candidate DataFormats/HLTReco JetMETCorrections/JetCorrector FWCore/Common DataFormats/HcalRecHit DataFormats/EgammaCandidates DataFormats/MuonReco DataFormats/VertexReco DataFormats/HcalDigi DataFormats/HcalDetId CalibFormats/HcalObjects DPGAnalysis/Skims GeneratorInterface/Pythia8Interface root RecoEgamma/EgammaTools JetMETCorrections/Modules DataFormats/PatCandidates CondFormats/JetMETObjects SimDataFormats/GeneratorProducts fastjet fastjet-contrib
AnalysisDataAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,AnalysisDataAuto,AnalysisDataAuto,$(SCRAMSTORENAME_LIB),src/Analysis/Data/plugins))
AnalysisDataAuto_PACKAGE := self/src/Analysis/Data/plugins
ALL_PRODS += AnalysisDataAuto
Analysis/Data_forbigobj+=AnalysisDataAuto
AnalysisDataAuto_INIT_FUNC        += $$(eval $$(call Library,AnalysisDataAuto,src/Analysis/Data/plugins,src_Analysis_Data_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
AnalysisDataAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,AnalysisDataAuto,src/Analysis/Data/plugins))
endif
ALL_COMMONRULES += src_Analysis_Data_plugins
src_Analysis_Data_plugins_parent := Analysis/Data
src_Analysis_Data_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Analysis_Data_plugins,src/Analysis/Data/plugins,PLUGINS))
ifeq ($(strip $(AnalysisMCAuto)),)
AnalysisMCAuto := self/src/Analysis/MC/plugins
PLUGINS:=yes
AnalysisMCAuto_files := $(patsubst src/Analysis/MC/plugins/%,%,$(wildcard $(foreach dir,src/Analysis/MC/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
AnalysisMCAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/Analysis/MC/plugins/BuildFile
AnalysisMCAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/TrackReco
AnalysisMCAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,AnalysisMCAuto,AnalysisMCAuto,$(SCRAMSTORENAME_LIB),src/Analysis/MC/plugins))
AnalysisMCAuto_PACKAGE := self/src/Analysis/MC/plugins
ALL_PRODS += AnalysisMCAuto
Analysis/MC_forbigobj+=AnalysisMCAuto
AnalysisMCAuto_INIT_FUNC        += $$(eval $$(call Library,AnalysisMCAuto,src/Analysis/MC/plugins,src_Analysis_MC_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
AnalysisMCAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,AnalysisMCAuto,src/Analysis/MC/plugins))
endif
ALL_COMMONRULES += src_Analysis_MC_plugins
src_Analysis_MC_plugins_parent := Analysis/MC
src_Analysis_MC_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Analysis_MC_plugins,src/Analysis/MC/plugins,PLUGINS))