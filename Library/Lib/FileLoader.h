/*
 * FileLoader.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_LIB_FILELOADER_H_
#define LIBRARY_LIB_FILELOADER_H_

#include <string>
#include <fstream>
#include <streambuf>
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
	 * @brief check if the xml structure is correct
	 */
	bool checkXML(pugi::xml_node& doc);

	virtual ~FileLoader();
private:
	std::string fLevelName;
	int fLevelDifficulty;

	std::list<XMLStage> fStages;
};

#endif /* LIBRARY_LIB_FILELOADER_H_ */
