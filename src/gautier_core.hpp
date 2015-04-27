/*! 	\file
 	\brief 	Fundamental definitions useful to an entire solution.
 	\par		Description
 	Common variables and functions of a general nature. See the Description section in "gautier_interation.hpp" titled, "Project History, Meaning of the Version Number", for further details on the project history.
 	\pre		ISO C++ 11 or later compliant compiler with an available C++ 11 STL implementation.
 	\version	4
 	\date		4/21/2015
 	\author 	Michael Gautier
 	\copyright 	Apache License 2.0
 	\par 		Copyright 2015 Michael Gautier
 	Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 . Software distributed under the License is distributed on an "AS IS" BASIS, NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit. See the License for details on permissions and limitations.
*/

///	\brief	Top-level namespace.
///	Contains the variables and functions relevant solution wide.
namespace gautier
{
	///	A bit faster than std::endl;
	constexpr auto OUTENDL = "\n";
	///	Simple check of a std::string to assert each digit is a character using std::all_of with is_digit as the unary predicate.
	auto is_numeric(const std::string& value) -> bool;
}
