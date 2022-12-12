#pragma once

class Player
{
private:
	int state;
	int health;
	Vector2 curPos;
	Vector2 curVel;

public:
	Player();
	~Player();
};