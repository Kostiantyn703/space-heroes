#include "game.h"
#include "SDL.h"

game::game()
	: active(true)
{
	SDL_Log("Game constructed");
}

game::~game()
{
	SDL_Log("Game destroyed");
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
