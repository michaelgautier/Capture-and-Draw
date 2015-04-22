/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/

#include "gautier_core.hpp"
#include "gautier_interaction.hpp"

#include <iostream>

auto gautier::interaction::get_planars(const composition& instance_composition) -> type_visual_response_model
{
	type_visual_response_model previsuals;
	
	for(auto planar_keyvalue : instance_composition.composites)
	{
		previsuals.push_back(planar_keyvalue.second);
	}

	return previsuals;
}
		
auto gautier::interaction::check_interaction_process_is_active() -> bool
{
	return impl_ns::check_interaction_process_is_active_impl();
}

auto gautier::interaction::set_interaction_process_is_active(bool value) -> void
{
	impl_ns::set_interaction_process_is_active_impl(value);

	return;
}

auto gautier::interaction::define_context_properties(const std::pair<float, float>& extent, const std::string& title) -> void
{
	impl_ns::define_context_properties_impl(extent, title);
	
	return;
}

auto gautier::interaction::make_default_data_key_to_interaction_def_pair() -> type_data_key_to_interaction_def_pair
{
	return std::make_pair("", interaction_def_type::interaction_def_type_none);
}

auto gautier::interaction::get_data_key_to_interactive_def_pair(const std::string& value, const type_data_key_to_interaction_def_list& instance_principle_key_map) -> type_data_key_to_interaction_def_pair
{
	type_data_key_to_interaction_def_pair instance_primary_key = make_default_data_key_to_interaction_def_pair();

	auto candidate_key = instance_principle_key_map.find(value);

	if(candidate_key != instance_principle_key_map.end())
	{
		instance_primary_key = std::make_pair(candidate_key->first, candidate_key->second);
	}

	return instance_primary_key;
}

auto gautier::interaction::output_composition_to_console(const composition& instance_composition) -> void
{
	std::cout << "composition name " << instance_composition.name << gautier::OUTENDL;
	std::cout << "composition text " << instance_composition.text << gautier::OUTENDL;
	std::cout << "composites size " << instance_composition.composites.size() << gautier::OUTENDL; 
	
	for(auto entry_composite : instance_composition.composites)
	{
		std::cout << "entry name, planar_def " << entry_composite.first << gautier::OUTENDL;
		
		auto instance_planar = entry_composite.second;
		
		std::cout << "planar_def description " 
		<< instance_planar.name << " " 
		<< instance_planar.text << " x "
		<< instance_planar.x << " y "
		<< instance_planar.y << " width "
		<< instance_planar.width << " height "
		<< instance_planar.height << gautier::OUTENDL;
	}

	return;
}

auto gautier::interaction::axis_modify_x_right_align(const planar_def& in_bnds, planar_def& out_bnds) -> float
{
	out_bnds.x = (in_bnds.width - out_bnds.width) + in_bnds.x;

	return out_bnds.x;
}

auto gautier::interaction::axis_modify_x_center_align(const planar_def& in_bnds, planar_def& out_bnds) -> float
{
	out_bnds.x = ((in_bnds.width / 2) + in_bnds.x) - (out_bnds.width / 2);

	return out_bnds.x;
}

auto gautier::interaction::axis_modify_y_space_align(const float& magnitude, const planar_def& in_bnds, planar_def& out_bnds) -> float
{
	out_bnds.y = (in_bnds.y - in_bnds.height) - magnitude;

	return out_bnds.y;
}

auto gautier::interaction::axis_modify_y_center_align(const planar_def& in_bnds, planar_def& out_bnds) -> float
{
	out_bnds.y = (in_bnds.y) - ((in_bnds.height / 2) - (out_bnds.height / 2));

	return out_bnds.y;
}

auto gautier::interaction::axis_modify_y_top_align(const planar_def& in_bnds, planar_def& out_bnds) -> float
{
	out_bnds.y = (in_bnds.y + in_bnds.height) - out_bnds.height;

	return out_bnds.y;
}

auto gautier::interaction::Function01_InputMappedToGeometry() -> float
{
	return 0;
}

auto gautier::interaction::Function02_VisualStructureToVisualOutput() -> float
{
	return 0;
}

auto gautier::interaction::update_text_buffer_by_name(std::map<std::string, std::string>& txtbfr, const std::string& name, input_def& input) -> void
{
	txtbfr[name] += input.input_text_value;

	input.input_text_value = "";
	
	return;
}
//Interaction Implementation, Generic
auto gautier::interaction::run_basic_capabilities_test() -> int
{
	return impl_ns::run_basic_capabilities_test_impl();
}

auto gautier::interaction::check_point_within_area(const std::vector<float>& xy, const std::vector<float>& xywh) -> bool
{
	return impl_ns::check_point_within_area_impl(xy, xywh);
}

auto gautier::interaction::check_point_within_area(const input_def& src, const planar_def& area) -> bool
{
	return impl_ns::check_point_within_area_impl({src.input_mouse_x, src.input_mouse_y}, {area.x, area.y, area.width, area.height});
}

auto gautier::interaction::check_area_overlaps(const std::vector<float>& xywh1, const std::vector<float>& xywh2) -> bool
{
	return impl_ns::check_area_overlaps_impl(xywh1, xywh2);
}

auto gautier::interaction::check_area_overlaps(const planar_def& area1, const planar_def& area2) -> bool
{
	return impl_ns::check_area_overlaps_impl({area1.x, area1.y, area1.width, area1.height}, {area2.x, area2.y, area2.width, area2.height});
}

auto gautier::interaction::capture_state(input_def& instance_input_model) -> void
{
	impl_ns::capture_state_impl(instance_input_model);

	return;
}

auto gautier::interaction::update_state(const type_visual_response_model& instance_visual_response_model) -> int
{
	return impl_ns::update_state_impl(instance_visual_response_model);
}
