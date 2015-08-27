/*
 * Highscores.cpp
 *
 *  Created on: 19-aug.-2015
 *      Author: Ruben
 */

#include "Highscores.h"

namespace tyLib{

Highscores::Highscores() {
	std::cout << "test" << std::endl;
    pt::ptree tree;

    // Parse the XML into the property tree.
    pt::read_xml("Data/highscores.xml", tree);

    int counter = 1;

	for(const auto& node : tree.get_child("highscores")){
		if(node.first == "score"){
			double const score = node.second.get<double>("");
			this->fScores[counter] = score;
			counter++;
		}else{
			// Not Valid node
		}
	}

}

bool Highscores::add(const double score) {
	for (std::map<int,double>::iterator it=this->fScores.begin(); it!=this->fScores.end(); ++it){
		if(it->second <= score){
			it->second = score;
			return true;
		}
	}

	return false;
}

std::map<int, double> Highscores::get() const{
	return this->fScores;
}

std::string Highscores::getString() const{
	std::string out = "";
	  for (std::map<int,double>::const_iterator it=this->fScores.begin(); it!=this->fScores.end(); ++it){
		  out += std::to_string(it->first);
		  out += ".  ";
		  out += std::to_string(it->second);
		  out += "\n";
	  }
	  return out;
}

void Highscores::print() const{
	std::cout << "Highscores" << std::endl;
	std::cout << "----------" << std::endl << std::endl;

	  for (std::map<int,double>::const_iterator it=this->fScores.begin(); it!=this->fScores.end(); ++it){
		  std::cout << it->first << " => " << it->second << std::endl;
	  }
}

Highscores::~Highscores() {
	std::cout << "destruct" << std::endl;
    // Create an empty property tree object.
    pt::ptree tree;

	for(std::map<int,double>::const_iterator it=this->fScores.begin(); it!=this->fScores.end(); ++it){
		tree.add("highscores.score", it->second);
	}


    // Write property tree to XML file
    pt::write_xml("Data/highscores.xml", tree);

}

}
