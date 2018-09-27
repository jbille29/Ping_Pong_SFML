#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Ball
{
private:
	sf::Vector2f position;

	// A RectangleShape object called ref
	sf::RectangleShape body;

	float xVelocity = 200.0f;
	float yVelocity = 200.0f;
	

public:
	//Ball(float startX, float startY);
	Ball();
	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	float getXVelocity();

	void reboundSides();

	void reboundBatOrTop();

	void hitBottom();

	void update(float dtAsSeconds);

	Collider GetCollider() { return Collider(body); }

};
