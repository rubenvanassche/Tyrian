/*
 * IntroStage.cpp
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#include "IntroStage.h"

namespace tySFML {


void IntroStage::run (){
	sf::Font* font = this->fAssets->getFont("stark.otf");
	Button button(sf::Vector2f(10,10), sf::Vector2f(200, 50), sf::Color::Blue);
	button.setText("Hallo",sf::Color::Red,  font);
	button.setLine(2, sf::Color::Yellow);

	while(this->fApp->isOpen()){
		std::cout << "Hoera" << std::endl;

		this->fApp->clear();
		this->fApp->draw(button);
		this->fApp->display();
	}
}

IntroStage::~IntroStage() {
	// TODO Auto-generated destructor stub
}

} /* namespace tySFML */
