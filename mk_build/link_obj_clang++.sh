cd build

#Link with Clang 	Program
clang++ -ggdb -std=c++11 -o c_and_d gautier_core.o gautier_interaction_console.o gautier_interaction.o gautier_interaction_sfml.o gautier_program_domain.o gautier_program_models.o gautier_program.o jsonlib.o -lsfml-graphics -lsfml-window -lsfml-system 

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
