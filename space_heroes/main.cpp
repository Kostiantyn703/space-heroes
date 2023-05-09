#include "engine.h"
#include "game.h"

int main(int argc, char* args[])
{
	const game *game_instance = new game;
	engine game_engine;
	game_engine.init(*game_instance);
	game_engine.run();
	return 0;
}