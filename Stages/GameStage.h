/*
 * GameStage.h
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#ifndef STAGES_GAMESTAGE_H_
#define STAGES_GAMESTAGE_H_

#include "../Helpers/Stage.h"
#include <iostream>

namespace tySFML {

class GameStage : public Stage {
public:
	using Stage::Stage;
	virtual void run ();
	virtual ~GameStage();
};

} /* namespace tySFML */

#endif /* STAGES_GAMESTAGE_H_ */
