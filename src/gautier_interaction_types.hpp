/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/


/*
-----------------------------

Types for the interaction API

-----------------------------
*/
#ifndef gautier_interaction_types
#define gautier_interaction_types

#include <map>
#include <vector>

namespace gautier
{
	namespace interaction
	{
		const auto MAX_UNAVAILABLE_EVENTS = 1000;

		/*
			Enums
		*/
		enum interaction_def_type
		{
			interaction_def_type_none = 0,
			interaction_def_type_composition,
			interaction_def_type_planar_def
		};

		/*
			Types
		*/
		struct planar_def
		{
			std::string name = "";
			std::string text = "";
			float x = -1,
			      y = -1,
			      width = -1,
			      height = -1;
		};

		struct composition
		{
			std::string name = "";
			std::string text = "";
			std::map<std::string, planar_def> composites;
	
			composition():composites(){}
		};

		struct input_def
		{
			std::string last_event_captured = "";

			float x = -1,
				y = -1;
		};

		/*
			Aliases
		*/
		using type_interaction_model = std::map<std::string, composition>;
		using type_visual_response_model = std::vector<planar_def>;
		using type_principle_map_key = std::pair<interaction_def_type, std::string>;
		using type_text_keyvalues_map = std::map<std::string, std::string>;
		using type_principle_key_map = std::map<std::string, interaction_def_type>;
	}
}
#endif
