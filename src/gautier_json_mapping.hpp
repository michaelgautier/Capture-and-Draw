/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/


/*
-----------------------------

Tools to *help* map generic JSON formatted data to data types specific to the project.
These tools do not do the mapping, but reduce the amount of code needed at the application level.

-----------------------------
*/
#ifndef gautier_json_mapping
#define gautier_json_mapping

#include "json/json.h"

namespace gautier
{
	namespace dataconv
	{
		namespace JSON
		{
			static auto get_jsoncpp_value_type_name(const int type_code) -> std::string;
			static auto get_json_node_is_value_type(const Json::Value& instance_node) -> bool;
		}
	}
}
#endif
