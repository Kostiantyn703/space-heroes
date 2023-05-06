#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

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
	virtual ~command() {	std::cout << "Command destroyed" << std::endl;	}
	virtual void execute() = 0;
};

class primary_command : public command
{
public:
	virtual void execute() { std::cout << "Primary command pressed" << std:: endl; };
};

class secondary_command : public command
{
	virtual void execute() { std::cout << "Secondary command pressed" << std::endl; };
};
#endif // COMMAND_H
