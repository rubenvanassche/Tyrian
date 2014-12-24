/*
 * Gun.h
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_GUN_H_
#define LIBRARY_MODELS_GUN_H_

#include "Entity.h"

/**
 * @brief Model representing a Gun
 */
class Gun : public Entity {
public:
	Gun();
	virtual void move(Direction const direction);
	virtual ~Gun();
};

#endif /* LIBRARY_MODELS_GUN_H_ */
