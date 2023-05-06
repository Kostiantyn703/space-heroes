#ifndef COMMAND_H
#define COMMAND_H
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
	virtual ~command() {}
	virtual void execute() = 0;
};

class primary_command : public command
{
public:
	virtual execute() {};
};

class secondary_command : public command
{
	virtual execute() {};
};
#endif // COMMAND_H
