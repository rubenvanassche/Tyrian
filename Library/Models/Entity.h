#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <list>
#include "../Lib/Point.h"
#include "../Lib/Size.h"
#include "../Lib/Direction.h"

/**
 * @brief Model representing an Entity, something that moves on the battle field
 */
class Entity{
public:
	/**
	 * @brief Construct an Entity
	 */
	Entity();

	/**
	 * @brief Move an Entity with a Direction, this function is pure virtual
	 */
	virtual void move(Direction const direction)=0;

	/**
	 * @brief Get the location of an Entity
	 */
	Point getLocation() const;

	/**
	 * @brief Get the Size of an Entity
	 */
	Size getSize() const;

	/**
	 * @brief Check if an Entity collides with this entity
	 */
	bool collides(Entity* entity);

	virtual ~Entity();
protected:
    Point fPoint;
    Size fSize;
};

#endif
