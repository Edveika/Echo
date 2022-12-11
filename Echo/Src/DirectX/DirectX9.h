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

	std::vector<int> supportedScreenWidth;
	std::vector<int> supportedScreenHeight;
	std::vector<int> supportedScreenRefreshRate;

public:
	DirectX9(HINSTANCE hInstance);
	~DirectX9();

	bool InitDirectX9(HINSTANCE hInstance);

	IDirect3DSurface9* GetSurfaceFromBitmap(std::string filename, int imageWidth, int imageHeight);

private:
	bool InitWindow(HINSTANCE hInstance);
	bool InitDirect3D();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};