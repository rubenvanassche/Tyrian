/*
 * Tile.h
 *
 *  Created on: 6-jan.-2015
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_TILE_H_
#define LIBRARY_MODELS_TILE_H_

#include "Entity.h"

namespace tyLib {

/**
 * @brief Representation of the background
 */
class Tile : public Entity {
public:
	Tile();

	/**
	 * @brief Move the tile in an direction, only up and down supported
	 */
	void move(Direction const direction, double const delta)

	virtual ~Tile();
};

} /* namespace tyLib */

#endif /* LIBRARY_MODELS_TILE_H_ */
