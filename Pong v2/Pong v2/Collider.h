#pragma once
#include <SFML/Graphics.hpp>

/*
	Collider: The class will detect and respond to collisions. This class is probably overkill
	relative to the complexity of this game, but the point is to build a robust Collider class
	that can be implemented in other applications.
*/
class Collider
{
private:
	sf::RectangleShape body;

public:
	Collider(sf::RectangleShape& body);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool checkCollision(Collider& other, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
};