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


	virtual ~View();
protected:
	Window* fWindow;
	Assets* fAssets;
};

} /* namespace tySML */

#endif /* VIEWS_VIEW_H_ */
