ifeq ($(strip $(testAnalysisNTuplizerTP)),)
testAnalysisNTuplizerTP := self/src/Analysis/NTuplizer/test
testAnalysisNTuplizerTP_files := $(patsubst src/Analysis/NTuplizer/test/%,%,$(foreach file,test_catch2_*.cc,$(eval xfile:=$(wildcard src/Analysis/NTuplizer/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/Analysis/NTuplizer/test/$(file). Please fix src/Analysis/NTuplizer/test/BuildFile.))))
testAnalysisNTuplizerTP_TEST_RUNNER_CMD :=  testAnalysisNTuplizerTP 
testAnalysisNTuplizerTP_BuildFile    := $(WORKINGDIR)/cache/bf/src/Analysis/NTuplizer/test/BuildFile
testAnalysisNTuplizerTP_LOC_USE := self  FWCore/TestProcessor catch2
testAnalysisNTuplizerTP_PACKAGE := self/src/Analysis/NTuplizer/test
ALL_PRODS += testAnalysisNTuplizerTP
testAnalysisNTuplizerTP_INIT_FUNC        += $$(eval $$(call Binary,testAnalysisNTuplizerTP,src/Analysis/NTuplizer/test,src_Analysis_NTuplizer_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
testAnalysisNTuplizerTP_CLASS := TEST
else
$(eval $(call MultipleWarningMsg,testAnalysisNTuplizerTP,src/Analysis/NTuplizer/test))
endif
ALL_COMMONRULES += src_Analysis_NTuplizer_test
src_Analysis_NTuplizer_test_parent := Analysis/NTuplizer
src_Analysis_NTuplizer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Analysis_NTuplizer_test,src/Analysis/NTuplizer/test,TEST))
