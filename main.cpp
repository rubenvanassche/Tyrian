#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Library/Controllers/Game.h"
#include "Views/Bullet.h"
#include "Views/Ship.h"


class SFMLBridge : public tyLib::Bridge{
public:
	virtual void createShip(tyLib::Ship* shipPtr){
		tySFML::Ship* ship = new tySFML::Ship(window, shipPtr);
		this->ships.push_back(ship);
	}
	virtual void createBullet(tyLib::Bullet* shipPtr){
		std::cout << "Added Bullet" << std::endl;
	}
	virtual void removeShip(tyLib::Ship* shipPtr){
		std::cout << "Removed Ship" << std::endl;
	}
	virtual void removeBullet(tyLib::Bullet* shipPtr){
		std::cout << "Removed Bullet" << std::endl;
	}

	std::list<tySFML::Ship*> ships;
	sf::RenderWindow* window;
};

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(320, 320), "SFML window");

    // Create the bridge between SFML and tyLib
    SFMLBridge* bridge = new SFMLBridge;
    bridge->window = &window;

    // Create the game
    tyLib::Game g("Library/Tests/Levels/level1.xml", bridge);

    tySFML::Bullet x(&window);

    while (window.isOpen())
    {
    	// Play once
    	g.play();

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();

        for(auto i : bridge->ships){
        	i->draw();
        }
       // window.draw();

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}

