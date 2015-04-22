/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/


/*
-----------------------------

Actual program

-----------------------------
*/
#include "gautier_core.hpp"
#include "gautier_program_models.hpp"

#include <iostream>

namespace gautier
{
	namespace program
	{
		auto process_interaction_model(gautier::interaction::type_interaction_model layout_model, gautier::interaction::input_def& instance_input_model) -> gautier::interaction::type_visual_response_model;
	}
}
