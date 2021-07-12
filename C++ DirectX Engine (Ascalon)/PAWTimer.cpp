#include "PAWTimer.h"

using namespace std::chrono;

PAWTimer::PAWTimer()
{
	last = steady_clock::now();
}

float PAWTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float PAWTimer::Peek() const
{
	return duration<float>(steady_clock::now() - last).count();
}