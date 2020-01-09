ifeq ($(strip $(L5_CorDataAuto)),)
L5_CorDataAuto := self/src/L5_Cor/Data/plugins
PLUGINS:=yes
L5_CorDataAuto_files := $(patsubst src/L5_Cor/Data/plugins/%,%,$(wildcard $(foreach dir,src/L5_Cor/Data/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
L5_CorDataAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/L5_Cor/Data/plugins/BuildFile
L5_CorDataAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/ParticleFlowCandidate DataFormats/JetReco DataFormats/METReco CommonTools/UtilAlgos CommonTools/RecoAlgos DataFormats/CLHEP DataFormats/Common DataFormats/Candidate DataFormats/HLTReco JetMETCorrections/JetCorrector FWCore/Common DataFormats/HcalRecHit DataFormats/EgammaCandidates DataFormats/MuonReco DataFormats/VertexReco DataFormats/HcalDigi DataFormats/HcalDetId CalibFormats/HcalObjects DPGAnalysis/Skims GeneratorInterface/Pythia8Interface root JetMETCorrections/Modules DataFormats/PatCandidates CondFormats/JetMETObjects SimDataFormats/GeneratorProducts fastjet fastjet-contrib
L5_CorDataAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,L5_CorDataAuto,L5_CorDataAuto,$(SCRAMSTORENAME_LIB),src/L5_Cor/Data/plugins))
L5_CorDataAuto_PACKAGE := self/src/L5_Cor/Data/plugins
ALL_PRODS += L5_CorDataAuto
L5_Cor/Data_forbigobj+=L5_CorDataAuto
L5_CorDataAuto_INIT_FUNC        += $$(eval $$(call Library,L5_CorDataAuto,src/L5_Cor/Data/plugins,src_L5_Cor_Data_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
L5_CorDataAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,L5_CorDataAuto,src/L5_Cor/Data/plugins))
endif
ALL_COMMONRULES += src_L5_Cor_Data_plugins
src_L5_Cor_Data_plugins_parent := L5_Cor/Data
src_L5_Cor_Data_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_L5_Cor_Data_plugins,src/L5_Cor/Data/plugins,PLUGINS))
ifeq ($(strip $(L5_CorMCAuto)),)
L5_CorMCAuto := self/src/L5_Cor/MC/plugins
PLUGINS:=yes
L5_CorMCAuto_files := $(patsubst src/L5_Cor/MC/plugins/%,%,$(wildcard $(foreach dir,src/L5_Cor/MC/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
L5_CorMCAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/L5_Cor/MC/plugins/BuildFile
L5_CorMCAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/TrackReco
L5_CorMCAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,L5_CorMCAuto,L5_CorMCAuto,$(SCRAMSTORENAME_LIB),src/L5_Cor/MC/plugins))
L5_CorMCAuto_PACKAGE := self/src/L5_Cor/MC/plugins
ALL_PRODS += L5_CorMCAuto
L5_Cor/MC_forbigobj+=L5_CorMCAuto
L5_CorMCAuto_INIT_FUNC        += $$(eval $$(call Library,L5_CorMCAuto,src/L5_Cor/MC/plugins,src_L5_Cor_MC_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
L5_CorMCAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,L5_CorMCAuto,src/L5_Cor/MC/plugins))
endif
ALL_COMMONRULES += src_L5_Cor_MC_plugins
src_L5_Cor_MC_plugins_parent := L5_Cor/MC
src_L5_Cor_MC_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_L5_Cor_MC_plugins,src/L5_Cor/MC/plugins,PLUGINS))
