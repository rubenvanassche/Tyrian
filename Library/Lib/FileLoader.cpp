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

XMLGame FileLoader::loadFile(std::string const filename){
	// Load the xml file
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename.c_str());

	if(result){
		// get the name of the level
		this->fLevelName = doc.child("level").child_value("name");
		// get the difficulty of the level
		this->fLevelDifficulty = atoi(doc.child("level").child_value("difficulty"));

		// Let's get the stages
		for (pugi::xml_node stage = doc.child("level").child("stages").child("stage"); stage; stage = stage.next_sibling("stage")){
			XMLStage newstage = this->processStage(stage);
			this->fStages.push_back(newstage);
		}

		// Let's check if the created data is valid
		if(this->checkData() == false){
			throw std::runtime_error("Something is wrong with the XML data");
		}

		// Ok, we're ready to give the XMLGame
		XMLGame game;
		game.levelName = this->fLevelName;
		game.levelDifficulty = this->fLevelDifficulty;
		game.stages = this->fStages;

		return game;
	}else{
		throw std::runtime_error("Something is wrong with the xml file, please correct it.");
	}

}

XMLStage FileLoader::processStage(pugi::xml_node& doc){
		XMLStage newstage;
		// Get the start of the stage
		newstage.start = atoi(doc.child_value("start"));
		// parse the ships
		for (pugi::xml_node ship = doc.child("ships").child("ship"); ship; ship = ship.next_sibling("ship")){
			XMLShip newship = this->processShip(ship);
			newstage.ships.push_back(newship);
		}

		return newstage;
}


XMLShip FileLoader::processShip(pugi::xml_node& doc){
	XMLShip newship;
	// Get the type of the ship
	newship.type = doc.child_value("type");
	newship.gun = doc.child_value("gun");
	newship.x = atoi(doc.child_value("x"));
	newship.y = atoi(doc.child_value("y"));

	// Convert the type and gun to lowercase
	std::transform(newship.type.begin(), newship.type.end(), newship.type.begin(), ::tolower);
	std::transform(newship.gun.begin(), newship.gun.end(), newship.gun.begin(), ::tolower);

	return newship;
}

bool FileLoader::checkData(){
	// Check if the difficulty is between 1 and 5
	if(this->fLevelDifficulty < 1 or this->fLevelDifficulty > 5){
		throw std::runtime_error("The level difficulty should be between 1 and 5");
		return false;
	}

	for(auto i : this->fStages){
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

