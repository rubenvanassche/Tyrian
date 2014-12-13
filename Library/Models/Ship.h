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
 * @brief Model representing a ship
 */
class Ship : public Entity {
public:
	Ship();
	void move(Direction const direction);
	Point getLocation() const;
	Size getSize() const;
	virtual ~Ship();
private:
	// the amount of pixel a ship moves in a direction
	int fSpeed = 5;
};

#endif /* LIBRARY_MODELS_SHIP_H_ */
