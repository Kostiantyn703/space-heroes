#include "input_handler.h"

#include <memory>
#include <iostream>
#include <utility>
#include "SDL.h"

#include "command.h"

input_handler::input_handler()
{
	// return key command
	command* primary_comm = new primary_command;
	SDL_Keycode return_key = SDLK_RETURN;
	m_commands.insert(std::make_pair(return_key, primary_comm));
	// escape key command
	command* secondary_comm = new secondary_command;
	SDL_Keycode escape_key = SDLK_ESCAPE;
	command_pair escape_command = std::make_pair(escape_key, secondary_comm);
	m_commands.insert(escape_command);
}

input_handler::~input_handler()
{

}

void input_handler::handle_input()
{
	while (SDL_PollEvent(&m_current_event) != 0) {
		if (m_current_event.type == SDL_KEYDOWN) {
			m_commands.find(m_current_event.key.keysym.sym)->second->execute();
		}
	}
}
