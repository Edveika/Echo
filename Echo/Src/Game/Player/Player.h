#pragma once

class Player
{
private:
	int state;
	int health;
	D3DXVECTOR3 curPos;
	D3DXVECTOR3 curVel;

public:
	Player();
	~Player();
};