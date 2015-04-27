/*!	\file
	\brief		Program's main implementation.
	\par		Description
	This the end-user level. The application program and its purpose is to demonstrate the concept of building a regular program that is supported by a cross-platform graphics solution of the implementer's choice.
	\par		Objectives
	The primary goal is to define a long-term approach to the creation of user interfaces. At the same time, have the ability to enhance the representation of information in a way that is minimally intrusive to the structure of the program. The program achieves these goals to a large extent. It does not replace platform solutions but potentially augments them in a way that provides a practical and structured means to adopt one or more of such solutions. Additional areas this solution focuses on is:
	\li 		Reduce code rebuild cost and effort to support a given operating system.
	\li		Make interactivity a service rather than a process tightly coupled with application logic.
	\li		Keep boilerplate code to a minimum while having a compact code base that is adaptable.
	\li		An example program, this module, that verifies the solution and these objectives.
	\pre		ISO C++ 11 or later compliant compiler with an available C++ 11 STL implementation.
	\pre		Gautier Interaction 4	
	\version	4
	\date		2/11/2015 4/21/2015
	\author 	Michael Gautier
	\copyright 	Apache License 2.0
	\par 		Copyright 2015 Michael Gautier
	Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 . Software distributed under the License is distributed on an "AS IS" BASIS, NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit. See the License for details on permissions and limitations.
*/
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

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

#ifndef __gautier_program_domain__
#define __gautier_program_domain__
#include "gautier_program_domain.hpp"
#endif

using type_composition = gautier::interaction::composition;
using type_input = gautier::interaction::input_def;
using type_interaction_def_enum = gautier::interaction::interaction_def_type;
using type_key_list = gautier::interaction::type_data_key_to_interaction_def_list;
using type_keyvaluepair = gautier::interaction::type_data_key_to_interaction_def_pair;
using type_keyvaluepair_list = gautier::interaction::type_text_keyvaluepair_list;
using type_output = gautier::interaction::type_visual_response_model;
using type_planar = gautier::interaction::planar_def;

type_composition instance_composition;
type_input previous_planar_input;

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
					\"receives_input\": true, \
					\"input_limit\": 12, \
					\"x\": 100.00, \
					\"y\": 90.00, \
					\"width\": 180.00, \
					\"height\": 24.00 \
				},\
				{ \
					\"planar_elemid\": \"password\", \
					\"planar_phrase\": \"Password\", \
					\"receives_input\": true, \
					\"input_limit\": 8, \
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
					\"receives_input\": true, \
					\"input_limit\": 24, \
					\"x\": 100.00, \
					\"y\": 80.00, \
					\"width\": 250.00, \
					\"height\": 44.00 \
				},\
				{ \
					\"planar_elemid\": \"lastname\", \
					\"planar_phrase\": \"Last name\", \
					\"receives_input\": true, \
					\"input_limit\": 24, \
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

	type_planar active_planar;/*defaults to an empty planar.*/

	if(instance_input_model.input_mouse_x > -1.0f 
	&& instance_input_model.input_mouse_y > -1.0f)
	{
		auto instance_input_model_local = instance_input_model;
		
		if(!instance_input_model.input_mouse_double_click)
		{
			instance_input_model_local = previous_planar_input;
		}
		else
		{
			instance_input_model.input_mouse_double_click = false;/*Acknowledge event*/
		}

		for(auto keyed_planar : instance_composition.composites)
		{
			auto planar_is_input_dest = gautier::interaction::check_point_within_area(instance_input_model_local, keyed_planar.second);

			if(planar_is_input_dest)
			{
				/*Could have multiple overlapping planars and one of them receive input.*/
				if(keyed_planar.second.receives_input)
				{
					/*std::cout << "PLANAR receives_input" << gautier::OUTENDL;*/
					active_planar = keyed_planar.second;

					instance_input_model.input_top_x = active_planar.x;
					instance_input_model.input_top_y = active_planar.y;

					break;
				}
			}
		}
	}

	if(!active_planar.name.empty())
	{
		/*std::cout << "active planar input check" << gautier::OUTENDL;*/

		if(!instance_input_model.input_text_value.empty())
		{
			auto dest_text = active_planar.input_text_value;
			auto src_text = instance_input_model.input_text_value;

			dest_text.append(src_text);
		
			if(dest_text.size() > active_planar.input_limit)
			{
				dest_text = dest_text.substr(0, active_planar.input_limit);
			}

			instance_input_model.input_text_value = "";
			active_planar.input_text_value = dest_text;
		}

		if(instance_input_model.input_text_remove_last_char)
		{
			instance_input_model.input_text_remove_last_char = false;
			
			if(active_planar.input_text_value.size() > 0)
			{
				active_planar.input_text_value.pop_back();
			}
		}

	}

//	if(instance_composition.name == "loginscreen")
//	{
//		/*each of these will set text limits*/
//		if(active_planar.name == "username")
//		{
//			/*Will need to validate username*/
//			std::cout << "" << gautier::OUTENDL;
//		}
//		else if(active_planar.name == "password")
//		{
//			/*Will need to validate password.*/
//			std::cout << "" << gautier::OUTENDL;
//			
//			/*Will need to mask the password.
//			Perhaps in-memory crypto at some point.*/
//		}
//	}

	previous_planar_input = instance_input_model;
	instance_composition.composites[active_planar.name] = active_planar;

	/*InputMappedToGeometry*/
	instance_visual_response_model = gautier::interaction::get_planars(instance_composition);

	return instance_visual_response_model;
}
