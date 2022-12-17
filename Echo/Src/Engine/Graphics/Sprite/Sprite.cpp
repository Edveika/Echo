#include "../../../Includes.h"

// todo: add sprite rows

Sprite::Sprite(Graphics* gfx, LPCWSTR fileName, D3DXVECTOR2 spriteSize, int numFrames)
{
	this->src.top = 0;
	this->src.left = 0;
	this->src.right = src.left + spriteSize.x;
	this->src.bottom = spriteSize.y;
	this->curFrame = 0;
	this->numFrames = numFrames;
	this->spriteSize = spriteSize;

	gfx->GetImageInfo(fileName, info);

	if (FAILED(D3DXCreateTextureFromFileEx(gfx->pd3dDevice, fileName, info.Width, info.Height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &texture)))
		MessageBoxA(NULL, "Failed to create texture from file!", NULL, NULL);

	if (FAILED(D3DXCreateSprite(gfx->pd3dDevice, &sprite)))
		MessageBoxA(NULL, "Failed to create a sprite!", NULL, NULL);
}

Sprite::~Sprite()
{
	texture->Release();

	sprite->Release();

	delete this->gfx;
}

void Sprite::Draw(D3DXVECTOR2 pos, D3DCOLOR color, int curFrame, int delay)
{
	if ((curFrame / 10) % delay == curFrame % delay)
		++this->curFrame;
	if (this->curFrame >= numFrames)
		this->curFrame = 0;

	this->src.left = this->curFrame * this->spriteSize.x;
	this->src.right = this->src.left + this->spriteSize.y;
	
	gfx->DrawTexture(this->texture, this->sprite, pos, this->src, 0xFFFFFFFF);
}