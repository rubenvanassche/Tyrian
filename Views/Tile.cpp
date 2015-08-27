/*
 * Tile.cpp
 *
 *  Created on: 11-jan.-2015
 *      Author: Ruben
 */

#include "Tile.h"

namespace tySFML {

Tile::Tile(Window* window) : View(window){
	this->fHeightAchieved = 0;
}


void Tile::drawGrass(){
	int textureOffsetX = 0;
	int textureOffsetY = 0;

	sf::Texture texture = *this->fAssets->getTexture("grass2.jpg");

	sf::Sprite sprite1;
	sprite1.setPosition(sf::Vector2f(0,320 - this->fHeightAchieved));
	sprite1.setTexture(texture);
	sprite1.setTextureRect(sf::IntRect(0, 0, 320, 320));

	sf::Sprite sprite2;
	sprite2.setPosition(sf::Vector2f(0,320*2 - this->fHeightAchieved));
	sprite2.setTexture(texture);
	sprite2.setTextureRect(sf::IntRect(0, 0, 320, 320));

	if(this->fHeightAchieved == 320){
		this->fHeightAchieved = 0;
	}else{
		this->fHeightAchieved++;
	}

	this->fWindow->draw(sprite1);
	this->fWindow->draw(sprite2);
}


} /* namespace tySFML */
