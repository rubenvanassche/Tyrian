/*
 * Bullet.cpp
 *
 *  Created on: 27-dec.-2014
 *      Author: Ruben
 */

#include "Bullet.h"

namespace tySFML {

Bullet::Bullet(Window* window, tyLib::Bullet* const bullet) : View(window){
	this->fBullet = bullet;
}

void Bullet::draw(){
	if(!this->fBullet->isVisible()){
		// Ship is not visible so don't draw
		return;
	}

	if(this->fBullet->isTextured()){
		tyLib::Texture texture = this->fBullet->getTexture();
		this->drawSprite(texture.filename, this->fBullet->getLocation(), this->fBullet->getSize(), texture.offset.x, texture.offset.y);
	}else{
		sf::RectangleShape rectangle(toVector2(this->fBullet->getSize()));
		rectangle.setPosition(toVector2(this->fBullet->getLocation()));
		rectangle.setFillColor(sf::Color::Red);

		this->fWindow->draw(rectangle);
	}

}

bool Bullet::is(tyLib::Bullet* const bullet) const{
	return this->fBullet == bullet;
}


} /* namespace tySFML */
