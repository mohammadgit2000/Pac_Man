#include"include/map.hpp"

int main()
{
    Set_Map_Empty();
    Insert_Shape(std::make_pair(0 ,0) ,std::make_pair(2 ,2) , WALL , std::make_pair(1 ,10));

    Print_Map();
    
    return 0;
}