/*
 * Helpers.h
 *
 *  Created on: 27-dec.-2014
 *      Author: Ruben
 */

#ifndef HELPERS_HELPERS_H_
#define HELPERS_HELPERS_H_

#include <Tylib/Lib/Point.h>
#include <Tylib/Lib/Size.h>
#include <SFML/Graphics.hpp>

namespace tySFML {
	/**
	 * @brief Convert a tyLib Size to an SFML Vector2
	 */
	sf::Vector2f toVector2(tyLib::Size size);

	/**
	 * @brief Convert a tyLib Point to an SFML Vector2
	 */
	sf::Vector2f toVector2(tyLib::Vector point);

} /* namespace tySFML */

#endif /* HELPERS_HELPERS_H_ */
