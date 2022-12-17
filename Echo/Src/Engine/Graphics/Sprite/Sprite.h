#pragma once

class Sprite
{
private:
	LPDIRECT3DTEXTURE9 texture = NULL;
	LPD3DXSPRITE sprite = NULL;

	RECT src;
	D3DXVECTOR2 spriteSize;
	int numFrames;
	int curFrame;



	Graphics* gfx;
	D3DXIMAGE_INFO info;

public:
	Sprite(Graphics* gfx, LPCWSTR fileName, D3DXVECTOR2 spriteSize, int numFrames);
	~Sprite();

	void Draw(D3DXVECTOR2 pos, D3DCOLOR color, int curFrame, int delay);
};