#include "../../../Includes.h"

// todo: add sprite rows

Sprite::Sprite(LPDIRECT3DDEVICE9 pd3dDevice, LPCWSTR fileName, D3DXVECTOR2 spriteSize, int numFrames)
{
	this->pd3dDevice = pd3dDevice;
	this->src.top = 0;
	this->src.left = 0;
	this->src.right = src.left + spriteSize.x;
	this->src.bottom = spriteSize.y;
	this->curFrame = 0;
	this->numFrames = numFrames;
	this->spriteSize = spriteSize;
	
	if (FAILED(D3DXGetImageInfoFromFile(fileName, &this->info)))
		MessageBoxA(NULL, "Failed to get image data!", NULL, NULL);

	if (FAILED(D3DXCreateTextureFromFileEx(pd3dDevice, fileName, info.Width, info.Height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &texture)))
		MessageBoxA(NULL, "Failed to create texture from file!", NULL, NULL);

	if (FAILED(D3DXCreateSprite(pd3dDevice, &sprite)))
		MessageBoxA(NULL, "Failed to create a sprite!", NULL, NULL);
}

Sprite::~Sprite()
{

}

void Sprite::DrawTexture(D3DXVECTOR2 pos, D3DCOLOR color)
{
	this->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 finalpos = D3DXVECTOR3(pos.x, pos.y, 0.0f);
	this->sprite->Draw(this->texture, &this->src, NULL, &finalpos, color);

	this->sprite->End();
}

void Sprite::Draw(D3DXVECTOR2 pos)
{
	if (this->curFrame < this->numFrames)
		++this->curFrame;
	else
		this->curFrame = 0;

	this->src.left = this->curFrame * this->spriteSize.x;
	this->src.right = this->src.left + this->spriteSize.y;

	DrawTexture(pos, 0xFFFFFFFF);
}