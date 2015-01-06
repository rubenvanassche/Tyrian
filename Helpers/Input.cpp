/*
 * Input.cpp
 *
 *  Created on: 30-dec.-2014
 *      Author: Ruben
 */

#include "Input.h"

namespace tySFML {

bool Input::instanceFlag = false;
Input* Input::obj = nullptr;
Input::Input(){
	// Do nothing
}

bool Input::wasKeyPressed(){
	/*
	if(this->fEvent.type == sf::Event::KeyPressed){
		return true;
	}else{
		return false;
	}
	*/
	return true;
}

Input* Input::getInstance(){
    if(instanceFlag == false){
        obj = new Input();
        instanceFlag = true;
        return obj;
    }else{
        return obj;
    }
}

void Input::executeEvent(sf::Event& event){
	this->fEvent = event;
}

bool Input::keyUp(){
	if(!this->wasKeyPressed()){return false;}

	if(this->fEvent.key.code == sf::Keyboard::Up){
		return true;
	}else{
		return false;
	}
}

bool Input::keyDown(){
	if(!this->wasKeyPressed()){return false;}

	if(this->fEvent.key.code == sf::Keyboard::Down){
		return true;
	}else{
		return false;
	}
}

bool Input::keyLeft(){
	if(!this->wasKeyPressed()){return false;}

	if(this->fEvent.key.code == sf::Keyboard::Left){
		return true;
	}else{
		return false;
	}
}

bool Input::keyRight(){
	if(!this->wasKeyPressed()){return false;}

	if(this->fEvent.key.code == sf::Keyboard::Right){
		return true;
	}else{
		return false;
	}
}

bool Input::spaceBar(){
	if(!this->wasKeyPressed()){return false;}

	if(this->fEvent.key.code == sf::Keyboard::Space){
		return true;
	}else{
		return false;
	}
}

bool Input::enter(){
	if(!this->wasKeyPressed()){return false;}

	if(this->fEvent.key.code == sf::Keyboard::BackSpace){
		return true;
	}else{
		return false;
	}
}

bool Input::escape(){
	if(!this->wasKeyPressed()){return false;}

	if(this->fEvent.key.code == sf::Keyboard::Escape){
		return true;
	}else{
		return false;
	}
}

Input::~Input(){
    instanceFlag = false;
}


} /* namespace tySFML */
