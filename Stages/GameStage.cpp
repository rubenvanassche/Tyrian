/*
 * GameStage.cpp
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#include "GameStage.h"

namespace tySFML {

void GameStage::run(){
	std::cout << this->fMessage << std::endl;

    // Create the bridge between SFML and tyLib
    tySFML::SFMLBridge* bridge = new tySFML::SFMLBridge;
    bridge->window = this->fApp;

    // Create the game
    tyLib::Game g(this->fMessage, bridge);

    // Get the background
    tySFML::Tile bg = Tile(this->fApp, g.getTile());

    // Create an assets library
    tySFML::Assets *assets = tySFML::Assets::getInstance();

    // Get our stopwatch
    tySFML::Stopwatch *stopwatch;
    stopwatch = tySFML::Stopwatch::getInstance();
    stopwatch->reset();

    // Get our input processor
    tySFML::Input *input;
    input = tySFML::Input::getInstance();

    sf::Clock clock;

	// Set the color of the Window
	this->fApp->setBackGroundColor(sf::Color::Black);

	while(this->fApp->isOpen()){
		// Update the stopwatch so all our entities run equal on each device.
    	stopwatch->update();

    	if(g.won() == true){
    		this->fStages->message->setMessage("You Win!");
    		this->fStages->message->run();
    	}

    	if(g.lose() == true){
    		this->fStages->message->setMessage("You Lose!");
    		this->fStages->message->run();
    	}

        // Process events
        sf::Event event;
        while (this->fApp->pollEvent(event)){
        	// Give the event to our input handler
        	input->executeEvent(event);

            // Close window : exit
            if (event.type == sf::Event::Closed)
            	this->fApp->close();

        	if(input->spaceBar()){
        		g.shootPlayer();
        	}

        	if(input->keyLeft()){
        		tyLib::Direction d("left");
        		g.movePlayer(d, stopwatch->getDelta());
        	}

        	if(input->keyRight()){
        		tyLib::Direction d("right");
        		g.movePlayer(d, stopwatch->getDelta());
        	}

        	if(input->keyUp()){
        		tyLib::Direction d("up");
        		g.movePlayer(d, stopwatch->getDelta());
        	}

        	if(input->keyDown()){
        		tyLib::Direction d("down");
        		g.movePlayer(d, stopwatch->getDelta());
        	}
        }

        // Play one iteration of the game.
        g.play(stopwatch->getDelta());


        // Clear screen
		this->fApp->clear();

		bg.draw();

        for(auto i : bridge->ships){
        	i->draw();
        }

        for(auto i : bridge->bullets){
        	i->draw();
        }


        // Update the window
        this->fApp->display();
	}
}

GameStage::~GameStage() {
	// TODO Auto-generated destructor stub
}

} /* namespace tySFML */
