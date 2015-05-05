/*!	\file
	\brief		A regular program uses this handle a visual device.
	\par		Description
	This is a gateway between a regular program and visual devices. A visual device system includes the combination of a display screen, input using touch, voice or mouse, and the icons or text entry fields on that screen.
	\par		What is a Regular Program
	A regular program is anything not concerned with graphics programming. A regular program presents functions for an end-user to use a computer to do work or engage in casual activity. This module represents the boundary between a regular program and the technical processes necessary to represent the program on a display screen and capture inputs represented on that screen. A screen is a general term that can also be represented as speakers and input as microphone for voice interfacing. This module deals in the details of such interactions so that the regular program is not flooded with such concepts that could obscure the structure and definition of that program.
	\par		Definition of UXLevel
	A UXLevel flag allows an implementer of the library to switch between underlying interactive technology implementations. The design also allows a future implementer to add new implementations that comply with the API that can bring regular programs up-to-date.
	\par		Project History, Meaning of the Version Number
	Version number is a major only number that describes this as the 4th major revision. It also follows that the code in this project is described in a series of articles known as the 4th Series on Building a Cross-Platform Program. The 1st series began in Sept. 2012. Series 2 began in July 2014 and was completed in late 2014. Series 3 began in January 2015 and was concluded in March 2015. The Series 4 code is an expanded modular version of Series 3 with a significant revision of functionality that began on April 12, 2015.
	\par		Project History, Dates Listing
	The core of the cross-platform aspect of the project exists in this file and the related implementations. This series is the first production quality version of the solution. Dates listed show the history towards the current form of the solution. Those dates are initial project milestone dates. The project code began in 2/22/2015 in a main.cpp file and evolved into its present form. The first milestone to achieve the goals of the project is the 4/21/2015 version. Develpment is current as of the latest commit date in GitHub.
	\pre		ISO C++ 11 or later compliant compiler with an available C++ 11 STL implementation.
	\pre		Simple Fast Media Library 2.1 or later
	\version	4
	\date		2/22/2015, 2/25/2015, 3/9/2015, 3/25/2015, 3/27/2015, 4/12/2015, 4/14/2015, 4/21/2015
	\author 	Michael Gautier
	\copyright 	Apache License 2.0
	\par 		Copyright 2015 Michael Gautier
	Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 . Software distributed under the License is distributed on an "AS IS" BASIS, NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit. See the License for details on permissions and limitations.
*/
namespace gautier
{
	///	\brief	The primary interface to a graphical interaction process.
	namespace interaction
	{
		///	\brief #1) A program calls this first.
		///	Defines the default layout of the visual context.
		auto define_context_properties(const std::pair<float, float>& extent, const std::string& title) -> void;

		///	\brief #2) A program calls this second.
		///	INPUT
		///	A loop or other iteration method can use this as the control input.
		///	Query this value to know if the visual context is still available.
		///	The primary use is when a user closes the program normally, 
		///	this is your key for controlled exit.
		auto check_interaction_process_is_active() -> bool;

		///	\brief #3) A program calls this third.
		///	Collects the input the user made. Keyboard, mouse, and text.
		auto capture_state(input_def& instance_input_model) -> void;

		///	\brief #98) A program calls this just before calling update_state.
		///	After you edit a composition following decisions on input, they need to be placed in z-order.
		///	The members of your composition are collected in a format for fast output in z-order.
		auto get_planars(const composition& instance_composition) -> type_visual_response_model;

		///	\brief #99) A program calls this last.
		///	OUTPUT
		///	Converts your list of items into graphical output.
		auto update_state(const type_visual_response_model& instance_visual_response_model) -> int;

		///	Center aligns the output planar to the input planar.
		auto axis_modify_x_center_align(const planar_def& in_bnds, planar_def& out_bnds) -> float;
		///	Right aligns the output planar to the input planar.
		auto axis_modify_x_right_align(const planar_def& in_bnds, planar_def& out_bnds) -> float;
		///	Vertical center aligns the output planar to the input planar.
		auto axis_modify_y_center_align(const planar_def& in_bnds, planar_def& out_bnds) -> float;
		///	Distances the output planar from the input planar on the Y-axis.
		auto axis_modify_y_space_align(const float& magnitude, const planar_def& in_bnds, planar_def& out_bnds) -> float;
		///	Top aligns the output planar to the input planar.
		auto axis_modify_y_top_align(const planar_def& in_bnds, planar_def& out_bnds) -> float;

		///	Decides if point xy is within area xy width and height.
		auto check_point_within_area(const std::vector<float>& xy, const std::vector<float>& xywh) -> bool;
		///	Decides if a planar's xy is within another planar's xy width and height.
		auto check_point_within_area(const input_def& src, const planar_def& area) -> bool;

		///	Decides if two areas, their xy width and height, cross in any way.
		auto check_area_overlaps(const std::vector<float>& xywh1, const std::vector<float>& xywh2) -> bool;
		///	Decides if two planars, their xy width and height, cross in any way.
		auto check_area_overlaps(const planar_def& area1, const planar_def& area2) -> bool;

		///	Intended to disassociate a program from an interactive input/output cycle.
		auto set_interaction_process_is_active(bool value) -> void;

		///	Assists in program lookup to know if a piece of data relates to one of the interaction types defined in gautier_interaction_types.hpp.
		auto get_data_key_to_interactive_def_pair(const std::string& value, const type_data_key_to_interaction_def_list& instance_data_key_to_interaction_def_list) -> type_data_key_to_interaction_def_pair;

		///	Creates an empty lookup key to assist processes in knowing what is not an interaction type.
		auto make_default_data_key_to_interaction_def_pair() -> type_data_key_to_interaction_def_pair;

		///	\brief Diagnostic
		///	Assists processes in validating the creation of a composition type.
		auto output_composition_to_console(const composition& instance_composition) -> void;

		///	\brief Diagnostic
		///	Helps you to validate compiler and linker directives.
		///	When compiling or linking a module that includes specific implementations
		///	it is useful to have a quick and very simple test of key functions from that
		///	implementation to make sure you have all the basic code library inputs 
		///	and that those inputs are specified to the compiler and linker appropriately.
		auto run_basic_capabilities_test() -> int;
	}
}
