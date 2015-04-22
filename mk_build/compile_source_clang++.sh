cd ..

#Build with clang++ 	JSONCpp		Third-party code, go easy on the compile
#compile the header for troubleshooting
#clang++ -ggdb -std=c++11 -Wpedantic json/json.h
clang++ -c -ggdb -std=c++11 -Wpedantic -o jsonlib.o src/jsoncpp.cpp

#Build with clang++ 	Program
#Build headers to troubleshoot

#clang++ -c -ggdb -std=c++11 -x none -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 src/gautier_core.hpp
#clang++ -c -ggdb -std=c++11 -x none -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 src/gautier_interaction_console.hpp
#clang++ -c -ggdb -std=c++11 -x none -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 src/gautier_interaction.hpp
#clang++ -c -ggdb -std=c++11 -x none -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 src/gautier_interaction_sfml.hpp
#clang++ -c -ggdb -std=c++11 -x none -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 src/gautier_interaction_types.hpp
#clang++ -c -ggdb -std=c++11 -x none -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 src/gautier_program_domain.hpp
#clang++ -c -ggdb -std=c++11 -x none -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 src/gautier_program_models.hpp

#Build implementations
clang++ -c -ggdb -std=c++11 -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 -o gautier_interaction_console.o src/gautier_interaction_console.cpp
clang++ -c -ggdb -std=c++11 -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 -o gautier_interaction.o src/gautier_interaction.cpp
clang++ -c -ggdb -std=c++11 -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 -o gautier_interaction_sfml.o src/gautier_interaction_sfml.cpp
clang++ -c -ggdb -std=c++11 -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 -o gautier_program.o src/gautier_program.cpp
clang++ -c -ggdb -std=c++11 -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 -o gautier_program_domain.o src/gautier_program_domain.cpp
clang++ -c -ggdb -std=c++11 -Wpedantic -fconstexpr-depth=512 -ffor-scope -fstrict-aliasing -fstrict-overflow -fvisibility-inlines-hidden -Wabi -Wall -Wcast-align -Wcast-qual -Wconversion -Wconversion-null -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Weffc++ -Wextra -Wfloat-equal -Wformat=2 -Wnarrowing -Wno-unused-function -Wnon-virtual-dtor -Wno-system-headers -Wold-style-cast -Woverloaded-virtual -Wreorder -Wshadow -Wsign-promo -Wstrict-overflow=5 -o gautier_program_models.o src/gautier_program_models.cpp

