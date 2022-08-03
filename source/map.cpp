#include"../include/map.hpp"

/*   -    -     -    -    -   S_I_N_G_L_E_T_O_N  P_A_T_T_E_R_N   -    -    -    -*/
Map * Map::instance = nullptr; // initializer of static member

Map * Map :: get_instance() // singleton pattern
{
    if(instance == nullptr)
    {
        instance = new Map();
    }
    return instance;
}

/*   -    -     -    -    -   I_N_S_E_R_T_I-O-N    -     -     -   -    -    -    -*/

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
    for (size_t i = begin.first; i <= end.first ; i++)
    {
        for (size_t j = begin.second; j <= end.second ; j++)
        {
            map_matrix[ i ][ j ] = type;
        }
    }
}


void Map :: Insert_T_Shape(const queue_type & line_one
            ,const queue_type & line_two
            ,const Map_Enum & type ) // create t shape in map
{
    Insert_Square_Rectangle_Shape(line_one.front().first , line_one.front().second , type); // create square rectangle shape
    Insert_Square_Rectangle_Shape(line_two.front().first , line_two.front().second , type); // create straight line shape
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


void Map :: Add_Location_T_Shape_Wall(const queue_type & temp)
{ // add wall location to map
    t_shape_wall.push(std::make_pair( std::make_pair(temp.front().first.first , temp.front().first.second)
                                    ,std::make_pair(temp.front().second.first , temp.front().second.second) ) );
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

void Map :: Default_Wall_Locations()
{

}


void Map :: Default_Wall_Square_Rectangle_Locations()
{
    square_rectangle_wall.push( std::make_pair( std::make_pair(2 ,2) , std::make_pair(4 , 5) ) );
    Insert_Square_Rectangle_Shape(square_rectangle_wall.back().first , square_rectangle_wall.back().second , WALL);
    Insert_Square_Rectangle_Shape(std::make_pair(2 , MAP_WIDTH - square_rectangle_wall.back().second.second - 1 ) ,
                                  std::make_pair(4 , MAP_WIDTH - square_rectangle_wall.back().first.second - 1 ) , WALL);

    square_rectangle_wall.push( std::make_pair( std::make_pair(2 ,7) , std::make_pair(4 , 11) ) );
    Insert_Square_Rectangle_Shape(square_rectangle_wall.back().first , square_rectangle_wall.back().second , WALL);
    Insert_Square_Rectangle_Shape(std::make_pair(2 ,MAP_WIDTH - square_rectangle_wall.back().second.second - 1) ,
                                  std::make_pair(4 ,MAP_WIDTH - square_rectangle_wall.back().first.second - 1) , WALL);

    square_rectangle_wall.push( std::make_pair( std::make_pair(6 ,2) , std::make_pair(7 , 5) ) );
    Insert_Square_Rectangle_Shape(square_rectangle_wall.back().first , square_rectangle_wall.back().second , WALL);
    Insert_Square_Rectangle_Shape(std::make_pair(6 ,MAP_WIDTH - square_rectangle_wall.back().second.second - 1) , 
                                  std::make_pair(7 ,MAP_WIDTH - square_rectangle_wall.back().first.second - 1) , WALL);

    square_rectangle_wall.push( std::make_pair( std::make_pair(9 ,0) , std::make_pair(13 , 5) ) );
    Insert_Square_Rectangle_Shape(square_rectangle_wall.back().first , square_rectangle_wall.back().second , WALL);
    Insert_Square_Rectangle_Shape(std::make_pair(9 ,MAP_WIDTH - square_rectangle_wall.back().second.second - 1) ,
                                  std::make_pair(13 ,MAP_WIDTH - square_rectangle_wall.back().first.second - 1) , WALL);

    square_rectangle_wall.push( std::make_pair( std::make_pair(15 ,0) , std::make_pair(19 , 5) ) );
    Insert_Square_Rectangle_Shape(square_rectangle_wall.back().first , square_rectangle_wall.back().second , WALL);
    Insert_Square_Rectangle_Shape(std::make_pair(15 ,MAP_WIDTH - square_rectangle_wall.back().second.second - 1) ,
                                  std::make_pair(19 ,MAP_WIDTH - square_rectangle_wall.back().first.second - 1) , WALL);

    square_rectangle_wall.push( std::make_pair( std::make_pair(21 ,7) , std::make_pair(22 , 11) ) );
    Insert_Square_Rectangle_Shape(square_rectangle_wall.back().first , square_rectangle_wall.back().second , WALL);
    Insert_Square_Rectangle_Shape(std::make_pair(21 ,MAP_WIDTH - square_rectangle_wall.back().second.second - 1) ,
     std::make_pair(22 ,MAP_WIDTH - square_rectangle_wall.back().first.second - 1) , WALL);
}



void Map :: Default_Wall_T_Locations() // insert wall by default
{
    queue_type temp1 ,temp2;

    temp1.push(std::make_pair(std::make_pair(6 ,7) , std::make_pair(13 , 8) ));
    temp2.push(std::make_pair(std::make_pair(9 ,7) , std::make_pair(10 , 11) ));
    
    Insert_T_Shape(temp1, temp2 , WALL);

    temp1.pop();
    temp2.pop();

    temp1.push(std::make_pair(std::make_pair(26 ,2) , std::make_pair(27 , 11) ));
    temp2.push(std::make_pair(std::make_pair(26 ,7) , std::make_pair(23 , 8) ));

    Insert_T_Shape(temp1, temp2 , WALL);


}