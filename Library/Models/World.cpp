/*
 * World.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "World.h"

namespace tyLib{

World::World(int width, int height, Bridge* bridge) {
	this->fPoint = Point(0, 0);
	this->fSize = Size(width, height);
	this->width = width;
	this->height = height;
	this->bridge = bridge;
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

Ship* World::getPlayer(){
	return this->player;
}

void World::setPlayer(Ship* player){
	this->player = player;
}

int World::getWidth(){
	return this->width;
}

int World::getHeight(){
	return this->height;
}

std::list<Ship*>& World::getShips(){
	return this->ships;
}

std::list<Bullet*>& World::getBullets(){
	return this->bullets;
}

void World::move(Direction const direction){

}

World::~World() {
	// TODO Auto-generated destructor stub
}

}
