/*
 * Bullet.cpp
 *
 *  Created on: 27-dec.-2014
 *      Author: Ruben
 */

#include "Bullet.h"

namespace tySFML {

Bullet::Bullet(Window* window, tyLib::Bullet* bullet) : View(window){
	this->fBullet = bullet;
}

void Bullet::draw(){
	if(!this->fBullet->isVisible()){
		// Ship is not visible so don't draw
		return;
	}

	if(this->fBullet->getType() == "blue"){
		this->drawBlue();
		return;
	}

	sf::RectangleShape rectangle(toVector2(this->fBullet->getSize()));
	rectangle.setPosition(toVector2(this->fBullet->getLocation()));
	rectangle.setFillColor(sf::Color::Red);

	this->fWindow->draw(rectangle);
}

void Bullet::drawBlue(){
	int textureOffsetX = 4;
	int textureOffsetY = 43;

	this->drawSprite("bullets.png", this->fBullet->getLocation(), this->fBullet->getSize(), textureOffsetX, textureOffsetY);
}

bool Bullet::is(tyLib::Bullet* bullet){
	return this->fBullet == bullet;
}


} /* namespace tySFML */
