#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f position;

	// A RectangleShape object called ref
	RectangleShape ballShape;

	float xVelocity = 200.0f;
	float yVelocity = 200.0f;

public:
	//Ball(float startX, float startY);
	Ball();
	FloatRect getPosition();

	RectangleShape getShape();

	float getXVelocity();

	void reboundSides();

	void reboundBatOrTop();

	void hitBottom();

	void update(float dtAsSeconds);

};
