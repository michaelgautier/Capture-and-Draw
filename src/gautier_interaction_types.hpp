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
			bool receives_input = false;
			unsigned short input_limit = 16;
			
			float x = -1,
			      y = -1,
			      width = -1,
			      height = -1;

			std::string name = "",
				text = "";
		};

		struct composition
		{
			std::string name = "",
				text = "";

			std::map<std::string, planar_def> composites;
	
			composition():composites(){}
		};

		struct input_def
		{
			bool root_context_is_active = true,
				input_key_is_down = false,
				input_key_is_up = false,
				input_mouse_is_down = false,
				input_mouse_is_up = false,
				input_mouse_button_is_left = false,
				input_mouse_button_is_right = false,
				input_mouse_button_is_middle = false;

			int input_key_sequence_count = 0;

			float root_context_width = -1,
				root_context_height = -1,
				input_mouse_x = -1,
				input_mouse_y = -1;

			std::string last_event_captured = "",
				input_text_value = "";
			char input_char_value = '\n';
		};

		/*
			Aliases
		*/
		using type_visual_response_model = std::vector<planar_def>;
		using type_text_keyvaluepair_list = std::map<std::string, std::string>;
		using type_data_key_to_interaction_def_list = std::map<std::string, interaction_def_type>;
		using type_data_key_to_interaction_def_pair = std::pair<std::string, interaction_def_type>;
	}
}
#endif
