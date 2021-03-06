/*
 * Tile.cpp
 *
 *  Created on: 6-jan.-2015
 *      Author: Ruben
 */

#include "Tile.h"

namespace tyLib {

Tile::Tile(int width, int height, std::string tiletype) {
	this->fVelocity = Vector(1, 100);
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
	const int entitiesNeededWidth = (int)(this->fWidth/backgroundEntity->size.width);
	const int entitiesNeededHeight = (int)(this->fHeight/backgroundEntity->size.height + 1);

	for(int i = 0; i< entitiesNeededWidth;i++){
		for(int j = 0; j < entitiesNeededHeight;j++){
			Vector point;
			point.x = i*backgroundEntity->size.width;
			point.y = this->fHeight - backgroundEntity->size.height*j;

			te::Entity* newEntity = this->getBackgroundEntity();
			newEntity->location = point;

			this->fBackgroundEntities.push_back(newEntity);
		}
	}

	delete backgroundEntity;
}

void Tile::moveBackground(double const delta){
	te::Entity* backgroundEntity = this->getBackgroundEntity();

	// Do we need to add entities to the top and remove the ones at the bottom
	if(this->fMoved >= backgroundEntity->size.height){
		// How many entities we need to add?
		const int entitiesNeeded = (int)(this->fWidth/backgroundEntity->size.width);

		// Add some new
		for(int i = 0;i < entitiesNeeded;i++){
			// Calculate the position of this entity
			Vector point;
			point.x = i*backgroundEntity->size.width;
			point.y = this->fHeight + backgroundEntity->size.height;

			te::Entity* newEntity = this->getBackgroundEntity();
			newEntity->location = point;

			this->fBackgroundEntities.push_back(newEntity);
		}

		// When we've added these entites it means we will also need to remove some
		std::list<te::Entity*>::iterator it;
		for(int i = 0;i < entitiesNeeded;i++){
			it = this->fBackgroundEntities.begin();
			delete *it;
			this->fBackgroundEntities.pop_front();
		}

		// Now reset the moved
		this->fMoved = 0;
	}else{
		// Nope just move all the entities
		for(auto i : this->fBackgroundEntities){
			i->location.y = i->location.y - this->fVelocity.y*delta;
		}
	}

	delete backgroundEntity;
}

te::Entity* Tile::getBackgroundEntity(){
	te::Entity* out = nullptr;
	if(this->fTileType == "Grass"){
		 out = new te::Grass;
	}

	return out;
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

} /* namespace tyLib */
