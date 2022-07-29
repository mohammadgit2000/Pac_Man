#if !defined(MAP_HPP)
#define MAP_HPP

#define MAP_WIDTH 27
#define MAP_HEIGHT 30

#include<iostream>

enum Map_Type {
    EMPTY,
    WALL,
    PAC_MAN,
    GHOST ,
    NORMAL_FEED
}; // contain all moods in the map

enum Shapes
{
    SQUARE_RECTANGLE,
    T ,
    STRAIGHT ,
    NOTHING
}; // contain all shape moods 


void Insert_Shape(const std::pair<unsigned short ,unsigned short> & 
                ,const std::pair<unsigned short ,unsigned short> &
                ,const Map_Type & = WALL
                ,const std::pair<unsigned short ,unsigned short> & = std::make_pair(0 ,0) );


void Straight_Shape(const std::pair<unsigned short ,unsigned short> & 
                   ,const std::pair<unsigned short ,unsigned short> &
                   ,const Map_Type & = WALL);
                   

void Square_Rectangle_Shape( const std::pair<unsigned short ,unsigned short> & 
                            ,const std::pair<unsigned short ,unsigned short> &
                            ,const Map_Type & = WALL);


void T_Shape(const std::pair<unsigned short ,unsigned short> & 
            ,const std::pair<unsigned short ,unsigned short> &
            ,const Map_Type & = WALL
            ,const std::pair<unsigned short ,unsigned short> & = std::make_pair(0 ,0) );

Shapes Return_Shape_Type(const std::pair<unsigned short , unsigned short > & 
                        ,const std::pair<unsigned short , unsigned short> &
                        ,const std::pair<unsigned short , unsigned short> &);

void Set_Map_Empty();
void Print_Map();

#endif // MAP_HPP
