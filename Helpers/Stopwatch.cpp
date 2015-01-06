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
    if(fClock.getElapsedTime().asSeconds() >= 1.f){
        fFps = fFrame;
        fFrame = 0;
        fClock.restart();
    }

    fFrame++;
}


int Stopwatch::getFPS(){
	return this->fFps;
}

Stopwatch::~Stopwatch(){
    instanceFlag = false;
}

} /* namespace tySFML */
