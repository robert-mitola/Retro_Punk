#include "Player.h"

Player::Player(int l_blockSize) {
	m_size = l_blockSize;
	m_position = sf::Vector2i(7 * l_blockSize, 6 * l_blockSize);
	m_bodyRect.setSize(sf::Vector2f(m_size, m_size));
	Reset();
}

Player::~Player() {

}

void Player::Reset() {
	SetDirection(Direction::None); // start off still
	m_speed = 60.0f;
	m_lives = 3;
	m_score = 0;
	m_lost = false;
}

void Player::SetDirection(Direction l_dir) {
	m_dir = l_dir;
}

Direction Player::GetDirection() {
	return m_dir;
}

float Player::GetSpeed() {
	return m_speed;
}

sf::Vector2i Player::GetPosition() {
	return m_position;
}

int Player::GetLives() {
	return m_lives;
}

int Player::GetScore() {
	return m_score;
}

void Player::IncreaseScore() {
	m_score += 10;
}

bool Player::HasLost() {
	return m_lost;
}

void Player::Lose() {
	m_lost = true;
}

void Player::ToggleLost() {
	m_lost = !m_lost;
}

void Player::Tick(const std::vector<std::vector<int>>& l_grid) {
	if (m_dir == Direction::None) {
		return;
	}
	sf::Vector2i previousPosition = m_position;
	Move();
	CheckCollision(previousPosition, l_grid);
}

void Player::Move() {
	if (m_dir == Direction::Left) {
		--m_position.x;
	}
	else if (m_dir == Direction::Right) {
		++m_position.x;
	}
	else if (m_dir == Direction::Up) {
		--m_position.y;
	}
	else if (m_dir == Direction::Down) {
		++m_position.y;
	}
}

void Player::CheckCollision(const sf::Vector2i& l_previousPosition, const std::vector<std::vector<int>>& l_grid) {
	// player bounds
	sf::Vector2i topLeft = sf::Vector2i(m_position.x, m_position.y);
	sf::Vector2i bottomLeft = sf::Vector2i(m_position.x, m_position.y + m_size - 1);
	sf::Vector2i topRight = sf::Vector2i(m_position.x + m_size -1, m_position.y);
	sf::Vector2i bottomRight = sf::Vector2i(m_position.x + m_size - 1, m_position.y + m_size - 1);

	if (l_grid[topLeft.y / m_size][topLeft.x / m_size] == 1 ||
		l_grid[bottomLeft.y / m_size][bottomLeft.x / m_size] == 1 ||
		l_grid[topRight.y / m_size][topRight.x / m_size] == 1 ||
		l_grid[bottomRight.y / m_size][bottomRight.x / m_size] == 1) {

		m_position = l_previousPosition;
	
	}
}

void Player::Render(sf::RenderWindow& l_window) {
	m_bodyRect.setFillColor(sf::Color::Yellow);
	m_bodyRect.setPosition(m_position.x, m_position.y);
	l_window.draw(m_bodyRect);
}