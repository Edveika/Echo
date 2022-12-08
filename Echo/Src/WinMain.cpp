#include "Includes.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DirectX9* dx9 = new DirectX9();
	XAudio2* xa2 = new XAudio2();

	dx9->InitDirectX9(hInstance);
	xa2->InitXAudio2();

	IXAudio2SourceVoice* srcVoice = xa2->LoadAudioData(L"song.wav");
	xa2->StartAudio(srcVoice);

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

		}
	}

	return 0;
}