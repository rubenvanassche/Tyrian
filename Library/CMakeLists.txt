cmake_minimum_required(VERSION 2.8.4)
project(TyrianLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(MODELS_FILES Models/Entity.cpp Models/Ship.cpp Models/Bullet.cpp Models/World.cpp)

set(CONTROLLERS_FILES Controllers/HAL9000.cpp)

set(TEST_FILES Tests/test.cpp Tests/direction.cpp)

set(LIBRARIES_FILES Lib/Catch.hpp Lib/Point.cpp Lib/Size.cpp Lib/Direction.cpp)

add_executable(LibTests ${TEST_FILES} ${MODELS_FILES} ${CONTROLLERS_FILES} ${LIBRARIES_FILES})