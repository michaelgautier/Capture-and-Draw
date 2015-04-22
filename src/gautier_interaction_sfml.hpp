/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/


/*
-----------------------------

Graphics and devices engine providing specific functions for input devices and 2D/3D graphical output.
This implementation is the Simple Fast Media Library.

-----------------------------
*/
#ifndef gautier_interaction_sfml
#define gautier_interaction_sfml

#include "gautier_interaction_types.hpp"

#include <utility>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

namespace gautier
{
	namespace interaction
	{
		namespace implsfml
		{
			/*
				Aliases
			*/
			using type_interaction_context = std::unique_ptr<sf::RenderWindow>;

			/*
				Instances
			*/
			static type_interaction_context instance_interaction_context;

			/*
				Functions
			*/
			auto check_interaction_process_is_active_impl() -> bool;
			auto set_interaction_process_is_active_impl(bool value) -> void;

			auto define_context_properties_impl(const std::pair<float, float>& extent, const std::string& title) -> void;

			auto capture_state_impl(gautier::interaction::input_def& instance_input_model) -> void;
			auto run_basic_capabilities_test_impl() -> int;
			auto update_state_impl(const gautier::interaction::type_visual_response_model& instance_visual_response_model) -> int;

			auto check_point_within_area_impl(const std::vector<float>& xy, const std::vector<float>& xywh) -> bool;
			auto check_area_overlaps_impl(const std::vector<float>& xywh1, const std::vector<float>& xywh2) -> bool;
		}
	}
}
#endif
