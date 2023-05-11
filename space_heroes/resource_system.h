#ifndef RESOURCE_SYSTEM_H
#define RESOURCE_SYSTEM_H

#include "engine_system.h"

#include "SDL.h"
#include "SDL_image.h"

#include <vector>
#include <string>

// paths
const std::string background01 = "../images/black.png";
const std::string background02 = "../images/blue.png";
const std::string background03 = "../images/darkPurple.png";
const std::string background04 = "../images/purple.png";

/*
	Resource system provides loading and storing images (textures).
*/
class resource_system : public engine_system
{
public:
	resource_system();
	virtual ~resource_system();
	
	void init() override;

	void load_texture(SDL_Surface *in_surface, SDL_Renderer &in_renderer);

	SDL_Texture &get_background() const { return *m_background; }
private:
	SDL_Texture* m_background;
	std::vector<std::string> a_tex_paths;
	size_t curr_index;
};

#endif // RESOURCE_SYSTEM_H
