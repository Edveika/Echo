#pragma once

class Sprite
{
private:
	LPDIRECT3DTEXTURE9 texture = NULL;
	LPD3DXSPRITE sprite = NULL;

	RECT src;
	D3DXVECTOR2 spriteSize;
	int numSpriteFrames;
	int curSpriteFrame;



	Graphics* gfx;
	D3DXIMAGE_INFO info;

public:
	Sprite(Graphics* gfx, LPCWSTR fileName, D3DXVECTOR2 spriteSize, int numFrames, int scale);
	Sprite(Graphics* gfx, LPCWSTR fileName, D3DXVECTOR2 spriteSize, int curFrame, int numFrames, int scale);
	~Sprite();

	void Draw(D3DXVECTOR2 pos, D3DCOLOR color, bool curFrame, int delay);
};