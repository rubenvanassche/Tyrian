#include "Helpers/Window.h"
#include "Helpers/Input.h"
#include "Helpers/Assets.h"
#include "Helpers/StopWatch.h"
#include "Helpers/Stage.h"

#include "Stages/GameStage.h"
#include "Stages/IntroStage.h"
#include "Stages/SelectlevelStage.h"
#include "Stages/MessageStage.h"

int main(){
    // Create the main window
	tySFML::Window window(320, 320);

	// The path where the fonts are
	std::string fontsPath = "Resources/Fonts";

	// The path where the textures are
	std::string texturesPath = "Resources/Textures";

	// Create the Assets Container
	tySFML::Assets assets = tySFML::Assets(texturesPath, fontsPath);

	// Create the stagescontainer
	tySFML::Stages stages;

	// Create the stages and link them in the stages container
	tySFML::IntroStage introStage = tySFML::IntroStage(&window, &stages, &assets);
	stages.intro = &introStage;
	tySFML::GameStage gameStage = tySFML::GameStage(&window, &stages, &assets);
	stages.game = &gameStage;
	tySFML::SelectLevelStage selectLevelStage = tySFML::SelectLevelStage(&window, &stages, &assets);
	stages.selectLevel = &selectLevelStage;
	tySFML::MessageStage messagestage = tySFML::MessageStage(&window, &stages, &assets);
	stages.message = &messagestage;

	// Start by running our intro stage
	introStage.run();
}

/*
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Library/Controllers/Game.h"
#include "Views/Bullet.h"
#include "Views/Ship.h"
#include "Helpers/SFMLBridge.h"
#include "Helpers/Stopwatch.h"
#include "Helpers/Input.h"
#include "Helpers/Window.h"
#include "Library/Lib/FileLoader.h"

int main() {
    // Create the main window
	tySFML::Window window(320, 320);

    // Create the bridge between SFML and tyLib
    tySFML::SFMLBridge* bridge = new tySFML::SFMLBridge;
    bridge->window = &window;

    // Create the game
    tyLib::Game g("Library/Tests/Levels/level1.xml", bridge);

    // Get our stopwatch
    tySFML::Stopwatch *stopwatch;
    stopwatch = tySFML::Stopwatch::getInstance();

    // Get our input processor
    tySFML::Input *input;
    input = tySFML::Input::getInstance();

    sf::Clock clock;


    while (window.isOpen())
    {
    	stopwatch->update();


    	double delta = clock.restart().asSeconds();

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
        	input->executeEvent(event);
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();

        	if(input->spaceBar()){
        		g.shootPlayer();
        	}

        	if(input->keyLeft()){
        		tyLib::Direction d("left");
        		g.movePlayer(d, delta);
        	}

        	if(input->keyRight()){
        		tyLib::Direction d("right");
        		g.movePlayer(d, delta);
        	}

        	if(input->keyUp()){
        		tyLib::Direction d("up");
        		g.movePlayer(d, delta);
        	}

        	if(input->keyDown()){
        		tyLib::Direction d("down");
        		g.movePlayer(d, delta);
        	}

        }

		   g.play(delta);

		   //g.print();



    	//g.print();

        // Clear screen
        window.clear();

        for(auto i : bridge->ships){
        	i->draw();
        }

        for(auto i : bridge->bullets){
        	i->draw();
        }

        // Update the window
        window.display();

    }
    return EXIT_SUCCESS;
}
*/
