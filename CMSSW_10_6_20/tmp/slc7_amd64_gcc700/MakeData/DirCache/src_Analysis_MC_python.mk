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
