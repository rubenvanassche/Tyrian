cmake_minimum_required(VERSION 2.8.4)
project(Tyrian)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/Extra")
find_package(SFML 2 COMPONENTS system window graphics)

set(SOURCE_FILES main.cpp)

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

add_executable(Tyrian ${SOURCE_FILES})

add_library(TyrianLib SHARED Library/Entity.cpp)

TARGET_LINK_LIBRARIES(Tyrian ${SFML_LIBRARIES})