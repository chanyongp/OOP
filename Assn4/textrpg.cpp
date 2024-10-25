#include "map.h"
#include "character.h"
#include "shop.h"
#include <iostream>
#include <string>

// after moving character's location, judge what will happen next
void judge(Character &ch, Map &map, Shop &sh); // definition is in map.cpp

int main()
{
    using namespace std;
    std::cout << "========================================================" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << " #######                      ######   ######   ##### " << std::endl;
    std::cout << "    #   ###### #    # #####   #     #  #     # #     # " << std::endl;
    std::cout << "    #   #       #  #    #     #     #  #     # # " << std::endl;
    std::cout << "    #   #####    ##     #     ######   ######  # #### " << std::endl;
    std::cout << "    #   #        ##     #     #  #     #       #     # " << std::endl;
    std::cout << "    #   #       # #     #     #   #    #       #     # " << std::endl;
    std::cout << "    #   ###### #   #    #     #    #   #        ##### " << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "========================================================" << std::endl;
    cout << "----- Menu -----" << endl;
    cout << "1. Start game" << endl;
    cout << "2. Exit" << endl;
    int menu_num;
    int menu_num2;

    while (true)
    {
        cout << "> ";
        cin >> menu_num;
        if (menu_num == 1) // start game
        {

            Character ch; // construct character
            Map map;      // construct map
            Shop sh;      // construct shop
            cout << "Game start!\n";
            while (true)
            {
                map.print_map(); // show map
                cout << "1. Choose direction" << endl;
                cout << "2. Show character status" << endl;
                cout << "3. Exit game" << endl;
                while (true)
                {
                    cout << "> ";
                    cin >> menu_num2;
                    if (menu_num2 == 1)
                    {
                        map.move();         // move character's location
                        judge(ch, map, sh); // after moving character's location, judge what will happen next
                        break;
                    }
                    else if (menu_num2 == 2)
                    {
                        ch.show_status(); // show character's status
                        break;
                    }
                    else if (menu_num2 == 3)
                    {
                        break; // get out of loop to exit game
                    }
                    else
                    {
                        continue; // input menu_num2 again
                    }
                }
                if (menu_num2 == 3)
                {
                    cout << "Exit...";
                    break; // exit game
                }
                if ((ch.get_curr_hp() <= 0) || (ch.get_victory() == 1))
                {
                    break;
                }
            }
            break;
        }
        else if (menu_num == 2)
        {
            cout << "Exit...";
            break; // exit game
        }
        else
        {
            continue; // input menu_num again
        }
    }

    return 0;
}