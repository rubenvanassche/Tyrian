#include "Entity.h"

Entity::Entity() {
	// TODO Auto-generated constructor stub

}

Point Entity::getLocation() const{
	return this->fPoint;
}

Size Entity::getSize() const{
	return this->fSize;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}
