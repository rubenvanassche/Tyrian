/*
 * FileLoader.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "FileLoader.h"

FileLoader::FileLoader() {
	// TODO Auto-generated constructor stub

}

void FileLoader::loadFile(std::string const filename){
	// Load the xml file
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename.c_str());

	if(result){
		// get the name of the level
		this->fLevelName = doc.child("level").child_value("name");
		// get the difficulty of the level
		this->fLevelDifficulty = atoi(doc.child("level").child_value("difficulty"));

		// Let's get the stages
		for (pugi::xml_node stage = doc.child("level").child("stages"); stage; stage = stage.next_sibling("stages")){
			XMLStage newstage = this->processStage(stage);
			this->fStages.push_back(newstage);
		}
	}else{
		throw std::runtime_error("Something is wrong with the xml file, please correct it.");
	}

}

XMLStage FileLoader::processStage(pugi::xml_node& doc){
		XMLStage newstage;
		// Get the start of the stage
		newstage.start = atoi(doc.child_value("start"));
		// parse the ships
		for (pugi::xml_node ship = doc.child("ships"); ship; ship = ship.next_sibling("ships")){
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

	return newship;
}

bool FileLoader::checkXML(pugi::xml_node& doc){

	return true;
}


FileLoader::~FileLoader() {
	// TODO Auto-generated destructor stub
}

