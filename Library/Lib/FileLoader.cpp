/*
 * FileLoader.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "FileLoader.h"

namespace tyLib{

FileLoader::FileLoader() {
	// TODO Auto-generated constructor stub

}

std::vector<Level> FileLoader::getLevels(std::string const directory){
	// System for reading directory
	tinydir_dir dir;
	tinydir_open(&dir, directory.c_str());

	std::vector<Level> levels;

	while (dir.has_next){
	    tinydir_file file;
	    tinydir_readfile(&dir, &file);

	    // Remove some unneeded things in the directory
	    if(file.name == ".." or file.name == "." or file.is_dir){
	    	tinydir_next(&dir);
	    	continue;
	    }

	    // Make a level;
	    Level level = this->getLevel(file.name, directory);
	    levels.push_back(level);

	    tinydir_next(&dir);
	}

	tinydir_close(&dir);

	return levels;
}

Level FileLoader::getLevel(std::string const filename, std::string directory){
	Level level;
	level.filename = filename;
	level.directory = directory;
	level.path = directory + "/" + filename;

	// Now get the difficulty and name
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(level.path.c_str());
	if(result){
		// get the name of the level
		level.name = doc.child("level").child_value("name");
		// get the difficulty of the level
		level.difficuly = atoi(doc.child("level").child_value("difficulty"));
	}else{
		throw std::runtime_error("Couldn't open the xml file");
	}

	return level;
}

XMLLevel FileLoader::loadFile(std::string const filename){
	// Load the xml File
	pt::ptree tree;
	pt::read_xml(filename, tree);

	// Create The Level
	XMLLevel level;
	level.name = tree.get<std::string>("level.name");
	level.difficulty = tree.get<int>("level.difficulty");

	// Process the Stages
	for(const auto& stageNode : tree.get_child("level.stages")){
		if(stageNode.first == "stage"){
			pt::ptree stageTree = stageNode.second;
			// Create a stage
			XMLStage stage;
			stage.start = stageTree.get<int>("start");

			for(const auto& shipNode : stageTree.get_child("ships")){
				if(shipNode.first == "ship"){
				pt::ptree shipTree = shipNode.second;
        		// Create a ship
        		XMLShip ship;

        		ship.type = shipTree.get<std::string>("type");
        		ship.gun = shipTree.get<std::string>("gun");
        		ship.x = shipTree.get<int>("x");
        		ship.y = shipTree.get<int>("y");

        		// Convert the type and gun to lowercase
        		std::transform(ship.type.begin(), ship.type.end(), ship.type.begin(), ::tolower);
        		std::transform(ship.gun.begin(), ship.gun.end(), ship.gun.begin(), ::tolower);


        		stage.ships.push_back(ship);
				}else{
					// Not valid xml node
				}
			}
			level.stages.push_back(stage);
		}else{
			// Not valid xml node
		}
    }

    //Check if the data is valid
	if(this->checkData(level) == false){
		throw std::runtime_error("Something is wrong with the XML data");
	}

	return level;
}



bool FileLoader::checkData(XMLLevel &level){
	// Check if the difficulty is between 1 and 5
	if(level.difficulty < 1 or level.difficulty > 5){
		throw std::runtime_error("The level difficulty should be between 1 and 5");
		return false;
	}

	for(auto i : level.stages){
		// Check if the start is an valid number
		if(i.start < 0){
			throw std::runtime_error("The start of a stage must be greater than 0");
			return false;
		}

		for(auto j : i.ships){
			// Check if the type is valid
			if(std::find(this->fValidShipTypes.begin(), this->fValidShipTypes.end(), j.type) == this->fValidShipTypes.end()){
				throw std::runtime_error("The Ship type is not valid");
				return false;
			}

			if(std::find(this->fValidGunTypes.begin(), this->fValidGunTypes.end(), j.gun) == this->fValidGunTypes.end()){
				throw std::runtime_error("The Gun type is not valid");
				return false;
			}

			// Check if the coordinates of the ships are valid
			if(j.x < 0 or j.x > this->fGameWidth){
				throw std::runtime_error("The X Coordinate of a ship must valid");
				return false;
			}

			if(j.y < 0){
				throw std::runtime_error("The y Coordinate of a ship must be positive or 0");
				return false;
			}
		}
	}

	return true;
}

void FileLoader::visualize(){
	if(this->fStages.empty()){
		std::cout << "Please load an XML file" << std::endl;
		return;
	}

	std::cout << "Level Name: " << this->fLevelName << std::endl;
	std::cout << "Level Difficulty: " << this->fLevelDifficulty << std::endl;

	int counter = 0;
	for(auto i: this->fStages){
		std::cout << "Stage " << counter << std::endl << "-----------------" << std::endl;
		std::cout << "Start after " << i.start << " seconds" << std::endl;

		int counter2 = 0;
		for(auto j : i.ships){
			std::cout << "Ship " << counter2 << "  - type:" << j.type << " - gun:" << j.gun << " - (" << j.x << ", " << j.y << ")" << std::endl;

			counter2++;
		}

		counter++;
	}
}


FileLoader::~FileLoader() {
	// TODO Auto-generated destructor stub
}

}

