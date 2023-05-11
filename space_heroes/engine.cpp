#include "engine.h"

#include "SDL.h"

#include <memory>

#include "command.h"

using namespace std::chrono;

constexpr unsigned int SCREEN_WIDTH = 800;
constexpr unsigned int SCREEN_HEIGHT = 600;

void engine::init(const game &game_instance)
{
	m_window = SDL_CreateWindow("Space Heroes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	m_screen_surface = SDL_GetWindowSurface(m_window);
	SDL_Init(SDL_INIT_VIDEO);

	m_game = std::make_unique<game>(game_instance);
	m_controller = std::make_unique<input_handler>();
	m_resource = std::make_unique<resource_system>();

	m_resource->load_texture(m_screen_surface, *m_renderer);

	launch_time = steady_clock::now();
	SDL_Log("Engine initialized");
}

engine::~engine()
{
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;
	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	shutdown_time = steady_clock::now();
	duration<float> elapsed_time = shutdown_time - launch_time;
	SDL_Log("Engine destroyed. Active time %.2f", elapsed_time.count());
};

void engine::run()
{
	while (m_game->is_active())
	{
		// input
		command* current_command = m_controller->handle_input();
		if (current_command) {
			current_command->execute(*m_game.get());
		}
		// update
		// render
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, &m_resource->get_background(), nullptr, nullptr);
		SDL_RenderPresent(m_renderer);
	}
}

void engine::change_background()
{

}
