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

auto gautier::interaction::implsfml::capture_state_impl(input_def& instance_input_model) -> void
{
	std::cout << "sfml Impl: capture_state()" << gautier::OUTENDL;
	// Process events
	sf::Event event;

	auto unavailble_event_count = 0;
	auto event_check_count = 0;
	const auto limit = gautier::interaction::MAX_UNAVAILABLE_EVENTS;

	while(unavailble_event_count <= limit || event_check_count <= limit)
	{
		unavailble_event_count++;
		event_check_count++;

		auto event_available = instance_interaction_context->pollEvent(event);

		/*
			Update state machine.
		*/
		if(event_available)
		{
			// Close window : exit
			if(event.type == sf::Event::Closed)
			{
				instance_interaction_context->close();
			}
			else
			{
				instance_input_model.x = 0;
				instance_input_model.y = 0;
			}
		}
	}

	return;
}

auto gautier::interaction::implsfml::update_state_impl(const type_visual_response_model& instance_visual_response_model) -> int
{
	std::cout << "sfml Impl: update_state()" << gautier::OUTENDL;

	// Clear screen
	instance_interaction_context->clear(sf::Color::Blue);
	
	if(instance_visual_response_model.size() > 0)
	{
		// Update the window
		instance_interaction_context->display();
	}
	
	return EXIT_SUCCESS;
}
//#endif
