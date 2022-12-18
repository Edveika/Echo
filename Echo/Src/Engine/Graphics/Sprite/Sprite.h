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
	D3DXIMAGE_INFO spriteSheetInfo;

public:
	Sprite(Graphics* gfx, LPCWSTR fileName, D3DXVECTOR2 spriteSize, int spriteScale);
	~Sprite();

	void Draw(D3DXVECTOR2 spritePos, D3DCOLOR spriteColor, bool bTimeToDraw);
};