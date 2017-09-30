#include "Player.h"

Player::Player(int l_blockSize) {
	m_size = l_blockSize;
	m_position = sf::Vector2i(3, 3);
	m_bodyRect.setSize(sf::Vector2f(m_size - 1, m_size - 1));
	Reset();
}

Player::~Player() {

}

void Player::Reset() {
	SetDirection(Direction::None); // start off still
	m_speed = 15.0f;
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

void Player::Tick() {
	if (m_dir == Direction::None) {
		return;
	}
	Move();
	CheckCollision();
}

void Player::Move() {
	if (m_dir == Direction::Left) {
		--m_position.x;
	} else if (m_dir == Direction::Right) {
		++m_position.x;
	} else if (m_dir == Direction::Up) {
		--m_position.y;
	} else if (m_dir == Direction::Down) {
		++m_position.y;
	}
}

void Player::CheckCollision() {
	
}

void Player::Render(sf::RenderWindow& l_window) {
	m_bodyRect.setFillColor(sf::Color::Yellow);
	m_bodyRect.setPosition(m_position.x * m_size, m_position.y * m_size);
	l_window.draw(m_bodyRect);
}