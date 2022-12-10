#pragma once

class DirectX9
{
public:
	LPDIRECT3DDEVICE9 pd3dDevice;
	int windowWidth = 860;
	int windowHeight = 366;

private:
	LPDIRECT3D9 pD3D;
	HINSTANCE hInst;
	HWND wndHandle;

	std::vector<std::string> supportedScreenWidth;
	std::vector<std::string> supportedScreenHeight;
	std::vector<std::string> supportedScreenRefreshRate;

public:
	DirectX9();
	~DirectX9();

	bool InitDirectX9(HINSTANCE hInstance);

	IDirect3DSurface9* GetSurfaceFromBitmap(std::string filename, int imageWidth, int imageHeight);

private:
	bool InitWindow(HINSTANCE hInstance);
	bool InitDirect3D();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};