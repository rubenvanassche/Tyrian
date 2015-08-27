/*
 * TileEntityTypes.h
 *
 *  Created on: 11-jan.-2015
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_TILEENTITYTYPES_HPP_
#define LIBRARY_MODELS_TILEENTITYTYPES_HPP_

#include "../Lib/Point.h"
#include "../Lib/Size.h"
#include <string>

namespace tyLib{
namespace te{

class Entity{
public:
	// Size of the Entity
	Size size;
	// location of the Entity
	Vector location;
	// name of the Entity
	std::string name;
	// Kind of environment the entity is found in
	std::string environmenttype;
};

// For Dirt Environments
class Dirt : public Entity{
public:
	Dirt(){
		this->size = Size(24,33);
		this->name = "Dirt";
		this->environmenttype = "Dirt";
	}
};

class Temple : public Dirt{
public:
	Temple(){
		this->size = Size(45,56);
		this->name = "Temple";
	};
};

class Stonehenge : public Dirt{
public:
	Stonehenge(){
		this->size = Size(48,56);
		this->name = "Stonehenge";
	};
};

class RockyMountains : public Dirt{
public:
	RockyMountains(){
		this->size = Size(51,56);
		this->name = "RockyMountains";
	};
};

class PalmTrees : public Dirt{
public:
	PalmTrees(){
		this->size = Size(49,28);
		this->name = "PalmTrees";
	};
};

class Oase : public Dirt{
public:
	Oase(){
		this->size = Size(72,56);
		this->name = "Oase";
	};
};

// For Grass Environments
class Grass : public Entity{
public:
	Grass(){
		this->size = Size(160,160);
		this->name = "Grass";
		this->environmenttype = "Grass";
	}
};

class Mud : public Entity{
public:
	Mud(){
		this->size = Size(72,84);
		this->name = "Mud";
	};
};

}
}

#endif /* LIBRARY_MODELS_TILEENTITYTYPES_HPP_ */
