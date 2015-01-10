/*
 * Game.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_CONTROLLERS_GAME_H_
#define LIBRARY_CONTROLLERS_GAME_H_

#include <string>
#include <list>
#include "../Lib/FileLoader.h"
#include "../Factories/ShipFactory.h"
#include "../Models/World.h"
#include "../Lib/Bridge.h"
#include "HAL9000.h"

namespace tyLib{

/**
 * @brief The master controller who controls the whole game
 */
class Game {
public:
	Game(std::string const filename, Bridge* bridge);

	/**
	 * @brief Play one iteration with a given delta(seconds between frames)
	 */
	void play(double const delta);

	/**
	 * @brief Create a stage from an XMLStage object
	 */
	void createStage(XMLStage const &stage);

	/**
	 * @brief Move the player with a certain delta
	 */
	void movePlayer(Direction direction, double const delta);

	/**
	 * @brief Shoot a bullet out of the gun of the player
	 */
	void shootPlayer();

	/**
	 * @brief returns true if the player has won the game
	 */
	bool won();

	/**
	 * @brief returns true if the player has lost the game
	 */
	bool lose();

	void print();

	virtual ~Game();
private:
	// Initial XML Stuff
	std::string fLevelName;
	int fLevelDifficulty;
	std::list<XMLStage> fStages;

	// The class stuff
	World* fWorld;
	HAL9000* fHAL;
	bool fWon;
	bool fLose;
};

}

#endif /* LIBRARY_CONTROLLERS_GAME_H_ */
