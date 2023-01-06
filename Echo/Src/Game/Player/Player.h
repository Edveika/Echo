#pragma once

class Player
{
private:
	int state;
	int health;
	D3DXVECTOR2 curPos;
	D3DXVECTOR2 curVel;

	Sprite* sprites[100];
	Sprite* curSprite;

	Engine* engine;

public:
	Player(Engine* engine);
	~Player();

	void Update();
	void Draw(bool bTimeToDraw);

	bool InitGraphics();

	void GetCurSprite();

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void JumpRight();
	void JumpLeft();
	void MoveIdle();

	void Movement();
};