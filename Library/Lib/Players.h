/*
 * Players.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_LIB_PLAYERS_H_
#define LIBRARY_LIB_PLAYERS_H_

#include <vector>
#include "../Models/Ship.h"
#include "Config.h"
#include "../Models/World.h"
#include "../Factories/ShipFactory.h"
#include "FileLoader.h"
#include <string>

namespace tyLib{
	class World;

/**
 * @ brief container representing one ore more players
 */
class Players {
public:
	/**
	 * @brief Construct a players container with an amount of players
	 * @param amount the amount of players to build
	 * @param world the world to create the player in
	 */
	Players(int const amount, World* world);

	/**
	 * @brief Checks if a ship is an player
	 * @return  true if the ship is an player
	 */
	bool isPlayer(Ship* const ship) const;

	/**
	 * Get a player
	 * @param  i
	 * @return   ship from the player
	 */
	Ship* operator[](int const i);

	/**
	 * Get a player
	 * @param  i
	 * @return   ship from the player
	 */
	Ship* at(int const i);

	/**
	 * The amount of players in the container
	 * @return integer
	 */
	int size() const;

	virtual ~Players();
private:
	std::vector<Ship*> fPlayers;
	World* fWorld = nullptr;
};

}

#endif /* LIBRARY_LIB_PLAYERS_H_ */
