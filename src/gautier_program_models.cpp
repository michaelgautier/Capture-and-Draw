/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/

#include "gautier_program_models.hpp"
#include "gautier_interaction.hpp"

namespace ire = gautier::interaction;

auto gautier::program::models::build_interactive_model(ire::type_text_keyvalues_map& instance_current_values) -> void
{
	ire::type_principle_map_key item_type_desc;

	for(const auto key_value_entry : instance_current_values)
	{
		auto current_type_desc = ire::get_interactive_def_primary_key(key_value_entry.first, instance_interaction_def_primary_keys);

		if(current_type_desc.first != ire::interaction_def_type::interaction_def_type_none)
		{
			item_type_desc = current_type_desc;

			break;
		}				
	}

	if(item_type_desc.first == ire::interaction_def_type::interaction_def_type_composition)
	{
		const std::string current_values_key = item_type_desc.second;
		
		std::string name = instance_current_values[current_values_key];

		ire::composition instance_composition;

		if(instance_interaction_models.count(name) > 0)
		{
			instance_composition = instance_interaction_models[name];
		}
		else
		{
			instance_composition.name = instance_current_values[current_values_key];
			instance_composition.text = instance_current_values["context_phrase"];
		}
	
		/*Single space marks a composition that has been reserved.
		Such is the case when the descendants from the JsonCpp API are read in first.
		Since the JsonCpp API lists items in alphabetical order instead of the actual order,
			the reassembly has to occur in an order independent way.
		Values from the most recent placeholder will be transfered to this instance.
		*/
		while(instance_interaction_models[" "].composites.size() > 0)
		{
			ire::composition& placeholder_instance_composition = instance_interaction_models[" "];

			/*Even though the elements are sometimes in a different order
				due to the way the JsonCpp API presents the data,
				it will not matter in this case since the visual placement
				is geometric in nature.
			*/
			for(auto composite_entry : placeholder_instance_composition.composites)
			{
				instance_composition.composites.insert(composite_entry);
			}

			placeholder_instance_composition.composites.clear();
		}

		instance_interaction_models.emplace(instance_composition.name, instance_composition);
	}
	else if(item_type_desc.first == ire::interaction_def_type::interaction_def_type_planar_def)
	{
		ire::composition& instance_composition = instance_interaction_models[" "];

		const auto name = instance_current_values[item_type_desc.second];

		ire::planar_def instance_planar_def;

		instance_planar_def.name = name;
		instance_planar_def.text = instance_current_values["planar_phrase"];
		instance_planar_def.x = std::stof(instance_current_values["x"]);
		instance_planar_def.y = std::stof(instance_current_values["y"]);
		instance_planar_def.width = std::stof(instance_current_values["width"]);
		instance_planar_def.height = std::stof(instance_current_values["height"]);

		instance_composition.composites.emplace(instance_planar_def.name, instance_planar_def);
	}

	return;
}

auto gautier::program::models::translate_json_node_to_planar(const Json::Value& instance_node, ire::type_text_keyvalues_map& instance_values) -> void
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
			translate_json_node_to_planar(instance_current_node, instance_values);

			build_interactive_model(instance_values);
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

auto gautier::program::models::create_interaction_model_from_JSONValue(const std::string& json_data) -> ire::type_interaction_model
{
	ire::composition instance_composition;

	instance_interaction_models.emplace(" ", instance_composition);

	/*
		Defining a user interface with JSON
		https://developer.gnome.org/clutter-cookbook/stable/script-ui.html

		JsonCpp Documentation
		http://open-source-parsers.github.io/jsoncpp-docs/doxygen/index.html
	*/
	instance_interaction_def_primary_keys["context_elemid"] = ire::interaction_def_type::interaction_def_type_composition;
	instance_interaction_def_primary_keys["planar_elemid"] = ire::interaction_def_type::interaction_def_type_planar_def;

	Json::Value spec_data;
	Json::Reader spec_reader;

	spec_reader.parse(json_data, spec_data, false);

	ire::type_text_keyvalues_map instance_values;

	translate_json_node_to_planar(spec_data, instance_values);

	instance_interaction_models.erase(" ");

	return instance_interaction_models;
}
