/*
 * MessageStage.h
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#ifndef STAGES_MESSAGESTAGE_H_
#define STAGES_MESSAGESTAGE_H_

#include "../Helpers/Stage.h"
#include "../Helpers/Button.h"
#include <iostream>

namespace tySFML {


class MessageStage : public Stage {
public:
	using Stage::Stage;
	virtual void run ();
	virtual ~MessageStage();
};

} /* namespace tySFML */

#endif /* STAGES_MESSAGESTAGE_H_ */
