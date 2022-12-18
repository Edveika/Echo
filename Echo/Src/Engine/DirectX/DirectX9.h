#pragma once

class DirectX9
{
public:
	LPDIRECT3DDEVICE9 pd3dDevice;

private:
	LPDIRECT3D9 pD3D;
	HINSTANCE hInst;
	HWND wndHandle;
	int windowWidth = 800;
	int windowHeight = 600;

	std::vector<D3DXVECTOR2> supportedScreenDim;
	std::vector<int> supportedScreenRefreshRate;

public:
	DirectX9(HINSTANCE hInstance);
	~DirectX9();

private:
	bool InitWindow(HINSTANCE hInstance);
	bool InitDirect3D();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	int GetWindowWidth();
	int GetWindowHeight();
};