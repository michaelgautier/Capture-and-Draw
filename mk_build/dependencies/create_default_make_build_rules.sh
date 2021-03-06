#Creates core build rules for a make file.

g++ -MM -I../src/core -I../src/data -I../src/interaction ../src/test/gautier_program.cpp > mkfdep.txt
g++ -MM -I../src/core -I../src/data -I../src/interaction ../src/test/gautier_program_domain.cpp >> mkfdep.txt
g++ -MM -I../src/core -I../src/data -I../src/interaction ../src/test/gautier_program_models.cpp >> mkfdep.txt

g++ -MM -I../src/core ../src/interaction/gautier_interaction.cpp >> mkfdep.txt
g++ -MM -I../src/core ../src/interaction/gautier_interaction_console.cpp >> mkfdep.txt
g++ -MM -I../src/core ../src/interaction/gautier_interaction_sfml.cpp >> mkfdep.txt

g++ -MM ../src/core/gautier_core.cpp >> mkfdep.txt

g++ -MM ../src/data/jsoncpp.cpp >> mkfdep.txt

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
