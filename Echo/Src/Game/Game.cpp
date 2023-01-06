#include "../Includes.h"

Game::Game(Engine* engine)
{
	this->timer = new Timer();
	this->engine = engine;
	this->localPlayer = new Player(engine);
	s_TimePassed = 0.0f;
}

Game::~Game()
{
	delete localPlayer;
	delete engine;
}

bool Game::InitGame()
{
	
}

void Game::StartGame(bool draw)
{
	
	UpdateGame();
	RenderGame(draw);

}

void Game::UpdateGame()
{
	localPlayer->Update();
}

void Game::RenderGame(bool draw)
{
	localPlayer->Draw(draw);
}