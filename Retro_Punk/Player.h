#pragma once

#include <SFML/Graphics.hpp>

enum class Direction { None, Up, Down, Left, Right };

class Player {
public:
	Player(int l_blockSize);
	~Player();

	// helper methods
	void SetDirection(Direction l_dir);
	Direction GetDirection();
	float GetSpeed();
	sf::Vector2i GetPosition();
	int GetLives();
	int GetScore();
	void IncreaseScore();
	bool HasLost();

	void Lose(); // lose the game
	void ToggleLost();

	void Reset(); // reset the player to starting position

	void Move(); // movement method
	void Tick(); // update method
	void Render(sf::RenderWindow& l_window);

private:
	void CheckCollision(); // checking for collisions

	sf::Vector2i m_position; 
	int m_size; //size of the graphics
	Direction m_dir; // current direction
	float m_speed; // speed
	int m_lives; // lives
	int m_score; // score
	bool m_lost; // losing state
	sf::RectangleShape m_bodyRect; // shape used in rendering
};
