#include "Includes.h"
#include <sstream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	srand(time(NULL));

	DirectX9* dx9 = new DirectX9(hInstance);
	//XAudio2* xa2 = new XAudio2();
	//Player* player = new Player();
	Keyboard kb(hInstance);
	Mouse mouse(hInstance);
	//IXAudio2SourceVoice* srcVoice = xa2->LoadAudioData(L"song.wav");
	//xa2->StartAudio(srcVoice);

	D3DXVECTOR2 vec{ 50,50 };
	Sprite* sprite = new Sprite(dx9->pd3dDevice, L"Walk.png", { 128, 128 }, 7);

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
			// Clears the entire buffer, thats why you pass 0 and NULL as first two parameters
			dx9->pd3dDevice->Clear
			(
				0,
				NULL,
				D3DCLEAR_TARGET, // tells dx that you want the render buffer to be cleared
				D3DCOLOR_XRGB(244, 0, 0), // clears the screen to white color
				1.0f, // 1.0f gets passed into depth buffer. depth buffers helps dx determine how far the object uis from the viewer. (hols a vlue between 0.0f - 1.0f)
				0 // Stencil buffer allows for masking certain areas of an image, so they arent displayed. because stencil buffer is not used, we pass 0
			);

			dx9->pd3dDevice->BeginScene();
			mouse.GetInput();
			if (mouse.IsPressed(0))
			{
				vec.x += mouse.TravelX();
				vec.y += mouse.TravelY();
			}
			sprite->Draw(vec);

			dx9->pd3dDevice->EndScene();

			// Present the back buffer contents to the display
			dx9->pd3dDevice->Present(NULL, NULL, NULL, NULL);
		}
	}

	return 0;
}