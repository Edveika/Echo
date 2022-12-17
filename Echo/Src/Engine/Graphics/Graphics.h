#pragma once

class Graphics
{
public:
	LPDIRECT3DDEVICE9 pd3dDevice;

public:
	Graphics(LPDIRECT3DDEVICE9 pd3dDevice);
	~Graphics();

	void ClearScreen(int r, int g, int b);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, LPD3DXSPRITE sprite, D3DXVECTOR2 pos, RECT src, D3DCOLOR color);
	IDirect3DSurface9* GetSurfaceFromBitmap(std::string filename, int imageWidth, int imageHeight);
	void GetImageInfo(LPCWSTR fileName, D3DXIMAGE_INFO& info);
};