#include "../../Includes.h"

// seperate class for graphics and audio?

Player::Player(DirectX9* dx9)
{
	this->dx9 = dx9;

	//this->bitmapFileName = spriteFileName;
	//this->bitmapImageWidth = spriteImageWidth;
	//this->bitmapImageHeight = spriteImageHeight;
}

Player::~Player()
{

}

bool Player::InitTextures()
{
	this->spwite = new Sprite(this->dx9->pd3dDevice, L"sprite.png");

	//curSprite = dx9->GetSurfaceFromBitmap(bitmapFileName, bitmapImageWidth, bitmapImageHeight);

	//if (curSprite == NULL)
	//	return false;

	return true;
}

// Animations
bool Player::InitSprites()
{
	spriteStruct.src.top = 0;
	spriteStruct.src.left = 0; //i * SPRITE_WIDTH;
	spriteStruct.src.right = spriteStruct.src.left + SPRITE_WIDTH;
	spriteStruct.src.bottom = SPRITE_HEIGHT;
	spriteStruct.x = 0;//rand() % (dx9->windowWidth - SPRITE_WIDTH);
	spriteStruct.y = 0;//rand() & (dx9->windowHeight - SPRITE_HEIGHT);
	spriteStruct.curFrame = 0;
	spriteStruct.numFrames = 4;

	return true;
}

void Player::Draw()
{
	IDirect3DSurface9* backbuffer = NULL;

	dx9->pd3dDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer);

	if (spriteStruct.curFrame < spriteStruct.numFrames)
		++spriteStruct.curFrame;
	else
		spriteStruct.curFrame = 0;

	spriteStruct.src.left = spriteStruct.curFrame * SPRITE_WIDTH;
	spriteStruct.src.right = spriteStruct.src.left + SPRITE_WIDTH;


	spwite->DrawTexture(0, 0, &spriteStruct.src, 0xFFFFFFFF);

	/*dx9->pd3dDevice->StretchRect
	(
		curSprite,
		&src,
		backbuffer,
		&dst,
		D3DTEXF_NONE
	);*/
}
