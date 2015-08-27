/*
 * Button.h
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#ifndef HELPERS_BUTTON_H_
#define HELPERS_BUTTON_H_

#include <SFML/Graphics/Drawable.hpp>
#include <stdexcept>
#include <iostream>
#include "Assets.h"

namespace tySFML {

/**
 * @brief A button which can be drawn directly by SFML
 */
class Button : public sf::Drawable {
public:
	/**
	 * @brief Create a button with a certain location size and background color
	 */
	Button(sf::Vector2f location, sf::Vector2f size, sf::Color backGroundColor);

	/**
	 * @brief Add a line surrounding the button with a certain thickness and color
	 */
	void setLine(int thickness, sf::Color color);

	/**
	 * @brief Set the text for the button
	 */
	void setText(std::string text, sf::Color textcolor, sf::Font* font);


	/**
	 * @brief Change the padding in the Button(normal: 2)
	 */
	void setPadding(int padding);

	/**
	 * @brief Check if a certain point lies in the button to check if it has been clicked
	 */
	bool isButtonClicked(sf::Vector2i point);

	/**
	 * @brief Enable SFML to draw this immediately
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual ~Button();
private:
	sf::Vector2f fLocation;
	sf::Vector2f fSize;

	int fLineThickness;
	sf::Color flineColor;

	sf::Color fBackGroundColor;

	int fPadding = 2;

	std::string fText;
	sf::Font* fFont;
	sf::Color fTextColor;
};

} /* namespace tySFML */

#endif /* HELPERS_BUTTON_H_ */
