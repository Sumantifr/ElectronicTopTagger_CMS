ifeq ($(strip $(testL5_CorMCTP)),)
testL5_CorMCTP := self/src/L5_Cor/MC/test
testL5_CorMCTP_files := $(patsubst src/L5_Cor/MC/test/%,%,$(foreach file,test_catch2_*.cc,$(eval xfile:=$(wildcard src/L5_Cor/MC/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/L5_Cor/MC/test/$(file). Please fix src/L5_Cor/MC/test/BuildFile.))))
testL5_CorMCTP_TEST_RUNNER_CMD :=  testL5_CorMCTP 
testL5_CorMCTP_BuildFile    := $(WORKINGDIR)/cache/bf/src/L5_Cor/MC/test/BuildFile
testL5_CorMCTP_LOC_USE := self  FWCore/TestProcessor catch2
testL5_CorMCTP_PACKAGE := self/src/L5_Cor/MC/test
ALL_PRODS += testL5_CorMCTP
testL5_CorMCTP_INIT_FUNC        += $$(eval $$(call Binary,testL5_CorMCTP,src/L5_Cor/MC/test,src_L5_Cor_MC_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
testL5_CorMCTP_CLASS := TEST
else
$(eval $(call MultipleWarningMsg,testL5_CorMCTP,src/L5_Cor/MC/test))
endif
ALL_COMMONRULES += src_L5_Cor_MC_test
src_L5_Cor_MC_test_parent := L5_Cor/MC
src_L5_Cor_MC_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_L5_Cor_MC_test,src/L5_Cor/MC/test,TEST))
