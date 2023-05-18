#ifndef GAME_H
#define GAME_H

class game_state;
class engine;
class input_handler;

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
	void set_state(game_state *in_state);

	void set_owner(engine &in_engine) { m_engine = &in_engine; }

private:
	bool active;

	engine *m_engine;

	game_state* current_state;
// game loop defaults
	void process_input(input_handler &in_controller);
	void update();
	void render();
};
#endif // GAME_H
