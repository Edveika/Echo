#pragma once

class Keyboard
{
private:
	LPDIRECTINPUT8 directObj;
	LPDIRECTINPUTDEVICE8 directInputDevice;
	char buffer[256];

public:
	Keyboard(HINSTANCE hInstance);
	~Keyboard();

	void GetInput();
	bool IsPressed(int key);

private:
	bool CreateDirectInputObject(HINSTANCE hInstance);
	bool CreateDirectInputDevice();
	bool SetDataFormat();
	bool AcquireAccess();
};