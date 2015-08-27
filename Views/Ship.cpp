/*
 * Ship.cpp
 *
 *  Created on: 27-dec.-2014
 *      Author: Ruben
 */

#include "Ship.h"

namespace tySFML {

Ship::Ship(Window* window, tyLib::Ship* const ship) : View(window){
	this->fShip = ship;
}

void Ship::draw(){
	if(!this->fShip->isVisible()){
		// Ship is not visible so don't draw
		return;
	}

	if(this->fShip->isTextured()){
		tyLib::Texture texture = this->fShip->getTexture();
		if(this->fTick > texture.ticks){
			this->fTick = 0;
		}

		int x = texture.offset.x + this->fTick*texture.tickOffset.x;
		int y = texture.offset.y;

		this->drawSprite(texture.filename, this->fShip->getLocation(), this->fShip->getSize(), x, y);

		this->fTick++;
	}else{
		sf::RectangleShape rectangle(toVector2(this->fShip->getSize()));
		rectangle.setPosition(toVector2(this->fShip->getLocation()));
		rectangle.setFillColor(sf::Color::Green);

		this->fWindow->draw(rectangle);
	}

}

bool Ship::is(tyLib::Ship* const ship) const{
	return this->fShip == ship;
}

} /* namespace tySFML */
