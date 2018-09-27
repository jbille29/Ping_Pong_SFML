#include "pch.h"
#include "Engine.h"
#include <iostream>

/*
	Engine: Initaiates all the game objects and variables.
*/
Engine::Engine()
{
	windowWidth = 1024;
	windowHeight = 768;

	window.create(sf::VideoMode(windowWidth, windowHeight), "Pong");

	score = 0;
	lives = 3;

	gamePause = false;

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
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed && event.key.code ==
			sf::Keyboard::Space)
		{
			if (gamePause)
			{
				gamePause = false;
			}
			else
			{
				gamePause = true;
			}
		}
	}

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

/*
	Update : Handles collision, increments score, decrements lives, calls game objects Update member functions, and updates the score to the screen.
			The collision is acting funky right now, most likely due to the ball and bat object being frame rate independent. The main loop is checking the collision
			faster than the objects can update. 
*/
void Engine::Update(float dtAsSeconds)
{
	// Ball hitting bottom of window	
	if (ball.getPosition().top > windowHeight)
	{
		ball.hitBottom();
		lives--;

		// Reset score if lives are less than 1
		if (lives < 1) {
			score = 0;
			lives = 3;
		}

	}

	// Ball hitting top of window
	if (ball.getPosition().top < 0)
	{
		ball.reboundBatOrTop();
		score++;
	}

	// Ball hitting sides of window
	if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
	{
		ball.reboundSides();
	}

	// Ball hitting bat
	if (ball.getPosition().intersects(bat.getPosition()))
	{
		// Hit detected so reverse the ball and score a point
		ball.reboundBatOrTop();
	}
	// Update ball and bat objects
	ball.update(dtAsSeconds);
	bat.update(dtAsSeconds);

	// Update the text
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
		   and Draw. The game loop uses variable time steps for now.
*/
void Engine::Start()
{
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		Input();

		if (!gamePause) {
			Update(dtAsSeconds);
			Draw();
		}
	}
}