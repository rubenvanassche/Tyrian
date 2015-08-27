/*
 * Direction.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */
#include "Direction.h"

namespace tyLib{

Direction::Direction(std::string direction) {
    // Set the string to lower characters
    std::transform(direction.begin(), direction.end(), direction.begin(), ::tolower);

    if(direction == "left" || direction == "right" || direction == "up" || direction == "down"){
        this->fDirection = direction;
    }else{
        throw std::runtime_error("Not a valid direction!");
    }
}

bool Direction::isLeft() const {
    if(this->fDirection == "left"){
        return true;
    }else{
        return false;
    }
}

bool Direction::isRight() const {
    if(this->fDirection == "right"){
        return true;
    }else{
        return false;
    }
}

bool Direction::isUp() const {
    if(this->fDirection == "up"){
        return true;
    }else{
        return false;
    }
}

bool Direction::isDown() const {
    if(this->fDirection == "down"){
        return true;
    }else{
        return false;
    }
}

std::string Direction::getDirection() const {
    return this->fDirection;
}


Direction::~Direction() {
	// TODO Auto-generated destructor stub
}

}
