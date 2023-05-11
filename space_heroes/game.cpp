#include "game.h"

#include "SDL.h"

#include "game_state.h"

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

void game::process_input()
{
	
}

void game::update()
{

}

void game::render()
{

}
