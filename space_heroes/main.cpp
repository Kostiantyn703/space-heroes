#include "engine.h"
#include "game.h"

int main()
{
	const game *game_instance = new game;
	engine game_engine(*game_instance);
	game_engine.run();
	return 0;
}