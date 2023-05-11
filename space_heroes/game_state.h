#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SDL.h"

#include "game.h"

class game_state
{
public:
	virtual ~game_state() { SDL_Log("game_state destroyed"); }
	virtual void on_primary_pressed(game &game_instance) = 0;
	virtual void on_secondary_pressed(game &game_instance) = 0;

};

class menu_state : public game_state
{
public:
	virtual ~menu_state() { SDL_Log("menu_state destroyed"); }
	virtual void on_primary_pressed(game &game_instance) {}
	virtual void on_secondary_pressed(game &game_instance) { game_instance.set_active(false); }
};

class active_state : public game_state
{
public:
	virtual ~active_state() { SDL_Log("Active_state destroyed"); }
	virtual void on_primary_pressed(game &game_instance) {}
	virtual void on_secondary_pressed(game &game_instance) {}
};

class pause_state
{
public:
	virtual ~pause_state() { SDL_Log("pause_state destroyed"); }
	virtual void on_primary_pressed(game &game_instance) {}
	virtual void on_secondary_pressed(game &game_instance) {}
};
#endif // GAME_STATE_H
