#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include "../Lib/Point.h"
#include "../Lib/Size.h"

class Entity{
public:
	Entity();
	virtual void move()=0;
	virtual ~Entity();
private:
    Point fPoint;
    Size fSize;
};

#endif;
