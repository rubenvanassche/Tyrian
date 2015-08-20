#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include "../Lib/Point.h"
#include "../Lib/Size.h"
#include "../Lib/Direction.h"
#include "../Lib/FileLoader.h"


namespace tyLib{

struct Texture{
	std::string filename;
	int ticks;
	Vector offset;
	Vector tickOffset;
};

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
	 * @brief Add an texture
	 */
	void addTexture(XMLTextureBlueprint const blueprint);

	/**
	 * @brief Move an Entity with a Direction, this function is pure virtual
	 */
	virtual void move(Direction const direction, double const delta)=0;

	/**
	 * @brief Get the location of an Entity
	 */
	Vector getLocation() const;

	/**
	 * @brief Get the Size of an Entity
	 */
	Size getSize() const;

	/**
	 * @brief Get the Texture of the Entity
	 */
	Texture getTexture() const;

	/**
	 * @brief Checks if an texture exists for the entity
	 */
	 bool isTextured() const;

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
	/**
	 * @brief How far does an Entity move in time
	 */
	Vector fVelocity;

	/**
	 * @brief Current location of the eEtity
	 */
    Vector fLocation;

	/**
	 * @brief Texture for the entity
	 */
    Texture fTexture;
		/**
		 * @brief Does the entity have an texture
		 */
		bool fTextured = false;

    Size fSize;
    std::string fType;
    bool fVisible = true;
};

}

#endif
