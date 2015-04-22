/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/
#include "gautier_program.hpp"

/*
	Constants
*/
//static constexpr short DEFAULT_MAX_UNITS = 80;
static constexpr short ICTX_DEFAULT_WIDTH = 1024;
static constexpr short ICTX_DEFAULT_HEIGHT = 728;

static constexpr std::pair<float, float> ICTX_DEFAULT_EXTENT =
{
	ICTX_DEFAULT_WIDTH,
	ICTX_DEFAULT_HEIGHT
};

static const std::string COUT_SECTION = "----------------------------";
static const std::string ICTX_DEFAULT_TITLE = "Gautier App Context";

/*
	Functions
*/
auto define_interaction_model() -> gautier::interaction::type_interaction_model
{
	const std::string ui_spec = 
	"[		\
		{	\
			\"context_elemid\": \"loginscreen\", \
			\"context_phrase\": \"Login Screen\", \
			 \"composites\": [\
				{ \
					\"planar_elemid\": \"username\", \
					\"planar_phrase\": \"User name\", \
					\"x\": 100.00, \
					\"y\": 200.00, \
					\"width\": 300.00, \
					\"height\": 400.00 \
				},\
				{ \
					\"planar_elemid\": \"password\", \
					\"planar_phrase\": \"Password\", \
					\"x\": 100.00, \
					\"y\": 300.00, \
					\"width\": 300.00, \
					\"height\": 400.00 \
				}\
			]\
		},	\
		{	\
			\"context_elemid\": \"profilescreen\", \
			\"context_phrase\": \"Profile Screen\", \
			 \"composites\": [\
				{ \
					\"planar_elemid\": \"firstname\", \
					\"planar_phrase\": \"First name\", \
					\"x\": 100.00, \
					\"y\": 80.00, \
					\"width\": 250.00, \
					\"height\": 44.00 \
				},\
				{ \
					\"planar_elemid\": \"lastname\", \
					\"planar_phrase\": \"Last name\", \
					\"x\": 200.00, \
					\"y\": 80.00, \
					\"width\": 350.00, \
					\"height\": 44.00 \
				}\
			]\
		}	\
	]		\
	";

	auto instance_interaction_model = gautier::program::models::create_interaction_model_from_JSONValue(ui_spec);

	return instance_interaction_model;
}

auto configure_interaction() -> gautier::interaction::type_interaction_model
{
	gautier::interaction::define_context_properties(ICTX_DEFAULT_EXTENT, ICTX_DEFAULT_TITLE);

	auto instance_interaction_models = define_interaction_model();

	gautier::interaction::output_model_to_console(instance_interaction_models);

	return instance_interaction_models;
}

auto gautier::program::execute() -> int
{
	auto return_value = 0;
	auto instance_interaction_models = configure_interaction();

	gautier::interaction::input_def instance_input_model;
	
	/*Accuracy and speed is essential for this to work.*/
	while(gautier::interaction::check_interaction_process_is_active())
	{
		//capture state
		gautier::interaction::capture_state(instance_input_model);

		/*
		THE INPUT***********
		
			Capture state details
				Need to saturate a struct with a snapshot of the input frame.
				Capture as much information as is available.

				Essential data design:
					Updates are additive.
					Just a continuous stream of inputs.
					Data container needs to be stateful.
					Need the primary state of the inputs.
					Need secondary state of the change to inputs.
					Use secondary state to affect control flow on primary state.
					You have two types of data:
						Data for Interactive Disposition
						Data for Control Flow Modification
					The state will exist thrice:
							Working state. A copy of previous state, then updated from device input.
							Current state. A copy of working state.
							Previous state. A copy of current state.
							
							Working state is created when the update process enters modification mode.
							In case of error or no updates, previous and current states are not changed.
							Current state becomes previous state.
							Working state becomes current state.
					The data structure is readonly everywhere except here.
				
				Need a function that will update the state:
					Several functions with a common prefix to define a group of functions.
					Each function is independent of the others.
					A single function maps the device input state to the interactive state.
						One of the functions deal with detecting double-clicks for example.
						One of the functions deal with key sequence interpretation.
							Reconciles last key entered with current key to produce a higher level designation.
							
						It follows one of these functions proceeds after the other.
						
						Function call is deterministic and follows a prescribed path.
						
						Another function will determine rudimentary input events.
							Events may be queued.
							A control flow indicator needs a timeout on acknowledging the event.
							No downstream event acknowledgement will be possible.
							The data structure is readonly outside of this process.


		*/



		//application specific logic goes here.
		auto instance_output_model = process_interaction_model(instance_interaction_models, instance_input_model);

		/*
		THE PROGRAM DOMAIN***********

			Read the device input state and map to a model of the output structure.
			
				Decide which model is active.
				Modify the model inplace.
				
				Visual changes occur partly through the use of geometry functions defined in gautier_interaction.hpp
				
				May end up with a multi function process.
				
					When the request model is not loaded.
					
						1. A function that loads a model template.
						2. The template becomes the current working copy.

					When the request model is active.
					
						1. Update the current working copy.
						2. Produce a geometry model.
						
							A couple of functions for that.
							These functions will create a coarse grained model destined for the update_state function.
							
		*/


		//present state
		return_value = gautier::interaction::update_state(instance_output_model);//defer to graphics translation engine
		
		/*
		THE OUTPUT***********

				The update_state function can decide what to do with the coarse grained model.
				The model came from the application logic phase.
					It may convert the coarse grained model to matrix strings for input into OpenGL
					It will likely map the coarse grained model into a series of geometric types for SFML.
					The design does what is appropriate or possible for the particular graphics implementation.

		*/
	}

	return return_value;
}
