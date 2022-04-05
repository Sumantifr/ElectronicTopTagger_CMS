ifeq ($(strip $(AnalysisNTuplizerAuto)),)
AnalysisNTuplizerAuto := self/src/Analysis/NTuplizer/plugins
PLUGINS:=yes
AnalysisNTuplizerAuto_files := $(patsubst src/Analysis/NTuplizer/plugins/%,%,$(wildcard $(foreach dir,src/Analysis/NTuplizer/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
AnalysisNTuplizerAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/Analysis/NTuplizer/plugins/BuildFile
AnalysisNTuplizerAuto_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/ParticleFlowCandidate DataFormats/JetReco DataFormats/METReco CommonTools/UtilAlgos CommonTools/RecoAlgos DataFormats/CLHEP DataFormats/Common DataFormats/Candidate DataFormats/HLTReco JetMETCorrections/JetCorrector FWCore/Common DataFormats/HcalRecHit DataFormats/EgammaCandidates DataFormats/MuonReco DataFormats/VertexReco DataFormats/HcalDigi DataFormats/HcalDetId CalibFormats/HcalObjects DPGAnalysis/Skims GeneratorInterface/Pythia8Interface root RecoEgamma/EgammaTools JetMETCorrections/Modules DataFormats/PatCandidates CondFormats/JetMETObjects SimDataFormats/GeneratorProducts CondFormats/BTauObjects CondTools/BTau fastjet fastjet-contrib
AnalysisNTuplizerAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,AnalysisNTuplizerAuto,AnalysisNTuplizerAuto,$(SCRAMSTORENAME_LIB),src/Analysis/NTuplizer/plugins))
AnalysisNTuplizerAuto_PACKAGE := self/src/Analysis/NTuplizer/plugins
ALL_PRODS += AnalysisNTuplizerAuto
Analysis/NTuplizer_forbigobj+=AnalysisNTuplizerAuto
AnalysisNTuplizerAuto_INIT_FUNC        += $$(eval $$(call Library,AnalysisNTuplizerAuto,src/Analysis/NTuplizer/plugins,src_Analysis_NTuplizer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
AnalysisNTuplizerAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,AnalysisNTuplizerAuto,src/Analysis/NTuplizer/plugins))
endif
ALL_COMMONRULES += src_Analysis_NTuplizer_plugins
src_Analysis_NTuplizer_plugins_parent := Analysis/NTuplizer
src_Analysis_NTuplizer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Analysis_NTuplizer_plugins,src/Analysis/NTuplizer/plugins,PLUGINS))
