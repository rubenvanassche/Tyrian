/*
 * World.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_WORLD_H_
#define LIBRARY_MODELS_WORLD_H_


#include <list>
#include "Bullet.h"
#include "Ship.h"
#include "Entity.h"
#include "../Lib/Bridge.h"
#include "Tile.h"
#include "../Lib/Players.h"

namespace tyLib{

class Bridge;
class Players;

/**
 * @brief The world class, containing the whole battlefield(all the Entities)
 */
class World : public Entity {
public:
	/**
	 * @brief World Constructor
	 */
	World(int width, int height, Bridge* bridge);

	virtual void move(Direction const direction, double const delta){};

	virtual ~World();

	/**
	 * @brief Add a Ship
	 */
	void addShip(Ship* ship);

	/**
	 * @brief Add a Bullet
	 */
	void addBullet(Bullet* bullet);

	/**
	 * @brief Remove a Ship
	 */
	void removeShip(Ship* ship);

	/**
	 * @brief Remove a Bullet
	 */
	void removeBullet(Bullet* bullet);

	/**
	 * @brief Get the player's Ship
	 */
	//Ship* getPlayer();

	/**
	 * @brief Set the player's Ship
	 */
	//void setPlayer(Ship* player);

	/**
	 * @brief Set the players Container
	 */
	void setPlayers(Players* players);

	/**
	 * @brief get the players Container
	 */
	Players* getPlayers();

	/**
	 * @brief get The width of the World
	 */
	int getWidth();

	/**
	 * @brief get The width of the World
	 */
	int getHeight();

	/**
	 * @brief Get all the Ships in the World
	 */
	std::list<Ship*>& getShips();

	/**
	 * @brief Get all the Bullets in the World
	 */
	std::list<Bullet*>& getBullets();

	/**
	 * @brief Get the backgroundtile
	 */
	Tile* getTile();

	/**
	 * @brief The Bridge
	 */
	Bridge* bridge;

private:

	/**
	 * @brief Container for Bullets
	 */
	std::list<Bullet*> bullets;

	/**
	 * @brief Container for Ships
	 */
	std::list<Ship*> ships;

	/**
	 * @brief The ship of the player
	 */
	//Ship* player = nullptr;

	/**
	 * @brief Container representing the player(s)
	 */
	Players* players = nullptr;

	/**
	 * @brief The Tile at the background
	 */
	Tile* tile;

	/**
	 * @brief The Height of the world
	 */
	int height;

	/**
	 * @brief The Width of the world
	 */
	int width;
};

}
#endif /* LIBRARY_MODELS_WORLD_H_ */
