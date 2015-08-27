#include "../External/Catch.hpp"
#include "../Lib/Direction.h"

using namespace tyLib;

TEST_CASE( "Direction can be Left", "[Direction]" ){
	Direction d("left");
	REQUIRE( d.isLeft() == true );
	REQUIRE( d.isRight() == false );
	REQUIRE( d.isUp() == false );
	REQUIRE( d.isDown() == false );
}

TEST_CASE( "Direction can be Right", "[Direction]" ){
	Direction d("right");
	REQUIRE( d.isLeft() == false );
	REQUIRE( d.isRight() == true );
	REQUIRE( d.isUp() == false );
	REQUIRE( d.isDown() == false );
}

TEST_CASE( "Direction can be Up", "[Direction]" ){
	Direction d("up");
	REQUIRE( d.isLeft() == false );
	REQUIRE( d.isRight() == false );
	REQUIRE( d.isUp() == true );
	REQUIRE( d.isDown() == false );
}

TEST_CASE( "Direction can be Down", "[Direction]" ){
	Direction d("down");
	REQUIRE( d.isLeft() == false );
	REQUIRE( d.isRight() == false );
	REQUIRE( d.isUp() == false );
	REQUIRE( d.isDown() == true );
}

TEST_CASE ("There are only 4 values as an Direction", "[Direction]"){
	REQUIRE_THROWS( Direction d("somewhere") );
	REQUIRE_NOTHROW( Direction d("left") );
}

TEST_CASE( "Directions can be in different cases", "[Direction]" ) {

    SECTION( "Capital at front" ) {
        Direction d("Left");

        REQUIRE( d.isLeft() == true );
    }
    SECTION( "Lowercase" ) {
        Direction d("left");

        REQUIRE( d.isLeft() == true );
    }
    SECTION( "Uppercase" ) {
        Direction d("LEFT");

        REQUIRE( d.isLeft() == true );
    }
}
