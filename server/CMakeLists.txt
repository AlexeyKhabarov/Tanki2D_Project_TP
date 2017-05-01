cmake_minimum_required (VERSION 2.8)
project(server)

set(SOURCES server.cpp)

set(CMAKE_CXX_FLAGS "-std=c++11 -g -O2")

add_executable(binary ${SOURCES})

set(CMAKE_MODULE_PATH  "/usr/share/SFML/cmake/Modules"})
find_package(SFML 2 REQUIRED graphics window system network)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(binary ${SFML_LIBRARIES})
endif()
