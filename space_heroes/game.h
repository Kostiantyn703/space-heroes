#ifndef GAME_H
#define GAME_H

//
class game
{
friend class engine;
public:
	game();
	~game();

	bool is_active()	const	{ return active; }
	void set_active(bool value)	{ active = value; }
private:
	bool active;
// game loop defaults
	void process_input();
	void update();
	void render();
};
#endif // GAME_H
