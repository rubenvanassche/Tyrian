/**
 * Assets.h
 *
 *  Created on: 11 jan. 2014
 *      Author: Ruben
 */

#ifndef ASSETS_H_
#define ASSETS_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <stdexcept>
#include <map>
#include "../Library/Lib/Config.h"

namespace tySFML{

/**
 * @brief Class for storing assets and getting them without making endless copies
 */
class Assets {
public:
    /**
     * @brief Get an instance of the Singleton
     */
    static Assets* getInstance();

	/**
	 * @brief get a texture
	 *
	 * @param file The path to the texture file
	 *
	 * @return A pointer to a texture
	 */
	sf::Texture* getTexture(std::string file);

	/**
	 * @brief get a font
	 *
	 * @param file The path to the font file
	 *
	 * @return A pointer to a font
	 */
	sf::Font* getFont(std::string file);

	/**
	 * @brief Set the font path
	 */
	void setFontPath(std::string path);

	/**
	 * @brief Set the textures path
	 */
	void setTexturesPath(std::string path);

	virtual ~Assets();
private:
	std::string fTexturePath = "";
	std::string fFontPath = "";

	std::map<std::string, sf::Texture*> fTextures;
	std::map<std::string, sf::Font*> fFonts;

	// For singleton
    static bool instanceFlag;
    static Assets *obj;
    sf::Event fEvent;
    Assets();
};

}

#endif /*** ASSETS_H_ */
