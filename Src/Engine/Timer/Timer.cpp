#include "../../Includes.h"

Timer::Timer()
{
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

void Timer::GetTimePassed(float& passedTime)
{
	passedTime += anim_rate;
}

float Timer::GetAnimRate()
{
	return this->anim_rate;
}

bool Timer::GetTime(float& passedTime, float seconds)
{
	if (passedTime >= seconds)
	{
		passedTime = 0;
		return true;
	}

	return false;
}