#include "Entity.h"

namespace tyLib{

Entity::Entity() {
	this->fLocation = Vector(0,0);
	this->fVelocity = Vector(1,1);
}

void Entity::addTexture(XMLTextureBlueprint const blueprint){
	this->fTexture.filename = blueprint.filename;
	this->fTexture.ticks = blueprint.ticks;
	this->fTexture.offset = blueprint.offset;
	this->fTexture.tickOffset = blueprint.tickOffset;
	this->fTextured = true;
}

Vector Entity::getLocation() const{
	return this->fLocation;
}

Size Entity::getSize() const{
	return this->fSize;
}

bool Entity::collides(Entity* entity){
	// Get the bounds from the given entity
	Vector upleft(entity->fLocation.x, entity->fLocation.y);
	Vector upright(entity->fLocation.x + entity->fSize.width, entity->fLocation.y);
	Vector downleft(entity->fLocation.x, entity->fLocation.y + entity->fSize.height);
	Vector downright(entity->fLocation.x + entity->fSize.width, entity->fLocation.y + entity->fSize.height);
	std::list<Vector> points{upleft, upright, downleft, downright};


	// Check if the points lie in me
	for(auto i : points){
		if(i.x >= this->fLocation.x and i.x <= (this->fLocation.x + this->fSize.width)){
			if(i.y >= this->fLocation.y and i.y <= (this->fLocation.y + this->fSize.height)){
				// Seems like this points lies in me
				return true;
			}
		}
	}

	// If none of these points lies in me so nope
	return false;
}

void Entity::setType(std::string type){
	this->fType = type;
}

::std::string Entity::getType(){
	return this->fType;
}

Texture Entity::getTexture() const{
	if(this->fTextured == false){
		std::runtime_error("No texture set");
	}

	return this->fTexture;
}

bool Entity::isTextured() const{
	return this->fTextured;
}

void Entity::hide(){
	this->fVisible = false;
}

void Entity::show(){
	this->fVisible = true;
}

bool Entity::isVisible(){
	return this->fVisible;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

}
