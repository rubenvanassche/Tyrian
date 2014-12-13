/*
 * FileLoader.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_LIB_FILELOADER_H_
#define LIBRARY_LIB_FILELOADER_H_

#include <string>
#include <fstream>
#include <streambuf>
#include "../External/Jsoncpp.hpp"


/**
 * @brief Loads a game file
 */
class FileLoader {
public:
	/**
	 * @brief Construct the loader
	 */
	FileLoader();

	bool loadFile();

	virtual ~FileLoader();
private:

	/**
	 * @brief Read the file from the HDD
	 */
	void readFile();

	/**
	 * @brief Create a JSON object based upon the file contents
	 */
	void createJSON();

	/**
	 * @brief Check if the formatting of the JSON is correct
	 */

	std::string fFilename;
	std::string fFileContents;
	std::string fJSON;
};

#endif /* LIBRARY_LIB_FILELOADER_H_ */
