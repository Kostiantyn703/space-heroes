#ifndef ENGINE_H
#define ENGINE_H

#include <chrono>
#include <memory>

#include "SDL.h"

using namespace std::chrono;

class game;
class input_handler;

class engine
{
using time_stamp = std::chrono::steady_clock::time_point;
public:
	engine(const game &game_instance);
	~engine();
	void run();

	// only constructor with arguments is valid case
	// other constructors and assignment operators are deleted
	engine() = delete;								// default constructor
	engine(const engine &value) = delete;			// copy constructor
	engine operator=(const engine&value) = delete;	// copy assignment
	engine(engine &&value) = delete;				// move constructor
	engine operator=(engine &&value) = delete;		// move assignment
private:
	// timers
	time_stamp launch_time;
	time_stamp shutdown_time;

	std::unique_ptr<game> m_game;
	std::unique_ptr<input_handler> m_controller;

	//The window we'll be rendering to
	SDL_Window* m_window = nullptr;
	//The surface contained by the window
	SDL_Surface* m_screen_surface = nullptr;
	// sound manager
	// rendered
	// particle system
	// logger
	// resource manager
	// collision manger
};
#endif // ENGINE_H
