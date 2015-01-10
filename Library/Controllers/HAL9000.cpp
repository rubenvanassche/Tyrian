/*
 * HAL9000.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "HAL9000.h"

namespace tyLib{

HAL9000::HAL9000(World* world) {
	this->fWorld = world;
}

std::string HAL9000::openThePodBayDoors() const{
	return "I'm sorry, Dave. I'm afraid I can't do that.";
}

void HAL9000::moveShips(double const delta){
	std::list<Ship*> &ships = this->fWorld->getShips();
	std::list<Ship*>::iterator it = ships.begin();
	while(it != ships.end()){
		// If the ship we want to move is the player's ship, we don't do anything
		if(*it == this->fWorld->getPlayer()){
			it++;
		}

		// Move it down
		// TODO find some better algorithm
		Direction direction("down");
		(*it)->move(direction, delta);

		// Check if the ship is out of the world
		if(this->fWorld->collides(*it) == false){
			// hide it because it's dead
			(*it)->hide();

			// Ok, it is out check if there are any bullets of the ship still flying because of Bullet pointers to ships we can't remove a ship before all bullets are removed
			bool wait = false;
			for(auto bullet : this->fWorld->getBullets()){
				if(bullet->getFrom() == *it){
					wait = true;
					break;
				}
			}

			if(wait == false){
				// First send a message to the Bridge
				this->fWorld->bridge->removeShip(*it);
				// Now remove it
				ships.erase(it++);
			}
		}

		// Becouse we remove some ships from the list we need to check if we haven't reached the end of the list otherwise we might use memory that isn't ours
		if(it != ships.end()){
			it++;
		}
	}
}

void HAL9000::moveBullets(double const delta){
	std::list<Bullet*> &bullets = this->fWorld->getBullets();
	std::list<Bullet*>::iterator it = bullets.begin();
	while(it != bullets.end()){
		// Move it down when enemy and move up when player
		// TODO find some better algorithm
		if((*it)->getFrom() == this->fWorld->getPlayer()){
			Direction direction("up");
			(*it)->move(direction, delta);
		}else{
			Direction direction("down");
			(*it)->move(direction, delta);
		}


		// Check if the bullet is out of the world
		if(this->fWorld->collides(*it) == false){
				// First send a message to the Bridge
				this->fWorld->bridge->removeBullet(*it);
				// Now remove it
				bullets.erase(it++);
		}

		// Becouse we remove some bullets from the list we need to check if we haven't reached the end of the list otherwise we might use memory that isn't ours
		if(it != bullets.end()){
			it++;
		}
	}
}

void HAL9000::shipCollisionDetection(){
	for(auto i : this->fWorld->getShips()){
		if(i == this->fWorld->getPlayer()){
			// I'm Sorry bit the player can't hit enemies, life isn't fair
			continue;
		}

		if(i->collides(this->fWorld->getPlayer())){
			this->fWorld->getPlayer()->reduceHealth(1);
		}
	}
}

void HAL9000::bulletCollisionDetection(){
	for(auto bullet : this->fWorld->getBullets()){
		for(auto ship : this->fWorld->getShips()){
			// first of all if a bullet collides with the ship it's shot go to the next ship
			if(bullet->getFrom() == ship){
				continue;
			}

			// Check collision
			if(ship->collides(bullet) == true){
				// if an enemy hits another enemy, do nothing
				if(bullet->getFrom() != this->fWorld->getPlayer() and ship != this->fWorld->getPlayer()){
					continue;
				}

				// otherwise reduce the ships score
				bullet->explode(ship);
			}
		}
	}
}

void HAL9000::checkForDeadShips(){
	std::list<Ship*> &ships = this->fWorld->getShips();
	std::list<Ship*>::iterator it = ships.begin();
	while(it != ships.end()){
		// Check if the ship is dead
		if((*it)->isDead()){
			// hide it because it's dead
			(*it)->hide();

			// check if there are any bullets of the ship still flying because of Bullet pointers to ships we can't remove a ship before all bullets are removed
			bool wait = false;
			for(auto bullet : this->fWorld->getBullets()){
				if(bullet->getFrom() == *it){
					wait = true;
					break;
				}
			}

			if(wait == false){
				// First send a message to the Bridge
				this->fWorld->bridge->removeShip(*it);
				// Now remove it
				ships.erase(it++);
			}
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

}
