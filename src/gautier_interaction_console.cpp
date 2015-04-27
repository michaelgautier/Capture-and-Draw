/*!	\file
	\brief		Directs input to a cli stdout.
	\par		Description
	Takes input from a regular program that uses the interface defined in "gautier_interaction.hpp" and dispatches it to standard out. The module can also be adapted to further to take input from standard in as a means to create a full cycle interactive scenario as you would have in a visual graphical interface. The full spectrum of implementation possibilities is not designed into this module but the basics are present for doing a quick test of an upstream program.
	\pre		ISO C++ 11 or later compliant compiler with an available C++ 11 STL implementation.
	\version	4
	\date		4/12/2015, 4/14/2015, 4/21/2015
	\author 	Michael Gautier
	\copyright 	Apache License 2.0
	\par 		Copyright 2015 Michael Gautier
	Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 . Software distributed under the License is distributed on an "AS IS" BASIS, NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit. See the License for details on permissions and limitations.
*/

#include <iostream>
#include <utility>
#include <vector>
#include <map>

#ifndef __gautier_core__
#define __gautier_core__
#include "gautier_core.hpp"
#endif

#ifndef __gautier_interaction_types__
#define __gautier_interaction_types__
#include "gautier_interaction_types.hpp"
#endif

#ifndef __gautier_interaction_console__
#define __gautier_interaction_console__
#include "gautier_interaction_console.hpp"
#endif
///	Tracks the state of the visual context in the graphics platform implementation. In this case, it simulates that behavior.
bool console_interaction_process_active = true;

auto gautier::interaction::implconsole::check_interaction_process_is_active_impl() -> bool
{
	return console_interaction_process_active;
}

auto gautier::interaction::implconsole::set_interaction_process_is_active_impl(bool value) -> void
{
	console_interaction_process_active = value;
	
	return;
}

auto gautier::interaction::implconsole::define_context_properties_impl(const std::pair<float, float>& extent, const std::string& title) -> void
{
	std::cout << "defining solution " << title << " width/height " << extent.first << "," << extent.second << gautier::OUTENDL;

	return;
}

auto gautier::interaction::implconsole::run_basic_capabilities_test_impl() -> int
{
	std::cout << "console output in generic interaction module." << gautier::OUTENDL;

	return 1;
}

auto check_point_within_area(const std::vector<float>& xy, const std::vector<float>& xywh) -> bool
{
	std::cout << "point " << xy[0] << "/" << xy[1] << " area " << xywh[0] << "/" << xywh[1] << ", " << xywh[2] << " " << xywh[3] << gautier::OUTENDL;
	
	return false;
}

auto check_area_overlaps(const std::vector<float>& xywh1, const std::vector<float>& xywh2) -> bool
{
	std::cout << " area 1 " << xywh1[0] << "/" << xywh1[1] << ", " << xywh1[2] << " " << xywh1[3] << " area " << xywh2[0] << "/" << xywh2[1] << ", " << xywh2[2] << " " << xywh2[3] << gautier::OUTENDL;
	
	return false;
}

auto gautier::interaction::implconsole::capture_state_impl(input_def& instance_input_model) -> void
{
	std::cout << "capturing state: Generic" << gautier::OUTENDL;
	
	std::cout << "input model last event captured " << instance_input_model.last_event_captured << gautier::OUTENDL;
	
	return;
}

auto gautier::interaction::implconsole::update_state_impl(const type_visual_response_model& instance_visual_response_model) -> int
{
	std::cout << "update state: Generic" << gautier::OUTENDL;
	
	auto is_active = check_interaction_process_is_active_impl();
	
	std::cout << "response model member count " << instance_visual_response_model.size() << gautier::OUTENDL;
	
	if(is_active)
	{
		std::cout << "setting termination signal on generic interaction" << gautier::OUTENDL;

		set_interaction_process_is_active_impl(false);
	}
	
	return 0;
}
