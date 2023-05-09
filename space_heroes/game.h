#ifndef GAME_H
#define GAME_H

class game
{
friend class engine;
public:
	game();
	~game();

private:
// game loop defaults
	void process_input();
	void update();
	void render();
};
#endif // GAME_H
