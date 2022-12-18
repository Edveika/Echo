#include "../../Includes.h"

Timer::Timer()
{
	passedTime = 0;
	QueryPerformanceFrequency(&this->timeFrequency);
}

Timer::~Timer()
{

}

void Timer::Start()
{
	QueryPerformanceCounter(&this->timeStart);
}

void Timer::End()
{
	QueryPerformanceCounter(&this->timeEnd);
	this->anim_rate = ((float)this->timeEnd.QuadPart - (float)this->timeStart.QuadPart) / this->timeFrequency.QuadPart;
	this->passedTime += anim_rate;
}

LARGE_INTEGER Timer::GetTimeStart()
{
	return this->timeStart;
}

LARGE_INTEGER Timer::GetTimeEnd()
{
	return this->timeEnd;
}

LARGE_INTEGER Timer::GetTimeFreq()
{
	return this->timeFrequency;
}

long long Timer::GetTimePassed()
{
	return 0;
}

float Timer::GetAnimRate()
{
	return this->anim_rate;
}

bool Timer::GetTime(float seconds)
{
	if (passedTime >= seconds)
	{
		passedTime = 0;
		return true;
	}

	return false;
}