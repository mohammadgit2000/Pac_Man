#include"include/map.hpp"

int main()
{
    Map * map = Map::get_instance();
    map->Set_Map_Empty();

    map->Print_Map();

    return 0;
}