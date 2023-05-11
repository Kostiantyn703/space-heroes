#ifndef COMMAND_H
#define COMMAND_H

#include "SDL.h"

#include "game.h"
#include "game_state.h"
/*
	Command is an interface to derive from.
	Concrete commands are:
	- primary action - accept items in menu, navigate through menus, player shoot in the game;
	- secondary action - decline, go back in menu, probably some additional functionality during game (shoot bombs, heal) or deprecated;
	- navigation, move;
*/
class command
{
public:
	// logging
	virtual ~command() {	SDL_Log("Command destroyed");	}
	virtual void execute(game &game_instance, game_state &current_state) = 0;
};

class primary_command : public command
{
public:
	~primary_command() override {	SDL_Log("Primary Command destroyed");	}
	virtual void execute(game &game_instance, game_state &current_state) override
	{
		SDL_Log("Primary command pressed");
		current_state.on_primary_pressed(game_instance);
	}
};

class secondary_command : public command
{
public:
	~secondary_command() override { SDL_Log("Secondary Command destroyed"); }
	virtual void execute(game &game_instance, game_state &current_state) override
	{
		SDL_Log("Secondary command pressed");
		current_state.on_secondary_pressed(game_instance);
	}
};
#endif // COMMAND_H
