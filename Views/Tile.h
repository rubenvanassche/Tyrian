/*
 * Tile.h
 *
 *  Created on: 11-jan.-2015
 *      Author: Ruben
 */

#ifndef VIEWS_TILE_H_
#define VIEWS_TILE_H_

#include "View.h"
#include <Tylib/Models/Tile.h>

namespace tySFML {

using namespace tyLib::te;

class Tile : public View {
public:
	Tile(Window* window, tyLib::Tile* ship);

	void draw();

	/**
	 * @brief Draw a Grass tile
	 */
	void drawGrass(Entity*);

	bool is(tyLib::Tile* tile);
private:
	tyLib::Tile* fTile;
};

} /* namespace tySFML */

#endif /* VIEWS_TILE_H_ */
