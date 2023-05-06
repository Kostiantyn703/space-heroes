#include "input_handler.h"

#include <memory>
#include <iostream>
#include <utility>
#include "SDL.h"

#include "command.h"

input_handler::input_handler()
{
	// return key command
	m_commands.insert(std::make_pair(SDLK_RETURN, std::make_unique<primary_command>()));
	// escape key command
	m_commands.insert(std::make_pair(SDLK_ESCAPE, std::make_unique<secondary_command>()));
}

input_handler::~input_handler()
{
	m_commands.clear();
}

command *input_handler::handle_input()
{
	while (SDL_PollEvent(&m_current_event) != 0) {
		if (m_current_event.type == SDL_KEYDOWN) {
			return m_commands.find(m_current_event.key.keysym.sym)->second.get();
		}
	}
	return nullptr;
}
