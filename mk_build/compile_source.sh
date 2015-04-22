rm -r build
mkdir build

#./compile_source_clang++.sh
./compile_source_g++.sh

mv ../*.o build/

ls -l build/.

