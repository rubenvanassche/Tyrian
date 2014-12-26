/*
 * Ship.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_SHIP_H_
#define LIBRARY_MODELS_SHIP_H_

class Gun;

#include "Entity.h"
#include "Gun.h"

/**
 * @brief Model representing a Ship
 */
class Ship : public Entity {
public:
	/**
	 * @brief Constructs a Ship
	 */
	Ship(Point location, Size size, double speed, double health);

	/**
	 * @brief Moves a ship to a certain Direction
	 */
	void move(Direction const direction);

	/**
	 * @brief Shoot a Bullet from the Ship
	 */
	void shoot() const;

	/**
	 * @brief Give the ship a Gun
	 */
	void setGun(Gun*);

	/**
	 * @brief Reduce health
	 */
	void reduceHealth(double points);

	/**
	 * @brief Returns a boolean telling if the ship is dead
	 */
	bool isDead();

	virtual ~Ship();
private:
	// the amount of pixel a ship moves in a direction
	double fSpeed;
	double fHealth;

	Gun* fGun;
};

#endif /* LIBRARY_MODELS_SHIP_H_ */
