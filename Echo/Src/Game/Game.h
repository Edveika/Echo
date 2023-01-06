#pragma once

class Game
{
public:
	Timer* timer;
	float s_TimePassed;

private:
	Engine* engine;
	Player* localPlayer;

public:
	Game(Engine* engine);
	~Game();

	bool InitGame();
	void StartGame(bool draw);

private:
	void UpdateGame();
	void RenderGame(bool draw);
};