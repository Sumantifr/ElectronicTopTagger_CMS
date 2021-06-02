ifeq ($(strip $(testAnalysisDataTP)),)
testAnalysisDataTP := self/src/Analysis/Data/test
testAnalysisDataTP_files := $(patsubst src/Analysis/Data/test/%,%,$(foreach file,test_catch2_*.cc,$(eval xfile:=$(wildcard src/Analysis/Data/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/Analysis/Data/test/$(file). Please fix src/Analysis/Data/test/BuildFile.))))
testAnalysisDataTP_TEST_RUNNER_CMD :=  testAnalysisDataTP 
testAnalysisDataTP_BuildFile    := $(WORKINGDIR)/cache/bf/src/Analysis/Data/test/BuildFile
testAnalysisDataTP_LOC_USE := self  FWCore/TestProcessor catch2
testAnalysisDataTP_PACKAGE := self/src/Analysis/Data/test
ALL_PRODS += testAnalysisDataTP
testAnalysisDataTP_INIT_FUNC        += $$(eval $$(call Binary,testAnalysisDataTP,src/Analysis/Data/test,src_Analysis_Data_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
testAnalysisDataTP_CLASS := TEST
else
$(eval $(call MultipleWarningMsg,testAnalysisDataTP,src/Analysis/Data/test))
endif
ALL_COMMONRULES += src_Analysis_Data_test
src_Analysis_Data_test_parent := Analysis/Data
src_Analysis_Data_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Analysis_Data_test,src/Analysis/Data/test,TEST))
