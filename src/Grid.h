#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class Grid : public sf::Drawable, public sf::Transformable
{
public:
	Grid(sf::Uint8 cols, sf::Uint8 rows, sf::Uint8 size);

	bool isPositionInBounds(sf::Vector2i pos) const;
	sf::Vector2i getCellPositionAt(sf::Vector2i pos) const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Uint8 rows;
	sf::Uint8 cols;
	sf::Uint8 size;
	sf::Uint16 width;
	sf::Uint16 height;

	sf::RectangleShape background;
	sf::Texture background_texture;
};