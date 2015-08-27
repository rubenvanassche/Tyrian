/*
 * Tile.cpp
 *
 *  Created on: 11-jan.-2015
 *      Author: Ruben
 */

#include "Tile.h"

namespace tySFML {

Tile::Tile(Window* window, tyLib::Tile* tile) : View(window){
	this->fTile = tile;
}

void Tile::draw(){
	// First draw the background
	for(auto i : *this->fTile->getBackground()){
		if(i->name == "Grass"){
			this->drawGrass(i);
		}
	}
}

void Tile::drawGrass(Entity* entity){
	int textureOffsetX = 0;
	int textureOffsetY = 0;

	sf::Texture texture = *this->fAssets->getTexture("grass.png");

	sf::Sprite sprite;
	//sprite.setScale(toVector2(entity->size));
	sprite.setPosition(toVector2(entity->location));
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(textureOffsetX, textureOffsetY, entity->size.width, entity->size.height));

	this->fWindow->draw(sprite);
}

bool Tile::is(tyLib::Tile* tile){
	return this->fTile == tile;
}

} /* namespace tySFML */
