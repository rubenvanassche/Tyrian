/*
 * IntroStage.h
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#ifndef STAGES_HIGHSCORES_H_
#define STAGES_HIGHSCORES_H_

#include "../Helpers/Stage.h"
#include "../Helpers/Button.h"
#include <iostream>
#include <Tylib/Lib/Highscores.h>
#include <map>
#include <string>

namespace tySFML {


class HighscoresStage : public Stage {
public:
	using Stage::Stage;
	virtual void run ();
	virtual ~HighscoresStage();
};

} /* namespace tySFML */

#endif /* STAGES_INTROSTAGE_H_ */
