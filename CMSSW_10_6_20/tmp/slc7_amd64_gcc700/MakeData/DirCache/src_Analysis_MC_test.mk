ifeq ($(strip $(testL5_CorMCTP)),)
testL5_CorMCTP := self/src/Analysis/MC/test
testL5_CorMCTP_files := $(patsubst src/Analysis/MC/test/%,%,$(foreach file,test_catch2_*.cc,$(eval xfile:=$(wildcard src/Analysis/MC/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/Analysis/MC/test/$(file). Please fix src/Analysis/MC/test/BuildFile.))))
testL5_CorMCTP_TEST_RUNNER_CMD :=  testL5_CorMCTP 
testL5_CorMCTP_BuildFile    := $(WORKINGDIR)/cache/bf/src/Analysis/MC/test/BuildFile
testL5_CorMCTP_LOC_USE := self  FWCore/TestProcessor catch2
testL5_CorMCTP_PACKAGE := self/src/Analysis/MC/test
ALL_PRODS += testL5_CorMCTP
testL5_CorMCTP_INIT_FUNC        += $$(eval $$(call Binary,testL5_CorMCTP,src/Analysis/MC/test,src_Analysis_MC_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
testL5_CorMCTP_CLASS := TEST
else
$(eval $(call MultipleWarningMsg,testL5_CorMCTP,src/Analysis/MC/test))
endif
ALL_COMMONRULES += src_Analysis_MC_test
src_Analysis_MC_test_parent := Analysis/MC
src_Analysis_MC_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Analysis_MC_test,src/Analysis/MC/test,TEST))
