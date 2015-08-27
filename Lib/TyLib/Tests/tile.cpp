#include "../External/Catch.hpp"
#include "../Models/Tile.h"

using namespace tyLib;

TEST_CASE( "Construct one", "[Tile]" ){
	Tile t(320, 320, "Grass");
	REQUIRE(t.getBackground()->size() > 0);
}

TEST_CASE( "Move once", "[Tile]" ){
	Tile t(320, 320, "Grass");
	for(int i = 0; i < 100;i++){
		t.move(Direction("Down"), 10);
	}
}

