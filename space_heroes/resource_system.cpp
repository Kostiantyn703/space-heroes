#include "resource_system.h"

resource_system::resource_system()
	:	curr_index{0}
	,	m_background{nullptr}
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
	//a_tex_paths.push_back(background01);
	a_tex_paths.push_back(background02);
	a_tex_paths.push_back(background03);
	a_tex_paths.push_back(background04);
}

void resource_system::load_texture(SDL_Surface *in_surface, SDL_Renderer &in_renderer)
{
	if (!m_background) {
		in_surface = IMG_Load(a_tex_paths[curr_index].c_str());
	}

	if (!in_surface) {
		SDL_Log("Unable create surface.");
		return;
	}

	m_background = SDL_CreateTextureFromSurface(&in_renderer, in_surface);
	SDL_FreeSurface(in_surface);
}
