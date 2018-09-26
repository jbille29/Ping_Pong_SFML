#include "pch.h"
#include "Engine.h"
#include <iostream>

/*
	Engine: Initaiates all our game objects and variables.
*/
Engine::Engine()
{
	
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	std::cout << resolution.x << " " << resolution.y << std::endl;
	// 1920 1080

	window.create(sf::VideoMode(resolution.x, resolution.y),
		"Hive Defense",
		sf::Style::Fullscreen);

	score = 0;
	lives = 3;

	font.loadFromFile("DS-DIGIT.ttf");
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(sf::Color::Red);
}

/*
	Input: Gathers real-time input from the user, which make the bat move.
*/
void Engine::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		bat.moveLeft();
	}
	else 
	{
		bat.stopLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		bat.moveRight();
	}
	else 
	{
		bat.stopRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
}

void Engine::Update(float dtAsSeconds)
{
	// Handle ball hitting the bottom
	//if (ball.getPosition().top > resolution.y)
	if (ball.getPosition().top > resolution.y)
	{
		// reverse the ball direction
		ball.hitBottom();

		lives--;

		// Check for zero lives
		if (lives < 1) {
			// reset the score
			score = 0;
			// reset the lives
			lives = 3;
		}

	}

	// Handle ball hitting top
	if (ball.getPosition().top < 0)
	{
		ball.reboundBatOrTop();

		// Add a point to the players score
		score++;

	}

	// Handle ball hitting sides
	//if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > resolution.x)
	if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > resolution.x)
	{
		ball.reboundSides();
	}

	// Has the ball hit the bat?
	if (ball.getPosition().intersects(bat.getPosition()))
	{
		// Hit detected so reverse the ball and score a point
		ball.reboundBatOrTop();
	}

	ball.update(dtAsSeconds);
	bat.update(dtAsSeconds);


	// Update the HUD text
	std::stringstream ss;
	ss << "Score:" << score << "    Lives:" << lives;
	hud.setString(ss.str());
}


/*
	Draw: Clears the window, draws newly updated objects, and displays them on the screen.
*/
void Engine::Draw()
{
	window.clear();

	window.draw(bat.getShape());
	window.draw(ball.getShape());

	window.draw(hud);

	window.display();
}

/*
	Start: This is where our main game loop lives. It calls our private member functions Input, Update
		   and Draw. The game loop uses minimum time steps, so it executes as fast as it can as long as 
		   it is at least going ___
*/
void Engine::Start()
{
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		Input();
		Update(dtAsSeconds);
		Draw();
	}
}