#include "pch.h"
#include "Bat.h"

// This the constructor and it is called when we create an object
//Bat::Bat(float startX, float startY)
Bat::Bat()
{
	//position.x = startX;
	//position.y = startY;

	position.x = 1920/2;
	position.y = 1080 - 20;

	batShape.setSize(sf::Vector2f(50, 5));
	batShape.setPosition(position);
	batShape.setFillColor(sf::Color::Red);

	rightPressed, leftPressed = false;
}

FloatRect Bat::getPosition()
{
	return batShape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return batShape;
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

	if(leftPressed)
		position.x -= batSpeed * dtAsSeconds;
	if(rightPressed)
		position.x += batSpeed * dtAsSeconds;

	batShape.setPosition(position);
}