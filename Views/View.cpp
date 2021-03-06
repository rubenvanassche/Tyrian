/*
 * View.cpp
 *
 *  Created on: 27-dec.-2014
 *      Author: Ruben
 */

#include "View.h"

namespace tySFML {

View::View(Window* window)  {
	this->fWindow = window;
	this->fAssets = Assets::getInstance();
}

sf::Sprite View::drawSprite(std::string const file,  tyLib::Vector  const location, tyLib::Size const size, int const offsetX, int const offsetY){
	sf::Texture texture = *this->fAssets->getTexture(file);

	sf::Sprite sprite;
	sprite.setPosition(toVector2(location));
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(offsetX, offsetY, size.width, size.height));

	this->fWindow->draw(sprite);

	return sprite;
}

View::~View() {
	// TODO Auto-generated destructor stub
}

} /* namespace tySML */
