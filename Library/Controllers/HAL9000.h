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
	 * @brief move all the enemy hips
	 */
	void moveShips();

	/**
	 * @brief move all the Bullets
	 */
	void moveBullets();

	/**
	 * @brief Reduce health points if an enemy ship hits the player
	 */
	void shipCollisionDetection();

	/**
	 * @brief Check if bullets hit ships and reduce their health
	 */
	void bulletCollisionDetection();

	virtual ~HAL9000();
private:
	World* fWorld;
};

}

#endif /* LIBRARY_CONTROLLERS_HAL9000_H_ */
