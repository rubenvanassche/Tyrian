/*
 * Input.h
 *
 *  Created on: 30-dec.-2014
 *      Author: Ruben
 */

#ifndef HELPERS_INPUT_H_
#define HELPERS_INPUT_H_

#include <iostream>
#include <SFML/Window.hpp>

namespace tySFML {

/**
 * @brief Represents the user input by a given Event
 */
class Input {
private:
    static bool instanceFlag;
    static Input *obj;
    sf::Event fEvent;
    Input();

    /**
     * @brief check if an key was pressed
     */
    bool wasKeyPressed();

public:
    /**
     * @brief Get an instance of the Singleton
     */
    static Input* getInstance();

    /**
     * @brief Execute an Event
     */
    void executeEvent(sf::Event&  event);

    /**
     * @brief Check if the up key was pressed
     */
    bool keyUp() ;

    /**
     * @brief Check if the down key was pressed
     */
    bool keyDown() ;

    /**
     * @brief Check if the left key was pressed
     */
    bool keyLeft() ;

    /**
     * @brief Check if the right key was pressed
     */
    bool keyRight() ;

    /**
     * @brief Check if the i key was pressed
     */
    bool keyI() ;

    /**
     * @brief Check if the l key was pressed
     */
    bool keyL() ;

    /**
     * @brief Check if the k key was pressed
     */
    bool keyK() ;

    /**
     * @brief Check if the j key was pressed
     */
    bool keyJ() ;

    /**
     * @brief Check if the h key was pressed
     */
    bool keyH() ;

    /**
     * @brief Check if the spacebar key was pressed
     */
    bool spaceBar() ;

    /**
     * @brief Check if the enter key was pressed
     */
    bool enter() ;

    /**
     * @brief Check if the escape key was pressed
     */
    bool escape() ;
    ~Input();
};

} /* namespace tySFML */

#endif /* HELPERS_INPUT_H_ */
