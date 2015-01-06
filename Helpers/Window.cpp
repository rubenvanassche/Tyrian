/*
 * Window.cpp
 *
 *  Created on: 3-jan.-2015
 *      Author: Ruben
 */

#include "Window.h"

namespace tySFML {


Window::Window(int width, int height){
	this->fWindow = new sf::RenderWindow(sf::VideoMode(height, width), "Tyrian");
	//this->fWindow->setFramerateLimit(60);
	this->fWidth = width;
	this->fHeight = height;
}


void Window::clear(){
	this->fWindow->clear();
}

void Window::draw(sf::Shape &drawable){
	// change the y corrdinate because SFML is strange
	sf::Vector2f position = drawable.getPosition();
	position.y = this->fHeight - position.y;
	drawable.setPosition(position);
	this->fWindow->draw(drawable);
}

void Window::close(){
	this->fWindow->close();
}

bool Window::pollEvent (sf::Event &event){
	return this->fWindow->pollEvent(event);
}


bool Window::isOpen(){
	return this->fWindow->isOpen();
}

void Window::display(){
	this->fWindow->display();
}

Window::~Window() {
	// TODO Auto-generated destructor stub
}

} /* namespace tySFML */
