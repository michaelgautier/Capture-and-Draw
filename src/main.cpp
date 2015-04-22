/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/
#include "gautier_program.hpp"

auto main() -> int
{
	auto return_value = gautier::program::execute();

	return return_value;
}

/*
	Edit log

	Compile sizes

Using Clang
		173248 Feb 23 00:12 main.o	debug
		105918 Feb 23 00:12 assembled executable	debug

		173264 Feb 23 00:43 main.o	debug
		105891 Feb 23 00:44 assembled executable	debug

		173264 Feb 23 00:52 main.o	debug
		105891 Feb 23 00:52 assembled executable	debug

		181688 Feb 23 01:13 main.o	debug
		113467 Feb 23 01:14 assembled executable	debug

		206360 Feb 23 13:25 main.o	debug
		123092 Feb 23 13:25 assembled executable	debug

		241752 Feb 23 20:39 main.o	debug
		143825 Feb 23 20:39 assembled executable	debug

		315736 Feb 24 17:44 main.o	debug
		182628 Feb 24 17:44 assembled executable	debug

		325240 Feb 25 08:12 main.o	debug
		190548 Feb 25 08:12 assembled executable	debug

		425152 Mar  9 18:38 main.o	debug
		250633 Mar  9 18:38 assembled executable	debug

		214916 Mar 25 02:10 main.o	debug		code size decline
		172052 Mar 25 02:10 assembled executable	debug

		1303512 Mar 25 13:24 jsonlib.o	debug
		 334996 Mar 25 13:24 program.o	debug
		1107965 Mar 25 13:24 assembled executable	debug

		1303512 Mar 27 02:00 jsonlib.o	debug
		 732284 Mar 27 02:00 program.o	debug
		1370581 Mar 27 02:00 assembled executable	debug

		1303512 Mar 27 14:34 jsonlib.o	debug
		 767024 Mar 27 14:34 program.o	debug
		1396436 Mar 27 14:34 assembled executable	debug

Using GCC
		1269652 Apr 12 13:50 jsonlib.o	debug
		 888692 Apr 12 13:50 program.o	debug

		1269652 Apr 12 14:28 jsonlib.o	debug
		 859224 Apr 12 14:28 program.o 	debug
		1383294 Apr 12 14:28 assembled executable	debug


		1269652 Apr 12 14:57 jsonlib.o	debug
		 859536 Apr 12 14:57 program.o	debug
		1383489 Apr 12 14:57 assembled executable	debug

		1269652 Apr 12 16:03 jsonlib.o	debug
		 863172 Apr 12 16:03 program.o	debug
		1384763 Apr 12 16:03 assembled executable	debug

Using GCC

UXLevel = 1

		  67416 Apr 14 17:31 gautier_interaction_console.o
		 341480 Apr 14 17:31 gautier_interaction.o
		 247408 Apr 14 17:31 gautier_interaction_sfml.o
		 103156 Apr 14 17:31 gautier_json_mapping.o
		 821032 Apr 14 17:31 gautier_program_models.o
		 436520 Apr 14 17:31 gautier_program.o
		1269652 Apr 14 17:31 jsonlib.o
		1779425 Apr 14 17:31 c_and_d


UXLevel = 0

		  67416 Apr 14 17:34 gautier_interaction_console.o
		 237572 Apr 14 17:34 gautier_interaction.o
		 247408 Apr 14 17:34 gautier_interaction_sfml.o
		 103156 Apr 14 17:34 gautier_json_mapping.o
		 718252 Apr 14 17:34 gautier_program_models.o
		 333276 Apr 14 17:34 gautier_program.o
		1269652 Apr 14 17:34 jsonlib.o
		1676833 Apr 14 17:34 c_and_d


Using Clang

		  47560 Apr 14 18:05 gautier_interaction_console.o
		 231976 Apr 14 18:05 gautier_interaction.o
		 138728 Apr 14 18:05 gautier_interaction_sfml.o
		   2160 Apr 14 18:05 gautier_json_mapping.o
		 749156 Apr 14 18:05 gautier_program_models.o
		 324884 Apr 14 18:05 gautier_program.o
		1303512 Apr 14 18:04 jsonlib.o
		1694676 Apr 14 18:05 c_and_d



*/
