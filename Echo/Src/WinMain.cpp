#include "Includes.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	srand(time(NULL));

	Engine* engine = new Engine(hInstance);
	Sprite* sprite = new Sprite(engine->gfx, L"Run.png", 128, 128, 2);
	//Sprite* sprite1 = new Sprite(engine->gfx, L"Run.png", 96, 96, 2);
	Timer* timer = new Timer();
	float timePassed = 0.0f;

	Player* localPlayer = new Player(engine);
	Game* game = new Game(engine);

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

			engine->gfx->ClearScreen(0, 0, 0);

			engine->dx9->pd3dDevice->BeginScene();

			game->StartGame(timer->GetTime(timePassed, 0.1f));
			
			engine->dx9->pd3dDevice->EndScene();

			// Present the back buffer contents to the display
			engine->dx9->pd3dDevice->Present(NULL, NULL, NULL, NULL);

			timer->End();
			timer->GetTimePassed(timePassed);
		}
	}

	return 0;
}