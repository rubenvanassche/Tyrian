/*
 * IntroStage.cpp
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#include "HighscoresStage.h"
#include "../Library/Lib/Highscores.h"
#include <map>
#include <string>

namespace tySFML {


void HighscoresStage::run(){
	sf::Font* font = this->fAssets->getFont("stark.otf");

	Button button(sf::Vector2f(135,270), sf::Vector2f(50, 30), sf::Color(0,140,158));
	button.setText("Back",sf::Color(52,56,56),  font);
	button.setLine(1, sf::Color(249,212,35));
	button.setPadding(7);

	sf::Text text;
	text.setFont(*font);
	text.setString("Highscores");
	text.setColor(sf::Color::White);
	text.setPosition(sf::Vector2f(60,30));
	text.setCharacterSize(40);

	// Create the highscores string
	tyLib::Highscores HighScores;
	std::string scores = HighScores.getString();

	sf::Text highscorestext;
	highscorestext.setFont(*font);
	highscorestext.setString(scores);
	highscorestext.setColor(sf::Color::White);
	highscorestext.setPosition(sf::Vector2f(95,85));
	highscorestext.setCharacterSize(14);

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

					if(button.isButtonClicked(localPosition)){
						// Yes we did  click the button so go the select level stage
						this->fStages->intro->run();
					}
            	}
            }
        }


		this->fApp->clear();
		this->fApp->draw(button);
		this->fApp->draw(text);
		this->fApp->draw(highscorestext);
		this->fApp->display();
	}
}

HighscoresStage::~HighscoresStage() {
	// TODO Auto-generated destructor stub
}

} /* namespace tySFML */
