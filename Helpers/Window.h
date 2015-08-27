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
#include "../Library/Lib/Config.h"
#include <iostream>

namespace tySFML {

/**
 * @brief Represents an SFML Window
 */
class Window {
public:
	/**
	 * @brief Generate a window with a creating height and with
	 */
	Window();

	/**
	 * @brief Clear the window
	 */
	void clear();

	/**
	 * @brief Draw an View
	 */
	void draw(sf::Shape &drawable);

	/**
	 * @brief Draw an View
	 */
	void draw(sf::Sprite &drawable);

	/**
	 * @brief Draw an View
	 */
	void draw(sf::Drawable &drawable);

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


	/**
	 * @brief Sets the background color of the Window
	 */
	void setBackGroundColor(sf::Color const color);

	/**
	 * @brief Get the pointer to the Window
	 */
	sf::RenderWindow* getWindow(){return this->fWindow;};

	virtual ~Window();
private:
	sf::RenderWindow* fWindow;
	int fHeight;
	int fWidth;
	sf::Color fBackGroundColor;
};

} /* namespace tySFML */

#endif /* HELPERS_WINDOW_H_ */
