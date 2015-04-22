/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/
#include "gautier_program_domain.hpp"
#include "gautier_interaction.hpp"

gautier::interaction::composition instance_composition;

std::map<std::string, std::string> input_text_buffers;

auto get_model_template_text_login_screen() -> std::string
{
	return 
	"[		\
		{	\
			\"context_elemid\": \"loginscreen\", \
			\"context_phrase\": \"Login Screen\", \
			 \"composites\": [\
				{ \
					\"planar_elemid\": \"username\", \
					\"planar_phrase\": \"User name\", \
					\"x\": 100.00, \
					\"y\": 90.00, \
					\"width\": 180.00, \
					\"height\": 24.00 \
				},\
				{ \
					\"planar_elemid\": \"password\", \
					\"planar_phrase\": \"Password\", \
					\"x\": 300.00, \
					\"y\": 90.00, \
					\"width\": 80.00, \
					\"height\": 24.00 \
				}\
			]\
		}	\
	]		\
	";
}

auto get_model_template_text_profile_screen() -> std::string
{
	return
	"[		\
		{	\
			\"context_elemid\": \"profilescreen\", \
			\"context_phrase\": \"Profile Screen\", \
			 \"composites\": [\
				{ \
					\"planar_elemid\": \"firstname\", \
					\"planar_phrase\": \"First name\", \
					\"x\": 100.00, \
					\"y\": 80.00, \
					\"width\": 250.00, \
					\"height\": 44.00 \
				},\
				{ \
					\"planar_elemid\": \"lastname\", \
					\"planar_phrase\": \"Last name\", \
					\"x\": 200.00, \
					\"y\": 80.00, \
					\"width\": 350.00, \
					\"height\": 44.00 \
				}\
			]\
		}	\
	]		\
	";
}

auto get_composition(const std::string& model_template_text) -> gautier::interaction::composition
{
	using namespace gautier::program;

	type_key_list instance_data_key_to_interaction_def_list;

	instance_data_key_to_interaction_def_list["context_elemid"] = type_interaction_def_enum::interaction_def_type_composition;
	instance_data_key_to_interaction_def_list["planar_elemid"] = type_interaction_def_enum::interaction_def_type_planar_def;

	auto instance_current_composition = gautier::program::models::create_composition_from_json_data(instance_data_key_to_interaction_def_list, model_template_text);

	return instance_current_composition;
}

auto gautier::program::process_input(type_input& instance_input_model) -> type_output
{
	type_output instance_visual_response_model;

	if(instance_composition.name.empty())
	{
		instance_composition = get_composition(get_model_template_text_login_screen());

		gautier::interaction::output_composition_to_console(instance_composition);
	}

	auto planar_is_input_dest = false;
	type_planar active_planar;//defaults to an empty planar.
	
	if(instance_composition.composites.size() > 0)
	{
		for(auto keyed_planar : instance_composition.composites)
		{
			planar_is_input_dest = gautier::interaction::check_point_within_area(instance_input_model, keyed_planar.second);

			if(planar_is_input_dest)
			{
				active_planar = keyed_planar.second;
				break;
			}
		}
	}

	if(instance_composition.name == "loginscreen")
	{
		if(planar_is_input_dest)
		{
			//may need to validate the text before allowing it in.
			if(!instance_input_model.input_text_value.empty())
			{
				gautier::interaction::update_text_buffer_by_name(input_text_buffers, active_planar.name, instance_input_model);
			}

/*May need to update the data model with the following

	Add a flag:  receives_text = true/false
	Add text limit	positive value
	

*/
			//each of these will set text limits
			if(active_planar.name == "username")
			{
				//Will need to validate username
				std::cout << "" << gautier::OUTENDL;
			}
			else if(active_planar.name == "password")
			{
				//Will need to validate password.
				std::cout << "" << gautier::OUTENDL;
				
				//Will need to mask the password.
				//Perhaps in-memory crypto at some point.
			}
		}
	}

	if(instance_input_model.input_mouse_x > -1.0f)
	{
		std::cout << "input mouse x " << instance_input_model.input_mouse_x << gautier::OUTENDL;
	}

	instance_visual_response_model = gautier::interaction::get_planars(instance_composition);

	return instance_visual_response_model;
}
