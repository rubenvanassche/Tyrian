/*
 * Window.h
 *
 *  Created on: 3-jan.-2015
 *      Author: Ruben
 */

#ifndef HELPERS_WINDOW_H_
#define HELPERS_WINDOW_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace tySFML {

/**
 * @brief Represents an SFML Window
 */
class Window {
public:
	/**
	 * @brief Generate a window with a creating height and with
	 */
	Window(int width, int height);

	/**
	 * @brief Clear the window
	 */
	void clear();

	/**
	 * @brief Draw an View
	 */
	void draw(sf::Shape &drawable);

	/**
	 * @brief Close the Window
	 */
	void close();

	/**
	 * @brief Returns true if an Event has happened
	 */
	bool pollEvent (sf::Event &event);

	/**
	 * @brief Returns true if the Window is open
	 */
	bool isOpen();

	/**
	 * @brief Display the window
	 */
	void display();

	virtual ~Window();
private:
	sf::RenderWindow* fWindow;
	int fHeight;
	int fWidth;

};

} /* namespace tySFML */

#endif /* HELPERS_WINDOW_H_ */
