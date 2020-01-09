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
