#include "Includes.h"
#include <sstream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	srand(time(NULL));

	Engine* engine = new Engine(hInstance);
	Sprite* sprite = new Sprite(engine->gfx, L"RunBack.png", 96, 96, 5, 2);
	//Sprite* sprite1 = new Sprite(engine->gfx, L"Run.png", 96, 96, 2);
	Timer* timer = new Timer();
	float timePassed0 = 0.0f;
	float timePassed1 = 0.0f;

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

			sprite->DrawBack({ 50,50 }, 0XFFFFFFFF, timer->GetTime(sprite->timePassed, 1.f));
			//sprite1->Draw({ 250,50 }, 0XFFFFFFFF, timer->GetTime(sprite1->timePassed, 1.f));
			
			engine->dx9->pd3dDevice->EndScene();

			// Present the back buffer contents to the display
			engine->dx9->pd3dDevice->Present(NULL, NULL, NULL, NULL);

			timer->End();
			timer->GetTimePassed(sprite->timePassed);
			//timer->GetTimePassed(sprite1->timePassed);
		}
	}

	return 0;
}