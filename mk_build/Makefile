OBJ_DIR := obj
OBJ :=  $(OBJ_DIR)/jsoncpp.o $(OBJ_DIR)/gautier_core.o $(OBJ_DIR)/gautier_interaction_console.o $(OBJ_DIR)/gautier_interaction.o $(OBJ_DIR)/gautier_interaction_sfml.o $(OBJ_DIR)/gautier_program_domain.o $(OBJ_DIR)/gautier_program_models.o $(OBJ_DIR)/gautier_program.o

LIB_LOCAL := libsfml-system.so.2.2.0 libsfml-window.so.2.2.0 libsfml-graphics.so.2.2.0

CPP_MIN := -c -ggdb -std=c++11 -Wpedantic
CPP_MG := $(CPP_MIN) -fabi-version=0 -fcheck-new -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Wdouble-promotion -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wliteral-suffix -Wnarrowing -Wnoexcept -Wno-non-template-friend -Wno-unused-function -Wnon-virtual-dtor -Wno-pmf-conversions -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-aliasing=3 -Wstrict-null-sentinel -Wstrict-overflow=5 -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wuseless-cast 

INC_DAT := -I../src/data
INC_COR := -I../src/core
INC_VIZ := -I../src/interaction
INC_SFM := -I../../../liblocal

LIB_SFM_DIR := ../../../liblocal/libsfml_gcc
LIB_SFM := -lfreetype -lpthread -lX11 -lGLU -ljpeg -lsfml-graphics -lsfml-window -lsfml-system

ifeq ($(CXX),clang++)
	CPP_MG := -c -ggdb -std=c++11 -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5
	LIB_SFM_DIR := ../../../liblocal/libsfml_clang
endif


c_and_d : $(OBJ)
	$(CXX) -v -ggdb -std=c++11 -Wl,-rpath,'lib' -L$(LIB_SFM_DIR) -o $@ $(OBJ) $(LIB_SFM)

$(OBJ_DIR)/gautier_program.o: ../src/test/gautier_program.cpp \
 ../src/core/gautier_core.hpp \
 ../src/interaction/gautier_interaction_types.hpp \
 ../src/interaction/gautier_interaction.hpp \
 ../src/test/gautier_program_domain.hpp
	$(CXX) $(INC_DAT) $(INC_COR) $(INC_VIZ) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/gautier_program_domain.o: ../src/test/gautier_program_domain.cpp \
 ../src/data/json/json.h ../src/core/gautier_core.hpp \
 ../src/interaction/gautier_interaction_types.hpp \
 ../src/interaction/gautier_interaction.hpp \
 ../src/test/gautier_program_models.hpp \
 ../src/test/gautier_program_domain.hpp
	$(CXX) $(INC_DAT) $(INC_COR) $(INC_VIZ) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/gautier_program_models.o: ../src/test/gautier_program_models.cpp \
 ../src/data/json/json.h ../src/core/gautier_core.hpp \
 ../src/interaction/gautier_interaction_types.hpp \
 ../src/interaction/gautier_interaction.hpp \
 ../src/test/gautier_program_models.hpp
	$(CXX) $(INC_DAT) $(INC_COR) $(INC_VIZ) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/gautier_interaction.o: ../src/interaction/gautier_interaction.cpp \
 ../src/core/gautier_core.hpp \
 ../src/interaction/gautier_interaction_types.hpp \
 ../src/interaction/gautier_interaction.hpp \
 ../src/interaction/gautier_interaction_sfml.hpp
	$(CXX) $(INC_COR) $(INC_VIZ) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/gautier_interaction_console.o: \
 ../src/interaction/gautier_interaction_console.cpp \
 ../src/core/gautier_core.hpp \
 ../src/interaction/gautier_interaction_types.hpp \
 ../src/interaction/gautier_interaction_console.hpp
	$(CXX) $(INC_COR) $(INC_VIZ) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/gautier_interaction_sfml.o: \
 ../src/interaction/gautier_interaction_sfml.cpp \
 ../src/core/gautier_core.hpp \
 ../src/interaction/gautier_interaction_types.hpp \
 ../src/interaction/gautier_interaction_sfml.hpp
	$(CXX) $(INC_COR) $(INC_VIZ) $(INC_SFM) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/gautier_core.o: ../src/core/gautier_core.cpp ../src/core/gautier_core.hpp
	$(CXX) $(INC_COR) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/jsoncpp.o: ../src/data/jsoncpp.cpp ../src/data/json/json.h infrastructure
	$(CXX) $(CPP_MIN) -o $@ $< 

infrastructure: $(LIB_LOCAL)
	mkdir -p $(OBJ_DIR)

$(LIB_LOCAL) :
	mkdir -p lib
	cp --update $(LIB_SFM_DIR)/$@ lib/

#Copyright 2015 Michael Gautier

#Licensed under the Apache License, Version 2.0 (the "License");
#you may not use this file except in compliance with the License.
#You may obtain a copy of the License at

#http://www.apache.org/licenses/LICENSE-2.0

#Unless required by applicable law or agreed to in writing, software
#distributed under the License is distributed on an "AS IS" BASIS,
#WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#See the License for the specific language governing permissions and
#limitations under the License.
