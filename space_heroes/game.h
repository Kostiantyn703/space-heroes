#ifndef GAME_H
#define GAME_H

class game_state;

class game
{
friend class engine;
public:
	game();
	~game();

	void init();

	bool is_active()	const { return active; }
	void set_active(bool value) { active = value; }

	game_state &get_current_state() const { return *current_state; }
	void set_state(game_state &in_state) { current_state = &in_state; }

private:
	bool active;

	game_state* current_state;
// game loop defaults
	void process_input();
	void update();
	void render();
};
#endif // GAME_H
