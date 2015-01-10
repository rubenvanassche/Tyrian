/*
 * Stage.cpp
 *
 *  Created on: 4-jan.-2015
 *      Author: Ruben
 */

#include "Stage.h"

namespace tySFML {

Stage::Stage(Window* app, Stages* stages, Assets* assets) {
	this->fApp = app;
	this->fStages = stages;
	this->fAssets = assets;
}

Stage::~Stage() {
	// TODO Auto-generated destructor stub
}

} /* namespace tySFML */
