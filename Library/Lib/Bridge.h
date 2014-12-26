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

/**
 * @brief A bridge between the tyLib and an graphical representation
 */
class Bridge {
public:
	Bridge();

	/**
	 * @brief this function get's called when a new Ship is created
	 */
	virtual void createShip(Ship* shipPtr)=0;

	/**
	 * @brief this function get's called when a new Bullet is created
	 */
	virtual void createBullet(Bullet* shipPtr)=0;

	/**
	 * @brief this function get's called when a  Ship is removed
	 */
	virtual void removeShip(Ship* shipPtr)=0;

	/**
	 * @brief this function get's called when a  Bullet is removed
	 */
	virtual void removeBullet(Bullet* shipPtr)=0;

	virtual ~Bridge();
};

#endif /* LIBRARY_LIB_BRIDGE_H_ */
