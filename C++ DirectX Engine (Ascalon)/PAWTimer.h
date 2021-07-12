#pragma once
#include <chrono>

class PAWTimer
{
public:
	PAWTimer();
	float Mark();
	float Peek() const;
private:
	std::chrono::steady_clock::time_point last;
};