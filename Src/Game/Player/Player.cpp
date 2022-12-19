#include "../../Includes.h"

Player::Player(Keyboard* kb)
{
	this->kb = kb;


}

Player::~Player()
{

}

void Player::Update()
{
	this->kb->GetInput();

	if (this->kb->IsPressed(DIK_A))
		MoveLeft();
	else if (this->kb->IsPressed(DIK_D))
		MoveRight();
}

void Player::Draw()
{
	//this->curSprite->Draw();
}

void Player::GetCurSprite()
{
	switch (this->state)
	{
	case MOVE_RIGHT:
		this->curSprite = this->sprites[MOVE_RIGHT];
		break;
	case MOVE_LEFT:
		this->curSprite = this->sprites[MOVE_LEFT];
		break;
	case JUMP_RIGHT:
		this->curSprite = this->sprites[JUMP_RIGHT];
		break;
	case JUMP_LEFT:
		this->curSprite = this->sprites[JUMP_LEFT];
		break;
	default:
		this->curSprite = this->sprites[IDLE];
		break;
	}
}

void Player::MoveRight()
{
	this->state = MOVE_RIGHT;
	++this->curPos.x;
}

void Player::MoveLeft()
{
	this->state = MOVE_LEFT;
	--this->curPos.x;
}

void Player::MoveUp()
{

}

void Player::MoveDown()
{

}

void Player::JumpRight()
{

}

void Player::JumpLeft()
{

}