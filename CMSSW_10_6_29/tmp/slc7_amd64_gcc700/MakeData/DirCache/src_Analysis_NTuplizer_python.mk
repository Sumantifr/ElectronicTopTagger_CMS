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
