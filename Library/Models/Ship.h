/*
 * Ship.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_SHIP_H_
#define LIBRARY_MODELS_SHIP_H_

#include "Entity.h"
#include "Gun.h"

namespace tyLib{

class Gun;


/**
 * @brief Model representing a Ship
 */
class Ship : public Entity {
public:
	/**
	 * @brief Constructs a Ship
	 */
	Ship(Vector location, Size size, Vector veolcity, double health);

	/**
	 * @brief Moves a ship to a certain Direction
	 */
	void move(Direction const direction, double const delta);

	/**
	 * @brief Shoot a Bullet from the Ship
	 */
	void shoot() const;

	/**
	 * @brief Add some score to the ship
	 */
	void addScore(const double score);

	/**
	 * @brief Get the score the ship recieved
	 */
	double getScore() const;

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
	double fHealth;

	double fScore;

	Gun* fGun;
};

}

#endif /* LIBRARY_MODELS_SHIP_H_ */
