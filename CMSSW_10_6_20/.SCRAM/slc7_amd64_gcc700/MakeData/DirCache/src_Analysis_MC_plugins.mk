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
