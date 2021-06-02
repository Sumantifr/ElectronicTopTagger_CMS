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
