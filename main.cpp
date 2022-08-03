#include"include/map.hpp"

int main()
{
    Map * map = Map::get_instance();
    map->Set_Map_Empty();

    // map->Default_Wall_Square_Rectangle_Locations();
    map->Default_Wall_T_Locations();

    map->Print_Map();

    return 0;
}