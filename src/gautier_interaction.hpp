/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/


/*
-----------------------------

Interaction API dealing with Input Response. That covers input devices and 2D graphical output.
	Links to an interchangeable, specific implementation and maps that implementation to a generic, application level API.

-----------------------------
*/
#ifndef gautier_interaction
#define gautier_interaction
#define UXLevel 0

#include "gautier_interaction_types.hpp"
#include <utility>

#if UXLevel == 1	//sfml implementation
	#include "gautier_interaction_sfml.hpp"
#else
	#include "gautier_interaction_console.hpp"
#endif

namespace gautier
{
	namespace interaction
	{
		/*
			Functions
		*/
		auto capture_state(input_def& instance_input_model) -> void;
		auto update_state(const type_visual_response_model& instance_visual_response_model) -> int;

		auto check_interaction_process_is_active() -> bool;
		auto set_interaction_process_is_active(bool value) -> void;

		auto define_context_properties(const std::pair<float, float>& extent, const std::string& title) -> void;

		auto axis_modify_x_center_align(const planar_def& in_bnds, planar_def& out_bnds) -> float;
		auto axis_modify_x_right_align(const planar_def& in_bnds, planar_def& out_bnds) -> float;
		auto axis_modify_y_center_align(const planar_def& in_bnds, planar_def& out_bnds) -> float;
		auto axis_modify_y_space_align(const float& magnitude, const planar_def& in_bnds, planar_def& out_bnds) -> float;
		auto axis_modify_y_top_align(const planar_def& in_bnds, planar_def& out_bnds) -> float;

		auto Function01_InputMappedToGeometry() -> float;
		auto Function02_VisualStructureToVisualOutput() -> float;

		auto get_interactive_def_primary_key(const std::string& value, const type_principle_key_map& instance_principle_key_map) -> type_principle_map_key;
		auto make_default_interactive_def_primary_key() -> type_principle_map_key;

		auto output_model_to_console(const type_interaction_model& instance_models) -> void;
		auto run_basic_capabilities_test() -> int;

		#if UXLevel == 1	//sfml implementation
			namespace impl_ns = gautier::interaction::implsfml;
		#else
			namespace impl_ns = gautier::interaction::implconsole;
		#endif		
	}
}
#endif
