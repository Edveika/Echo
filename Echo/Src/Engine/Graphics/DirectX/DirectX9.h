#pragma once

class DirectX9
{
public:
	HWND wndHandle;
	LPDIRECT3DDEVICE9 pd3dDevice;
	int windowWidth = 800;
	int windowHeight = 600;

private:
	LPDIRECT3D9 pD3D;
	HINSTANCE hInst;

	std::vector<D3DXVECTOR2> supportedScreenDim;
	std::vector<int> supportedScreenRefreshRate;

public:
	DirectX9(HINSTANCE hInstance);
	~DirectX9();

	IDirect3DSurface9* GetSurfaceFromBitmap(std::string filename, int imageWidth, int imageHeight);

private:
	bool InitWindow(HINSTANCE hInstance);
	bool InitDirect3D();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};