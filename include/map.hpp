#if !defined(MAP_HPP)
#define MAP_HPP

#define MAP_WIDTH 27
#define MAP_HEIGHT 30

#include<iostream>

enum map_type {
    EMPTY,
    WALL,
    PACMAN,
    GHOST ,
    NORMAL_FEED
};


void Insert_Shape(const std::pair<unsigned short ,unsigned short> & 
                ,const std::pair<unsigned short ,unsigned short> &
                ,const map_type & = WALL
                ,const std::pair<unsigned short ,unsigned short> & = std::make_pair(0 ,0) );


void Straight_Shape(const std::pair<unsigned short ,unsigned short> & 
                   ,const std::pair<unsigned short ,unsigned short> &
                   ,const map_type & = WALL);
                   

void Square_Rectangle_Shape( const std::pair<unsigned short ,unsigned short> & 
                            ,const std::pair<unsigned short ,unsigned short> &
                            ,const map_type & = WALL);


void T_Shape(const std::pair<unsigned short ,unsigned short> & 
            ,const std::pair<unsigned short ,unsigned short> &
            ,const map_type & = WALL
            ,const std::pair<unsigned short ,unsigned short> & = std::make_pair(0 ,0) );

void Set_Map_Empty();
void Print_Map();

#endif // MAP_HPP
