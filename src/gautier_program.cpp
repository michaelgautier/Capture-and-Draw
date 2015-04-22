/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/
#include "gautier_program.hpp"

auto define_context_properties() -> void
{
	constexpr short ICTX_DEFAULT_WIDTH = 1024;
	constexpr short ICTX_DEFAULT_HEIGHT = 728;

	constexpr std::pair<float, float> ICTX_DEFAULT_EXTENT =
	{
		ICTX_DEFAULT_WIDTH,
		ICTX_DEFAULT_HEIGHT
	};

	const std::string ICTX_DEFAULT_TITLE = "Gautier App Context";

	gautier::interaction::define_context_properties(ICTX_DEFAULT_EXTENT, ICTX_DEFAULT_TITLE);
	
	return;
}

auto gautier::program::execute() -> int
{
	auto return_value = 0;

	define_context_properties();

	gautier::interaction::input_def instance_input_model;

	/*Accuracy and speed is essential for this to work.*/
	while(gautier::interaction::check_interaction_process_is_active())
	{
		//capture state
		gautier::interaction::capture_state(instance_input_model);

		//application specific logic goes here.
		auto instance_output_model = process_input(instance_input_model);

		//present state
		return_value = gautier::interaction::update_state(instance_output_model);//defer to graphics translation engine

	}

	return return_value;
}
