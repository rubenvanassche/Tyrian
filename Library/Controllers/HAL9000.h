/*
 * HAL9000.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_CONTROLLERS_HAL9000_H_
#define LIBRARY_CONTROLLERS_HAL9000_H_

#include <string>
#include <list>
#include <cstdlib>
#include "../Models/World.h"
#include "../Models/Ship.h"
#include "../Lib/Direction.h"

namespace tyLib{

/**
 * @brief The Artificial Intelligence for Bullets and enemy Ships
 */
class HAL9000 {
public:
	/**
	 * @brief Construct HAL 9000
	 */
	HAL9000(World *world);

	std::string openThePodBayDoors() const;

	/**
	 * @brief move all the enemy Ships
	 */
	void moveShips(double const delta);

	/**
	 * @brief move all the Bullets
	 */
	void moveBullets(double const delta);

	/**
	 * @brief Reduce health points if an enemy ship hits the player
	 */
	void shipCollisionDetection();

	/**
	 * @brief Check if bullets hit ships and reduce their health
	 */
	void bulletCollisionDetection();

	/**
	 * @brief Check if there are dead ships which should be removed
	 */
	void checkForDeadShips();

	/**
	 * @brief Check if there are dead bullets which should be removed
	 */
	void checkForDeadBullets();

	/**
	 * @brief Let's enemies shoot bullets, if pass is true, there wil be fired a bullet imediatly without randomness
	 */
	void shootBullets(bool const pass);


	virtual ~HAL9000();
private:
	World* fWorld;
};

}

#endif /* LIBRARY_CONTROLLERS_HAL9000_H_ */
