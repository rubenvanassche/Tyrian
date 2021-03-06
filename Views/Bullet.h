/*
 * Bullet.h
 *
 *  Created on: 27-dec.-2014
 *      Author: Ruben
 */

#ifndef VIEWS_BULLET_H_
#define VIEWS_BULLET_H_

#include "View.h"
#include "../Library/Models/Bullet.h"

namespace tySFML {

class Bullet : public View {
public:
	Bullet(Window* window, tyLib::Bullet* const ship);

	void draw();

	bool is(tyLib::Bullet* const ship) const;
private:
	tyLib::Bullet* fBullet;
};

} /* namespace tySFML */

#endif /* VIEWS_BULLET_H_ */
