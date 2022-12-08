#include "../../Includes.h"

// seperate struct for sprites and audio?

Player::Player()
{

}

Player::~Player()
{

}

bool Init()
{

}

bool Player::InitTextures()
{
	spriteBitmap = dx9->GetSurfaceFromBitmap(bitmapFileName, bitmapImageWidth, bitmapImageHeight);

	if (spriteBitmap == NULL)
		return false;

	return true;
}

void Player::DecreaseHealth()
{
	--health;
}

void Player::IncreaseHealth()
{
	++health;
}