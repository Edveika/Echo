#pragma once

class Timer
{
private:
	LARGE_INTEGER timeStart;
	LARGE_INTEGER timeEnd;
	LARGE_INTEGER timeFrequency;
	float anim_rate;

public:
	Timer();
	~Timer();

	void Start();
	void End();

	LARGE_INTEGER GetTimeStart();
	LARGE_INTEGER GetTimeEnd();
	LARGE_INTEGER GetTimeFreq();
	void GetTimePassed(float& passedTime);
	float GetAnimRate();
	bool GetTime(float& passedTime, float seconds);
};