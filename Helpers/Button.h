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

	std::string fText;
	sf::Font* fFont;
	sf::Color fTextColor;
};

} /* namespace tySFML */

#endif /* HELPERS_BUTTON_H_ */
