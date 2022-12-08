#pragma once

class Player
{
private:
	DirectX9 *dx9;
	std::string bitmapFileName;
	int bitmapImageWidth;
	int bitmapImageHeight;

	int health;
	int state;
	Vector2 curPos;
	Vector2 curVel;

	IDirect3DSurface9* spriteBitmap;
	IDirect3DSurface9* curSprite;
	int spriteWidth;
	int spriteHeight;

	std::vector<IXAudio2SourceVoice*> soundEffect;
	std::vector<IXAudio2SourceVoice*> voice;

public:
	Player();
	~Player();

	bool Init();
	bool InitTextures();
	bool InitSounds();

	void DecreaseHealth();
	void IncreaseHealth();

	void WalkLeft();
	void WalkRight();
	void Jump();
	void Fall();
};