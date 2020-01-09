ifeq ($(strip $(testL5_CorDataTP)),)
testL5_CorDataTP := self/src/L5_Cor/Data/test
testL5_CorDataTP_files := $(patsubst src/L5_Cor/Data/test/%,%,$(foreach file,test_catch2_*.cc,$(eval xfile:=$(wildcard src/L5_Cor/Data/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/L5_Cor/Data/test/$(file). Please fix src/L5_Cor/Data/test/BuildFile.))))
testL5_CorDataTP_TEST_RUNNER_CMD :=  testL5_CorDataTP 
testL5_CorDataTP_BuildFile    := $(WORKINGDIR)/cache/bf/src/L5_Cor/Data/test/BuildFile
testL5_CorDataTP_LOC_USE := self  FWCore/TestProcessor catch2
testL5_CorDataTP_PACKAGE := self/src/L5_Cor/Data/test
ALL_PRODS += testL5_CorDataTP
testL5_CorDataTP_INIT_FUNC        += $$(eval $$(call Binary,testL5_CorDataTP,src/L5_Cor/Data/test,src_L5_Cor_Data_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
testL5_CorDataTP_CLASS := TEST
else
$(eval $(call MultipleWarningMsg,testL5_CorDataTP,src/L5_Cor/Data/test))
endif
ALL_COMMONRULES += src_L5_Cor_Data_test
src_L5_Cor_Data_test_parent := L5_Cor/Data
src_L5_Cor_Data_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_L5_Cor_Data_test,src/L5_Cor/Data/test,TEST))
