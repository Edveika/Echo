#pragma once

class Sprite
{
private:
	LPDIRECT3DDEVICE9 pd3dDevice;
	LPDIRECT3DTEXTURE9 texture = NULL;
	D3DXIMAGE_INFO info;

	RECT src;
	D3DXVECTOR2 spritePos;
	D3DXVECTOR2 spriteSize;
	int numFrames;
	int curFrame;

public:
	LPD3DXSPRITE sprite = NULL;
	Sprite(LPDIRECT3DDEVICE9 pd3dDevice, LPCWSTR fileName, D3DXVECTOR2 spriteSize, D3DXVECTOR2 spritePos, int numFrames);
	~Sprite();

	void DrawTexture(D3DCOLOR color);
	void Draw();
};