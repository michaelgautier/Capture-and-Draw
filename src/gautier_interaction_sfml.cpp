/*!	\file
	\brief		GUI logic direct dispatch to SFML API.
	\par		Description
	Applies the SFML technology within a single module. Calls to SFML functions, and specific types for SFML are organized into the functions listed.
	\pre		ISO C++ 11 or later compliant compiler with an available C++ 11 STL implementation.
	\pre		Simple Fast Media Library 2.1 or later
	\version	4
	\date		4/14/2015, 4/21/2015
	\author 	Michael Gautier
	\copyright 	Apache License 2.0
	\par 		Copyright 2015 Michael Gautier
	Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 . Software distributed under the License is distributed on an "AS IS" BASIS, NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit. See the License for details on permissions and limitations.
*/

#include "gautier_core.hpp"
#include "gautier_interaction_sfml.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <memory>

///	Type for the Visual Context.
using type_interaction_context = std::unique_ptr<sf::RenderWindow>;

///	Visual Context used to gather input and send output. It must exist at a scope above those of callers that access its functions.
type_interaction_context instance_interaction_context;

///	List of event names accessible by the event type normally output from the visual context.
std::map<sf::Event::EventType, std::string> event_names;

///	Primary font for the output of graphical text objects. SFML documentation advises maintaining instances of this object in a manner that avoids premature cleanup prior to calls to draw.
sf::Font default_font;

///	A 12pt font for graphical text.
const auto default_font_size = 12;

///	Tracks if font activation was successful.
auto default_font_is_loaded = false;

///	Generally indicates if the visual context is active. Updated on all accesses to the visual context's event query routines.
bool sfml_interaction_process_active = true;

///	Maps sf::Event to print friendly names that the can be used for evaluative and diagnostic purposes.
auto init_event_names() -> void
{
	if(event_names.size() == 0)
	{
		event_names[sf::Event::Closed] = "Closed";
		event_names[sf::Event::Count] = "Count";
		event_names[sf::Event::GainedFocus] = "GainedFocus";
		event_names[sf::Event::JoystickButtonPressed] = "JoystickButtonPressed";
		event_names[sf::Event::JoystickButtonReleased] = "JoystickButtonReleased";
		event_names[sf::Event::JoystickConnected] = "JoystickConnected";
		event_names[sf::Event::JoystickDisconnected] = "JoystickDisconnected";
		event_names[sf::Event::JoystickMoved] = "JoystickMoved";
		event_names[sf::Event::KeyPressed] = "KeyPressed";
		event_names[sf::Event::KeyReleased] = "KeyReleased";
		event_names[sf::Event::MouseButtonPressed] = "MouseButtonPressed";
		event_names[sf::Event::MouseButtonReleased] = "MouseButtonReleased";
		event_names[sf::Event::MouseEntered] = "MouseEntered";
		event_names[sf::Event::MouseLeft] = "MouseLeft";
		event_names[sf::Event::MouseMoved] = "MouseMoved";
		event_names[sf::Event::MouseWheelMoved] = "MouseWheelMoved";
		event_names[sf::Event::Resized] = "Resized";
		event_names[sf::Event::TextEntered] = "TextEntered";
	}

	return;
}

static const auto get_default_font_face() -> const std::string
{
	//Will need to validate font sources in the future.
	//	Using a default Linux distro font.
	//	Will need to query fonts and select appropriate to operating system.

	return "/usr/share/fonts/truetype/freefont/FreeSans.ttf";
}

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
	init_event_names();
	//Overall visual window
	//	Everything visual/interactive will fit inside this container by default.
	
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

	//SFML 2.1 documentation for the Text class says never use a local instance of a Font class.
	//All fonts instances must exist outside function scope.
	
	default_font_is_loaded = default_font.loadFromFile(get_default_font_face());

	return;
}

///	Implements the quick testing of SFML functionality.
auto execute_sfml_quick_test() -> int
{
	using namespace gautier::interaction::implsfml;
	//Start the loop
	while(instance_interaction_context->isOpen())
	{
		//Process events
		sf::Event event;

		while(instance_interaction_context->pollEvent(event))
		{
			//Close window : exit
			if(event.type == sf::Event::Closed)
			{
				instance_interaction_context->close();
			}
		}

		//Clear screen
		instance_interaction_context->clear(sf::Color::Blue);
		//Update the window
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
	//Process events
	sf::Event event;

	auto event_available = instance_interaction_context->pollEvent(event);

	//Update state
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
			instance_input_model.input_key_is_up = false;
			//event.keycode	The actual key entered. do not need to capture that at his time.
			instance_input_model.input_key_down_sequence_count++;
		}
		else if(event.type == sf::Event::KeyReleased)
		{
			instance_input_model.input_key_is_up = true;
			instance_input_model.input_key_is_down = false;
			instance_input_model.input_text_remove_last_char = (event.key.code == sf::Keyboard::Key::BackSpace);
			//event.keycode	The actual key entered.
			instance_input_model.input_key_up_sequence_count++;
		}
		else if(event.type == sf::Event::TextEntered)
		{
			//A substitute for running a function to decide if a key was entered
			//	and what text was entered at that time.
			//	This captures the text entered.

			//Casting using (char) does work better with control characters but traits provides a cleaner interface.
			instance_input_model.input_char_value = std::char_traits<char>::to_char_type(event.text.unicode);

			//std::cout << "character " << instance_input_model.input_char_value << gautier::OUTENDL;

			//The following avoids undefined behavior with std::string involving control characters.
			//	Limited the span of input characters to only those that are printable.
			if(std::isprint(instance_input_model.input_char_value))
			{
				instance_input_model.input_text_value.push_back(instance_input_model.input_char_value);
			}
		}
		//	Observations using
		//	SFML version 2.1 
		//	Will identify a mouse button press with two events. MouseButtonPressed and JoystickButtonPressed
		//		as well as MouseButtonReleased and JoystickButtonReleased.
		//	Observed Apr 20 2015
		//		in a virtual machine running fully updated Xubuntu 14.04 LTS
		else if(event.type == sf::Event::MouseButtonPressed)
		{
			//std::cout << "Mouse Down ----------------------------------" << gautier::OUTENDL;
			instance_input_model.input_mouse_is_up = false;
			instance_input_model.input_mouse_is_down = true;
			instance_input_model.input_mouse_down_sequence_count++;

			instance_input_model.input_mouse_x = static_cast<float>(event.mouseButton.x);
			instance_input_model.input_mouse_y = static_cast<float>(event.mouseButton.y);
		}
		else if(event.type == sf::Event::MouseButtonReleased)
		{
			//std::cout << "Mouse Up ----------------------------------" << gautier::OUTENDL;
			instance_input_model.input_mouse_is_down = false;
			instance_input_model.input_mouse_is_up = true;
			instance_input_model.input_mouse_up_sequence_count++;

			auto mouse_updown_count = (instance_input_model.input_mouse_up_sequence_count + instance_input_model.input_mouse_down_sequence_count);
			auto mouse_last_x = static_cast<int>(instance_input_model.input_mouse_x);
			auto mouse_last_y = static_cast<int>(instance_input_model.input_mouse_y);

			auto mouse_current_x = event.mouseButton.x;
			auto mouse_current_y = event.mouseButton.y;

			instance_input_model.input_mouse_double_click = 
				((mouse_updown_count == 4)
				&& (mouse_last_x == mouse_current_x)
				&& (mouse_last_y == mouse_current_y));
			
			//Visualizes the sequence of mouse up/down activity relevant for defining a simple double-click.
			//std::cout << " m dwn   " << (instance_input_model.input_mouse_is_down ? "y" : "n") << gautier::OUTENDL;
			//std::cout << " m  up   " << (instance_input_model.input_mouse_is_up ? "y" : "n") << gautier::OUTENDL;
			//std::cout << " m dwn + " << (instance_input_model.input_mouse_down_sequence_count) << gautier::OUTENDL;
			//std::cout << " m  up + " << (instance_input_model.input_mouse_up_sequence_count) << gautier::OUTENDL;
			//std::cout << " m lst x " << (mouse_last_x) << gautier::OUTENDL;
			//std::cout << " m lst y " << (mouse_last_y) << gautier::OUTENDL;
			//std::cout << " m now x " << (mouse_current_x) << gautier::OUTENDL;
			//std::cout << " m now y " << (mouse_current_y) << gautier::OUTENDL;
			//std::cout << " dblclk? " << (instance_input_model.input_mouse_double_click ? "y" : "n") << gautier::OUTENDL;
		}

		//The remaining events.
		//Not presently interested in using any of the following listed.
		//sf::Event::GainedFocus
		//sf::Event::MouseWheelMoved
		//sf::Event::MouseMoved
		//sf::Event::MouseEntered
		//sf::Event::MouseLeft
		//sf::Event::JoystickButtonPressed
		//sf::Event::JoystickButtonReleased
		//sf::Event::JoystickMoved
		//sf::Event::JoystickConnected
		//sf::Event::JoystickDisconnected
		//sf::Event::Count

		//Track the last event for diagnostic and evaluation purposes.
		instance_input_model.last_event_captured = event_names[event.type];
		
		//std::cout << instance_input_model.last_event_captured << gautier::OUTENDL;
	}

	return;
}

auto gautier::interaction::implsfml::update_state_impl(const type_visual_response_model& instance_visual_response_model) -> int
{
	//Clear screen
	instance_interaction_context->clear(sf::Color::Blue);
	
	if(instance_visual_response_model.size() > 0)
	{
		for(auto planar_item : instance_visual_response_model)
		{
			auto ref_x = planar_item.x;
			auto ref_y = planar_item.y;
			auto ref_w = planar_item.width;
			auto ref_h = planar_item.height;
			
			sf::RectangleShape item_to_draw(sf::Vector2f(ref_w, ref_h));
			item_to_draw.setPosition(ref_x, ref_y);

			instance_interaction_context->draw(item_to_draw);

			if(planar_item.receives_input &&
			!planar_item.input_text_value.empty())
			{
				//std::cout << "plan to output " << planar_item.input_text_value << " to " << ref_x << "/" << ref_y << gautier::OUTENDL;
				if (default_font_is_loaded)
				{
					//std::cout << "font loaded" << gautier::OUTENDL;

					sf::Text text_visual(planar_item.input_text_value, default_font, default_font_size);
					text_visual.setPosition(ref_x, ref_y);
					text_visual.setColor(sf::Color::Black);

					instance_interaction_context->draw(text_visual);
				}
			}
		}
	}

	//Update the window
	instance_interaction_context->display();

	return EXIT_SUCCESS;
}
