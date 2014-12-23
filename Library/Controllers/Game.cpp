/*
 * Game.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Game.h"

Game::Game() {
	this->fWorld = new World;

}

void Game::play(){

}

void Game::setup(std::string filename){
	// Load the xml file
	FileLoader fileloader;
	XMLGame game = fileloader.loadFile(filename);

	this->fLevelName = game.levelName;
	this->fLevelDifficulty = game.levelDifficulty;
	this>fStages = game.stages;
}

void Game::createStage(XMLStage &stage){
	ShipFactory factory(this->fWorld->ships);
	factory.build(stage);
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

