#include "shop.h"
#include "character.h"
#include <iostream>

Shop::Shop() // definition of class Shop's constructor
{
    potion_attack_num = 1;
    potion_defense_num = 1;
    potion_exp_num = 1;
}
int Shop::get_potion_attack_num() // return attack potion's number
{
    return potion_attack_num;
}
int Shop::get_potion_defense_num() // return defense potion's number
{
    return potion_defense_num;
}
int Shop::get_potion_exp_num() // return exp potion's number
{
    return potion_exp_num;
}
void Shop::buy_potion_attack() // if character buy attack potion, attack potion's number is not available
{
    potion_attack_num = 0;
}
void Shop::buy_potion_defense() // if character buy defense potion, defense potion's number is not available
{
    potion_defense_num = 0;
}
void Shop::buy_potion_exp() // if character buy exp potion, exp potion's number is not available
{
    potion_exp_num = 0;
}

void shopping(Character &ch, Shop &sh) // character does shopping in shop
{
    // show character's gold and shop's item list
    int shop_menu_num;
    std::cout << "Welcome to the item shop!\n";
    std::cout << "You have " << ch.get_gold() << " gold.\n";
    std::cout << "=======================================\n";
    std::cout << "============== Item list ==============\n";
    std::cout << "=======================================\n\n";
    // print (Available) if number of potion is not zero
    if (sh.get_potion_attack_num() == 1)
    {
        std::cout << "1. Attack +10 (700 Gold) (Available)\n";
    }
    else
    {
        std::cout << "1. Attack +10 (700 Gold) (Sold out)\n";
    }
    if (sh.get_potion_defense_num() == 1)
    {
        std::cout << "2. Defense +5 (700 Gold) (Available)\n";
    }
    else
    {
        std::cout << "2. Defense +5 (700 Gold) (Sold out)\n";
    }
    if (sh.get_potion_exp_num() == 1)
    {
        std::cout << "3. Exp +300 (700 Gold) (Available)\n";
    }
    else
    {
        std::cout << "3. Exp +300 (700 Gold) (Sold out)\n";
    }
    std::cout << "4. Restore HP (500 Gold) (Always available)\n";
    std::cout << "5. Restore MP (500 Gold) (Always available)\n";
    std::cout << "6. Exit shop\n\n";
    std::cout << "=======================================\n";
    while (true)
    {
        std::cout << "> ";
        std::cin >> shop_menu_num;
        if (((shop_menu_num == 1) && (sh.get_potion_attack_num() == 1) && (ch.get_gold() >= 700)) || ((shop_menu_num == 2) && (sh.get_potion_defense_num() == 1) && (ch.get_gold() >= 700)) || ((shop_menu_num == 4) && (ch.get_gold() >= 500)) || ((shop_menu_num == 5) && (ch.get_gold() >= 500)))
        {
            std::cout << "Yout bought an item!\n\n";
            std::cout << "=======================================\n";
            std::cout << "Character status\n";
            std::cout << "Level: " << ch.get_level() << "\n";
            if (shop_menu_num == 1)
            {
                ch.use_money(700);
                sh.buy_potion_attack();
                std::cout << "Attack: " << ch.get_attack() << " => ";
                ch.potion_attack();
                std::cout << ch.get_attack() << "\n";
            }
            else
            {
                std::cout << "Attack: " << ch.get_attack() << "\n";
            }
            if (shop_menu_num == 2)
            {
                ch.use_money(700);
                sh.buy_potion_defense();
                std::cout << "Defense: " << ch.get_defense() << " => ";
                ch.potion_defense();
                std::cout << ch.get_defense() << "\n";
            }
            else
            {
                std::cout << "Defense: " << ch.get_defense() << "\n";
            }
            if (shop_menu_num == 4)
            {
                ch.use_money(500);
                std::cout << "HP: " << ch.get_curr_hp() << " / " << ch.get_max_hp() << " => ";
                ch.restore_hp();
                std::cout << ch.get_curr_hp() << " / " << ch.get_max_hp() << "\n";
            }
            else
            {
                std::cout << "HP: " << ch.get_curr_hp() << " / " << ch.get_max_hp() << "\n";
            }
            if (shop_menu_num == 5)
            {
                ch.use_money(500);
                std::cout << "MP: " << ch.get_curr_mp() << " / " << ch.get_max_mp() << " => ";
                ch.restore_mp();
                std::cout << ch.get_curr_mp() << " / " << ch.get_max_mp() << "\n";
            }
            else
            {
                std::cout << "MP: " << ch.get_curr_mp() << " / " << ch.get_max_mp() << "\n";
            }

            std::cout << "EXP: " << ch.get_curr_exp() << " / " << ch.get_max_exp() << "\n";
            std::cout << "=======================================\n";
            std::cout << "Shop item list\n";
            if (sh.get_potion_attack_num() == 1)
            {
                std::cout << "1. Attack +10 (700 Gold) (Available)\n";
            }
            else
            {
                std::cout << "1. Attack +10 (700 Gold) (Sold out)\n";
            }
            if (sh.get_potion_defense_num() == 1)
            {
                std::cout << "2. Defense +5 (700 Gold) (Available)\n";
            }
            else
            {
                std::cout << "2. Defense +5 (700 Gold) (Sold out)\n";
            }
            if (sh.get_potion_exp_num() == 1)
            {
                std::cout << "3. Exp +300 (700 Gold) (Available)\n";
            }
            else
            {
                std::cout << "3. Exp +300 (700 Gold) (Sold out)\n";
            }
            std::cout << "4. Restore HP (500 Gold) (Always available)\n";
            std::cout << "5. Restore MP (500 Gold) (Always available)\n";
            std::cout << "=======================================\n\n";
            break;
        }
        else if ((shop_menu_num == 3) && (sh.get_potion_exp_num() == 1) && (ch.get_gold() >= 700))
        {

            std::cout << "Yout bought an item!\n\n";
            ch.use_money(700);
            sh.buy_potion_exp();
            ch.level_decision(300);
            std::cout << "Shop item list\n";
            if (sh.get_potion_attack_num() == 1)
            {
                std::cout << "1. Attack +10+5 (700 Gold) (Available)\n";
            }
            else
            {
                std::cout << "1. Attack +10 (700 Gold) (Sold out)\n";
            }
            if (sh.get_potion_defense_num() == 1)
            {
                std::cout << "2. Defense +5 (700 Gold) (Available)\n";
            }
            else
            {
                std::cout << "2. Defense +5 (700 Gold) (Sold out)\n";
            }
            std::cout << "3. Exp +300 (700 Gold) (Sold out)\n";
            std::cout << "4. Restore HP (500 Gold) (Always available)\n";
            std::cout << "5. Restore MP (500 Gold) (Always available)\n";
            std::cout << "=======================================\n\n";
            break;
        }
        else if (((shop_menu_num == 1) && (sh.get_potion_attack_num() == 0)) || ((shop_menu_num == 2) && (sh.get_potion_defense_num() == 0)) || ((shop_menu_num == 3) && (sh.get_potion_exp_num() == 0)))
        {
            std::cout << "Selected item is not available...\n\n";
        }
        else if (((shop_menu_num == 1) && (sh.get_potion_attack_num() == 1) && (ch.get_gold() < 700)) || ((shop_menu_num == 2) && (sh.get_potion_defense_num() == 1) && (ch.get_gold() < 700)) || ((shop_menu_num == 3) && (sh.get_potion_exp_num() == 1) && (ch.get_gold() < 700)) || ((shop_menu_num == 4) && (ch.get_gold() < 500)) || ((shop_menu_num == 5) && (ch.get_gold() < 500)))
        {
            std::cout << "You do not have enough gold...\n\n";
        }
        else if (shop_menu_num == 6)
        {
            break;
        }
        // if an integer other than 1 to 6 is entered, input again.
        else
        {
            continue;
        }
    }
}