/**
 * Assets.cpp
 *
 *  Created on: 11 jan. 2014
 *      Author: Ruben
 */

#include "Assets.h"

namespace tySFML{

Assets::Assets(std::string texturePath, std::string fontPath) {
	this->fFontPath = fontPath;
	this->fTexturePath = texturePath;

	// Remove the / at the end of a path if this is set
	if(this->fFontPath.back() == '/'){
		this->fFontPath = this->fFontPath.substr(0, this->fFontPath.size()-1);
	}

	if(this->fTexturePath.back() == '/'){
		this->fTexturePath = this->fTexturePath.substr(0, this->fTexturePath.size()-1);
	}
}

sf::Texture* Assets::getTexture(std::string file){
	// Is the texure already loaded
	if(this->fTextures.find(file) == this->fTextures.end()){
		// Nope so try to add it
		sf::Texture* tex = new sf::Texture;
		if(tex->loadFromFile(this->fTexturePath + '/' + file) == false){
			throw std::runtime_error("Asset couldn't be found!");
		}

		this->fTextures[file] = tex;
		return tex;
	}else{
		return this->fTextures[file];
	}
}

sf::Font* Assets::getFont(std::string file){
	// Is the font already loaded
	if(this->fFonts.find(file) == this->fFonts.end()){
		// Nope so try to add it
		sf::Font* font = new sf::Font;
		if(font->loadFromFile(this->fFontPath + '/' + file) == false){
			throw std::runtime_error("Asset couldn't be found!");
		}

		this->fFonts[file] = font;
		return font;
	}else{
		return this->fFonts[file];
	}
}

Assets::~Assets() {
	for(auto it = this->fTextures.begin();it != this->fTextures.end();it++){
		delete it->second;
	}

	for(auto it = this->fFonts.begin();it != this->fFonts.end();it++){
		delete it->second;
	}

	this->fTextures.clear();
	this->fFonts.clear();
}

}

