/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/

#include "gautier_json_mapping.hpp"

static auto get_jsoncpp_value_type_name(const int type_code) -> std::string
{
	std::string type_name;

	switch(type_code)
	{
		case Json::ValueType::nullValue://'null' value
			type_name = "null";
		break;
		case Json::ValueType::intValue://signed integer value
			type_name = "int";
		break;
		case Json::ValueType::uintValue://unsigned integer value
			type_name = "uint";
		break;
		case Json::ValueType::realValue://double value
			type_name = "real";
		break;
		case Json::ValueType::stringValue://UTF­8 string value.
			type_name = "string";
		break;
		case Json::ValueType::booleanValue://bool value
			type_name = "boolean";
		break;
		case Json::ValueType::arrayValue://array value (ordered list)
			type_name = "array";
		break;
		case Json::ValueType::objectValue://object value (collection of name/value pairs).
			type_name = "object";
		break;
	}

	return type_name;
}

static auto get_json_node_is_value_type(const Json::Value& instance_node) -> bool
{
	return (instance_node.isIntegral() || instance_node.isString());
}
