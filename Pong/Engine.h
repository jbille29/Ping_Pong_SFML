#pragma once
#include "Ball.h"
#include "Bat.h"
#include <sstream>
#include <SFML/Graphics.hpp>

class Engine
{
private:
	sf::Vector2f resolution;
	sf::RenderWindow window;

	int score;
	int lives;

	// create a bat
	//Bat bat(resolution.x / 2, resolution.y - 20);
	Bat bat;

		// create a ball
		//Ball ball(resolution.x / 2, 1);
	Ball ball;

	// create text objects
	Text hud;
	Font font;

	void Input();
	void Update(float dtAsSeconds);
	void Draw();
public:
	void Start();
	Engine();
};

