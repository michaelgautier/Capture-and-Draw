cd build

#Link with Clang 	Program
clang++ -ggdb -std=c++11 -o c_and_d jsonlib.o gautier_interaction_console.o gautier_interaction_sfml.o gautier_interaction.o gautier_program_models.o gautier_program_domain.o gautier_program.o -lsfml-graphics -lsfml-window -lsfml-system 

