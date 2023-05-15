#include "game_state.h"

menu_state::~menu_state()
{
	SDL_Log("menu_state destroyed");
}

void menu_state::on_primary_pressed(game &game_instance)
{
	SDL_Log("To active state.");
	game_instance.set_state(new active_state());
}

void menu_state::on_secondary_pressed(game &game_instance)
{
	game_instance.set_active(false);
}

active_state::~active_state()
{
	SDL_Log("Active_state destroyed");
}

void active_state::on_primary_pressed(game &game_instance)
{
	SDL_Log("Player fired a bullet.");
}

void active_state::on_secondary_pressed(game &game_instance)
{
	SDL_Log("To pause state.");
	game_instance.set_state(new pause_state());
}

pause_state::~pause_state()
{
	SDL_Log("pause_state destroyed");
}

void pause_state::on_primary_pressed(game &game_instance)
{
	SDL_Log("To active state.");
	game_instance.set_state(new active_state());
}

void pause_state::on_secondary_pressed(game &game_instance)
{
	SDL_Log("To menu state.");
	game_instance.set_state(new menu_state());
}
