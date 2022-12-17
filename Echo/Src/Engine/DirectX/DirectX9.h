#pragma once

class DirectX9
{
public:
	LPDIRECT3DDEVICE9 pd3dDevice;
	int windowWidth = 800;
	int windowHeight = 600;

private:
	LPDIRECT3D9 pD3D;
	HINSTANCE hInst;
	HWND wndHandle;

	std::vector<D3DXVECTOR2> supportedScreenDim;
	std::vector<int> supportedScreenRefreshRate;

public:
	DirectX9(HINSTANCE hInstance);
	~DirectX9();

private:
	bool InitWindow(HINSTANCE hInstance);
	bool InitDirect3D();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};