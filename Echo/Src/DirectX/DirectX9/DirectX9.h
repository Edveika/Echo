#pragma once

class DirectX9
{
public:
	LPDIRECT3D9 pD3D;
	LPDIRECT3DDEVICE9 pd3dDevice;

private:
	std::vector<std::string> adapterDetails;
	HINSTANCE hInst;
	HWND wndHandle;

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