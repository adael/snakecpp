#include "Grid.h"

Grid::Grid(sf::Uint8 cols, sf::Uint8 rows, sf::Uint8 size)
{
	this->rows = rows;
	this->cols = cols;
	this->size = size;
	width = cols * size;
	height = rows * size;

	
	background_texture.loadFromFile("res/tile.png");
	background_texture.setRepeated(true);

	background.setTexture(&background_texture);
	background.setTextureRect(sf::IntRect(0, 0, width, height));
	background.setSize(sf::Vector2f(width, height));
}

bool Grid::isPositionInBounds(sf::Vector2i pos) const
{
	sf::Vector2i npos(pos.x - getPosition().x, pos.y - getPosition().y);

	if (npos.x < 0 || npos.y < 0) {
		return false;
	}

	if (npos.x >= cols * size || npos.y >= rows * size) {
		return false;
	}

	return true;
}

sf::Vector2i Grid::getCellPositionAt(sf::Vector2i pos) const {
	return sf::Vector2i(
		(pos.x - getPosition().x) / size,
		(pos.y - getPosition().y) / size
	);
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(background, states);
}
