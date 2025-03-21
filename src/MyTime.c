#include "MyTime.h"

#include <windows.h>

LARGE_INTEGER frequency;
LARGE_INTEGER prev_counter;

float delta_time = 0.f;

void InitializeTime()
{
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&prev_counter);

	srand((unsigned int)prev_counter.QuadPart);
}

void UpdateTime()
{
	LARGE_INTEGER current_counter;

	QueryPerformanceCounter(&current_counter);

	delta_time = (float)(current_counter.QuadPart - prev_counter.QuadPart) / frequency.QuadPart;

	prev_counter = current_counter;
}

float DeltaTime()
{
	return delta_time;
}