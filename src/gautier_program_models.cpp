/*! 	\file
	\brief		Produces models used by the program.
	\par		Description
	The primary function of this module is to link data types into forms productive for the application in processing information for capture or dispatch. The principle is that the program will often need to deal with information organized as lists data and the structure of those lists will determine suitable algorithms and routines. The level of productivity in defining the regular program begins in this module.
	\pre		ISO C++ 11 or later compliant compiler with an available C++ 11 STL implementation.
	\pre		JsonCpp http://open-source-parsers.github.io/jsoncpp-docs/doxygen/index.html
	\version	4
	\date		4/12/2015 4/21/2015
	\author 	Michael Gautier
	\copyright 	Apache License 2.0
	\par 		Copyright 2015 Michael Gautier
	Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 . Software distributed under the License is distributed on an "AS IS" BASIS, NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit. See the License for details on permissions and limitations.
*/
#include <iostream>
#include <map>
#include <vector>
#include <utility>

#include "json/json.h"

#ifndef __gautier_core__
#define __gautier_core__
#include "gautier_core.hpp"
#endif

#ifndef __gautier_interaction_types__
#define __gautier_interaction_types__
#include "gautier_interaction_types.hpp"
#endif

#ifndef __gautier_interaction__
#define __gautier_interaction__
#include "gautier_interaction.hpp"
#endif

#ifndef __gautier_program_models__
#define __gautier_program_models__
#include "gautier_program_models.hpp"
#endif
auto gautier::program::models::build_composition(const type_key_list& instance_data_key_to_interaction_def_list, type_composition& instance_composition, type_keyvaluepair_list& instance_current_values) -> void
{
	type_keyvaluepair item_type_desc;

	for(const auto key_value_entry : instance_current_values)
	{
		auto current_type_desc = gautier::interaction::get_data_key_to_interactive_def_pair(key_value_entry.first, instance_data_key_to_interaction_def_list);

		if(current_type_desc.second != type_interaction_def_enum::interaction_def_type_none)
		{
			item_type_desc = current_type_desc;

			break;
		}				
	}

	/*The current JSON API lists values alphabetically. Must not make decisions based on the original order of elements.
	*/
	if(item_type_desc.second == type_interaction_def_enum::interaction_def_type_composition)
	{
		const std::string current_values_key = item_type_desc.first;
		
		instance_composition.name = instance_current_values[current_values_key];
		instance_composition.text = instance_current_values["context_phrase"];
	}
	else if(item_type_desc.second == type_interaction_def_enum::interaction_def_type_planar_def)
	{
		gautier::interaction::planar_def instance_planar_def;

		for(const auto current_item : instance_current_values)
		{
			const auto current_name = current_item.first;
			const auto current_value = current_item.second;

			/*A a more reliable process in the event fields are missing.*/
			if(current_name == "height")
			{
				if(gautier::is_numeric(current_value))
				{
					instance_planar_def.height = std::stof(current_value);
				}
			}
			else if(current_name == "input_limit")
			{
				if(gautier::is_numeric(current_value))
				{
					instance_planar_def.input_limit = std::stoi(current_value);
				}
			}
			else if(current_name == "planar_elemid")
			{
				if(current_name == item_type_desc.first)
				{
					instance_planar_def.name = current_value;
				}
			}
			else if(current_name == "planar_phrase")
			{
				instance_planar_def.text = current_value;
			}
			else if(current_name == "receives_input")
			{
				instance_planar_def.receives_input = ("true" == current_value);
			}
			else if(current_name == "width")
			{
				if(gautier::is_numeric(current_value))
				{
					instance_planar_def.width = std::stof(current_value);
				}
			}
			else if(current_name == "x")
			{
				if(gautier::is_numeric(current_value))
				{
					instance_planar_def.x = std::stof(current_value);
				}
			}
			else if(current_name == "y")
			{
				if(gautier::is_numeric(current_value))
				{
					instance_planar_def.y = std::stof(current_value);
				}
			}
		}

		if(!instance_planar_def.name.empty())
		{
			instance_composition.composites.emplace(instance_planar_def.name, instance_planar_def);
		}
	}

	return;
}

auto gautier::program::models::create_composition_from_json_data(const Json::Value& instance_node, const type_key_list& instance_data_key_to_interaction_def_list, type_composition& instance_composition, type_keyvaluepair_list& instance_values) -> void
{
	for(Json::Value::const_iterator pos = instance_node.begin(); pos != instance_node.end(); std::advance(pos, 1))
	{
		const Json::Value node_key = pos.key();
		const Json::Value& instance_current_node = *pos;

		const bool is_container = (
		   instance_current_node.type() == Json::ValueType::objectValue 
		|| instance_current_node.type() == Json::ValueType::arrayValue
		);

		if(is_container)
		{
			create_composition_from_json_data(instance_current_node, instance_data_key_to_interaction_def_list, instance_composition, instance_values);

			build_composition(instance_data_key_to_interaction_def_list, instance_composition, instance_values);
			instance_values.clear();
		}
		else
		{
			std::string node_key_text = node_key.asString();

			instance_values[node_key_text] = instance_current_node.asString();
		}
	}

	return;
}

auto gautier::program::models::create_composition_from_json_data(const type_key_list& instance_data_key_to_interaction_def_list, const std::string& json_data) -> type_composition
{
	type_composition instance_composition;

	/*
		Defining a user interface with JSON
		https://developer.gnome.org/clutter-cookbook/stable/script-ui.html

		JsonCpp Documentation
		http://open-source-parsers.github.io/jsoncpp-docs/doxygen/index.html
	*/

	Json::Value spec_data;
	Json::Reader spec_reader;

	spec_reader.parse(json_data, spec_data, false);

	type_keyvaluepair_list instance_values;

	create_composition_from_json_data(spec_data, instance_data_key_to_interaction_def_list, instance_composition, instance_values);

	return instance_composition;
}
