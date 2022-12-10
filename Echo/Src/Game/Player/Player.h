#pragma once

class Player
{
private:
	DirectX9 *dx9;
	Sprite* spwite;

	//std::string bitmapFileName;
	//int bitmapImageWidth;
	//int bitmapImageHeight;

	int health;
	int state;
	Vector2 curPos;
	Vector2 curVel;

	IDirect3DSurface9* spriteBitmap;
	IDirect3DSurface9* curSprite;
	
	#define SPRITE_WIDTH 170
	#define SPRITE_HEIGHT 180

	struct SpriteStruct
	{
		RECT src;

		float x;
		float y;

		float moveX;
		float moveY;

		int numFrames;
		int curFrame;
	} spriteStruct;

	std::vector<IXAudio2SourceVoice*> soundEffect;
	std::vector<IXAudio2SourceVoice*> voice;

public:
	Player(DirectX9* dx9);
	~Player();

	bool InitTextures();

	// Animations
	bool InitSprites();
	void Draw();

};