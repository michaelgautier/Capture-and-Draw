/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/
//#if UXLevel == 1	//sfml implementation

#include "gautier_core.hpp"
#include "gautier_interaction_sfml.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

bool sfml_interaction_process_active = true;

auto gautier::interaction::implsfml::check_interaction_process_is_active_impl() -> bool
{
	return sfml_interaction_process_active;
}

auto gautier::interaction::implsfml::set_interaction_process_is_active_impl(bool value) -> void
{
	sfml_interaction_process_active = value;
	
	return;
}

auto gautier::interaction::implsfml::define_context_properties_impl(const std::pair<float, float>& extent, const std::string& title) -> void
{
	/*
		Overall visual window
			Everything visual/interactive will fit inside this container by default.
	*/
	auto width = static_cast<uint>(extent.first);
	auto height = static_cast<uint>(extent.second);

	instance_interaction_context.reset(
	    new sf::RenderWindow(
		sf::VideoMode(
		    width,
		    height
		),
		title
	    )
	);

	return;
}

//For testing purposes.
auto execute_sfml_quick_test() -> int
{
	using namespace gautier::interaction::implsfml;
	// Start the loop
	while(instance_interaction_context->isOpen())
	{
		// Process events
		sf::Event event;

		while(instance_interaction_context->pollEvent(event))
		{
			// Close window : exit
			if(event.type == sf::Event::Closed)
			{
				instance_interaction_context->close();
			}
		}

		// Clear screen
		instance_interaction_context->clear(sf::Color::Blue);
		// Update the window
		instance_interaction_context->display();
	}

	return 0;
}

//Interaction Implementation, sfml
auto gautier::interaction::implsfml::run_basic_capabilities_test_impl() -> int
{
	return execute_sfml_quick_test();
}

auto gautier::interaction::implsfml::check_point_within_area_impl(const std::vector<float>& xy, const std::vector<float>& xywh) -> bool
{
	auto return_value = false;

	if(xy.size() > 1 && xywh.size() > 3)
	{
		sf::FloatRect area(xywh[0], xywh[1], xywh[2], xywh[3]);
	
		return_value = area.contains(xy[0], xy[1]);
	}
	
	return return_value;
}

auto gautier::interaction::implsfml::check_area_overlaps_impl(const std::vector<float>& xywh1, const std::vector<float>& xywh2) -> bool
{
	auto return_value = false;

	if(xywh1.size() > 3 && xywh2.size() > 3)
	{
		sf::FloatRect area1(xywh1[0], xywh1[1], xywh1[2], xywh1[3]);
		sf::FloatRect area2(xywh2[0], xywh2[1], xywh2[2], xywh2[3]);
	
		return_value = area1.intersects(area2);
	}
	
	return return_value;
}

auto gautier::interaction::implsfml::capture_state_impl(input_def& instance_input_model) -> void
{
	// Process events
	sf::Event event;

	auto event_available = instance_interaction_context->pollEvent(event);

	/*
		Update state machine.
	*/
	if(event_available)
	{
		if(event.type == sf::Event::Closed)
		{
			sfml_interaction_process_active = false;
			instance_input_model.root_context_is_active = false;

			instance_interaction_context->close();
		}
		else if(event.type == sf::Event::Resized)
		{
			instance_input_model.root_context_height = static_cast<float>(event.size.height);
			instance_input_model.root_context_width = static_cast<float>(event.size.width);
			
			auto area_update = sf::FloatRect(0, 0, instance_input_model.root_context_width, instance_input_model.root_context_height);
			
			instance_interaction_context->setView(sf::View(area_update));
		}
		else if(event.type == sf::Event::KeyPressed)
		{
			instance_input_model.input_key_is_down = true;
			//event.keycode	//the actual key entered. //do not need to capture that at his time.
		}
		else if(event.type == sf::Event::KeyReleased)
		{
			instance_input_model.input_key_is_up = true;
			//event.keycode	//the actual key entered.
			instance_input_model.input_key_sequence_count++;
		}
		else if(event.type == sf::Event::TextEntered)
		{
			//A substitute for running a function to decide if a key was entered
			//and what text was entered at that time.
			//This captures the text entered.
			instance_input_model.input_char_value = static_cast<const char>(event.text.unicode);
			instance_input_model.input_text_value += instance_input_model.input_char_value;
		}
		else if(event.type == sf::Event::MouseButtonPressed)
		{
			instance_input_model.input_mouse_is_down = true;
		}
		else if(event.type == sf::Event::MouseButtonReleased)
		{
			instance_input_model.input_mouse_is_up = true;
			instance_input_model.input_mouse_x = static_cast<float>(event.mouseButton.x);
			instance_input_model.input_mouse_y = static_cast<float>(event.mouseButton.y);
		}
		/*
			//The remaining events not interested in.
			if(event.type == sf::Event::GainedFocus)
			if(event.type == sf::Event::MouseWheelMoved)
			if(event.type == sf::Event::MouseMoved)
			if(event.type == sf::Event::MouseEntered)
			if(event.type == sf::Event::MouseLeft)
			if(event.type == sf::Event::JoystickButtonPressed)
			if(event.type == sf::Event::JoystickButtonReleased)
			if(event.type == sf::Event::JoystickMoved)
			if(event.type == sf::Event::JoystickConnected)
			if(event.type == sf::Event::JoystickDisconnected)
			if(event.type == sf::Event::Count)
		*/
	}

	return;
}

auto gautier::interaction::implsfml::update_state_impl(const type_visual_response_model& instance_visual_response_model) -> int
{
	// Clear screen
	instance_interaction_context->clear(sf::Color::Blue);
	
	if(instance_visual_response_model.size() > 0)
	{
		for(auto planar_item : instance_visual_response_model)
		{
			sf::RectangleShape item_to_draw(sf::Vector2f(planar_item.width, planar_item.height));
			item_to_draw.setPosition(planar_item.x, planar_item.y);

			instance_interaction_context->draw(item_to_draw);
		}
	}

	// Update the window
	instance_interaction_context->display();

	
	return EXIT_SUCCESS;
}
//#endif
