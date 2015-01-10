/*
 * IntroStage.h
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#ifndef STAGES_INTROSTAGE_H_
#define STAGES_INTROSTAGE_H_

#include "../Helpers/Stage.h"
#include "../Helpers/Button.h"
#include <iostream>

namespace tySFML {

class IntroStage : public Stage {
public:
	using Stage::Stage;
	virtual void run ();
	virtual ~IntroStage();
};

} /* namespace tySFML */

#endif /* STAGES_INTROSTAGE_H_ */
