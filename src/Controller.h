#pragma once
#include "SFML/Graphics.hpp"

class Controller
{
public:
	Controller();

	void handle(sf::RenderWindow &window);
	
	bool closed = false;
	bool left = false;
	bool right = false;
	bool up = false;
	bool down = false;
	bool run = false;

};