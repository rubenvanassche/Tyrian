#include "Entity.h"

Entity::Entity() {
	this->fPoint = Point(0,0);

}

Point Entity::getLocation() const{
	return this->fPoint;
}

Size Entity::getSize() const{
	return this->fSize;
}

bool Entity::collides(Entity* entity){
	// Get the bounds from the given entity
	Point upleft(entity->fPoint.x, entity->fPoint.y);
	Point upright(entity->fPoint.x + entity->fSize.width, entity->fPoint.y);
	Point downleft(entity->fPoint.x, entity->fPoint.y + entity->fSize.height);
	Point downright(entity->fPoint.x + entity->fSize.width, entity->fPoint.y + entity->fSize.height);
	std::list<Point> points{upleft, upright, downleft, downright};


	// Check if the points lie in me
	for(auto i : points){
		if(i.x >= this->fPoint.x and i.x <= (this->fPoint.x + this->fSize.width)){
			if(i.y >= this->fPoint.y and i.y <= (this->fPoint.y + this->fSize.height)){
				// Seems like this points lies in me
				return true;
			}
		}
	}

	// If none of these points lies in me so nope
	return false;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}
