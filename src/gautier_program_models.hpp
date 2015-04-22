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
			/*
				Instances
			*/
			static gautier::interaction::type_interaction_model instance_interaction_models;
			static gautier::interaction::type_principle_key_map instance_interaction_def_primary_keys;

			static gautier::interaction::type_text_keyvalues_map instance_text_keyvalues;
			static gautier::interaction::type_principle_map_key instance_principle_map_key;

			/*
				Functions
			*/
			auto build_interactive_model(gautier::interaction::type_text_keyvalues_map& instance_current_values) -> void;
			auto create_interaction_model_from_JSONValue(const std::string& json_data) -> gautier::interaction::type_interaction_model;
			auto translate_json_node_to_planar(const Json::Value& instance_node, gautier::interaction::type_text_keyvalues_map& instance_values) -> void;
		}
	}
}
#endif
