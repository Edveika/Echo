#pragma once

class Player
{
private:
	int health;
	int state;
	Vector2 curPos;
	Vector2 curVel;

public:
	Player();
	~Player();
};