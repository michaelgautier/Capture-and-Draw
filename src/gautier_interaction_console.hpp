/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/


/*
-----------------------------

Placeholder module for when switching between implementations for compile.

-----------------------------
*/
#ifndef gautier_interaction_console
#define gautier_interaction_console

#include "gautier_interaction_types.hpp"
#include <utility>

namespace gautier
{
	namespace interaction
	{
		namespace implconsole
		{
			/*
				Functions
			*/
			auto check_interaction_process_is_active_impl() -> bool;
			auto set_interaction_process_is_active_impl(bool value) -> void;

			auto define_context_properties_impl(const std::pair<float, float>& extent, const std::string& title) -> void;

			auto capture_state_impl(input_def& instance_input_model) -> void;
			auto run_basic_capabilities_test_impl() -> int;
			auto update_state_impl(const type_visual_response_model& instance_visual_response_model) -> int;

			auto check_point_within_area(const std::vector<float>& xy, const std::vector<float>& xywh) -> bool;
			auto check_area_overlaps(const std::vector<float>& xywh1, const std::vector<float>& xywh2) -> bool;

		}
	}
}
#endif
