#include "Timer.h"

Timer::Timer() : elapsed_time(0) {
	StartTimer();
}

void Timer::StartTimer() {
	start_time = std::chrono::steady_clock::now();
}

void Timer::UpdateTimer() {
	auto now = std::chrono::steady_clock::now();
	elapsed_time = static_cast<int>(std::chrono::duration_cast<std::chrono::seconds>(now - start_time).count());
}

int Timer::GetElapsedTime() const {
	return elapsed_time;
}
void Timer::DisplayTimer() const
{
	AmusingDolphins::Image minute_tens(Numbers[(GetElapsedTime() / 60) / 10]);
	AmusingDolphins::Image minute_ones(Numbers[(GetElapsedTime() / 60) % 10]);
	AmusingDolphins::Image second_tens(Numbers[(GetElapsedTime() % 60) / 10]);
	AmusingDolphins::Image second_ones(Numbers[(GetElapsedTime() % 60) % 10]);

	//Display Minutes
	AmusingDolphins::Renderer::Draw(minute_tens, 740, 700);
	AmusingDolphins::Renderer::Draw(minute_ones, 800, 700);

	//Display Seconds
	AmusingDolphins::Renderer::Draw(second_tens, 880, 700);
	AmusingDolphins::Renderer::Draw(second_ones, 940, 700);
}
