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
#include <map>

namespace tySFML{

/**
 * @brief Class for storing assets and getting them without making endless copies
 */
class Assets {
public:
	/**
	 * @brief Constructor for Assets with the path where the textures are and the path where the fonts are
	 */
	Assets(std::string texturePath, std::string fontPath);

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

	virtual ~Assets();
private:
	std::string fTexturePath;
	std::string fFontPath;

	std::map<std::string, sf::Texture*> fTextures;
	std::map<std::string, sf::Font*> fFonts;
};

}

#endif /*** ASSETS_H_ */
