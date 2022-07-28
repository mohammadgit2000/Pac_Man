#if !defined(MAP_HPP)
#define MAP_HPP

#define MAP_WIDTH 27
#define MAP_HEIGHT 30

#include<iostream>

enum map_type {
    MAP_EMPTY,
    MAP_WALL,
    MAP_PACMAN,
    MAP_GHOST
};


void Insert_Line(const std::pair<unsigned short ,unsigned short> & 
                ,const std::pair<unsigned short ,unsigned short> & 
                , const map_type & );

void Set_Map_Empty();
void Print_Map();


#endif // MAP_HPP
