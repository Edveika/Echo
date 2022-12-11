#pragma once

class Sprite
{
private:
	LPDIRECT3DDEVICE9 pd3dDevice;
	LPDIRECT3DTEXTURE9 texture = NULL;
	LPD3DXSPRITE sprite = NULL;

	RECT src;
	Vector2 spritePos;
	Vector2 spriteSize;
	int numFrames;
	int curFrame;

public:
	Sprite(LPDIRECT3DDEVICE9 pd3dDevice, LPCWSTR fileName, Vector2 imageSize, Vector2 spriteSize, Vector2 spritePos, int numFrames);
	~Sprite();

	void DrawTexture(Vector2 texturePos, RECT* src, D3DCOLOR color);
	void DrawTexture(D3DCOLOR color);
	void Draw();
};