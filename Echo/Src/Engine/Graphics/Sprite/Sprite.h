#pragma once

class Sprite
{
private:
	LPDIRECT3DDEVICE9 pd3dDevice;
	LPDIRECT3DTEXTURE9 texture = NULL;
	D3DXIMAGE_INFO info;

	RECT src;
	D3DXVECTOR2 spriteSize;
	int numFrames;
	int curFrame;

public:
	LPD3DXSPRITE sprite = NULL;
	Sprite(LPDIRECT3DDEVICE9 pd3dDevice, LPCWSTR fileName, D3DXVECTOR2 spriteSize, int numFrames);
	~Sprite();

	void DrawTexture(D3DXVECTOR2 pos, D3DCOLOR color);
	void Draw(D3DXVECTOR2 pos);
};