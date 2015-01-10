cmake_minimum_required(VERSION 2.8.4)
project(Tyrian)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/Extra")
find_package(SFML 2 COMPONENTS system window graphics)
FIND_PACKAGE( Boost 1.40 COMPONENTS system filesystem  REQUIRED )

set(VIEWS Views/View.cpp Views/Bullet.cpp Views/Ship.cpp)

set(HELPERS Helpers/Helpers.cpp Helpers/SFMLBridge.cpp Helpers/Input.cpp Helpers/Stopwatch.cpp Helpers/Window.cpp)

set(SOURCE_FILES main.cpp)

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR} ${Boost_INCLUDE_DIR} Library)


add_subdirectory(Library)

add_executable(Tyrian ${SOURCE_FILES} ${VIEWS} ${HELPERS})

TARGET_LINK_LIBRARIES(Tyrian ${SFML_LIBRARIES} Ty ${Boost_LIBRARIES})