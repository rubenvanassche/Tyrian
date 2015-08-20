/*
 * Players.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Players.h"

namespace tyLib{

Players::Players(int amount){
  Config* config = Config::getInstance();
}

bool Players::isPlayer(Ship* const ship) const{
  if(std::find(this->fPlayers.begin(), this->fPlayers.end(), ship) == this->fPlayers.end()){
    return false;
  }else{
    return true;
  }
}


Players::~Players() {
	// TODO Auto-generated destructor stub
}

}
