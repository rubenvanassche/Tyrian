/*
 * Stopwatch.cpp
 *
 *  Created on: 30-dec.-2014
 *      Author: Ruben
 */

#include "Stopwatch.h"

namespace tySFML {

bool Stopwatch::instanceFlag = false;
Stopwatch* Stopwatch::obj = nullptr;
Stopwatch::Stopwatch(){
	// Do nothing
}

Stopwatch* Stopwatch::getInstance(){
    if(instanceFlag == false){
        obj = new Stopwatch();
        instanceFlag = true;
        return obj;
    }else{
        return obj;
    }
}

void Stopwatch::update(){
    if(fFPSClock.getElapsedTime().asSeconds() >= 1.f){
        fFps = fFrame;
        fFrame = 0;
        fFPSClock.restart();
    }

    fFrame++;

    // Reset the delta attribute
    this->fDelta = 0;
}


int Stopwatch::getFPS(){
	return this->fFps;
}

double Stopwatch::getDelta(){
	if(this->fDelta == 0){
		this->fDelta = fClock.restart().asSeconds();
	}

	return this->fDelta;
}

void Stopwatch::reset(){
	this->fClock.restart();
	this->fFPSClock.restart();
	this->fDelta = 0;
	this->fFrame = 0;
	this->fFps = 0;
}

Stopwatch::~Stopwatch(){
    instanceFlag = false;
}

} /* namespace tySFML */
