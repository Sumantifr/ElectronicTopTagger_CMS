ALL_SUBSYSTEMS+=Analysis
subdirs_src_Analysis = src_Analysis_Data src_Analysis_MC
ALL_PACKAGES += Analysis/Data
subdirs_src_Analysis_Data := src_Analysis_Data_plugins src_Analysis_Data_python src_Analysis_Data_test
ifeq ($(strip $(PyAnalysisData)),)
PyAnalysisData := self/src/Analysis/Data/python
src_Analysis_Data_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Analysis/Data/python)
PyAnalysisData_files := $(patsubst src/Analysis/Data/python/%,%,$(wildcard $(foreach dir,src/Analysis/Data/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyAnalysisData_LOC_USE := self  
PyAnalysisData_PACKAGE := self/src/Analysis/Data/python
ALL_PRODS += PyAnalysisData
PyAnalysisData_INIT_FUNC        += $$(eval $$(call PythonProduct,PyAnalysisData,src/Analysis/Data/python,src_Analysis_Data_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyAnalysisData,src/Analysis/Data/python))
endif
ALL_COMMONRULES += src_Analysis_Data_python
src_Analysis_Data_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Analysis_Data_python,src/Analysis/Data/python,PYTHON))
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
ALL_PACKAGES += Analysis/MC
subdirs_src_Analysis_MC := src_Analysis_MC_plugins src_Analysis_MC_python src_Analysis_MC_test
ifeq ($(strip $(PyAnalysisMC)),)
PyAnalysisMC := self/src/Analysis/MC/python
src_Analysis_MC_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Analysis/MC/python)
PyAnalysisMC_files := $(patsubst src/Analysis/MC/python/%,%,$(wildcard $(foreach dir,src/Analysis/MC/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyAnalysisMC_LOC_USE := self  
PyAnalysisMC_PACKAGE := self/src/Analysis/MC/python
ALL_PRODS += PyAnalysisMC
PyAnalysisMC_INIT_FUNC        += $$(eval $$(call PythonProduct,PyAnalysisMC,src/Analysis/MC/python,src_Analysis_MC_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyAnalysisMC,src/Analysis/MC/python))
endif
ALL_COMMONRULES += src_Analysis_MC_python
src_Analysis_MC_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Analysis_MC_python,src/Analysis/MC/python,PYTHON))
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
