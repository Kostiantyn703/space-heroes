#include "resource_system.h"

resource_system::resource_system()
	:	m_background{nullptr}
{
	init();
	SDL_Log("Resource system created");
}

resource_system::~resource_system()
{
	SDL_DestroyTexture(m_background);
	SDL_Log("Resource system destroyed");
}

void resource_system::init()
{
	map_tex_paths.insert(std::make_pair(0, background02));
	map_tex_paths.insert(std::make_pair(1, background03));
	map_tex_paths.insert(std::make_pair(2, background04));
}

void resource_system::load_texture(SDL_Surface *in_surface, SDL_Renderer &in_renderer, const size_t in_state_id)
{
	in_surface = IMG_Load(map_tex_paths.find(in_state_id)->second.c_str());
	
	if (!in_surface) {
		SDL_Log("Unable create surface.");
		return;
	}

	m_background = SDL_CreateTextureFromSurface(&in_renderer, in_surface);
	SDL_FreeSurface(in_surface);
}
