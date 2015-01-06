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
	sf::RectangleShape rectangle(toVector2(this->fBullet->getSize()));
	rectangle.setPosition(toVector2(this->fBullet->getLocation()));
	rectangle.setFillColor(sf::Color::Red);

	this->fWindow->draw(rectangle);
}

bool Bullet::is(tyLib::Bullet* bullet){
	return this->fBullet == bullet;
}


} /* namespace tySFML */
