#include"../include/map.hpp"

enum map_type map_matrix[ MAP_HEIGHT ][ MAP_WIDTH ];

void Insert_Shape(const std::pair<unsigned short ,unsigned short> & begin
                ,const std::pair<unsigned short ,unsigned short> & end
                , const map_type & type 
                ,const std::pair<unsigned short , unsigned short> & third
                ) // begin and end argument are the two points of the line (square or rectangle)
{ // if we want create T shape , we need third argument .

    if (begin.first == end.first) // (0 ,3) , (0 ,5) mean that Between these two points we have type of map (enum).
    { // In the direction of the Axis X
        Straight_Shape(begin ,end ,type);
    }

    else if (begin.second == end.second) // (3 ,0) , (3 ,10) mean that Between these tow points we have type of map (enum).
    { /// In the direction of the Axis Y
        Straight_Shape(begin ,end ,type);
    }

    else if (third.first == 0 && third.second == 0) // in this section we create square or rectangle shape
    {
        Square_Rectangle_Shape(begin ,end ,type);
    }

    else if(third.first != 0 && third.second != 0)
    {
        T_Shape(begin ,end ,type ,third);
    }

    else
    {
        std::cout << "Error: Insert_Line: begin and end are not in the same line" << std::endl;
    }
}




void Straight_Shape(const std::pair<unsigned short ,unsigned short> & begin
                   ,const std::pair<unsigned short ,unsigned short> & end
                   ,const map_type & type = WALL) // create straight line of map_type (enum)
{
    if(begin.first == end.first)  // In the direction of the Axis X
    {
        for(unsigned short i = begin.second ; i <= end.second ; i++)
        {
            map_matrix[ begin.first ][ i ] = type;
        }
    }

    else  // In the direction of the Axis Y
    {
        for(unsigned short i = begin.first ; i <= end.first ; i++)
        {
            map_matrix[ i ][ begin.second ] = type;
        }
    }
}



void Square_Rectangle_Shape( const std::pair<unsigned short ,unsigned short> & begin
                            ,const std::pair<unsigned short ,unsigned short> & end
                            ,const map_type & type = WALL)
{
    for (size_t i = 0; i <= end.first ; i++)
    {
        for (size_t j = 0; j <= end.second ; j++)
        {
            map_matrix[ i ][ j ] = type;
        }
    }
}


void T_Shape(const std::pair<unsigned short ,unsigned short> & begin
            ,const std::pair<unsigned short ,unsigned short> & end
            ,const map_type & type = WALL
            ,const std::pair<unsigned short ,unsigned short> & third = std::make_pair(0 ,0) )
{
    Straight_Shape(begin ,end ,type);
    Straight_Shape( { begin.first ,third.second } ,third ,type );
}

void Set_Map_Empty()
{
    for(unsigned short i = 0 ; i < MAP_HEIGHT ; i++)
    {
        for(unsigned short j = 0 ; j < MAP_WIDTH ; j++)
        {
            map_matrix[ i ][ j ] = EMPTY;
        }
    }
}

void Print_Map()
{
    for(unsigned short i = 0 ; i < MAP_HEIGHT ; i++)
    {
        for(unsigned short j = 0 ; j < MAP_WIDTH ; j++)
        {
            std::cout << map_matrix[ i ][ j ] << " ";
        }
        std::cout << std::endl;
    }
}