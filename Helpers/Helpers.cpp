/*
 * Helpers.cpp
 *
 *  Created on: 27-dec.-2014
 *      Author: Ruben
 */

#include "Helpers.h"

namespace tySFML {

sf::Vector2f toVector2(tyLib::Size size){
	sf::Vector2f vector;
	vector.x = size.width;
	vector.y = size.height;

	return vector;
}

sf::Vector2f toVector2(tyLib::Point point){
	sf::Vector2f vector;
	vector.x = point.x;
	vector.y = point.y;

	return vector;
}

} /* namespace tySFML */
