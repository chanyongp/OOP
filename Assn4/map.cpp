#include "map.h"
#include "monster.h"
#include "shop.h"
#include "character.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>

// E: EMPTY
// R: RANDOM
// M: MONSTER
// S: SHOP
// B: BOSS

void shopping(Character &ch, Shop &sh);  // definition is in shop.cpp
void fight(Character &ch, Monster &mon); // definition is in monster.cpp

Map::Map() // definition of class Map's constructor
{
    strcpy(map_array[0], "ERMMREMM");
    strcpy(map_array[1], "MEREMRER");
    strcpy(map_array[2], "RMEEMEMM");
    strcpy(map_array[3], "MERSMMER");
    strcpy(map_array[4], "MMERERME");
    strcpy(map_array[5], "ERMEMEER");
    strcpy(map_array[6], "MERMMERM");
    strcpy(map_array[7], "EEMERMEB");

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            map_array_trace[i][j] = 0;
        }
    }
    // start location is [0][0]
    curr_row = 0;
    curr_col = 0;
    // except start location, character haven't been anywhere
    map_array_trace[curr_row][curr_col] = 2;
}

char **Map::get_map_array() // copy map by using pointer and dynamic memory allocation
{
    char **arr = new char *[8];
    for (int i = 0; i < 8; i++)
    {
        arr[i] = new char[8];
        std::memcpy(arr[i], map_array[i], sizeof(char) * 8);
    }
    return arr;
}

int Map::get_curr_row() // return character's current x value
{
    return curr_row;
}
int Map::get_curr_col() // return character's current y value
{
    return curr_col;
}
void Map::print_map() // print map, trace, and character's location
{
    std::cout << "┌───┬───┬───┬───┬───┬───┬───┬───┐\n";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (map_array_trace[i][j] == 0) // if map_array_trace value is 0, character haven't been there
                std::cout << "│ ? ";
            else if (map_array_trace[i][j] == 1) // if map_array_trace value is 1, character have been there
                std::cout << "│   ";
            else if (map_array_trace[i][j] == 2) // if map_array_trace value is 2, character is there
                std::cout << "│You";
        }
        std::cout << "│\n";
        if (i < 7)
        {
            std::cout << "├───┼───┼───┼───┼───┼───┼───┼───┤\n";
        }
    }
    std::cout << "└───┴───┴───┴───┴───┴───┴───┴───┘\n";
}

void Map::move() // change character's location base on player's input
{
    char direction;
    std::cout << "Where do you want to go?\n";
    while (true)
    {
        std::cout << "> ";
        std::cin >> direction; // input character's direction
        // unless x value is 0, go up
        if ((direction == 'w') && (curr_row != 0))
        {
            map_array_trace[curr_row][curr_col] = 1;
            curr_row -= 1;
            map_array_trace[curr_row][curr_col] = 2;
            break;
        }
        // unless y value is 0, go left
        else if ((direction == 'a') && (curr_col != 0))
        {
            map_array_trace[curr_row][curr_col] = 1;
            curr_col -= 1;
            map_array_trace[curr_row][curr_col] = 2;
            break;
        }
        // unless x value is 7, go down
        else if ((direction == 's') && (curr_row != 7))
        {
            map_array_trace[curr_row][curr_col] = 1;
            curr_row += 1;
            map_array_trace[curr_row][curr_col] = 2;
            break;
        }
        // unless y value is 7, go right
        else if ((direction == 'd') && (curr_col != 7))
        {
            map_array_trace[curr_row][curr_col] = 1;
            curr_col += 1;
            map_array_trace[curr_row][curr_col] = 2;
            break;
        }
        // if direction other than w,a,s,d is entered, input again
        else
        {
            std::cout << "You cannot move to that direction.\n";
            continue;
        }
    }
}
void Map::already_been() // change its location to EMPTY
{
    map_array[curr_row][curr_col] = 'E';
}
void judge(Character &ch, Map &map, Shop &sh) // judge what will happen to character base on E,R,M,S,B
{
    char **map_array_judge = map.get_map_array();                       // dynamic memory allocation
    if (map_array_judge[map.get_curr_row()][map.get_curr_col()] == 'E') // if current location is E, nothing happens
    {
    }
    else if (map_array_judge[map.get_curr_row()][map.get_curr_col()] == 'R') // if current location is R, random event emerges
    {
        std::cout << "Random encounter!\n";
        srand(time(NULL));          // in order to make a random number every time the program starts
        int prob = int(rand() % 4); // in order to randomly choose event
        if (prob == 0)
        {
            ch.random_hurt();
            std::cout << "\nYou lost HP...\n";
        }
        else if (prob == 1)
        {
            ch.random_heal();
            std::cout << "\nYou restored HP\n";
        }
        else if (prob == 2)
        {
            ch.earn_money(100);
            std::cout << "\nYou found 100 gold!\n";
        }
        else if (prob == 3)
        {
            std::cout << "\nNothing happened...\n";
        }
        map.already_been(); // except S, after visiting, change its location to EMPTY
    }
    else if (map_array_judge[map.get_curr_row()][map.get_curr_col()] == 'M') // if current location is M, character interacts with monster
    {
        // initialize monster and fight
        Monster mon(map.get_curr_row(), map.get_curr_col());
        fight(ch, mon);
        map.already_been(); // except S, after visiting, change its location to EMPTY
    }
    else if (map_array_judge[map.get_curr_row()][map.get_curr_col()] == 'S') // if current location is S, character interacts with shop
    {
        // character goes shopping
        shopping(ch, sh);
    }
    else if (map_array_judge[map.get_curr_row()][map.get_curr_col()] == 'B') // if current location is B, character interacts with boss monster
    {
        // initialize boss monster and fight
        Monster boss(200, 30, 10);
        fight(ch, boss);
        map.already_been(); // except S, after visiting, change its location to EMPTY
    }

    // delete after dynamic memory alloction
    for (int i = 0; i < 8; i++)
    {
        delete[] map_array_judge[i];
    }
    delete[] map_array_judge;
}
