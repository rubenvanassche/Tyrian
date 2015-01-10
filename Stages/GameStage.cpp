/*
 * GameStage.cpp
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#include "GameStage.h"

namespace tySFML {

void GameStage::run (){
	while(this->fApp->isOpen()){
		std::cout << "Hoera" << std::endl;
	}
}

GameStage::~GameStage() {
	// TODO Auto-generated destructor stub
}

} /* namespace tySFML */
