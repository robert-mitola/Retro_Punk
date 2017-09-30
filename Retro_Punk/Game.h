#pragma once

#include "Window.h"
#include "World.h"
#include "Textbox.h"

class Game {
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
	sf::Time GetElapsed();
	void RestartClock();

private:
	Window m_window;
	World m_world;
	Player m_player;
	Textbox m_textbox;
	sf::Clock m_clock;
	sf::Time m_elapsed;
	sf::Vector2i m_increment;
};