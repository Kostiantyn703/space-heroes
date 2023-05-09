#ifndef ENGINE_SYSTEM_H
#define ENGINE_SYSTEM_H

#include "SDL.h"

/*
	Parent class for engine systems (sound system, collision system etc.).
*/
class engine_system
{
public:
	virtual ~engine_system() { SDL_Log("engine system destroyed"); }
	virtual void init() = 0;
};

#endif // ENGINE_SYSTEM_H
