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
    sf::Clock fFPSClock;
    sf::Clock fClock;
    double fDelta;
public:
    /**
     * @brief Get an instance of the Singleton
     */
    static Stopwatch* getInstance();

    /**
     * @brief Update the clock for FPS and delta
     */
    void update();

    /**
     * @brief Get the delta
     */
    double getDelta();

    /**
     * @brief reset the Stopwatch
     */
    void reset();

    /**
     * Get the framerate per second
     */
    int getFPS() const;
    ~Stopwatch();
};

} /* namespace tySFML */

#endif /* HELPERS_STOPWATCH_H_ */
