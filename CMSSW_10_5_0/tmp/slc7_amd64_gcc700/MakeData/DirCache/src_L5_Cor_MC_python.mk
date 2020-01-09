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
