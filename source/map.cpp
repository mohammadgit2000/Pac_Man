#include"../include/map.hpp"

enum Map_Type map_matrix[ MAP_HEIGHT ][ MAP_WIDTH ];

void Insert_Shape(const std::pair<unsigned short ,unsigned short> & begin
                ,const std::pair<unsigned short ,unsigned short> & end
                , const Map_Type & type 
                ,const std::pair<unsigned short , unsigned short> & third
                ) // begin and end argument are the two points of the line (square or rectangle)
{ // if we want create T shape , we need third argument .

    switch (Return_Shape_Type(begin ,end ,third))
    {
        case SQUARE_RECTANGLE:
            Square_Rectangle_Shape(begin , end , type);
            break;
        case STRAIGHT:
            Straight_Shape(begin , end , type);
            break;
        case T:
            T_Shape(begin , end , type , third);
            break;
        case NOTHING:
            break;
    }
}



void Straight_Shape(const std::pair<unsigned short ,unsigned short> & begin
                   ,const std::pair<unsigned short ,unsigned short> & end
                   ,const Map_Type & type ) // create straight line of map_type (enum)
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
                            ,const Map_Type & type )
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
            ,const Map_Type & type 
            ,const std::pair<unsigned short ,unsigned short> & third )
{
    switch (Return_Shape_Type(begin ,end ,{0 ,0}))
    {
        case SQUARE_RECTANGLE:
            std::cout << "SQUARE_RECTANGLE" << std::endl;
            Square_Rectangle_Shape(begin , end , type);
            break;

        case STRAIGHT:
            std::cout << "STRAIGHT" << std::endl;
            Straight_Shape(begin , end , type);
            break;

        case NOTHING:
            std::cout << "NOTHING" << std::endl;
            return;
    }

    Straight_Shape( { third.first ,begin.second } ,third ,type );
}



Shapes Return_Shape_Type(const std::pair<unsigned short , unsigned short > & begin 
                        ,const std::pair<unsigned short , unsigned short> & end
                        ,const std::pair<unsigned short , unsigned short> & third)
{
    if (begin.first == end.first)
    {
        return STRAIGHT;
    }
    
    else if (begin.second == end.second)
    {
        return STRAIGHT;
    }
    
    else if (third.first == 0 && third.second == 0)
    {
        return SQUARE_RECTANGLE;
    }
    
    else if(third.first != 0 && third.second != 0)
    {
        return T;
    }
    
    else
    {
        return NOTHING;
    }
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