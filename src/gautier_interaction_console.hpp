/*!	\file
	\brief		Applies a logical visual representation to a command-line environment.
	\par		Description
	The initial purpose was to test output defined in "gautier_program_models.cpp" but has evolved in two directions. Fallback interface and test scaffold.
	\par		Fallback Interface
	This header defines an implementation interface for the main interaction module. See "gautier_interaction.hpp" and "gautier_interaction.cpp" for details. As the project progressed, it was clear that this interface could be useful when the input requirements was indeed a cli environment. The solution, as currently defined, does not address that possibility in reality, but the structure is in place.
	\par		Test Scaffold
	A more practical need this interface and corresponding implementation addresses is the quick test of output in a cli environment during development. It allows you to see the flow of the program logic in terms of the alternation between input and output that might occur if a graphics stack was involved. That becomes useful when the sequence of the upstream program requires additional review and revision.
	\pre		ISO C++ 11 or later compliant compiler with an available C++ 11 STL implementation.
	\version	4
	\date		4/12/2015, 4/14/2015, 4/21/2015
	\author 	Michael Gautier
	\copyright 	Apache License 2.0
	\par 		Copyright 2015 Michael Gautier
	Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 . Software distributed under the License is distributed on an "AS IS" BASIS, NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit. See the License for details on permissions and limitations.
*/
namespace gautier
{
	namespace interaction
	{
		///	\brief	Implementation for the console output functionality of the interaction API.
		namespace implconsole
		{
			///	Tests the output capabilities of the implementation.
			auto run_basic_capabilities_test_impl() -> int;

			///	Identifies if the implementation is actively accepting requests for input/output.
			auto check_interaction_process_is_active_impl() -> bool;
			
			///	Allows callers to actively change the status of this implementation.
			auto set_interaction_process_is_active_impl(bool value) -> void;

			///	Echoes the values normally provided to a graphical implementation to standard out.
			auto define_context_properties_impl(const std::pair<float, float>& extent, const std::string& title) -> void;

			///	Tracks inputs made in the cli environment.
			auto capture_state_impl(input_def& instance_input_model) -> void;

			///	Presents a list of layout data to the cli environment.
			auto update_state_impl(const type_visual_response_model& instance_visual_response_model) -> int;

			///	Uses available methods to determine if a point resides in an area.
			auto check_point_within_area(const std::vector<float>& xy, const std::vector<float>& xywh) -> bool;

			///	Uses available methods to determine two areas coincides.
			auto check_area_overlaps(const std::vector<float>& xywh1, const std::vector<float>& xywh2) -> bool;
		}
	}
}
