/*!	\file
	\brief		Types for the interaction module.
	\par		Description
	Primary formats for communication between a regular program and the interaction module.
	\remarks	Began as struct cartesoid and evolved into the following types. This is the most important part of the solution as it determines the how the program is organized.
	\pre		ISO C++ 11 or later compliant compiler with an available C++ 11 STL implementation.
	\version	4
	\date		2/11/2015, 3/23/2015, 4/14/2015, 4/21/2015
	\author 	Michael Gautier
	\copyright 	Apache License 2.0
	\par 		Copyright 2015 Michael Gautier
	Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 . Software distributed under the License is distributed on an "AS IS" BASIS, NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit. See the License for details on permissions and limitations.
*/
namespace gautier
{
	namespace interaction
	{
		///	Structured flags processes use to create the types implied.
		enum interaction_def_type
		{
			interaction_def_type_none = 0,
			interaction_def_type_composition,
			interaction_def_type_planar_def
		};

		///	Defines the basic properties of an item to be output.
		struct planar_def
		{
			bool 
				///	A value of true is a hint to consider text and other inputs as affiliated with this planar.
				receives_input = false
			;

			unsigned int 
				///	Specifies how much of an input quantity (characters, selection options, etc) will be accepted.
				input_limit = 16
			;

			float 
				///	Horizontal position.
				x = -1,
				///	Vertical position.
				y = -1,
				///	Logical line magnitude from x.
				width = -1,
				///	Logical line magnitude from y.
				height = -1
			;

			std::string 
				///	Identifies the planar to processes.
				name = "",
				///	A text label that may be output on screen.
				text = "",
				///	Text data entered, normally by keyboard.
				input_text_value = ""
			;
		};

		///	A grouping of planar definitions.
		struct composition
		{
			std::string 
				///	Identifies a group of planars.
				name = "",
				///	A text label that may be output on screen.
				text = ""
			;

			std::map<std::string, planar_def> 
				///	Planars for a composition tagged by name of each planar.
				composites
			;

			///	Constructor initializes list of planars.
			composition():composites(){}
		};

		///	Describes recent user interface input to a program.
		struct input_def
		{
			bool 
				///	Indicates the top-most element is active in the user interface.
				root_context_is_active = true,
				///	Keyboard key was pressed or is held in the down position.
				input_key_is_down = false,
				///	Keyboard key just released.
				input_key_is_up = false,
				///	Mouse button was pressed or is held in the down position.
				input_mouse_is_down = false,
				///	Mouse button was released.
				input_mouse_is_up = false,
				///	Left mouse button was used.
				input_mouse_button_is_left = false,
				///	Right mouse button was used.
				input_mouse_button_is_right = false,
				///	Middle mouse button was used.
				input_mouse_button_is_middle = false,
				///	A mouse double-click was detected.
				input_mouse_double_click = false,
				///	A backspace key was pressed.
				input_text_remove_last_char = false
			;

			int 
				///	Total times the keyboard key was released.
				input_key_up_sequence_count = 0,
				///	Total times the keyboard key was pressed.
				input_key_down_sequence_count = 0,
				///	Total times the mouse button was released.
				input_mouse_up_sequence_count = 0,
				///	Total times the mouse button was pressed.
				input_mouse_down_sequence_count = 0
			;

			float 
				///	Primary graphical element width.
				root_context_width = -1,
				///	Primary graphical element height.
				root_context_height = -1,
				///	X position where the mouse was when an event occured.
				input_mouse_x = -1,
				///	Y position where the mouse was when an event occured.
				input_mouse_y = -1,
				///	X position saved since last event.
				input_top_x = -1,
				///	Y position saved since last event.
				input_top_y = -1
			;

			std::string 
				///	Text printable name of the last event encountered.
				last_event_captured = "",
				///	Text data captured. Should be limited to printable characters as defined in std::isprint().
				input_text_value = ""
			;

			char 
				///	A single character. Some graphical interactive engines will report a character that can be converted to std::string. The sequence then is to migrate the value here to the input_text_value field.
				input_char_value = '\n'
			;
		};

		///	List of planars. A z-order list of layouts for a graphical output engine.
		using type_visual_response_model = std::vector<planar_def>;

		///	List of text data values with a tag naming the value.
		using type_text_keyvaluepair_list = std::map<std::string, std::string>;

		///	List of interaction_def_type enumeration values with a tag naming the value.
		using type_data_key_to_interaction_def_list = std::map<std::string, interaction_def_type>;

		///	A single interaction_def_type value with a tag set by callers. Normally used in conjunction with instances of type_data_key_to_interaction_def_list to translate data in which the tag identifies a key.
		using type_data_key_to_interaction_def_pair = std::pair<std::string, interaction_def_type>;
	}
}
