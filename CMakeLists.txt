
cmake_minimum_required(VERSION 3.0)
project(Pac_Man)
set(CMAKE_CXX_STANDARD 11)
set ( SOURCES
    main.cpp
    source/map.cpp
)
add_executable(app ${SOURCES})
include_directories(include/)
target_link_libraries(app sfml-window sfml-system sfml-graphics)