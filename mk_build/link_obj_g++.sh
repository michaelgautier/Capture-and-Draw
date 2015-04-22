cd ..

mkdir build
rm build/c_and_d

#Link with GCC 		Program
g++ -ggdb -std=c++11 -o build/c_and_d build/gautier_json_mapping.o build/gautier_program_models.o build/jsonlib.o build/gautier_interaction_console.o build/gautier_interaction_sfml.o build/gautier_interaction.o build/gautier_program_domain.o build/gautier_program.o build/gautier_main.o -lsfml-graphics -lsfml-window -lsfml-system 

ls -l build/.


