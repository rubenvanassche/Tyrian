#include "Helpers/Window.h"
#include "Helpers/Input.h"
#include "Helpers/Assets.h"
#include "Helpers/Stopwatch.h"
#include "Helpers/Stage.h"

#include "Stages/GameStage.h"
#include "Stages/IntroStage.h"
#include "Stages/SelectLevelStage.h"
#include "Stages/MessageStage.h"
#include "Stages/HighscoresStage.h"

int main(){
    // Create the main window
	tySFML::Window window;

	// The config for assets paths
	tyLib::Config *config = tyLib::Config::getInstance();

	// Create the Assets Container
	tySFML::Assets *assets = tySFML::Assets::getInstance();
	assets->setFontPath(config->getFontsPath());
	assets->setTexturesPath(config->getTexturesPath());

	// Create the stagescontainer
	tySFML::Stages stages;

	// Create the stages and link them in the stages container
	tySFML::IntroStage introStage = tySFML::IntroStage(&window, &stages);
	stages.intro = &introStage;
	tySFML::GameStage gameStage = tySFML::GameStage(&window, &stages);
	stages.game = &gameStage;
	tySFML::SelectLevelStage selectLevelStage = tySFML::SelectLevelStage(&window, &stages);
	stages.selectLevel = &selectLevelStage;
	tySFML::MessageStage messagestage = tySFML::MessageStage(&window, &stages);
	stages.message = &messagestage;
	tySFML::HighscoresStage highscoresStage = tySFML::HighscoresStage(&window, &stages);
	stages.highscores = &highscoresStage;

	// Start by running our intro stage
	introStage.run();

	// End of all things
	delete config;
	delete assets;
}
