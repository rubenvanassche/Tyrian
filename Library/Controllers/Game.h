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
#include "HAL9000.h"

/**
 * @brief The master controller who controls the whole game
 */
class Game {
public:
	Game(std::string const filename);

	/**
	 * @brief Play one iteration
	 */
	void play();

	/**
	 * @brief Create a stage from an XMLStage object
	 */
	void createStage(XMLStage const &stage);

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
};

#endif /* LIBRARY_CONTROLLERS_GAME_H_ */
