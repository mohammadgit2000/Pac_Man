#include"../include/map.hpp"

Map * Map::instance = nullptr; // initializer of static member

Map * Map :: get_instance() // singleton pattern
{
    if(instance == nullptr)
    {
        instance = new Map();
    }
    return instance;
}


void Map:: Insert_Shape(const std::pair<unsigned short ,unsigned short> & begin
                ,const std::pair<unsigned short ,unsigned short> & end
                , const Map_Type & type 
                ,const std::pair<unsigned short , unsigned short> & third )
// begin and end argument are the two points of the line (square or rectangle)
{ // if we want create T shape , we need third argument .

    switch (Return_Shape_Type(begin ,end ,third)) // diagnose shape type 
    {
        case SQUARE_RECTANGLE:
            Insert_Square_Rectangle_Shape(begin , end , type); // create square or rectangle shape
            break;

        case STRAIGHT:
            Insert_Straight_Shape(begin , end , type); // create straight line shape
            break;

        case T:
            Insert_T_Shape(begin , end , type , third); // create T shape
            break;

        case NOTHING:
            break;
    }
}



void Map :: Insert_Straight_Shape(const std::pair<unsigned short ,unsigned short> & begin
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


void Map :: Insert_Square_Rectangle_Shape( const std::pair<unsigned short ,unsigned short> & begin
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


void Map :: Insert_T_Shape(const std::pair<unsigned short ,unsigned short> & begin
            ,const std::pair<unsigned short ,unsigned short> & end
            ,const Map_Type & type 
            ,const std::pair<unsigned short ,unsigned short> & third )
{
    switch (Return_Shape_Type(begin ,end ,{0 ,0}))
    {
        case SQUARE_RECTANGLE:
            std::cout << "SQUARE_RECTANGLE" << std::endl;
            Insert_Square_Rectangle_Shape(begin , end , type);
            break;

        case STRAIGHT:
            std::cout << "STRAIGHT" << std::endl;
            Insert_Straight_Shape(begin , end , type);
            break;

        case NOTHING:
            std::cout << "NOTHING" << std::endl;
            return;
    }

    Insert_Straight_Shape( { third.first ,begin.second } ,third ,type );
}



Shapes Map :: Return_Shape_Type(const std::pair<unsigned short , unsigned short > & begin 
                        ,const std::pair<unsigned short , unsigned short> & end
                        ,const std::pair<unsigned short , unsigned short> & third) const
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

void Map :: Set_Map_Empty()
{
    for(unsigned short i = 0 ; i < MAP_HEIGHT ; i++)
    {
        for(unsigned short j = 0 ; j < MAP_WIDTH ; j++)
        {
            map_matrix[ i ][ j ] = EMPTY;
        }
    }
}

void Map :: Print_Map() const
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