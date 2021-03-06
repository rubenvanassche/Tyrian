cmake_minimum_required(VERSION 2.8.4)
project(TyrianLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g")

set(MODELS_FILES Models/Entity.cpp Models/Ship.cpp Models/Bullet.cpp Models/Gun.cpp Models/World.cpp Models/Tile.cpp Models/TileEntityTypes.hpp)

set(CONTROLLERS_FILES Controllers/HAL9000.cpp Controllers/Game.cpp)

set(FACTORIES_FILES Factories/ShipFactory.cpp Factories/BulletFactory.cpp Factories/GunFactory.cpp)

set(TEST_FILES Tests/test.cpp Tests/direction.cpp Tests/fileloader.cpp Tests/tile.cpp)

set(LIBRARIES_FILES Lib/Point.cpp Lib/Size.cpp Lib/Direction.cpp Lib/FileLoader.cpp Lib/Bridge.cpp Lib/Highscores.cpp Lib/Config.cpp Lib/Players.cpp)

set(EXTERNAL_FILES External/Catch.hpp External/pugixml.cpp External/tinydir.h)

add_executable(LibTests ${TEST_FILES} ${MODELS_FILES} ${CONTROLLERS_FILES} ${LIBRARIES_FILES} ${FACTORIES_FILES} ${EXTERNAL_FILES})


add_library(Ty STATIC ${MODELS_FILES} ${CONTROLLERS_FILES} ${LIBRARIES_FILES} ${FACTORIES_FILES} ${EXTERNAL_FILES})
