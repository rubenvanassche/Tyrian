/*
 * Game.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Game.h"

namespace tyLib{

Game::Game(std::string const filename, Bridge* bridge, int const amountOfPlayers) {
	// Load the xml file
	FileLoader fileloader;
	XMLLevel level = fileloader.loadFile(filename);

	this->fLevelName = level.name;
	this->fLevelDifficulty = level.difficulty;
	this->fStages = level.stages;

	// Config
	Config *config = tyLib::Config::getInstance();

	// Create a world
	this->fWorld = new World(config->getHeight(), config->getWidth(), bridge);

	// Create HAL9000 the A.I.
	this->fHAL = new HAL9000(this->fWorld);

	// Build the ship of the player
	ShipFactory factory(this->fWorld);
	Vector startPosition(100, 100);

	// Build Players container
 	Players* players = new Players(amountOfPlayers, this->fWorld);
	this->fWorld->setPlayers(players);
}

void Game::play(double const delta){
	// Have we won?
	if(this->fStages.size() == 0){
		if(this->fWorld->onlyPlayers()){
			if(this->fWorld->getPlayers()->isPlayer( this->fWorld->getShips().front() )){
				this->fWon = true;
				this->updateHighscores();
				return;
			}else{
				this->fLose = true;
				this->updateHighscores();
				return;
			}
		}
	}

	// Check the Health of the player
	for(int i = 0;i < this->fWorld->getPlayers()->size();i++){
		if(this->fWorld->getPlayers()->at(i)->isDead()){
			this->fLose = true;
			this->updateHighscores();
			return;
		}
	}

	// Do we need to load other ships, only if there are only players
	if(this->fWorld->onlyPlayers()){
		this->createStage(this->fStages.front());
		this->fStages.pop_front();
	}

	// Let's move all the enemy ships
	fHAL->moveShips(delta);

	// Let's move all the bullets
	fHAL->moveBullets(delta);

	// Move the background
	this->fWorld->getTile()->move(Direction("Down"), delta);

	// Do collision detection of enemy ships with player
	fHAL->shipCollisionDetection();

	// Do collision detection of bullets
	fHAL->bulletCollisionDetection();

	// Check if we have dead Ships
	fHAL->checkForDeadShips();

	// Check if we have dead Ships
	fHAL->checkForDeadBullets();

	// Shoot bullets from enemy ships
	fHAL->shootBullets(false);
}


void Game::createStage(XMLStage const &stage){
	ShipFactory factory(this->fWorld);
	factory.buildStage(stage);
}

void Game::movePlayer(Direction direction, double const delta, int const playerID){
	// Check if we can move the players ship without getting out of bounds
	if(this->fWorld->collides(this->fWorld->getPlayers()->at(playerID)) == false){
		// Ship isn't in Game anymore
		return;
	}

	// Check if the player isn't going out of bounds
	Vector playerLocation = this->fWorld->getPlayers()->at(playerID)->getLocation();
	Size playerSize = this->fWorld->getPlayers()->at(playerID)->getSize();

	if(playerLocation.x < 0 and direction.isLeft()){
		return;
	}

	if((playerLocation.x + playerSize.width) > this->fWorld->getHeight() and direction.isRight()){
		return;
	}

	if((playerLocation.y - playerSize.height ) < 0 and direction.isDown()){
		return;
	}

	if(playerLocation.y + 10 > this->fWorld->getHeight() and direction.isUp()){
		return;
	}


	// Just move it
	this->fWorld->getPlayers()->at(playerID)->move(direction, delta);
}

void Game::shootPlayer(int const playerID){
	this->fWorld->getPlayers()->at(playerID)->shoot();
}

bool Game::won() const{
	return this->fWon;
}

bool Game::lose() const{
	return this->fLose;
}

bool Game::updateHighscores() const{
	Highscores scores;
	bool highscore = false;
	for(int i = 0; i < this->fWorld->getPlayers()->size();i++){
		if( scores.add(this->fWorld->getPlayers()->at(i)->getScore()) ){
			highscore = true;
		}
	}
	return highscore;
}

Tile* Game::getTile(){
	return this->fWorld->getTile();
}

Game::~Game() {
	delete this->fWorld;
	delete this->fHAL;
}

}
