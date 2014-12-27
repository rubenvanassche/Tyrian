/*
 * View.h
 *
 *  Created on: 27-dec.-2014
 *      Author: Ruben
 */

#ifndef VIEWS_VIEW_H_
#define VIEWS_VIEW_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../Library/Models/Entity.h"
#include "../Helpers/Helpers.h"

namespace tySFML {

/**
 * @Brief Represents an object to be drown by SFML
 */
class View {
public:
	/**
	 * @brief Construct a View by giving an SFML RenderWindow
	 */
	View(sf::RenderWindow* window);


	virtual ~View();
protected:
	sf::RenderWindow* fWindow;
};

} /* namespace tySML */

#endif /* VIEWS_VIEW_H_ */
