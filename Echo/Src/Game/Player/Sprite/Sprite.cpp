#include "../../../Includes.h"

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

	D3DXCreateTextureFromFileEx(pd3dDevice, fileName, imageSize.x, imageSize.y, D3DX_DEFAULT, 0, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &texture);
	D3DXCreateSprite(pd3dDevice, &sprite);
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
	if (curFrame < numFrames)
		++curFrame;
	else
		curFrame = 0;

	src.left = curFrame * spriteSize.x;
	src.right = src.left + spriteSize.y;

	DrawTexture(this->spritePos, &this->src, 0xFFFFFFFF);
}