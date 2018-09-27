#include "pch.h"
#include "Ball.h"

Ball::Ball()
{
	position.x = 1024 / 2;
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
	// Update ball position
	position.y += yVelocity * dtAsSeconds;
	position.x += xVelocity * dtAsSeconds;

	// Set new position for ball
	body.setPosition(position);
}