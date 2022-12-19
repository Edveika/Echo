#pragma once

class Sprite
{
public:
	float timePassed;

private:
	LPDIRECT3DTEXTURE9 spriteSheetTexture = NULL;
	LPD3DXSPRITE sprite = NULL;
	D3DXIMAGE_INFO spriteSheetInfo;
	Graphics* gfx;

	RECT src;
	int spriteWidth;
	int spriteHeight;
	int numSpriteFrames;
	int curSpriteFrame;

public:
	Sprite(Graphics* gfx, LPCWSTR fileName, int spriteWidth, int spriteHeight, int spriteScale);
	Sprite(Graphics* gfx, LPCWSTR fileName, int spriteWidth, int spriteHeight, int curFrame, int spriteScale);
	~Sprite();

	void Draw(D3DXVECTOR2 spritePos, D3DCOLOR spriteColor, bool bTimeToDraw);
	void DrawBack(D3DXVECTOR2 spritePos, D3DCOLOR spriteColor, bool bTimeToDraw);
};