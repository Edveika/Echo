#include "../../Includes.h"

// todo: add sprite rows

Sprite::Sprite(LPDIRECT3DDEVICE9 pd3dDevice, LPCWSTR fileName, Vector2 imageSize, Vector2 spriteSize, Vector2 spritePos, int numFrames)
{
	this->pd3dDevice = pd3dDevice;
	this->src.top = 0;
	this->src.left = 0;
	this->src.right = src.left + spriteSize.x;
	this->src.bottom = spriteSize.y;
	this->curFrame = 0;
	this->numFrames = numFrames;
	this->spritePos = spritePos;
	this->spriteSize = spriteSize;
	
	if (FAILED(D3DXCreateTextureFromFileEx(pd3dDevice, fileName, imageSize.x, imageSize.y, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &texture)))
		MessageBoxA(NULL, "Failed to create texture from file!", NULL, NULL);

	if (FAILED(D3DXCreateSprite(pd3dDevice, &sprite)))
		MessageBoxA(NULL, "Failed to create a sprite!", NULL, NULL);
}

Sprite::~Sprite()
{

}

void Sprite::DrawTexture(Vector2 texturePos, RECT* src, D3DCOLOR color)
{
	this->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 pos = D3DXVECTOR3(texturePos.x, texturePos.y, 0.0f);
	this->sprite->Draw(this->texture, src, NULL, &pos, color);
	
	this->sprite->End();
}

void Sprite::DrawTexture(D3DCOLOR color)
{
	this->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 pos = D3DXVECTOR3(this->spritePos.x, this->spritePos.y, 0.0f);
	this->sprite->Draw(this->texture, &this->src, NULL, &pos, color);

	this->sprite->End();
}

void Sprite::Draw()
{
	if (this->curFrame < this->numFrames)
		++this->curFrame;
	else
		this->curFrame = 0;

	this->src.left = this->curFrame * this->spriteSize.x;
	this->src.right = this->src.left + this->spriteSize.y;

	DrawTexture(this->spritePos, &this->src, 0xFFFFFFFF);
}