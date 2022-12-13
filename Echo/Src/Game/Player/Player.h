#pragma once

class Player
{
private:
	int state;
	int health;
	D3DXVECTOR3 curPos;
	D3DXVECTOR3 curVel;

	std::vector<Sprite*> sprites;
	Sprite* curSprite;

	Keyboard* kb;

public:
	Player(Keyboard* kb);
	~Player();

	void Update();
	void Draw();

	void GetCurSprite();

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void JumpRight();
	void JumpLeft();
};