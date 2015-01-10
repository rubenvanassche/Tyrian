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
	Stage(Window* app, Stages* stages, Assets* assets);
	virtual void run ()=0;
	virtual ~Stage();
protected:
	Stages* fStages = nullptr;
	Assets* fAssets = nullptr;
	Window* fApp = nullptr;
};

/**
 * @brief Structure representing all the Stages
 */
struct Stages{
	Stage* intro;
	Stage* game;
	Stage* selectLevel;
};

} /* namespace tySFML */

#endif /* STAGES_STAGE_H_ */
