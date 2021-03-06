/*
 * Bridge.h
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_LIB_BRIDGE_H_
#define LIBRARY_LIB_BRIDGE_H_

#include "../Models/Ship.h"
#include "../Models/Bullet.h"

namespace tyLib{

class Ship;
class Bullet;

/**
 * @brief A bridge between the tyLib and an graphical representation
 */
class Bridge {
public:
	Bridge();

	/**
	 * @brief this function get's called when a new Ship is created
	 */
	virtual void createShip(Ship* const shipPtr)=0;

	/**
	 * @brief this function get's called when a new Bullet is created
	 */
	virtual void createBullet(Bullet* const shipPtr)=0;

	/**
	 * @brief this function get's called when a  Ship is removed
	 */
	virtual void removeShip(Ship* const shipPtr)=0;

	/**
	 * @brief this function get's called when a  Bullet is removed
	 */
	virtual void removeBullet(Bullet* const shipPtr)=0;

	virtual ~Bridge();
};

}

#endif /* LIBRARY_LIB_BRIDGE_H_ */
