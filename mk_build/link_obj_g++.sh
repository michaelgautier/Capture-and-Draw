cd build

#Link with GCC 		Program
g++ -ggdb -std=c++11 -o c_and_d gautier_json_mapping.o gautier_program_models.o jsonlib.o gautier_interaction_console.o gautier_interaction_sfml.o gautier_interaction.o gautier_program_domain.o gautier_program.o gautier_main.o -lsfml-graphics -lsfml-window -lsfml-system 

