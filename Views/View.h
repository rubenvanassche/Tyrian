/*
 * View.h
 *
 *  Created on: 27-dec.-2014
 *      Author: Ruben
 */

#ifndef VIEWS_VIEW_H_
#define VIEWS_VIEW_H_

#include "../Library/Models/Entity.h"
#include "../Helpers/Helpers.h"
#include "../Helpers/Window.h"
#include "../Helpers/Assets.h"

namespace tySFML {

/**
 * @Brief Represents an object to be drown by SFML
 */
class View{
public:
	/**
	 * @brief Construct a View by giving an SFML RenderWindow
	 */
	View(Window* window);

	/**
	 * @brief Draws a sprite based upon
	 * @param file The file where the sprite is in
	 * @param location The location the entity is at
	 * @param size The size of the Entity
	 * @param offsetX the offset x needed in the file to find the sprite
	 * yparam offsetX the offset x needed in the file to find the sprite
	 */
	sf::Sprite drawSprite(const std::string& file, const tyLib::Vector&  location, const tyLib::Size& size, const int offsetX, const int offsetY);


	virtual ~View();
protected:
	Window* fWindow;
	Assets* fAssets;
};

} /* namespace tySML */

#endif /* VIEWS_VIEW_H_ */
