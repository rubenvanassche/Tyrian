/*
 * Stage.h
 *
 *  Created on: 4-jan.-2015
 *      Author: Ruben
 */

#ifndef STAGES_STAGE_H_
#define STAGES_STAGE_H_

#include "Window.h"
#include "Assets.h"

namespace tySFML {

struct Stages;

/**
 * @brief Represents a Stage, a certain part of the game
 */
class Stage {
public:
	Stage(Window* app, Stages* stages);
	virtual void run ()=0;
	void setMessage(std::string message){this->fMessage  = message;};
	std::string getMessage(){return this->fMessage;};
	virtual ~Stage();
protected:
	Stages* fStages = nullptr;
	Window* fApp = nullptr;
	Assets* fAssets = nullptr;
	std::string fMessage;
};

struct Stages{
	Stage* intro;
	Stage* game;
	Stage* selectLevel;
	Stage* message;
};


} /* namespace tySFML */

#endif /* STAGES_STAGE_H_ */
