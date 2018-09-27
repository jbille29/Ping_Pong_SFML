#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Bat
{
private:
	sf::Vector2f position;

	sf::RectangleShape body;

	float batSpeed;

	bool rightPressed, leftPressed;

public:
	Bat();

	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	void moveLeft();

	void moveRight();

	void stopLeft();

	void stopRight();

	void update(float dtAsSeconds);

	Collider GetCollider() { return Collider(body); }

};
