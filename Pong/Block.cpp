#include "pch.h"
#include "Block.h"
#include <iostream>


Block::Block()
{

	Block::numBlocks++;

	blockShape.setSize(sf::Vector2f(sizeX, sizeY));
	blockShape.setPosition(sf::Vector2f(startPosX + numBlocks*sizeX \
		+ numBlocks*spaceX, startPosY));


	std::cout << numBlocks << "\n";
	
}

Block::~Block()
{
	Block::numBlocks--;
	std::cout << "Dead\n";
}

sf::RectangleShape Block::getShape()
{
	return blockShape;
}

void Block::rebound()
{
	
}


void Block::hitBottom()
{

}

void Block::update()
{

}

int Block::numBlocks;
