#include "pch.h"
#include "Bat.h"

Bat::Bat()
{
	position.x = 1024 / 2;
	position.y = 768 - 20;

	batSpeed = 300.f;

	body.setSize(sf::Vector2f(50, 5));
	body.setPosition(position);
	body.setFillColor(sf::Color::Red);

	rightPressed, leftPressed = false;
}

sf::FloatRect Bat::getPosition()
{
	return body.getGlobalBounds();
}

sf::RectangleShape Bat::getShape()
{
	return body;
}

void Bat::moveLeft()
{
	leftPressed = true;
}

void Bat::moveRight()
{
	rightPressed = true;
}

void Bat::stopLeft()
{
	leftPressed = false;
}

void Bat::stopRight()
{
	rightPressed = false;
}


void Bat::update(float dtAsSeconds)
{
	// Update position of bat
	if (leftPressed)
		position.x -= batSpeed * dtAsSeconds;
	if (rightPressed)
		position.x += batSpeed * dtAsSeconds;

	// Set position of bat
	body.setPosition(position);
}