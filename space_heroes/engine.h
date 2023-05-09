#ifndef ENGINE_H
#define ENGINE_H

#include "SDL.h"

#include <chrono>
#include <memory>

#include "game.h"
#include "resource_system.h"
#include "input_handler.h"

class game;
class input_handler;
class resource_system;

using namespace std::chrono;

class engine
{
using time_stamp = std::chrono::steady_clock::time_point;
public:
	engine() = default;
	~engine();

	// call only once in main()
	void init(const game &game_instance);
	void run();

	void change_background();
private:
	// timers
	time_stamp launch_time;
	time_stamp shutdown_time;

	std::unique_ptr<game> m_game;

	std::unique_ptr<input_handler> m_controller;

	//The window we'll be rendering to
	SDL_Window *m_window;
	//The surface contained by the window
	SDL_Surface *m_screen_surface;
	SDL_Renderer *m_renderer;
	
	// engine systems
	std::unique_ptr<resource_system> m_resource;
	// sound manager
	// particle system
	// collision manger
public:
	// only default constructor is valid case
	// constructors and assignment operators are deleted
	engine(const engine &value)				= delete;	// copy constructor
	engine operator=(const engine&value)	= delete;	// copy assignment
	engine(engine &&value)					= delete;	// move constructor
	engine operator=(engine &&value)		= delete;	// move assignment
};
#endif // ENGINE_H
