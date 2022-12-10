#include "../../../Includes.h"

Sprite::Sprite(LPDIRECT3DDEVICE9 pd3dDevice, LPCWSTR fileName)
{
	this->pd3dDevice = pd3dDevice;

	D3DXCreateTextureFromFileEx(this->pd3dDevice, fileName, 860, 366, D3DX_DEFAULT, 0, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &texture);
	//D3DXCreateTextureFromFile(this->pd3dDevice, fileName, &texture);
	D3DXCreateSprite(this->pd3dDevice, &sprite);
}

void Sprite::DrawTexture(int x, int y, RECT* src, D3DCOLOR color)
{
	this->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 pos = D3DXVECTOR3(x, y, 0.0f);
	this->sprite->Draw(this->texture, src, NULL, &pos, color);
	
	this->sprite->End();
}