#include <SFML/Graphics.hpp>
#include <vector>
#include "Grid.h"
#include "Controller.h"

int main()
{

	auto sw = 1024;
	auto sh = 768;
	auto padding = 10;
	auto size = 32;
	auto cols = (sw - padding * 2) / size;
	auto rows = (sh - padding * 2) / size;
	bool paused = true;

	sf::RenderWindow window(sf::VideoMode(sw, sh), "Snake");
	window.setFramerateLimit(60);

	Grid grid(cols, rows, size);

	Controller controller;

	while (window.isOpen())
	{

		controller.handle(window);
		
		if(controller.closed){
			window.close();
			return 0;
		}

		window.clear();
		window.draw(grid);
		window.display();
	}

	return 0;
}