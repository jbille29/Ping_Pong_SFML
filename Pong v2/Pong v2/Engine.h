#pragma once
#include "Ball.h"
#include "Bat.h"
#include <sstream>
#include <SFML/Graphics.hpp>

class Engine
{
private:
	// member variables
	sf::RenderWindow window;

	int windowWidth, windowHeight;
	int score;
	int lives;

	bool gamePause;

	// game objects
	Bat bat;
	Ball ball;

	// text objects
	sf::Text hud;
	sf::Font font;

	// private member functions
	void Input();
	void Update(float dtAsSeconds);
	void Draw();
public:
	Engine();
	void Start();
};