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

/**
 * @brief The master controller who controls the whole game
 */
class Game {
public:
	Game();

	/**
	 * @brief Play one iteration
	 */
	void play();

	/**
	 * @brief Setup a level with a given file
	 */
	void setup(std::string file);

	/**
	 * @brief Create a stage from an XMLStage object
	 */
	void createStage(XMLStage &stage);

	virtual ~Game();
private:
	// Initial XML Stuff
	std::string fLevelName;
	int fLevelDifficulty;
	std::list<XMLStage> fStages;

	// The class stuff
	World* fWorld;
};

#endif /* LIBRARY_CONTROLLERS_GAME_H_ */
