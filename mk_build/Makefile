dot := .
space := " "

#Directories
LIB_LOCAL_DIR := ../../../liblocal
LIB_SFM_DIR := $(LIB_LOCAL_DIR)/libsfml_gcc
LIB_JSONCPP_DIR := $(LIB_LOCAL_DIR)/libjson_gcc
SRC_DIR = ../src
OBJ_DIR := obj
LIB_DIR := lib

#Includes
INC_COR := $(SRC_DIR)/core
INC_VIZ := $(SRC_DIR)/interaction
INC_SFM := $(LIB_LOCAL_DIR)
INC_JSON := $(LIB_LOCAL_DIR)/JSONCpp
INC_SYS := $(LIB_LOCAL_DIR)

#Compiled Objects
OBJ :=  $(OBJ_DIR)/jsoncpp.o $(OBJ_DIR)/gautier_core.o $(OBJ_DIR)/gautier_interaction_console.o $(OBJ_DIR)/gautier_interaction.o $(OBJ_DIR)/gautier_interaction_sfml.o $(OBJ_DIR)/gautier_program_domain.o $(OBJ_DIR)/gautier_program_models.o $(OBJ_DIR)/gautier_program.o

#Compiler parameters. Minimum standard.
CPP_MIN := -c -ggdb -std=c++11 -Wpedantic -Wno-system-headers 

#Compiler parameters. Debug
CPP_MG := $(CPP_MIN) -fabi-version=0 -fcheck-new -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Wdouble-promotion -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wliteral-suffix -Wnarrowing -Wnoexcept -Wno-non-template-friend -Wno-unused-function -Wnon-virtual-dtor -Wno-pmf-conversions -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-aliasing=3 -Wstrict-null-sentinel -Wstrict-overflow=5 -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wuseless-cast 

#Shared and/or Static Libraries
LIB_SFML_VER := 2.2.0
LIB_SFML := libsfml-system.so libsfml-window.so libsfml-graphics.so

#Linker parameters
LIB_LINK := -l freetype -l pthread -l X11 -l GLU -l jpeg -l sfml-graphics -l sfml-window -l sfml-system

#Parameter and source values updates
ifeq ($(CXX),clang++)
	CPP_MG := -c -ggdb -std=c++11 -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5
	LIB_SFM_DIR := ../../../liblocal/libsfml_clang
	LIB_JSONCPP_DIR := $(LIB_LOCAL_DIR)/libjson_clang
endif

#---------------------------------------------------------------------------------------------START

#Build the program
c_and_d : $(OBJ)
	$(CXX) -v -ggdb -std=c++11 -Wl,-rpath,'lib' -L$(LIB_SFM_DIR) -o $@ $(OBJ) $(LIB_LINK)

#Build the object files
$(OBJ_DIR)/gautier_program.o: $(SRC_DIR)/test/gautier_program.cpp \
 $(SRC_DIR)/core/gautier_core.hpp \
 $(SRC_DIR)/interaction/gautier_interaction_types.hpp \
 $(SRC_DIR)/interaction/gautier_interaction.hpp \
 $(SRC_DIR)/test/gautier_program_domain.hpp
	$(CXX) -I$(INC_JSON) -I$(INC_COR) -I$(INC_VIZ) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/gautier_program_domain.o: $(SRC_DIR)/test/gautier_program_domain.cpp \
 $(INC_JSON)/json/json.h $(SRC_DIR)/core/gautier_core.hpp \
 $(SRC_DIR)/interaction/gautier_interaction_types.hpp \
 $(SRC_DIR)/interaction/gautier_interaction.hpp \
 $(SRC_DIR)/test/gautier_program_models.hpp \
 $(SRC_DIR)/test/gautier_program_domain.hpp
	$(CXX) -I$(INC_JSON) -isystem$(INC_JSON) -I$(INC_COR) -I$(INC_VIZ) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/gautier_program_models.o: $(SRC_DIR)/test/gautier_program_models.cpp \
 $(INC_JSON)/json/json.h $(SRC_DIR)/core/gautier_core.hpp \
 $(SRC_DIR)/interaction/gautier_interaction_types.hpp \
 $(SRC_DIR)/interaction/gautier_interaction.hpp \
 $(SRC_DIR)/test/gautier_program_models.hpp
	$(CXX) -I$(INC_JSON) -isystem$(INC_JSON) -I$(INC_COR) -I$(INC_VIZ) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/gautier_interaction.o: $(SRC_DIR)/interaction/gautier_interaction.cpp \
 $(SRC_DIR)/core/gautier_core.hpp \
 $(SRC_DIR)/interaction/gautier_interaction_types.hpp \
 $(SRC_DIR)/interaction/gautier_interaction.hpp \
 $(SRC_DIR)/interaction/gautier_interaction_sfml.hpp
	$(CXX) -I$(INC_COR) -I$(INC_VIZ) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/gautier_interaction_console.o: \
 $(SRC_DIR)/interaction/gautier_interaction_console.cpp \
 $(SRC_DIR)/core/gautier_core.hpp \
 $(SRC_DIR)/interaction/gautier_interaction_types.hpp \
 $(SRC_DIR)/interaction/gautier_interaction_console.hpp
	$(CXX) -I$(INC_COR) -I$(INC_VIZ) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/gautier_interaction_sfml.o: \
 $(SRC_DIR)/interaction/gautier_interaction_sfml.cpp \
 $(SRC_DIR)/core/gautier_core.hpp \
 $(SRC_DIR)/interaction/gautier_interaction_types.hpp \
 $(SRC_DIR)/interaction/gautier_interaction_sfml.hpp
	$(CXX) -I$(INC_COR) -I$(INC_VIZ) -I$(INC_SFM) -isystem$(INC_SYS) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/gautier_core.o: $(SRC_DIR)/core/gautier_core.cpp $(SRC_DIR)/core/gautier_core.hpp 
	$(CXX) -I$(INC_COR) $(CPP_MG) -o $@ $< 

$(OBJ_DIR)/jsoncpp.o : infrastructure_build
	cp --update $(LIB_JSONCPP_DIR)/jsoncpp.o $(OBJ_DIR)/

#Setup prerequisite directories and files.
infrastructure_build: $(LIB_SFML) $(LIB_JSONCPP_DIR)/jsoncpp.o
	mkdir -p $(OBJ_DIR)

$(LIB_SFML) : infrastructure_run
	cp --update $(LIB_SFM_DIR)/$@.$(LIB_SFML_VER) lib/
	rm -rf lib/$@.$(firstword $(subst $(dot), $(space),$(LIB_SFML_VER)))
	ln -s 	$@.$(LIB_SFML_VER) lib/$@.$(firstword $(subst $(dot), $(space),$(LIB_SFML_VER)))

infrastructure_run : 
	mkdir -p lib

.PHONY : clean

clean : 
	rm -rf obj/
	rm -rf lib/
	rm -f c_and_d

#---------------------------------------------------------------------------------------------END

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
