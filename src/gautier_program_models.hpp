/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/


/*
-----------------------------

Tools to *help* map generic JSON formatted data to data types specific to the project.
These tools do not do the mapping, but reduce the amount of code needed at the application level.

-----------------------------
*/
#ifndef gautier_program_models
#define gautier_program_models

#include "gautier_interaction_types.hpp"

#include "json/json.h"

namespace gautier
{
	namespace program
	{
		namespace models
		{
			using type_key_list = gautier::interaction::type_data_key_to_interaction_def_list;
			using type_composition = gautier::interaction::composition;
			using type_keyvaluepair_list = gautier::interaction::type_text_keyvaluepair_list;
			using type_keyvaluepair = gautier::interaction::type_data_key_to_interaction_def_pair;
			using type_interaction_def_enum = gautier::interaction::interaction_def_type;

			auto build_composition(const type_key_list& instance_data_key_to_interaction_def_list, type_composition& instance_composition, type_keyvaluepair_list& instance_current_values) -> void;
			auto create_composition_from_json_data(const Json::Value& instance_node, const type_key_list& instance_data_key_to_interaction_def_list, type_composition& instance_composition, type_keyvaluepair_list& instance_values) -> void;
			auto create_composition_from_json_data(const type_key_list& instance_data_key_to_interaction_def_list, const std::string& json_data) -> type_composition;
		}
	}
}
#endif
