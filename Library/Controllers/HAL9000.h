/*
 * HAL9000.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_CONTROLLERS_HAL9000_H_
#define LIBRARY_CONTROLLERS_HAL9000_H_

#include <string>

/**
 * @brief The Artificial Intelligence for Bullets and enemy Ships
 */
class HAL9000 {
public:
	/**
	 * @brief Construct HAL 9000
	 */
	HAL9000();

	std::string openThePodBayDoors() const;

	virtual ~HAL9000();
};

#endif /* LIBRARY_CONTROLLERS_HAL9000_H_ */
