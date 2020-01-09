ALL_SUBSYSTEMS+=L5_Cor
subdirs_src_L5_Cor = src_L5_Cor_Data src_L5_Cor_MC
ALL_PACKAGES += L5_Cor/Data
subdirs_src_L5_Cor_Data := src_L5_Cor_Data_plugins src_L5_Cor_Data_python src_L5_Cor_Data_test
ifeq ($(strip $(PyL5_CorData)),)
PyL5_CorData := self/src/L5_Cor/Data/python
src_L5_Cor_Data_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/L5_Cor/Data/python)
PyL5_CorData_files := $(patsubst src/L5_Cor/Data/python/%,%,$(wildcard $(foreach dir,src/L5_Cor/Data/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyL5_CorData_LOC_USE := self  
PyL5_CorData_PACKAGE := self/src/L5_Cor/Data/python
ALL_PRODS += PyL5_CorData
PyL5_CorData_INIT_FUNC        += $$(eval $$(call PythonProduct,PyL5_CorData,src/L5_Cor/Data/python,src_L5_Cor_Data_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyL5_CorData,src/L5_Cor/Data/python))
endif
ALL_COMMONRULES += src_L5_Cor_Data_python
src_L5_Cor_Data_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_L5_Cor_Data_python,src/L5_Cor/Data/python,PYTHON))
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
ALL_PACKAGES += L5_Cor/MC
subdirs_src_L5_Cor_MC := src_L5_Cor_MC_plugins src_L5_Cor_MC_python src_L5_Cor_MC_test
ifeq ($(strip $(PyL5_CorMC)),)
PyL5_CorMC := self/src/L5_Cor/MC/python
src_L5_Cor_MC_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/L5_Cor/MC/python)
PyL5_CorMC_files := $(patsubst src/L5_Cor/MC/python/%,%,$(wildcard $(foreach dir,src/L5_Cor/MC/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyL5_CorMC_LOC_USE := self  
PyL5_CorMC_PACKAGE := self/src/L5_Cor/MC/python
ALL_PRODS += PyL5_CorMC
PyL5_CorMC_INIT_FUNC        += $$(eval $$(call PythonProduct,PyL5_CorMC,src/L5_Cor/MC/python,src_L5_Cor_MC_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyL5_CorMC,src/L5_Cor/MC/python))
endif
ALL_COMMONRULES += src_L5_Cor_MC_python
src_L5_Cor_MC_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_L5_Cor_MC_python,src/L5_Cor/MC/python,PYTHON))
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
