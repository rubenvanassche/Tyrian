/*
 * SelectLevelStage.cpp
 *
 *  Created on: 10-jan.-2015
 *      Author: Ruben
 */

#include "SelectLevelStage.h"

namespace tySFML {

void SelectLevelStage::run(){
	sf::Font* font = this->fAssets->getFont("stark.otf");
	// Build the select a level text
	sf::Text text;
	text.setFont(*font);
	text.setString("Select a level");
	text.setColor(sf::Color::White);
	text.setPosition(sf::Vector2f(10,10));
	text.setCharacterSize(30);

	// Get the levels in our levels folder
	tyLib::FileLoader fileLoader;
	std::vector<tyLib::Level> levels = fileLoader.getLevels("Data/Levels");

	// Now create buttons for these levels to start
	std::list<Button> buttons;
	int buttonLocationY = 60;
	for(auto i : levels){
		std::string difficultylevel;
		switch(i.difficuly){
			case 1:
				difficultylevel = "Easy";
				break;
			case 2:
				difficultylevel = "Simple";
				break;
			case 3:
				difficultylevel = "Moderate";
				break;
			case 4:
				difficultylevel = "Difficult";
				break;
			case 5:
				difficultylevel = "Hard";
				break;
			default:
				difficultylevel = "Not set";
				break;
		}

		Button button(sf::Vector2f(10,buttonLocationY), sf::Vector2f(290, 30), sf::Color(0,140,158));
		button.setText(i.name + "(" + difficultylevel + ")",sf::Color(52,56,56),font);
		button.setLine(1, sf::Color(249,212,35));
		button.setPadding(7);

		buttonLocationY += 40;

		buttons.push_back(button);
	}



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

					// Check if a button is clicked
					int counter = 0;
					for(auto i : buttons){
						if(i.isButtonClicked(localPosition)){
							// Now by the counter we can check which file to load and start the next stage
							this->fStages->game->setMessage(levels[counter].path);
							this->fStages->game->run();
						}

						counter++;
					}
            	}
            }
        }


		this->fApp->clear();

		// Draw the buttons
		for(auto i : buttons){
			this->fApp->draw(i);
		}

		this->fApp->draw(text);
		this->fApp->display();
	}
}

SelectLevelStage::~SelectLevelStage() {
	// TODO Auto-generated destructor stub
}

} /* namespace tySFML */
