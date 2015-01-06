/*
 * Tile.cpp
 *
 *  Created on: 6-jan.-2015
 *      Author: Ruben
 */

#include "Tile.h"

namespace tyLib {

Tile::Tile() {
	// TODO Auto-generated constructor stub

}

void Tile::move(Direction const direction){
	if(direction.isLeft() or direction.isRight()){
		throw std::runtime_error("A Tile can only move up and down");
	}
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

} /* namespace tyLib */
