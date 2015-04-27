cd ..

#Build with G++ 	JSONCpp		Third-party code, go easy on the compile
#compile the header for troubleshooting
#g++ -ggdb -std=c++11 -Wpedantic json/json.h

#third party libraries
g++ -c -ggdb -std=c++11 -Wpedantic -o jsonlib.o src/jsoncpp.cpp

#Build implementations

#common library
g++ -c -ggdb -std=c++11 -Wpedantic -fabi-version=0 -fcheck-new -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Wdouble-promotion -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wliteral-suffix -Wnarrowing -Wnoexcept -Wno-non-template-friend -Wno-unused-function -Wnon-virtual-dtor -Wno-pmf-conversions -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-aliasing=3 -Wstrict-null-sentinel -Wstrict-overflow=5 -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wuseless-cast -o gautier_core.o src/gautier_core.cpp

#interaction library
g++ -c -ggdb -std=c++11 -Wpedantic -fabi-version=0 -fcheck-new -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Wdouble-promotion -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wliteral-suffix -Wnarrowing -Wnoexcept -Wno-non-template-friend -Wno-unused-function -Wnon-virtual-dtor -Wno-pmf-conversions -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-aliasing=3 -Wstrict-null-sentinel -Wstrict-overflow=5 -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wuseless-cast -o gautier_interaction.o src/gautier_interaction.cpp
g++ -c -ggdb -std=c++11 -Wpedantic -fabi-version=0 -fcheck-new -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Wdouble-promotion -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wliteral-suffix -Wnarrowing -Wnoexcept -Wno-non-template-friend -Wno-unused-function -Wnon-virtual-dtor -Wno-pmf-conversions -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-aliasing=3 -Wstrict-null-sentinel -Wstrict-overflow=5 -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wuseless-cast -o gautier_interaction_console.o src/gautier_interaction_console.cpp
g++ -c -ggdb -std=c++11 -Wpedantic -fabi-version=0 -fcheck-new -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Wdouble-promotion -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wliteral-suffix -Wnarrowing -Wnoexcept -Wno-non-template-friend -Wno-unused-function -Wnon-virtual-dtor -Wno-pmf-conversions -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-aliasing=3 -Wstrict-null-sentinel -Wstrict-overflow=5 -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wuseless-cast -o gautier_interaction_sfml.o src/gautier_interaction_sfml.cpp

#demo program
g++ -c -ggdb -std=c++11 -Wpedantic -fabi-version=0 -fcheck-new -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Wdouble-promotion -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wliteral-suffix -Wnarrowing -Wnoexcept -Wno-non-template-friend -Wno-unused-function -Wnon-virtual-dtor -Wno-pmf-conversions -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-aliasing=3 -Wstrict-null-sentinel -Wstrict-overflow=5 -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wuseless-cast -o gautier_program_domain.o src/gautier_program_domain.cpp
g++ -c -ggdb -std=c++11 -Wpedantic -fabi-version=0 -fcheck-new -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Wdouble-promotion -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wliteral-suffix -Wnarrowing -Wnoexcept -Wno-non-template-friend -Wno-unused-function -Wnon-virtual-dtor -Wno-pmf-conversions -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-aliasing=3 -Wstrict-null-sentinel -Wstrict-overflow=5 -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wuseless-cast -o gautier_program_models.o src/gautier_program_models.cpp
g++ -c -ggdb -std=c++11 -Wpedantic -fabi-version=0 -fcheck-new -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Wdouble-promotion -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wliteral-suffix -Wnarrowing -Wnoexcept -Wno-non-template-friend -Wno-unused-function -Wnon-virtual-dtor -Wno-pmf-conversions -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-aliasing=3 -Wstrict-null-sentinel -Wstrict-overflow=5 -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wuseless-cast -o gautier_program.o src/gautier_program.cpp

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
