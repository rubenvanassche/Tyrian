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

namespace tyLib{
/**
 * @ brief container representing one ore more players
 */
class Players {
public:
	/**
	 * @brief Construct a players container with an amount of players
	 */
	Players(int amount);

	/**
	 * @brief Checks if a ship is an player
	 * @return  true if the ship is an player
	 */
	bool isPlayer(Ship* const ship) const;

	virtual ~Players();
private:
	std::vector<Ship*> fPlayers;
};

}

#endif /* LIBRARY_LIB_PLAYERS_H_ */
