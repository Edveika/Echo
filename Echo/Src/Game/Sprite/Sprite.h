#pragma once

class Sprite
{
private:
	LPDIRECT3DDEVICE9 pd3dDevice;
	LPDIRECT3DTEXTURE9 texture = NULL;
	D3DXIMAGE_INFO info;

	RECT src;
	Vector2 spritePos;
	Vector2 spriteSize;
	int numFrames;
	int curFrame;

public:
	LPD3DXSPRITE sprite = NULL;
	Sprite(LPDIRECT3DDEVICE9 pd3dDevice, LPCWSTR fileName, Vector2 spriteSize, Vector2 spritePos, int numFrames);
	~Sprite();

	void DrawTexture(D3DCOLOR color);
	void Draw();
};