#include "Controller.h"

Controller::Controller() {

}

void Controller::handle(sf::RenderWindow &window)
{
	sf::Event event;
	
	closed = false;
	left = false;
	right = false;
	up = false;
	down = false;
	run = false;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			closed = true;
		}

		if (event.type == sf::Event::KeyPressed) {
			switch(event.key.code){
				case sf::Keyboard::Space:
					run = true;
					break;
				case sf::Keyboard::Left:
					left = true;
					break;
				case sf::Keyboard::Right:
					right = true;
					break;
				case sf::Keyboard::Up:
					up = true;
					break;
				case sf::Keyboard::Down:
					down = true;
					break;
			}
		}
	}
}