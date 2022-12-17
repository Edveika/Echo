#include "Includes.h"
#include <sstream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	srand(time(NULL));

	Engine* engine = new Engine(hInstance);

	Sprite* sprite = new Sprite(engine->gfx, L"Walk.png", { 128,128 }, 7);
	Sprite* sprite1 = new Sprite(engine->gfx, L"Walk.png", { 128,128 }, 7);
	Sprite* sprite2 = new Sprite(engine->gfx, L"Walk.png", { 128,128 }, 7);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	int index = 0;
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// Clears the entire buffer, thats why you pass 0 and NULL as first two parameters
			engine->gfx->ClearScreen(0, 0, 0);

			engine->dx9->pd3dDevice->BeginScene();

			sprite->Draw({ 50,50 }, 0XFFFFFFFF, index, 10);
			sprite1->Draw({ 150,50 }, 0XFFFFFFFF, index, 4);
			sprite2->Draw({ 250,50 }, 0XFFFFFFFF, index, 1);

			engine->dx9->pd3dDevice->EndScene();

			// Present the back buffer contents to the display
			engine->dx9->pd3dDevice->Present(NULL, NULL, NULL, NULL);
			index++;
		}
	}

	return 0;
}