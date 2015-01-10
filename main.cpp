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

    	std::cout << delta << std::endl;

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

