/*
 * HAL9000.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "HAL9000.h"

HAL9000::HAL9000(World* world) {
	this->fWorld = world;
}

std::string HAL9000::openThePodBayDoors() const{
	return "I'm sorry, Dave. I'm afraid I can't do that.";
}

void HAL9000::move(std::list<Ship*>& ships){
	std::list<Ship*>::iterator it = ships.begin();
	while(it != ships.end()){
		// If the ship we want to move is the player's ship, we don't do anything
		if(*it == this->fWorld->player){
			it++;
		}

		// Move it down
		// TODO find some better algorithm
		Direction direction("down");
		(*it)->move(direction);

		// Check if the ship is out of the world
		if(this->fWorld->collides(*it) == false){
			// yes it is, remove it
			ships.erase(it++);
		}

		// Becouse we remove some ships from the list we need to check if we haven't reached the end of the list otherwise we might use memory that isn't ours
		if(it != ships.end()){
			it++;
		}
	}
}

HAL9000::~HAL9000() {
	// TODO Auto-generated destructor stub
}

