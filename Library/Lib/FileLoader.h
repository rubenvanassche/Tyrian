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
#include <stdlib.h>
#include <iostream>
#include "../External/pugixml.hpp"

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
 * @brief Loads a game file
 */
class FileLoader {
public:
	/**
	 * @brief Construct the loader
	 */
	FileLoader();

	void loadFile(std::string const filename);

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
	std::list<std::string> const fValidShipTypes{"standard"};
	// List with all the valid guntypes
	std::list<std::string> const fValidGunTypes{"basic"};
	// The width of the game
	int const fGameWidth = 320;

	std::string fLevelName;
	int fLevelDifficulty;

	std::list<XMLStage> fStages;
};

#endif /* LIBRARY_LIB_FILELOADER_H_ */
