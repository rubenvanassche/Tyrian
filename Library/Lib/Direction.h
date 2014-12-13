/*
 * Direction.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_LIB_DIRECTION_H_
#define LIBRARY_LIB_DIRECTION_H_

#include <string>
#include <algorithm>

/**
 * @brief Container for the direction an Entity should move to
 */
class Direction {
public:
	/**
	 * @brief Constructor for Direction
	 */
	Direction(std::string direction);

	/**
	 * @brief checks if the direction is left
	 */
	bool isLeft() const;

	/**
	 * @brief checks if the direction is right
	 */
	bool isRight() const;

	/**
	 * @brief checks if the direction is up
	 */
	bool isUp() const;

	/**
	 * @brief checks if the direction is down
	 */
	bool isDown() const;

	/**
	 * @brief get the direction in an std::string format
	 */
	std::string getDirection() const;

	virtual ~Direction();
private:
	std::string fDirection;
};

#endif /* LIBRARY_LIB_DIRECTION_H_ */
