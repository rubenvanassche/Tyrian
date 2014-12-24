/*
 * World.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "World.h"

World::World(int width, int height) {
	this->fPoint = Point(0, 0);
	this->fSize = Size(width, height);
	this->width = width;
	this->height = height;
}

void World::move(Direction const direction){

}

World::~World() {
	// TODO Auto-generated destructor stub
}

