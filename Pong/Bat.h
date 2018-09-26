#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
	Vector2f position;

	// A RectangleShape object
	RectangleShape batShape;

	float batSpeed = 300.0f;

	bool rightPressed, leftPressed;

public:
	//Bat(float startX, float startY);
	Bat();
	FloatRect getPosition();

	RectangleShape getShape();

	void moveLeft();

	void moveRight();

	void stopLeft();

	void stopRight();

	void update(float dtAsSeconds);

};