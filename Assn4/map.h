#ifndef MAP_
#define MAP_ // in order to prevent duplication

class Map
{
private:
    char map_array[8][8];      // in order to initialize what will happen
    int map_array_trace[8][8]; // in order to show '?', blank, and 'You'
    // current location
    int curr_row;
    int curr_col;

public:
    Map();                  // constructor
    ~Map(){};               // destructor
    char **get_map_array(); // used in copying private member map_array
    int get_curr_row();
    int get_curr_col();
    void print_map();    // show current location and other places by using map_array_trace
    void move();         // to move character's current location
    void already_been(); // used in changing place to E
};

#endif