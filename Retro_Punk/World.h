#pragma once

#include "Player.h"
#include <vector>

class World {
public:
	World(sf::Vector2u l_windSize);
	~World();

	int GetBlockSize();
	std::vector<std::vector<int>> GetGrid();

	void Update(Player& l_player);
	void Render(sf::RenderWindow& l_window);

private:
	sf::Vector2u m_windowSize;
	sf::Vector2i m_item;
	int m_blockSize;

	sf::CircleShape m_appleShape;
	sf::Vector2i m_gridSize;
	std::vector<std::vector<int>> m_grid;
};