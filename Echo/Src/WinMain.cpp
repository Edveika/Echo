#include "Includes.h"
#include <sstream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	srand(time(NULL));

	Engine* engine = new Engine(hInstance);
	Sprite* sprite = new Sprite(engine->gfx, L"Jump.png", 96, 96, 2);
	Sprite* sprite1 = new Sprite(engine->gfx, L"Run.png", 96, 96, 2);
	Timer* timer = new Timer();
	
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			timer->Start();
			// Clears the entire buffer, thats why you pass 0 and NULL as first two parameters
			engine->gfx->ClearScreen(0, 0, 0);

			engine->dx9->pd3dDevice->BeginScene();

			// timer doesnt work on 2 structs, the value gets reseted for 2nd obj
			sprite->Draw({ 50,50 }, 0XFFFFFFFF, 1);
			sprite1->Draw({ 250,50 }, 0XFFFFFFFF, 1);
			
			engine->dx9->pd3dDevice->EndScene();

			// Present the back buffer contents to the display
			engine->dx9->pd3dDevice->Present(NULL, NULL, NULL, NULL);

			timer->End();
			timer->GetTimePassed();
		}
	}

	return 0;
}