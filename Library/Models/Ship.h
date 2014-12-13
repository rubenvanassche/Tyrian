/*
 * Ship.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_SHIP_H_
#define LIBRARY_MODELS_SHIP_H_

#include "Entity.h"

/**
 * @brief Model representing a Ship
 */
class Ship : public Entity {
public:
	/**
	 * @brief Constructs a Ship
	 */
	Ship();

	/**
	 * @brief Moves a ship to a certain Direction
	 */
	void move(Direction const direction);

	/**
	 * @brief Shoot a Bullet from the Ship
	 */
	void shoot() const;

	virtual ~Ship();
private:
	// the amount of pixel a ship moves in a direction
	int fSpeed = 5;
};

#endif /* LIBRARY_MODELS_SHIP_H_ */
