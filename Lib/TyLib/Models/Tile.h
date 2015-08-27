/*
 * Tile.h
 *
 *  Created on: 6-jan.-2015
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_TILE_H_
#define LIBRARY_MODELS_TILE_H_

#include "Entity.h"
#include <vector>
#include <string>
#include "../Lib/Point.h"
#include "TileEntityTypes.hpp"

namespace tyLib {


/**
 * @brief Representation of the background
 */
class Tile : public Entity {
public:
	/**
	 * @brief Construct a tile with a certain height and type
	 */
	Tile(int width, int height, std::string tiletype);

	/**
	 * @brief Move the tile in an direction, only up and down supported
	 */
	void move(Direction const direction, double const delta);

	/**
	 * @brief get the entities
	 */
	std::list<te::Entity*>* getEntities();

	/**
	 * @brief get the background
	 */
	std::list<te::Entity*>* getBackground();

	virtual ~Tile();
private:
	/**
	 * @brief Move the entities of the Tile
	 */
	void moveEntities(double const delta);

	/**
	 * @brief Add Entities to the Tile if needed
	 */
	void addEntities(double const delta);

	/**
	 * @brief Move the background
	 */
	void moveBackground(double const delta);

	/**
	 * 	@brief build up the initial background
	 */
	void buildBackground();

	/**
	 * @brief get an Background Entity
	 */
	te::Entity* getBackgroundEntity();

	// Background entities
	std::list<te::Entity*> fBackgroundEntities;
	// Special Entities
	std::list<te::Entity*> fEntities;
	double fMoved = 0;
	int fHeight;
	int fWidth;
	std::string fTileType;
};

} /* namespace tyLib */

#endif /* LIBRARY_MODELS_TILE_H_ */
