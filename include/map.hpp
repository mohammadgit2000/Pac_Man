#if !defined(MAP_HPP)
#define MAP_HPP

#define MAP_WIDTH 27 // width of map 
#define MAP_HEIGHT 30 // height of map

#include<iostream>

enum Map_Type 
{
    EMPTY,
    WALL,
    PAC_MAN,
    GHOST ,
    NORMAL_FEED
}; // contain moods in the map

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
/*Insert Shape : in this function we diagnose Wall Shape and insert wall in map*/

void Straight_Shape(const std::pair<unsigned short ,unsigned short> & 
                   ,const std::pair<unsigned short ,unsigned short> &
                   ,const Map_Type & = WALL);
/* Straight Shape : in this function we just create a straight line (Axis X or Y) */                  

void Square_Rectangle_Shape( const std::pair<unsigned short ,unsigned short> & 
                            ,const std::pair<unsigned short ,unsigned short> &
                            ,const Map_Type & = WALL);
/* Square Rectangle : create rectangular or square shape  */

void T_Shape(const std::pair<unsigned short ,unsigned short> & 
            ,const std::pair<unsigned short ,unsigned short> &
            ,const Map_Type & = WALL
            ,const std::pair<unsigned short ,unsigned short> & = std::make_pair(0 ,0) );
/* T Shape : create T shape */

Shapes Return_Shape_Type(const std::pair<unsigned short , unsigned short > & 
                        ,const std::pair<unsigned short , unsigned short> &
                        ,const std::pair<unsigned short , unsigned short> &);
/* Return Shape Type : return the shape type of the shape we want to create */

void Set_Map_Empty(); // set all map to empty mood

void Print_Map(); // print map

#endif // MAP_HPP
