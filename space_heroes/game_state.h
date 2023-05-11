#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SDL.h"

class game_state
{
public:
	virtual ~game_state() { SDL_Log("game_state destroyed"); }
	virtual handle_input() = 0

};

class menu_state
{
public:
	virtual ~menu_state() { SDL_Log("menu_state destroyed"); }
	virtual handle_input() {}
};

class active_state
{
public:
	virtual ~active_state() { SDL_Log("Active_state destroyed"); }
	virtual handle_input() {}
};

class pause_state
{
public:
	virtual ~pause_state() { SDL_Log("pause_state destroyed"); }
	virtual handle_input() {}
};
#endif // GAME_STATE_H
