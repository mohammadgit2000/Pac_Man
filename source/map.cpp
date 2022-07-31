#include"../include/map.hpp"

/*   -    -     -    -    -   S_I_N_G_L_E_T-O-N  P_A_T_T_E_R_N   -    -    -    -*/
Map * Map::instance = nullptr; // initializer of static member

Map * Map :: get_instance() // singleton pattern
{
    if(instance == nullptr)
    {
        instance = new Map();
    }
    return instance;
}

/*   -    -     -    -    -   S_I_N_G_L_E_T-O-N  P_A_T_T_E_R_N   -    -    -    -*/
void Map:: Insert_Shape(const pair_type & begin
                ,const pair_type & end
                , const Map_Enum & type 
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



void Map :: Insert_Straight_Shape(const pair_type & begin
                   ,const pair_type & end
                   ,const Map_Enum & type ) // create straight line of map_type (enum)
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


void Map :: Insert_Square_Rectangle_Shape( const pair_type & begin
                            ,const pair_type & end
                            ,const Map_Enum & type ) // create square rectangle in map
{
    for (size_t i = 0; i <= end.first ; i++)
    {
        for (size_t j = 0; j <= end.second ; j++)
        {
            map_matrix[ i ][ j ] = type;
        }
    }
}


void Map :: Insert_T_Shape(const pair_type & begin
            ,const pair_type & end
            ,const Map_Enum & type 
            ,const pair_type & third ) // create t shape in map
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



Shapes_Enum Map :: Return_Shape_Type(const pair_type & begin 
                        ,const pair_type & end
                        ,const pair_type & third) const
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


/*   -     -     -     -     -     -   A_D_D  W_A_L_L  L_O_C_A_T_I_O_N     -     -    -     -    - */
void Map :: Add_Location_Square_Rectangle_Wall(const queue_type & temp)
{ // add wall location to map
    square_rectangle_wall.push(std::make_pair( std::make_pair(temp.front().first.first , temp.front().first.second)
                                            ,std::make_pair(temp.front().second.first , temp.front().second.second) ) );
}


void Map :: Add_Location_T_Shape_Wall(const t_queue_type & temp)
{ // add wall location to map
    t_shape_wall.push(std::make_pair( std::make_pair(temp.front().first.first , temp.front().first.second)
                                    ,temp.front().second));
}


void Map :: Add_Location_Straight_Wall(const queue_type & temp)
{ // add wall location to map
    straight_wall.push(std::make_pair(std::make_pair(temp.front().first.first , temp.front().first.second)
                                                    ,std::make_pair(temp.front().second.first , temp.front().second.second)));
}


void Map :: Add_Location_Empty_Area(const pair_type & temp)
{ // add empty area location to map
    empty_area.push(std::make_pair(temp.first , temp.second));
}




/*   -     -     -     -     -     -   A_D_D  W_A_L_L  L_O_C_A_T_I_O_N     -     -    -     -    - */