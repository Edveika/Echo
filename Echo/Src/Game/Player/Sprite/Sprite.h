#pragma once

class Sprite
{
private:
	LPDIRECT3DDEVICE9 pd3dDevice;

	LPDIRECT3DTEXTURE9 texture = NULL;
	LPD3DXSPRITE sprite = NULL;

public:
	Sprite(LPDIRECT3DDEVICE9 pd3dDevice, LPCWSTR fileName);
	~Sprite();

	void DrawTexture(int x, int y, RECT* src, D3DCOLOR color);
};