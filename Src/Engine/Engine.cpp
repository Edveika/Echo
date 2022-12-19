#include "../Includes.h"

Engine::Engine(HINSTANCE hInstance)
{
	this->hInstance = hInstance;

	if ((this->dx9 = new DirectX9(this->hInstance)) == NULL)
		MessageBoxA(NULL, "Failed to create DirectX9 obj!", NULL, NULL);

	if ((this->gfx = new Graphics(dx9->pd3dDevice)) == NULL)
		MessageBoxA(NULL, "Failed to create Graphics obj!", NULL, NULL);

	if ((this->audio = new XAudio2()) == NULL)
		MessageBoxA(NULL, "Failed to create XAudio2 obj!", NULL, NULL);

	if ((this->kb = new Keyboard(this->hInstance)) == NULL)
		MessageBoxA(NULL, "Failed to create Keyboard obj!", NULL, NULL);

	if ((this->mouse = new Mouse(this->hInstance)) == NULL)
		MessageBoxA(NULL, "Failed to create Mouse obj!", NULL, NULL);
}

Engine::~Engine()
{
	delete this->dx9;

	delete this->gfx;

	delete this->audio;

	delete this->kb;

	delete this->mouse;
}