#include "Game.h"

#include <iostream>

Game::Game() : m_window("Chapter 2", sf::Vector2u(800, 600)), m_player(m_world.GetBlockSize()), m_world(sf::Vector2u(800,600)) {
	// setting up class members
	m_increment = sf::Vector2i(400, 400);

	m_textbox.Setup(5, 14, 350, sf::Vector2f(255, 0));
	srand(time(nullptr));
	m_textbox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));
}

Game::~Game() {

}

void Game::HandleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_player.SetDirection(Direction::Down);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_player.SetDirection(Direction::Up);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_player.SetDirection(Direction::Right);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_player.SetDirection(Direction::Left);
	} else {
		m_player.SetDirection(Direction::None);
	}
}

void Game::Update() {
	m_window.Update(); // update window events

	float frametime = 1.0f / m_player.GetSpeed(); // (player speed) per second

	if (m_elapsed.asSeconds() >= frametime) {
		m_player.Tick();
		m_world.Update(m_player);
		m_elapsed -= sf::seconds(frametime);
		if (m_player.HasLost()) {
			m_player.Reset();
		}
	}
}

void Game::Render() {
	m_window.BeginDraw(); // clear

	// render here
	m_world.Render(*m_window.GetRenderWindow());
	m_player.Render(*m_window.GetRenderWindow());
	m_textbox.Render(*m_window.GetRenderWindow());

	m_window.EndDraw(); // display
}

Window* Game::GetWindow() {
	return &m_window;
}

sf::Time Game::GetElapsed() {
	return m_elapsed;
}

void Game::RestartClock() {
	m_elapsed += m_clock.restart();
}