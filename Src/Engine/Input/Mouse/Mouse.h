#pragma once

class Mouse
{
private:
	LPDIRECTINPUT8 directObj;
	LPDIRECTINPUTDEVICE8 directInputDevice;
	DIMOUSESTATE mouseState;

public:
	Mouse(HINSTANCE hInstance);
	~Mouse();

	void GetInput();
	bool IsPressed(int button);
	int TravelX();
	int TravelY();
	int TravelZ();

private:
	bool CreateDirectInputObject(HINSTANCE hInstance);
	bool CreateDirectInputDevice();
	bool SetDataFormat();
	bool AcquireAccess();
};