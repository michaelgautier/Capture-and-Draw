/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/

#include "gautier_core.hpp"
#include "gautier_interaction_console.hpp"

#include <iostream>

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
