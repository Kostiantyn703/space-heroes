#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <map>
#include <memory>
#include "SDL.h"

#include "command.h"

class input_handler
{
using commands_map = std::map<SDL_Keycode, command*>;
using command_pair = std::pair<SDL_Keycode, command*>;
public:
	input_handler();
	~input_handler();

	void handle_input();
private:
	SDL_Event m_current_event;

	commands_map m_commands;
};
#endif // INPUT_HANDLER_H
