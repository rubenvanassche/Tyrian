/*
 * Players.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Players.h"

namespace tyLib{

Players::Players(int const amount, World* world){
  this->fWorld = world;

  // Setup players creation
  Config* config = Config::getInstance();
  std::vector<Vector> startpositions = config->getPlayers();
  ShipFactory factory(this->fWorld);
  FileLoader fileloader;

  // Create players
  if(amount - 1 > startpositions.size()){
    std::runtime_error("More ships then startpositions defined");
  }

  for(int i = 0; i < amount; i++){
    Ship* player = factory.buildShip(startpositions[i], fileloader.getShipBlueprints()[config->getPlayership()], true);
    this->fPlayers.push_back(player);
    this->fWorld->addShip(player);
  }
}

bool Players::isPlayer(Ship* const ship) const{
  if(std::find(this->fPlayers.begin(), this->fPlayers.end(), ship) != this->fPlayers.end()){
    return true;
  }else{
    return false;
  }

}

Ship* Players::at(int const i){
  return this->fPlayers.at(i);
}

Ship* Players::operator[](int const i){
  return this->fPlayers.at(i);
}

int Players::size() const{
  return this->fPlayers.size();
}


Players::~Players() {
  if(this->fPlayers.size() == 1){
    this->fWorld->bridge->removeShip(this->at(0));
  }else if(this->fPlayers.size() == 2){
    this->fWorld->bridge->removeShip(this->at(0));
    this->fWorld->bridge->removeShip(this->at(1));
  }else{

  }

}

}
