#pragma once
#include <SFML/Graphics.hpp>

class Block
{
private:
	sf::Vector2f position;

	sf::RectangleShape blockShape;

	void rebound(); // only going to be called in hitBottom()
	
	const float startPosX = 100, startPosY = 100;
	const float sizeX = 100, sizeY = 30;
	const float spaceX = 50, spaceY = 50;
	
	
public:

	static int numBlocks;

	Block();

	~Block();

	sf::RectangleShape getShape();

	void hitBottom();

	void update();

};

