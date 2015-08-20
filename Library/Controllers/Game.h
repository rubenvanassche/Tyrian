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
#include "../Lib/Highscores.h"
#include "../Lib/Config.h"
#include "HAL9000.h"

namespace tyLib{

/**
 * @brief The master controller who controls the whole game
 */
class Game {
public:
	Game(std::string const filename, Bridge* bridge, int const amountOfPlayers);

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
	void movePlayer(Direction direction, double const delta, int const playerID);

	/**
	 * @brief Shoot a bullet out of the gun of the player
	 */
	void shootPlayer(int const playerID);

	/**
	 * @brief returns true if the player has won the game
	 */
	bool won();

	/**
	 * @brief returns true if the player has lost the game
	 */
	bool lose();

	/**
	 * @brief Update the highscores
	 */
	bool updateHighscores() const;

	/**
	 * @brief get a pointer to the Tile
	 */
	Tile* getTile();

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
	bool fWon = false;
	bool fLose = false;
};

}

#endif /* LIBRARY_CONTROLLERS_GAME_H_ */
