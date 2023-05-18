#include "game.h"

#include "SDL.h"

#include "game_state.h"
#include "engine.h"
#include "input_handler.h"

game::game()
	: active(true)
{
	init();
	SDL_Log("Game constructed");
}

game::~game()
{
	SDL_Log("Game destroyed");
}

void game::init()
{
	current_state = new menu_state;
}

void game::set_state(game_state *in_state)
{
	if (current_state)
	{
		delete current_state;
		current_state = nullptr;
	}
	current_state = in_state;
	
	if (m_engine)
	{
		m_engine->on_state_changed();
	}
}

void game::process_input(input_handler &in_controller)
{
	command* current_command = in_controller.handle_input();
	if (current_command)
	{
		current_command->execute(*this, get_current_state());
	}
}

void game::update()
{

}

void game::render()
{

}
