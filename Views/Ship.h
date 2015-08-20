/*
 * Ship.h
 *
 *  Created on: 27-dec.-2014
 *      Author: Ruben
 */

#ifndef VIEWS_SHIP_H_
#define VIEWS_SHIP_H_

#include "View.h"
#include "../Library/Models/Ship.h"

namespace tySFML {

class Ship : public View {
public:
	Ship(Window* window, tyLib::Ship* ship);

	void draw();

	bool is(tyLib::Ship* ship);
private:
	tyLib::Ship* fShip;
	int fTick = 0;
};

} /* namespace tySFML */

#endif /* VIEWS_SHIP_H_ */
