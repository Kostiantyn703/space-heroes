#ifndef ENGINE_H
#define ENGINE_H

#include <chrono>
#include <memory>

using namespace std::chrono;

class game;

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
	// sound manager
	// rendered
	// particle system
	// something else
	// logger
	// resource manager
};
#endif // ENGINE_H
