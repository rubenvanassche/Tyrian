#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(100, 250, 50));

    while (window.isOpen())
    {

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

        window.draw(shape);

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}