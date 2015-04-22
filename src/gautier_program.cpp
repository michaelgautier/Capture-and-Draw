/*! 	\file
	\brief		Demonstrates a native, cross-platform interactive solution.
	\par		Description
	This is starting point of the program that exercises a native, cross-platform solution for user interfaces and interactivity. Further details are listed among the files associated with the solution.
	\pre		ISO C++ 11 or later compliant compiler with an available C++ 11 STL implementation.
	\version	4
	\date		2/11/2015 4/21/2015
	\author 	Michael Gautier
	\copyright 	Apache License 2.0
	\par 		Copyright 2015 Michael Gautier
	Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 . Software distributed under the License is distributed on an "AS IS" BASIS, NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit. See the License for details on permissions and limitations.
*/

#include "gautier_core.hpp"
#include "gautier_interaction_types.hpp"
#include "gautier_program_models.hpp"
#include "gautier_interaction.hpp"
#include "gautier_program_domain.hpp"

#include <iostream>

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

auto main() -> int
{
	auto return_value = 0;

	define_context_properties();

	gautier::interaction::input_def instance_input_model;

	/*Accuracy and speed is essential for this to work.*/
	while(gautier::interaction::check_interaction_process_is_active())
	{
		/*capture state*/
		gautier::interaction::capture_state(instance_input_model);

		/*application specific logic goes here.*/
		auto instance_output_model = gautier::program::process_input(instance_input_model);

		/*present state*/
		/*VisualStructureToVisualOutput*/
		return_value = gautier::interaction::update_state(instance_output_model);/*defer to graphics translation engine*/
	}

	std::cout << gautier::OUTENDL;

	return return_value;
}
