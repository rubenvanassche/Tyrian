/*
 * Game.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Game.h"

namespace tyLib{

Game::Game(std::string const filename, Bridge* bridge) {
	// Load the xml file
	FileLoader fileloader;
	XMLGame game = fileloader.loadFile(filename);

	this->fLevelName = game.levelName;
	this->fLevelDifficulty = game.levelDifficulty;
	this->fStages = game.stages;

	// Create a world
	this->fWorld = new World(320, 320, bridge);

	// Create HAL9000 the A.I.
	this->fHAL = new HAL9000(this->fWorld);

	// Build the ship of the player
	ShipFactory factory(this->fWorld);
	Vector startPosition(100, 100);
	Ship* playerPtr = factory.fighter(startPosition, "basic");
	this->fWorld->setPlayer(playerPtr);
	this->fWorld->addShip(playerPtr);
}

void Game::play(){
	// Have we won?
	if(this->fStages.size() == 0){
		if(this->fWorld->getShips().size() == 1){
			if(this->fWorld->getShips().front() == this->fWorld->getPlayer()){
				// TODO you win
				std::cout << "WON" << std::endl;
				return;
			}else{
				// TODO you lose
				std::cout << "LOSE" << std::endl;
				return;
			}
		}
	}

	// Do we need to load other ships
	if(this->fWorld->getShips().size() == 1){
		this->createStage(this->fStages.front());
		this->fStages.pop_front();
	}

	// Let's move all the enemy ships
	fHAL->moveShips();

	// Let's move all the bullets
	fHAL->moveBullets();

	// Do collision detection of enemy ships with player
	fHAL->shipCollisionDetection();

	// Do collision detection of bullets
	fHAL->bulletCollisionDetection();

	// Check if we have dead Ships
	fHAL->checkForDeadShips();
}


void Game::createStage(XMLStage const &stage){
	ShipFactory factory(this->fWorld);
	factory.build(stage);
}

void Game::movePlayer(Direction direction){
	// Check if we can move the players ship without getting out of bounds
	if(this->fWorld->collides(this->fWorld->getPlayer()) == false){
		// Ship isn't in Game anymore
		return;
	}

	this->fWorld->getPlayer()->move(direction);
}

void Game::shootPlayer(){
	this->fWorld->getPlayer()->shoot();
	std::cout << "shoot" << std::endl;
}

void Game::print(){

	std::cout << "Levelname: " << this->fLevelName << std::endl;
	std::cout << "Difficulty: " << this->fLevelDifficulty << std::endl;
	std::cout << "Stages todo: " << this->fStages.size() << std::endl;
	std::cout << "World(" << this->fWorld->getWidth() << ", " << this->fWorld->getHeight() << ")" << std::endl;
	std::cout << "--------------" << std::endl << "Ships(" << this->fWorld->getShips().size() << ")"<< std::endl << "----------------" << std::endl;
	for(auto i : this->fWorld->getShips()){
		if(i == this->fWorld->getPlayer()){
			std::cout << "PLAYER: (" << i->getLocation().x << ", " << i->getLocation().y << ")" << std::endl;
		}else{
			std::cout << "ENEMY: (" << i->getLocation().x << ", " << i->getLocation().y << ")" << std::endl;
		}
	}
	std::cout << "--------------" << std::endl << "Bullets(" << this->fWorld->getBullets().size() << ")"<< std::endl << "----------------" << std::endl;
	for(auto i : this->fWorld->getBullets()){
		if(i->getFrom() == this->fWorld->getPlayer()){
			std::cout << "PLAYER: (" << i->getLocation().x << ", " << i->getLocation().y << ")" << std::endl;
		}else{
			std::cout << "ENEMY: (" << i->getLocation().x << ", " << i->getLocation().y << ")" << std::endl;
		}
	}

	//std::cout << "Stages todo: " << this->fStages.size() << "  --  Ships(" << this->fWorld->getShips().size() << ")" << std::endl;
}

Game::~Game() {
	delete this->fWorld;
	delete this->fHAL;
}

}

