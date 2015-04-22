/*!	\file
	\brief		Maps a generic GUI API to SFML.
	\par		Description
	An implementation interface to apply SFML to the creation of graphical user interfaces.
	\pre		ISO C++ 11 or later compliant compiler with an available C++ 11 STL implementation.
	\pre		Simple Fast Media Library 2.1 or later
	\version	4
	\date		4/14/2015, 4/21/2015
	\author 	Michael Gautier
	\copyright 	Apache License 2.0
	\par 		Copyright 2015 Michael Gautier
	Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 . Software distributed under the License is distributed on an "AS IS" BASIS, NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit. See the License for details on permissions and limitations.
*/

#ifndef gautier_interaction_sfml
#define gautier_interaction_sfml

#include "gautier_interaction_types.hpp"

#include <utility>

namespace gautier
{
	namespace interaction
	{
		///	Implementation for the console output functionality of the interaction API.
		namespace implsfml
		{
			///	Queries if the visual context is active to support input capture and graphical output.
			auto check_interaction_process_is_active_impl() -> bool;
			
			///	Allows a caller to opt out of the interactive process. The visual context remains active unless closed by an end-user.
			auto set_interaction_process_is_active_impl(bool value) -> void;

			///	Sets the main window's properties just prior to initialization.
			auto define_context_properties_impl(const std::pair<float, float>& extent, const std::string& title) -> void;

			///	Notes input values from a user interface using facilities native to SFML.
			auto capture_state_impl(gautier::interaction::input_def& instance_input_model) -> void;

			///	Transforms a list of layouts into graphical output using facilities native to SFML.
			auto update_state_impl(const gautier::interaction::type_visual_response_model& instance_visual_response_model) -> int;

			///	Decides if a point resides in an area using facilities native to SFML.
			auto check_point_within_area_impl(const std::vector<float>& xy, const std::vector<float>& xywh) -> bool;

			///	Decides if two areas coincide using facilities native to SFML.
			auto check_area_overlaps_impl(const std::vector<float>& xywh1, const std::vector<float>& xywh2) -> bool;

			///	Uses an SFML test sequence to validate the operational state of SFML.
			auto run_basic_capabilities_test_impl() -> int;
		}
	}
}
#endif
