/*! 	\file
 	\brief 	Implementation commonly useful functions.
 	\pre		ISO C++ 11 or later compliant compiler with an available C++ 11 STL implementation.
 	\version	4
 	\date		4/21/2015
 	\author 	Michael Gautier
 	\copyright 	Apache License 2.0
 	\par 		Copyright 2015 Michael Gautier
 	Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 . Software distributed under the License is distributed on an "AS IS" BASIS, NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit. See the License for details on permissions and limitations.
*/
#include <algorithm>

#ifndef __gautier_core__
#define __gautier_core__
#include "gautier_core.hpp"
#endif

///	Naturally translates return value of std::isdigit to boolean.
auto is_digit(const char value) -> bool 
{ 
	return std::isdigit(value); 
}

bool gautier::is_numeric(const std::string& value) 
{ 
	return std::all_of(value.begin(), value.end(), is_digit); 
}

