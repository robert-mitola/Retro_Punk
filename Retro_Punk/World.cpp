#include "World.h"

World::World(sf::Vector2u l_windSize) {
	m_blockSize = 16;

	m_gridSize = sf::Vector2i(15, 10);
	m_grid = {
		{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
		{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 }
	};

	m_windowSize = l_windSize;
	m_appleShape.setFillColor(sf::Color::Red);
	m_appleShape.setRadius(m_blockSize / 2);

}

World::~World() {}

void World::Update(Player& l_player) {
	// change this
	if (l_player.GetPosition() == m_item) {
		l_player.IncreaseScore();
		// delete item
	}

	int gridSize_x = m_windowSize.x / m_blockSize;
	int gridSize_y = m_windowSize.y / m_blockSize;

	if (l_player.GetPosition().x <= 0 || l_player.GetPosition().y <= 0 || l_player.GetPosition().x >= gridSize_x - 1 || l_player.GetPosition().y >= gridSize_y - 1) {
		l_player.Lose(); // change this
	}
}

void World::Render(sf::RenderWindow& l_window) {
	for (int i = 0; i < m_gridSize.x; ++i) {
		for (int j = 0; j < m_gridSize.y; ++j) {
			
			if (m_grid[j][i] == 1) {
				sf::RectangleShape block;
				block.setPosition(i * m_blockSize, j * m_blockSize);
				block.setSize(sf::Vector2f(m_blockSize, m_blockSize));
				block.setFillColor(sf::Color::Blue);
				l_window.draw(block);
			}
		}
	}

	l_window.draw(m_appleShape);
}

int World::GetBlockSize() {
	return m_blockSize;
}

std::vector<std::vector<int>> World::GetGrid() {
	return m_grid;
}