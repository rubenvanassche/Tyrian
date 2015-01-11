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
#include <string>
#include "../Helpers/Button.h"
#include <SFML/Graphics.hpp>
#include "../Library/Controllers/Game.h"
#include "../Helpers/SFMLBridge.h"
#include "../Helpers/Stopwatch.h"
#include "../Helpers/Input.h"
#include "../Views/Tile.h"
#include <Lib/FileLoader.h>

namespace tySFML {


class GameStage : public Stage {
public:
	using Stage::Stage;
	/**
	 * @brief Set the name of the level we're going to play
	 */
	void setFileName(std::string fileName){this->fFileName  = fileName;};
	virtual void run();
	virtual ~GameStage();
private:
	std::string fFileName;
};

} /* namespace tySFML */

#endif /* STAGES_GAMESTAGE_H_ */
