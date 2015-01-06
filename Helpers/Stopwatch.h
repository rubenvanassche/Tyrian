/*
 * Stopwatch.h
 *
 *  Created on: 30-dec.-2014
 *      Author: Ruben
 */

#ifndef HELPERS_STOPWATCH_H_
#define HELPERS_STOPWATCH_H_

#include <SFML/Window.hpp>

namespace tySFML {

class Stopwatch {
private:
    static bool instanceFlag;
    static Stopwatch *obj;
    Stopwatch();
    int fFrame = 0;
    int fFps = 0;
    sf::Clock fClock;
public:
    /**
     * @brief Get an instance of the Singleton
     */
    static Stopwatch* getInstance();

    /**
     * Update the clock
     */
    void update();

    /**
     * Get the framerate per second
     */
    int getFPS();
    ~Stopwatch();
};

} /* namespace tySFML */

#endif /* HELPERS_STOPWATCH_H_ */
