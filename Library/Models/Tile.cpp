/*
 * Tile.cpp
 *
 *  Created on: 6-jan.-2015
 *      Author: Ruben
 */

#include "Tile.h"

namespace tyLib {

Tile::Tile(int width, int height, std::string tiletype) {
	this->fVelocity = Vector(0, 10);
	this->fTileType = tiletype;
	this->fWidth = width;
	this->fHeight = height;

	// Start building the background
	this->buildBackground();
}

void Tile::move(Direction const direction, double const delta){
	if(direction.isLeft() or direction.isRight()){
		throw std::runtime_error("A Tile can only move up and down");
	}

	// Update the rol to see how far we're in the tile
	this->fMoved += delta*this->fVelocity.y;

	// Move the Entities on the map
	this->moveEntities(delta);

	// Move the background
	this->moveBackground(delta);

}

std::list<te::Entity*>* Tile::getEntities(){
	return &this->fEntities;
}

std::list<te::Entity*>* Tile::getBackground(){
	return &this->fBackgroundEntities;
}

void Tile::moveEntities(double const delta){
	for(auto i: this->fEntities){
		i->location = i->location+(fVelocity*delta);
	}
}

void Tile::addEntities(double const delta){
	/*if(this->fEntities.size() > 2){
		// We don't want more then two entities on the map
		return;
	}*/
}

void Tile::buildBackground(){
	te::Entity* backgroundEntity = this->getBackgroundEntity();
	const int entitiesNeededWidth = (int)(this->fWidth/backgroundEntity->size.width + 1);
	const int entitiesNeededHeight = (int)(this->fHeight/backgroundEntity->size.height + 1);

	for(int i = 0; i< entitiesNeededWidth;i++){
		for(int j = 0; j < entitiesNeededHeight;j++){
			Vector point;
			point.x = i*backgroundEntity->size.width;
			point.y = this->fHeight - backgroundEntity->size.height*j;

			te::Entity* newEntity = this->getBackgroundEntity();
			newEntity->location = point;

			this->fBackgroundEntities.push_back(newEntity);

			std::cout << "Added by build" << std::endl;
		}
	}

	delete backgroundEntity;
}

void Tile::moveBackground(double const delta){
	te::Entity* backgroundEntity = this->getBackgroundEntity();

	// Do we need to add entities to the top and remove the ones at the bottom
	if(this->fMoved >= backgroundEntity->size.height){
		// How many entities we need to add?
		const int entitiesNeeded = (int)(this->fWidth/backgroundEntity->size.width + 1);

		// Add some new
		for(int i = 0;i < entitiesNeeded;i++){
			// Calculate the position of this entity
			Vector point;
			point.x = i*backgroundEntity->size.width;
			point.y = this->fHeight + backgroundEntity->size.height;

			te::Entity* newEntity = this->getBackgroundEntity();
			newEntity->location = point;

			this->fBackgroundEntities.push_back(newEntity);

			std::cout << "Added by move" << std::endl;
		}

		// When we've added these entites it means we will also need to remove some
		std::list<te::Entity*>::iterator it;
		for(int i = 0;i < entitiesNeeded;i++){
			it = this->fBackgroundEntities.begin();
			delete *it;
			this->fBackgroundEntities.pop_front();

			std::cout << "deleted by move" << std::endl;
		}
	}else{
		// Nope just move all the entities
		for(auto i : this->fBackgroundEntities){
			i->location = i->location - this->fVelocity*delta;
		}
	}

	delete backgroundEntity;
}

te::Entity* Tile::getBackgroundEntity(){
	te::Entity* out;
	if(this->fTileType == "Grass"){
		 out = new te::Grass;
	}

	return out;
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

} /* namespace tyLib */
