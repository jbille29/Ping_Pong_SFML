#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Bat
{
private:
	sf::Vector2f position;

	// A RectangleShape object
	sf::RectangleShape body;

	float batSpeed = 300.0f;

	bool rightPressed, leftPressed;

public:
	//Bat(float startX, float startY);
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