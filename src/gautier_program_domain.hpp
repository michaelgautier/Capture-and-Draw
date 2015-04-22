/*! 	\file
	\brief		Interface for the program's main implementation.
	\par		Description
	The functions here are referenced by the program's entry point in main(). Each function constitute the functionality of the program at an application level.
	\pre		ISO C++ 11 or later compliant compiler with an available C++ 11 STL implementation.
	\version	4
	\date		2/11/2015 4/21/2015
	\author 	Michael Gautier
	\copyright 	Apache License 2.0
	\par 		Copyright 2015 Michael Gautier
	Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 . Software distributed under the License is distributed on an "AS IS" BASIS, NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit. See the License for details on permissions and limitations.
*/

#include "gautier_interaction_types.hpp"

namespace gautier
{
	namespace program
	{
		auto process_input(gautier::interaction::input_def& instance_input_model) -> gautier::interaction::type_visual_response_model;
	}
}
