#if !defined(MAP_HPP)
#define MAP_HPP

#define MAP_WIDTH 27 // width of map 
#define MAP_HEIGHT 30 // height of map

#include<iostream>
#include<queue>

typedef std::pair<unsigned short ,unsigned short> pair_type;

typedef std::queue < std::pair < pair_type , pair_type > > queue_type;
typedef std::queue < std::pair<pair_type ,unsigned short> > t_queue_type;
typedef std::queue <pair_type> empty_queue_type;

enum Map_Enum 
{
    EMPTY,
    WALL,
    PAC_MAN,
    GHOST ,
    NORMAL_FEED
}; // contain moods in the map

enum Shapes_Enum
{
    SQUARE_RECTANGLE,
    T ,
    STRAIGHT ,
    NOTHING
}; // contain all shape moods 


class Map
{
    private : 

    Map_Enum map_matrix[ MAP_HEIGHT ][ MAP_WIDTH ]; // map matrix

    static Map * instance; // instance of map (for singleton)

    queue_type square_rectangle_wall; // wall locations

    t_queue_type t_shape_wall; // wall locations

    queue_type straight_wall; // wall locations

    empty_queue_type empty_area; // empty area locations

    public :

    static Map * get_instance(); // get instance of map (for singleton)


/*    -     -     -     -    I_N_S_E_R_T_I_O_N  M_A_P    -     -      -      -     -     -*/

    void Insert_Shape(const pair_type & 
                ,const pair_type &
                ,const Map_Enum & = WALL
                ,const pair_type & = std::make_pair(0 ,0) );
/*Insert Shape : in this function we diagnose Wall Shape and insert wall in map*/


void Insert_Straight_Shape(const pair_type & 
                   ,const pair_type &
                   ,const Map_Enum & = WALL);
/* Straight Shape : in this function we just create a straight line (Axis X or Y) */                  


void Insert_Square_Rectangle_Shape( const pair_type & 
                            ,const pair_type &
                            ,const Map_Enum & = WALL);
/* Square Rectangle : create rectangular or square shape  */


void Insert_T_Shape(const pair_type & 
            ,const pair_type &
            ,const Map_Enum & = WALL
            ,const pair_type & = std::make_pair(0 ,0) );
/* T Shape : create T shape */


Shapes_Enum Return_Shape_Type(const pair_type & 
                        ,const pair_type &
                        ,const pair_type &) const;
/* Return Shape Type : return the shape type of the shape we want to create */


void Set_Map_Empty(); // set all map to empty mood

void Print_Map() const; // print map


/*   -     -     -     -     -     -   A_D_D  W_A_L_L  L_O_C_A_T_I_O_N     -     -    -     -    - */
    void Add_Location_Square_Rectangle_Wall(const queue_type &);
/* Add Location Square Rectangle Wall : add wall locations to the queue */

    
    void Add_Location_T_Shape_Wall(const t_queue_type &);
/* Add Location T Shape Wall : add wall locations to the queue */

    
    void Add_Location_Straight_Wall(const queue_type &);
/* Add Location Straight Wall : add wall locations to the queue */

        
    void Add_Location_Empty_Area(const pair_type &);
/* Add Location Empty Area : add empty area locations to the queue */


/*   -     -     -     -     -     -   A_D_D  W_A_L_L  L_O_C_A_T_I_O_N     -     -    -     -    - */
void Default_Wall_Locations();


};




#endif // MAP_HPP
