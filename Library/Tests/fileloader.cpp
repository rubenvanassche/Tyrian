#include "../External/Catch.hpp"
#include "../Lib/FileLoader.h"
#include <string>
#include <vector>

using namespace tyLib;

TEST_CASE( "Load a file", "[FileLoader]" ) {

	SECTION( "That doesn't exists" ){
		std::string filename = "bla.xml";
		FileLoader f;
		REQUIRE_THROWS( f.loadFile(filename) );
	}

	SECTION("That exists"){
		std::string filename = "Tests/Levels/level1.xml";
		FileLoader f;
		REQUIRE_NOTHROW( f.loadFile(filename) );
	}
}

TEST_CASE( "XMLShip processing", "[FileLoader]"){
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("Tests/Levels/level1.xml");
	pugi::xml_node ship = doc.child("level").child("stages").child("stage").child("ships").child("ship");

	FileLoader f;
	XMLShip exampleship;
	exampleship.type = "standard";
	exampleship.gun = "basic";
	exampleship.x = 10;
	exampleship.y = 10;

	XMLShip generatedship = f.processShip(ship);

	REQUIRE(exampleship.type == generatedship.type);
	REQUIRE(exampleship.gun == generatedship.gun);
	REQUIRE(exampleship.x == generatedship.x);
	REQUIRE(exampleship.y == generatedship.y);
}

TEST_CASE( "XMLStage processing", "[FileLoader]"){
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("Tests/Levels/level1.xml");
	pugi::xml_node stage = doc.child("level").child("stages").child("stage");
	pugi::xml_node ship1node = doc.child("level").child("stages").child("stage").child("ships").child("ship");
	pugi::xml_node ship2node = doc.child("level").child("stages").child("stage").child("ships").child("ship").next_sibling("ship");
	pugi::xml_node ship3node = doc.child("level").child("stages").child("stage").child("ships").child("ship").next_sibling("ship").next_sibling("ship");


	FileLoader f;
	XMLShip ship1 = f.processShip(ship1node);
	XMLShip ship2 = f.processShip(ship2node);
	XMLShip ship3 = f.processShip(ship3node);
	std::vector<XMLShip> exampleships{ship1, ship2, ship3};


	XMLStage examplestage;
	examplestage.start = 5;

	XMLStage generatedstage = f.processStage(stage);

	REQUIRE(examplestage.start == generatedstage.start);

	int counter = 0;
	for(auto i : generatedstage.ships){
		REQUIRE( i.type == exampleships.at(counter).type);
		REQUIRE( i.gun == exampleships.at(counter).gun);
		REQUIRE( i.x == exampleships.at(counter).x);
		REQUIRE( i.y == exampleships.at(counter).y);
		counter++;
	}
}

TEST_CASE( "XMLFile processing", "[FileLoader]"){
	// Todo
}

TEST_CASE( "CheckData", "[FileLoader]"){
	// Todo
}
