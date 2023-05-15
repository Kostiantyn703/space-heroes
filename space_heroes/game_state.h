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
	
	size_t get_id() const { return state_id; }
protected:
	size_t state_id;
};

class menu_state : public game_state
{
public:
	menu_state() { state_id = 0; }
	virtual ~menu_state();
	virtual void on_primary_pressed(game &game_instance);
	virtual void on_secondary_pressed(game &game_instance);
};

class active_state : public game_state
{
public:
	active_state() { state_id = 1; }
	virtual ~active_state();
	virtual void on_primary_pressed(game &game_instance);
	virtual void on_secondary_pressed(game &game_instance);
};

class pause_state : public game_state
{
public:
	pause_state() { state_id = 2; }
	virtual ~pause_state();
	virtual void on_primary_pressed(game &game_instance);
	virtual void on_secondary_pressed(game &game_instance);
};
#endif // GAME_STATE_H
