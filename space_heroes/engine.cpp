#include "engine.h"

//#include <chrono>
#include <iostream>
#include <memory>

#include "game.h"

using namespace std::chrono;

engine::engine(const game &game_instance)
{
	m_game = std::make_unique<game>(game_instance);
	std::cout << "Engine initialized" << std::endl;
	launch_time = steady_clock::now();
}

engine::~engine()
{
	std::cout << "Engine destroyed" << std::endl;
	shutdown_time = steady_clock::now();
	duration<float> elapsed_time = shutdown_time - launch_time;
	std::cout << "Engine worked for " << elapsed_time.count() << " seconds." << std::endl;
};

void engine::run()
{
	float time_to_work = 50000.f;
	while (time_to_work > 0)
	{
		m_game->process_input();
		m_game->update();
		m_game->render();
		time_to_work -= 0.002f;
	}
}