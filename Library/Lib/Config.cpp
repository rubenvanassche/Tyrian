/*
 * Stopwatch.cpp
 *
 *  Created on: 30-dec.-2014
 *      Author: Ruben
 */

#include "Config.h"

namespace tyLib {

bool Config::instanceFlag = false;
Config* Config::obj = nullptr;
bool Config::fIsLoaded = false;
std::string Config::fName;
int Config::fWidth;
int Config::fHeight;
int Config::fFrameratelimit;
std::string Config::fPlayership;
std::string Config::fFontsPath;
std::string Config::fTexturesPath;
std::string Config::fDataPath;
std::vector<Vector> Config::fPlayers;

Config::Config(){
	// Do nothing
}

Config* Config::getInstance(){
    if(instanceFlag == false){
        obj = new Config();
        instanceFlag = true;
        pt::ptree tree;
        pt::read_xml("Data/config.xml", tree);

        fName = tree.get<std::string>("config.name");
        fWidth = tree.get<int>("config.width");
        fHeight  = tree.get<int>("config.height");
        fFrameratelimit  = tree.get<int>("config.frameratelimit");
        fPlayership = tree.get<std::string>("config.playership");
        fFontsPath  = tree.get<std::string>("config.paths.fonts");
        fTexturesPath =  tree.get<std::string>("config.paths.textures");
        fDataPath =  tree.get<std::string>("config.paths.data");
        fIsLoaded = true;

        // Load the players
        for(const auto& node : tree.get_child("config.players")){
        		if(node.first == "player"){
        			pt::ptree stageTree = node.second;
        			// Create a vector with the player position
        			Vector startposition;
        			startposition.x = stageTree.get<int>("startposition.x");
              startposition.y = stageTree.get<int>("startposition.y");

              fPlayers.push_back(startposition);
        		}else{
        			// Not valid xml node
        		}
        }
        return obj;
    }else{
        return obj;
    }
}

std::string Config::getName(){
  return fName;
}

int Config::getWidth(){
  return fWidth;
}

int Config::getHeight(){
  return fHeight;
}

int Config::getFrameratelimit(){
  return fFrameratelimit;
}

std::string Config::getPlayership(){
  return fPlayership;
}

std::string Config::getFontsPath(){
  return fFontsPath;
}

std::string Config::getTexturesPath(){
  return fTexturesPath;
}

std::string Config::getDatapath(){
  return fDataPath;
}

std::vector<Vector> Config::getPlayers(){
  return fPlayers;
}


Config::~Config(){
    instanceFlag = false;
}

} /* namespace tyLib */
