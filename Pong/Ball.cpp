#include "pch.h"
#include "Ball.h"

// This the constructor and it is called when we create an object
//Ball::Ball(float startX, float startY)
Ball::Ball()
{
	//position.x = startX;
	//position.y = startY;

	position.x = 1920/2;
	position.y = 1;

	body.setSize(sf::Vector2f(10, 10));
	body.setPosition(position);
	body.setFillColor(sf::Color::Red);
}

sf::FloatRect Ball::getPosition()
{
	return body.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
	return body;
}

float Ball::getXVelocity()
{
	return xVelocity;
}

void Ball::reboundSides()
{
	xVelocity = -xVelocity;
}

void Ball::reboundBatOrTop()
{
	position.y -= (yVelocity * 30);
	yVelocity = -yVelocity;

}

void Ball::hitBottom()
{
	position.y = 1;
	position.x = 500;
}

void Ball::update(float dtAsSeconds)
{
	// Update the ball position variables
	position.y += yVelocity * dtAsSeconds;
	position.x += xVelocity * dtAsSeconds;

	// Move the ball and the bat
	body.setPosition(position);
}