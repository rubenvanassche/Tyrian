/*
 * Stage.cpp
 *
 *  Created on: 4-jan.-2015
 *      Author: Ruben
 */

#include "Stage.h"

namespace tySFML {

Stage::Stage(Window* app, Stages* stages) {
	this->fApp = app;
	this->fStages = stages;
	this->fAssets = Assets::getInstance();
}

Stage::~Stage() {
	// TODO Auto-generated destructor stub
}

} /* namespace tySFML */
