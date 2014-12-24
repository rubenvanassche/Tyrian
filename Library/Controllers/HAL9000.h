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
	 * @brief move all the enemy ships
	 */
	void move(std::list<Ship*>& ships);

	virtual ~HAL9000();
private:
	World* fWorld;
};

#endif /* LIBRARY_CONTROLLERS_HAL9000_H_ */
