/*
 * Bullet.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_BULLET_H_
#define LIBRARY_MODELS_BULLET_H_

#include "Entity.h"

/**
 * @brief Model representing a Bullet
 */
class Bullet : public Entity {
public:
	/**
	 * @brief Construct a Bullet
	 */
	Bullet();

	/**
	 * @brief Moves a Bullet to a certain Direction
	 */
	void move(Direction const direction);

	virtual ~Bullet();
private:
	int fSpeed = 2;
};

#endif /* LIBRARY_MODELS_BULLET_H_ */
