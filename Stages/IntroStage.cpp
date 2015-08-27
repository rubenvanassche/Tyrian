/*
 * IntroStage.cpp
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#include "IntroStage.h"

namespace tySFML {


void IntroStage::run(){
	sf::Font* font = this->fAssets->getFont("stark.otf");

	Button singleplayer(sf::Vector2f(105,150), sf::Vector2f(106, 30), sf::Color(0,140,158));
	singleplayer.setText("Singleplayer",sf::Color(52,56,56),  font);
	singleplayer.setLine(1, sf::Color(249,212,35));
	singleplayer.setPadding(7);

	Button multiplayer(sf::Vector2f(109,200), sf::Vector2f(98, 30), sf::Color(0,140,158));
	multiplayer.setText("Multiplayer",sf::Color(52,56,56),  font);
	multiplayer.setLine(1, sf::Color(249,212,35));
	multiplayer.setPadding(7);

	Button highscores(sf::Vector2f(110,250), sf::Vector2f(96, 30), sf::Color(0,140,158));
	highscores.setText("HighScores",sf::Color(52,56,56),  font);
	highscores.setLine(1, sf::Color(249,212,35));
	highscores.setPadding(7);

	sf::Text text;
	text.setFont(*font);
	text.setString("Tyrian");
	text.setColor(sf::Color::White);
	text.setPosition(sf::Vector2f(80,30));
	text.setCharacterSize(50);

	// Set the color of the Window
	this->fApp->setBackGroundColor(sf::Color(52,56,56));

	while(this->fApp->isOpen()){

        sf::Event event;
        while (this->fApp->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                this->fApp->close();

            // Check if we clicked the Start Button
            if(event.type == sf::Event::MouseButtonPressed){
            	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					sf::Vector2i localPosition = sf::Mouse::getPosition(*(this->fApp->getWindow()));

					if(singleplayer.isButtonClicked(localPosition)){
						// Yes we did  click the button so go the select level stage
						this->fStages->game->setPlayersAmount(1);
						this->fStages->selectLevel->run();
					}

					if(multiplayer.isButtonClicked(localPosition)){
						// Yes we did  click the button so go the select level stage
						this->fStages->game->setPlayersAmount(2);
						this->fStages->selectLevel->run();
					}

					if(highscores.isButtonClicked(localPosition)){
						// Yes we did  click the button so go the select level stage
						this->fStages->highscores->run();
					}
            	}
            }
        }


		this->fApp->clear();
		this->fApp->draw(singleplayer);
		this->fApp->draw(multiplayer);
		this->fApp->draw(highscores);
		this->fApp->draw(text);
		this->fApp->display();
	}
}

IntroStage::~IntroStage() {
	// TODO Auto-generated destructor stub
}

} /* namespace tySFML */
