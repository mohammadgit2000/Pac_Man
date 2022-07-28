#include"../include/map.hpp"

enum map_type map_matrix[ MAP_HEIGHT ][ MAP_WIDTH ];

void Insert_Line(const std::pair<unsigned short ,unsigned short> & begin
                ,const std::pair<unsigned short ,unsigned short> & end
                , const map_type & type)
{
    if (begin.first == end.first)
    {
        for(unsigned short i = begin.second ; i <= end.second ; i++)
        {
            map_matrix[begin.first][i] = type;
        }
    }
    else if (begin.second == end.second)
    {
        for(unsigned short i = begin.first ; i <= end.first ; i++)
        {
            map_matrix[i][begin.second] = type;
        }
    }
    else
    {
        std::cout << "Error: Insert_Line: begin and end are not in the same line" << std::endl;
    }
    
}

void Set_Map_Empty()
{
    for(unsigned short i = 0 ; i < MAP_HEIGHT ; i++)
    {
        for(unsigned short j = 0 ; j < MAP_WIDTH ; j++)
        {
            map_matrix[i][j] = MAP_EMPTY;
        }
    }
}

void Print_Map()
{
    for(unsigned short i = 0 ; i < MAP_HEIGHT ; i++)
    {
        for(unsigned short j = 0 ; j < MAP_WIDTH ; j++)
        {
            std::cout << map_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}