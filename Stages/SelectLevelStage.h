/*
 * SelectLevelStage.h
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#ifndef STAGES_SELECTLEVELSTAGE_H_
#define STAGES_SELECTLEVELSTAGE_H_

#include "../Helpers/Stage.h"
#include <iostream>
#include "../Helpers/Button.h"
#include "../Library/Lib/FileLoader.h"

namespace tySFML {


class SelectLevelStage : public Stage {
public:
	using Stage::Stage;
	virtual void run();
	virtual ~SelectLevelStage();
};

} /* namespace tySFML */

#endif /* STAGES_SELECTLEVELSTAGE_H_ */
