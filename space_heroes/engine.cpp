#include "engine.h"

#include "SDL.h"

#include <iostream>
#include <memory>

#include "game.h"
#include "input_handler.h"

using namespace std::chrono;

constexpr unsigned int SCREEN_WIDTH = 800;
constexpr unsigned int SCREEN_HEIGHT = 600;

engine::engine(const game &game_instance)
{

	m_window = SDL_CreateWindow("Space Heroes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	m_screen_surface = SDL_GetWindowSurface(m_window);
	SDL_Init(SDL_INIT_VIDEO);
	m_game = std::make_unique<game>(game_instance);
	m_controller = std::make_unique<input_handler>();

	std::cout << "Engine initialized" << std::endl;
	launch_time = steady_clock::now();
}

engine::~engine()
{
	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	std::cout << "Engine destroyed" << std::endl;
	shutdown_time = steady_clock::now();
	duration<float> elapsed_time = shutdown_time - launch_time;
	std::cout << "Engine worked for " << elapsed_time.count() << " seconds." << std::endl;
};

void engine::run()
{
	while (m_game->is_active())
	{
		command* current_command = m_controller->handle_input();
		if (current_command) {
			current_command->execute(*m_game.get());
		}
		m_game->process_input();
		m_game->update();
		m_game->render();
	}
}