#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <list>
#include <string>
#include "../Lib/Point.h"
#include "../Lib/Size.h"
#include "../Lib/Direction.h"


namespace tyLib{

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
	Vector getLocation() const;

	/**
	 * @brief Get the Size of an Entity
	 */
	Size getSize() const;

	/**
	 * @brief Check if an Entity collides with this entity
	 */
	bool collides(Entity* entity);

	/**
	 * @brief Set the type of this Entity(used for bitmapping)
	 */
	virtual void setType(std::string type);

	/**
	 * @brief Get the type of this entity
	 */
	virtual std::string getType();

	/**
	 * @brief hide the Entity
	 */
	void hide();

	/**
	 * @brief show the Entity
	 */
	void show();

	/**
	 * @brief is the Entity visible
	 */
	bool isVisible();

	virtual ~Entity();
protected:
    Vector fPoint;
    Size fSize;
    std::string fType;
    bool fVisible = true;
};

}

#endif
