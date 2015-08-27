/*
 * World.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "World.h"

namespace tyLib{

World::World(int width, int height, Bridge* bridge) {
	this->fLocation = Vector(0, 0);
	this->fSize = Size(width, height);
	this->width = width;
	this->height = height;
	this->bridge = bridge;

	// Initiate the tile
	this->tile = new Tile(width, height, "Grass");
}

void World::addShip(Ship* ship){
	this->ships.push_back(ship);
	this->bridge->createShip(ship);
}

void World::addBullet(Bullet* bullet){
	this->bullets.push_back(bullet);
	this->bridge->createBullet(bullet);
}

void World::removeShip(Ship* ship){

}

void World::removeBullet(Bullet* bullet){

}

/*
Ship* World::getPlayer(){
	return this->player;
}

void World::setPlayer(Ship* player){
	this->player = player;
}
*/

void World::setPlayers(Players* players){
	this->players = players;
}

bool World::onlyPlayers() const{


	for(auto ship : this->ships){
		if(this->players->isPlayer(ship)){
			continue;
		}else{
			return false;
		}
	}

	return true;
}

Players* World::getPlayers(){
	return this->players;
}

int World::getWidth() const{
	return this->width;
}

int World::getHeight() const{
	return this->height;
}

std::list<Ship*>& World::getShips(){
	return this->ships;
}

std::list<Bullet*>& World::getBullets(){
	return this->bullets;
}

Tile* World::getTile(){
	return this->tile;
}


World::~World() {
		delete this->players;
		delete this->tile;
}

}
