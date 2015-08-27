/*
 * Highscores.h
 *
 *  Created on: 19-aug.-2015
 *      Author: Ruben
 */

#ifndef LIBRARY_LIB_HIGHSCORES_H_
#define LIBRARY_LIB_HIGHSCORES_H_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <map>
#include <iostream>
#include <string>
namespace pt = boost::property_tree;

namespace tyLib{
/**
 * @brief Conatiner for Highscores
 */
class Highscores {
public:
	/**
	 * @brief loads the highscores from the highscores.xml file
	 */
	Highscores();

	/**
	 * @brief add a new score to the highscores table, this doesn't mean it will be an highscore
	 *
	 * @return true if this is an highscore
	 */
	bool add(const double score);

	/**
	 * @brief returns a map with the highscores
	 */
	std::map<int, double> get() const;

	/**
	 * @brief return string with the highscores
	 */
	std::string getString() const;

	/**
	 * @brief print the highscores
	 */
	void print() const;

	/**
	 * @brief saves the highscores from the highscores.xml file
	 */
	virtual ~Highscores();
private:
	std::map<int, double> fScores;

};
}

#endif /* LIBRARY_LIB_HIGHSCORES_H_ */
