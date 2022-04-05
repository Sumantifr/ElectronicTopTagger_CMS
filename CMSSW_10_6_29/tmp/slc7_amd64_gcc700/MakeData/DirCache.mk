ALL_SUBSYSTEMS+=Analysis
subdirs_src_Analysis = src_Analysis_NTuplizer
ALL_PACKAGES += Analysis/NTuplizer
subdirs_src_Analysis_NTuplizer := src_Analysis_NTuplizer_plugins src_Analysis_NTuplizer_python src_Analysis_NTuplizer_test
ifeq ($(strip $(PyAnalysisNTuplizer)),)
PyAnalysisNTuplizer := self/src/Analysis/NTuplizer/python
src_Analysis_NTuplizer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Analysis/NTuplizer/python)
PyAnalysisNTuplizer_files := $(patsubst src/Analysis/NTuplizer/python/%,%,$(wildcard $(foreach dir,src/Analysis/NTuplizer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyAnalysisNTuplizer_LOC_USE := self  
PyAnalysisNTuplizer_PACKAGE := self/src/Analysis/NTuplizer/python
ALL_PRODS += PyAnalysisNTuplizer
PyAnalysisNTuplizer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyAnalysisNTuplizer,src/Analysis/NTuplizer/python,src_Analysis_NTuplizer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyAnalysisNTuplizer,src/Analysis/NTuplizer/python))
endif
ALL_COMMONRULES += src_Analysis_NTuplizer_python
src_Analysis_NTuplizer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Analysis_NTuplizer_python,src/Analysis/NTuplizer/python,PYTHON))
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
