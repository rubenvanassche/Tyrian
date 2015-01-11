/*
 * FileLoader.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_LIB_FILELOADER_H_
#define LIBRARY_LIB_FILELOADER_H_

#include <string>
#include <list>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "../External/pugixml.hpp"
#include "../External/tinydir.h"

namespace tyLib{

/**
 * @brief Structure to represent an XML Ship
 */
struct XMLShip{
	std::string type;
	std::string gun;
	int x;
	int y;
};

/**
 * @brief Structure to represent an XML Stage
 */
struct XMLStage{
	int start;
	std::list<XMLShip> ships;
};

/**
 * @brief Structure representing the whole game
 */
struct XMLGame{
	std::string levelName;
	int levelDifficulty;
	std::list<XMLStage> stages;
};

/**
 * @brief Structure representing a level
 */
struct Level{
	std::string directory;
	std::string filename;
	std::string name;
	std::string path;
	int difficuly;
};

/**
 * @brief Loads a game file
 */
class FileLoader {
public:
	/**
	 * @brief Construct the loader
	 */
	FileLoader();

	/**
	 * @brief Get all the levels in an certain directory
	 */
	std::vector<Level> getLevels(std::string const directory);

	/**
	 * @brief get information about a level file
	 */
	Level getLevel(std::string const filename, std::string directory);

	/**
	 * @brief Load a file by a given filename and return an XMLGame
	 */
	XMLGame loadFile(std::string const filename);

	/**
	 * @brief Generate a Stage Structure based upon an given Stage xml node
	 */
	XMLStage processStage(pugi::xml_node& doc);

	/**
	 * @brief Generate a Ship Structure based upon an given Ship xml node
	 */
	XMLShip processShip(pugi::xml_node& doc);

	/**
	 * @brief check if the Data is correct loaded from an xml document
	 */
	bool checkData();

	/**
	 * @brief Generate a visual representation of an XML file(using the IOStream)
	 */
	void visualize();

	virtual ~FileLoader();
private:
	// List with all the valid shiptypes
	std::list<std::string> const fValidShipTypes{"standard", "longue"};
	// List with all the valid guntypes
	std::list<std::string> const fValidGunTypes{"basic"};
	// The width of the game
	int const fGameWidth = 320;

	std::string fLevelName;
	int fLevelDifficulty;

	std::list<XMLStage> fStages;
};

}

#endif /* LIBRARY_LIB_FILELOADER_H_ */
