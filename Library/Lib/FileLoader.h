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
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include "../External/pugixml.hpp"
#include "../External/tinydir.h"
#include "../Lib/Size.h"
#include "../Lib/Point.h"
#include <set>
#include <map>
#include <exception>
#include <assert.h>
namespace pt = boost::property_tree;

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
 * @brief Structure representing the level game
 */
struct XMLLevel{
	// Level Info
	std::string name;
	int difficulty;
	std::list<XMLStage> stages;
};

/**
 * @brief Structure representing a texture
 */
struct XMLTextureBlueprint{
	std::string filename;
	int ticks;
	Vector offset;
	Vector tickOffset;
};

/**
 * @brief Structure representing a ship
 */
struct XMLShipBlueprint{
	std::string type;
	Size size;
	Vector velocity;
	double health;
	std::string gun;
	XMLTextureBlueprint texture;
};

/**
 * @brief Structure representing a bullet
 */
struct XMLBulletBlueprint{
	std::string type;
	Size size;
	Vector velocity;
	double damage;
	XMLTextureBlueprint texture;
};

/**
 * @brief Structure representing a gun
 */
struct XMLGunBlueprint{
	std::string type;
	std::string bullets;
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
	XMLLevel loadFile(std::string const filename);

	/**
	 * @brief check if the Data is correct loaded from an xml document
	 */
	bool checkData(XMLLevel &game);

	/**
	 * @brief load the ship blueprints
	 */
	std::map<std::string, XMLShipBlueprint> getShipBlueprints();

	/**
	 * @brief load the bullet blueprints
	 */
	std::map<std::string, XMLBulletBlueprint> getBulletBlueprints();

	/**
	 * @brief load the gun blueprints
	 */
	std::map<std::string, XMLGunBlueprint> getGunBlueprints();

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
