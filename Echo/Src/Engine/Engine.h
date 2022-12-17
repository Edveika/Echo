#pragma once

class Engine
{
private:
	HINSTANCE hInstance;

public:
	DirectX9* dx9;
	Graphics* gfx;
	XAudio2* audio;
	Keyboard* kb;
	Mouse* mouse;

public:
	Engine(HINSTANCE hInstance);
	~Engine();
};