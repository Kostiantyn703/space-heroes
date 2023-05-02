#include "engine.h"

#include <chrono>
#include <iostream>

using namespace std::chrono;

engine::engine()
{
	std::cout << "Engine initialized" << std::endl;
}

engine::~engine()
{
	std::cout << "Engine destroyed" << std::endl;
};

void engine::run()
{
	float time_to_work = 3.f;
	duration<float> elapsed_time;
	steady_clock::time_point start_time = steady_clock::now();
	while (elapsed_time.count() < time_to_work)
	{
		steady_clock::time_point current_time = steady_clock::now();
		elapsed_time = current_time - start_time;
		std::cout << "Elapsed time " << elapsed_time.count() << std::endl;
	}
}