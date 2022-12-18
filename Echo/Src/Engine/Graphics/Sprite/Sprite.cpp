#include "../../../Includes.h"

// todo: add sprite rows

Sprite::Sprite(Graphics* gfx, LPCWSTR fileName, int spriteWidth, int spriteHeight, int spriteScale)
{
	this->gfx = gfx;
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->curSpriteFrame = 0;
	this->src.top = 0;
	this->src.left = 0;
	this->src.right = src.left + spriteWidth;
	this->src.bottom = spriteHeight;

	gfx->GetImageInfo(fileName, this->spriteSheetInfo);

	if (FAILED(D3DXCreateTextureFromFileEx(this->gfx->pd3dDevice, fileName, this->spriteSheetInfo.Width, this->spriteSheetInfo.Height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &this->spriteSheetTexture)))
		MessageBoxA(NULL, "Failed to create texture from file!", NULL, NULL);
	
	this->numSpriteFrames = this->spriteSheetInfo.Width / spriteWidth;

	if (FAILED(D3DXCreateSprite(this->gfx->pd3dDevice, &this->sprite)))
		MessageBoxA(NULL, "Failed to create a sprite!", NULL, NULL);

	D3DXMATRIX scaleMat = gfx->MatrixScale(spriteScale, spriteScale, 0);
	sprite->SetTransform(&scaleMat);
}

Sprite::~Sprite()
{
	spriteSheetTexture->Release();

	sprite->Release();

	delete this->gfx;
}

void Sprite::Draw(D3DXVECTOR2 spritePos, D3DCOLOR spriteColor, bool bTimeToDraw)
{
	if (bTimeToDraw == true)
		++this->curSpriteFrame;
	if (this->curSpriteFrame + 1 > numSpriteFrames)
		this->curSpriteFrame = 0;

	this->src.left = this->curSpriteFrame * this->spriteWidth;
	this->src.right = this->src.left + this->spriteHeight;

	gfx->DrawTexture(this->spriteSheetTexture, this->sprite, spritePos, this->src, spriteColor);
}