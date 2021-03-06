/*
 * Window.cpp
 *
 *  Created on: 3-jan.-2015
 *      Author: Ruben
 */

#include "Window.h"

namespace tySFML {


Window::Window(){
	tyLib::Config *config = tyLib::Config::getInstance();

	this->fWindow = new sf::RenderWindow(sf::VideoMode(config->getHeight(), config->getWidth()),config->getName());
	this->fWindow->setFramerateLimit(config->getFrameratelimit());
	this->fWidth = config->getWidth();
	this->fHeight = config->getHeight();
	this->fBackGroundColor = sf::Color::Black;

	std::cout << config->getHeight() << config->getHeight() << config->getName() << config->getFrameratelimit() << std::endl;
}


void Window::clear(){
	this->fWindow->clear(this->fBackGroundColor);
}

void Window::draw(sf::Shape &drawable){
	// change the y corrdinate because SFML is strange
	sf::Vector2f position = drawable.getPosition();
	position.y = this->fHeight - position.y;
	drawable.setPosition(position);
	this->fWindow->draw(drawable);
}

void Window::draw(sf::Sprite &drawable){
	// change the y corrdinate because SFML is strange
	sf::Vector2f position = drawable.getPosition();
	position.y = this->fHeight - position.y;
	drawable.setPosition(position);
	this->fWindow->draw(drawable);
}

void Window::draw(sf::Drawable &drawable){
	this->fWindow->draw(drawable);
}

void Window::close(){
	this->fWindow->close();
}

bool Window::pollEvent (sf::Event &event){
	return this->fWindow->pollEvent(event);
}


bool Window::isOpen() const{
	return this->fWindow->isOpen();
}

void Window::display(){
	this->fWindow->display();
}

void Window::setBackGroundColor(sf::Color const color){
	this->fBackGroundColor = color;
}

Window::~Window() {
	// TODO Auto-generated destructor stub
}

} /* namespace tySFML */
