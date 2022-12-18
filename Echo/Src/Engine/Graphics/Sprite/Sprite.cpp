#include "../../../Includes.h"

// todo: add sprite rows

Sprite::Sprite(Graphics* gfx, LPCWSTR fileName, D3DXVECTOR2 spriteSize, int numFrames, int scale)
{
	this->gfx = gfx;
	this->src.top = 0;
	this->src.left = 0;
	this->src.right = src.left + spriteSize.x;
	this->src.bottom = spriteSize.y;
	this->spriteSize = spriteSize;
	this->curSpriteFrame = 0;

	gfx->GetImageInfo(fileName, info);

	if (FAILED(D3DXCreateTextureFromFileEx(this->gfx->pd3dDevice, fileName, this->info.Width, this->info.Height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &this->texture)))
		MessageBoxA(NULL, "Failed to create texture from file!", NULL, NULL);
	
	this->numSpriteFrames = info.Width / this->spriteSize.x;

	if (FAILED(D3DXCreateSprite(this->gfx->pd3dDevice, &this->sprite)))
		MessageBoxA(NULL, "Failed to create a sprite!", NULL, NULL);

	D3DXMATRIX scaleMat = gfx->MatrixScale(scale, scale, 0);
	sprite->SetTransform(&scaleMat);
}

Sprite::~Sprite()
{
	texture->Release();

	sprite->Release();

	delete this->gfx;
}

void Sprite::Draw(D3DXVECTOR2 spritePos, D3DCOLOR color, int curGameFrame, int f_spriteAnimationDelay)
{
	// ToFIX: First frame skips to second sprite frame
	if ((curGameFrame / 10) % f_spriteAnimationDelay == curGameFrame % f_spriteAnimationDelay)
		++this->curSpriteFrame;
	if (this->curSpriteFrame + 1 > numSpriteFrames)
		this->curSpriteFrame = 0;

	this->src.left = this->curSpriteFrame * this->spriteSize.x;
	this->src.right = this->src.left + this->spriteSize.y;

	gfx->DrawTexture(this->texture, this->sprite, spritePos, this->src, color);
}