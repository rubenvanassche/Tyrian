/*
 * Stopwatch.h
 *
 *  Created on: 30-dec.-2014
 *      Author: Ruben
 */

#ifndef LIB_CONFIG_H_
#define LIB_CONFIG_H_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>
#include <vector>
#include "Point.h"
namespace pt = boost::property_tree;

namespace tyLib {

/**
 @brief Represents the game configuration
*/
class Config {
private:
    static bool instanceFlag;
    static Config *obj;
    Config();

    static bool fIsLoaded;
    static std::string fName;
    static int fWidth;
    static int fHeight;
    static int fFrameratelimit;
    static std::string fPlayership;
    static std::string fFontsPath;
    static std::string fTexturesPath;
    static std::string fDataPath;
    static std::vector<Vector> fPlayers;
public:
    /**
     * @brief Get an instance of the Singleton
     */
    static Config* getInstance();

    static std::string getName();
    static int getWidth();
    static int getHeight();
    static int getFrameratelimit();
    static std::string getPlayership();
    static std::string getFontsPath();
    static std::string getTexturesPath();
    static std::string getDatapath();
    static std::vector<Vector> getPlayers();

    ~Config();
};

} /* namespace tyLib */

#endif /* LIB_CONFIG_H_ */
