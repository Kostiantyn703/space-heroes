#ifndef COMMAND_H
#define COMMAND_H

#include "SDL.h"

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
	virtual void execute() = 0;
};

class primary_command : public command
{
public:
	virtual void execute() override
	{
		SDL_Log("Primary command pressed");
	}
};

class secondary_command : public command
{
public:
	virtual void execute() override
	{
		SDL_Log("Secondary command pressed");
	}
};
#endif // COMMAND_H
