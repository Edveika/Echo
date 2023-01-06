#include "../../Includes.h"

Player::Player(Engine* engine)
{
	this->engine = engine;
	InitGraphics();
}

Player::~Player()
{
	delete engine;
}

void Player::Update()
{
	this->engine->kb->GetInput();

	Movement();
	GetCurSprite();
}

bool Player::InitGraphics()
{
	if ((sprites[IDLE] = new Sprite(this->engine->gfx, L"Idle.png", 128, 128, 2)) == NULL)
		return false;

	if ((sprites[MOVE_LEFT] = new Sprite(this->engine->gfx, L"Run.png", 128, 128, 2)) == NULL)
		return false;

	if ((sprites[MOVE_RIGHT] = new Sprite(this->engine->gfx, L"Dead.png", 128, 128, 2)) == NULL)
		return false;

	return true;
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
	this->state = MOVE_UP;
	--this->curPos.y;
}

void Player::MoveDown()
{
	this->state = MOVE_DOWN;
	++this->curPos.y;
}

void Player::JumpRight()
{

}

void Player::JumpLeft()
{

}

void Player::MoveIdle()
{
	this->state = IDLE;
}

void Player::Movement()
{
	if (this->engine->kb->IsPressed(DIK_A))
		MoveLeft();
	else if (this->engine->kb->IsPressed(DIK_D))
		MoveRight();
	else
		MoveIdle();
}

void Player::Draw(bool bTimeToDraw)
{
	curSprite->Draw(this->curPos, 0XFFFFFFFF, bTimeToDraw);
}