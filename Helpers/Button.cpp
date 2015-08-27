/*
 * Button.cpp
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#include "Button.h"

namespace tySFML {

Button::Button(sf::Vector2f const location, sf::Vector2f const size, sf::Color const backGroundColor){
	this->fLocation = location;
	this->fSize = size;
	this->fBackGroundColor = backGroundColor;

	this->fLineThickness = 0;
	this->flineColor = sf::Color::Black;

	this->fText = "Button";
	this->fFont = nullptr;
}

void Button::setLine(int const thickness, sf::Color const color){
	this->fLineThickness = thickness;
	this->flineColor = color;
}

void Button::setText(std::string const text, sf::Color const textcolor,  sf::Font* const font){
	this->fText = text;
	this->fFont = font;
	this->fTextColor = textcolor;
}

void Button::setPadding(int const padding){
	this->fPadding = padding;
}

bool Button::isButtonClicked(sf::Vector2i const point) const{
	if(this->fLocation.x <= point.x and (this->fLocation.x + this->fSize.x) >= point.x){
		if(this->fLocation.y <= point.y and (this->fLocation.y + this->fSize.y) >= point.y){
			return true;
		}
	}

	return false;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	if(this->fFont == nullptr){
		throw std::runtime_error("No font set");
	}

	// If we have an line we need to to some more work
	sf::Vector2f insideBoxLocation = this->fLocation;
	if(this->fLineThickness > 0){
		sf::Vector2f superBoxSize = this->fSize;
		superBoxSize.x += this->fLineThickness*2;
		superBoxSize.y += this->fLineThickness*2;

		sf::RectangleShape superBox(superBoxSize);
		superBox.setPosition(this->fLocation);
		superBox.setFillColor(this->flineColor);

		target.draw(superBox);

		// Change the location of the insidebox so it adapts to the line
		insideBoxLocation.x += this->fLineThickness;
		insideBoxLocation.y += this->fLineThickness;
	}

	// Draw the box
	sf::RectangleShape insideBox(this->fSize);
	insideBox.setPosition(insideBoxLocation);
	insideBox.setFillColor(this->fBackGroundColor);

	target.draw(insideBox);


	// Draw the text
	sf::Vector2f textLocation = insideBoxLocation;
	textLocation.x += this->fPadding;
	textLocation.y += this->fPadding;
	int textSize = this->fSize.y - (this->fPadding*2);

	sf::Text text;
	text.setFont(*this->fFont);
	text.setString(this->fText);
	text.setColor(this->fTextColor);
	text.setCharacterSize(textSize);
	text.setPosition(textLocation);

	target.draw(text);
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

} /* namespace tySFML */
