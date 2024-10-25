#include "monster.h"
#include "character.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

Monster::Monster(int x, int y) // definition of class Monster's constructor
{
    boss_decision = 0;
    srand(time(NULL));      // in order to make a random number every time the program starts
    int difficulty = x + y; // difficulty=manhattan distance
    // monster's specifications are reset according to difficulties
    max_hp = 50 + (difficulty * 5);
    curr_hp = 50 + (difficulty * 5);
    attack = 5 + (difficulty * 2);
    defense = 2 + (difficulty / 2);
    gold = 100 + difficulty * 10;
    exp = 100 + difficulty * 10;
    int randomidx = int(rand() % 4); // in order to randomly choose monster's type
    std::string typelist[4];
    typelist[0] = "grass";
    typelist[1] = "fire";
    typelist[2] = "water";
    typelist[3] = "none";
    type = typelist[randomidx]; // type is randomly choosed
}
Monster::Monster(int hp, int atk, int def) // class overloading
{
    max_hp = hp;
    curr_hp = hp;
    attack = atk;
    defense = def;
    boss_decision = 1;
    srand(time(NULL));               // in order to make a random number every time the program starts
    int randomidx = int(rand() % 4); // in order to randomly choose monster's type
    std::string typelist[4];
    typelist[0] = "grass";
    typelist[1] = "fire";
    typelist[2] = "water";
    typelist[3] = "none";
    type = typelist[randomidx]; // type is randomly choosed
}

int Monster::get_attack() // return monster's attack
{
    return attack;
}
int Monster::get_defense() // return monster's defense
{
    return defense;
}
int Monster::get_max_hp() // return monster's maximum hp
{
    return max_hp;
}
int Monster::get_curr_hp() // return monster's current hp
{
    return curr_hp;
}
int Monster::get_gold() // return monster's gold for reward
{
    return gold;
}
int Monster::get_exp() // return monster's exp for reward
{
    return exp;
}
int Monster::get_boss_decision() // to verify whether monster is boss or not
{
    return boss_decision;
}
std::string Monster::get_type() // return monster's type
{
    return type;
}
void Monster::get_hurt(int damage) // reduce monster's current hp by damage
{
    curr_hp -= damage;
}
int Monster::attack_basic(int chdef) // return monster's attack damage
{
    // damage=(monster's attack)-(character's defense)
    if ((attack - chdef) > 0)
    {
        return attack - chdef;
    }
    else
    {
        return 0;
    }
}

void fight(Character &ch, Monster &mon) // character fights with monster
{
    std::cout << "Wild monster appeared!\n\n";
    // fight continues unless one of them die.
    while (true)
    {
        // show character's status and monster's status
        std::cout << "=======================================\n";
        std::cout << "Character status\n";
        std::cout << "Level: " << ch.get_level() << "\n";
        std::cout << "Attack: " << ch.get_attack() << "\n";
        std::cout << "Defense: " << ch.get_defense() << "\n";
        std::cout << "HP: " << ch.get_curr_hp() << " / " << ch.get_max_hp() << "\n";
        std::cout << "MP: " << ch.get_curr_mp() << " / " << ch.get_max_mp() << "\n";
        std::cout << "EXP: " << ch.get_curr_exp() << " / " << ch.get_max_exp() << "\n";
        std::cout << "=======================================\n";
        std::cout << "Monster status\n";
        std::cout << "Attack: " << mon.get_attack() << "\n";
        std::cout << "Defense: " << mon.get_defense() << "\n";
        std::cout << "HP: " << mon.get_curr_hp() << " / " << mon.get_max_hp() << "\n";
        std::cout << "=======================================\n";
        std::cout << "Choose your action\n";
        std::cout << "1. Meele attack\n";
        std::cout << "2. Magic attack\n";
        std::cout << "3. Fire magic attack\n";
        std::cout << "4. Grass magic attack\n";
        std::cout << "5. Water magic attack\n";
        int fight_menu_num;
        while (true)
        {
            std::cout << "> ";
            std::cin >> fight_menu_num;
            if (fight_menu_num == 1) // character does meele attack and monster attacks
            {
                int damage_mon_got = ch.attack_basic(mon.get_defense());
                int damage_ch_got = mon.attack_basic(ch.get_defense());
                mon.get_hurt(damage_mon_got);
                ch.get_hurt(damage_ch_got);
                std::cout << "\n\nYou hit the monster with " << damage_mon_got << " damage!\n";
                std::cout << "Monster hit you with " << damage_ch_got << " damage!\n";
                break;
            }
            else if (fight_menu_num == 2) // character does magic attack and monster attacks
            {
                if (ch.get_curr_mp() >= 15) // character does magic attack if character's mp>=15
                {
                    int damage_mon_got = ch.attack_skill(mon.get_defense());
                    int damage_ch_got = mon.attack_basic(ch.get_defense());
                    mon.get_hurt(damage_mon_got);
                    ch.get_hurt(damage_ch_got);
                    std::cout << "\n\nYou hit the monster with " << damage_mon_got << " damage!\n";
                    std::cout << "Monster hit you with " << damage_ch_got << " damage!\n";
                    break;
                }
                else // if character's mp<15, character cannot do magic attack
                {
                    int damage_ch_got = mon.attack_basic(ch.get_defense());
                    ch.get_hurt(damage_ch_got);
                    std::cout << "\n\nNot enough MP...\n";
                    std::cout << "Monster hit you with " << damage_ch_got << " damage!\n";
                    break;
                }
            }
            else if (fight_menu_num == 3) // character does fire magic attack and monster attacks
            {
                if (ch.get_curr_mp() >= 15) // character does fire magic attack if character's mp>=15
                {
                    int damage_mon_got = ch.attack_fire(mon.get_defense(), mon.get_type());
                    int damage_ch_got = mon.attack_basic(ch.get_defense());
                    mon.get_hurt(damage_mon_got);
                    ch.get_hurt(damage_ch_got);
                    std::cout << "\n\nYou hit the monster with " << damage_mon_got << " damage!\n";
                    std::cout << "Monster hit you with " << damage_ch_got << " damage!\n";
                    break;
                }
                else // if character's mp<15, character cannot do fire magic attack
                {
                    int damage_ch_got = mon.attack_basic(ch.get_defense());
                    ch.get_hurt(damage_ch_got);
                    std::cout << "\n\nNot enough MP...\n";
                    std::cout << "Monster hit you with " << damage_ch_got << " damage!\n";
                    break;
                }
            }
            else if (fight_menu_num == 4) // character does grass magic attack and monster attacks
            {
                if (ch.get_curr_mp() >= 15) // character does grass magic attack if character's mp>=15
                {
                    int damage_mon_got = ch.attack_grass(mon.get_defense(), mon.get_type());
                    int damage_ch_got = mon.attack_basic(ch.get_defense());
                    mon.get_hurt(damage_mon_got);
                    ch.get_hurt(damage_ch_got);
                    std::cout << "\n\nYou hit the monster with " << damage_mon_got << " damage!\n";
                    std::cout << "Monster hit you with " << damage_ch_got << " damage!\n";
                    break;
                }
                else // if character's mp<15, character cannot do grass magic attack
                {
                    int damage_ch_got = mon.attack_basic(ch.get_defense());
                    ch.get_hurt(damage_ch_got);
                    std::cout << "\n\nNot enough MP...\n";
                    std::cout << "Monster hit you with " << damage_ch_got << " damage!\n";
                    break;
                }
            }
            else if (fight_menu_num == 5) // character does water magic attack and monster attacks
            {
                if (ch.get_curr_mp() >= 15) // character does water magic attack if character's mp>=15
                {
                    int damage_mon_got = ch.attack_water(mon.get_defense(), mon.get_type());
                    int damage_ch_got = mon.attack_basic(ch.get_defense());
                    mon.get_hurt(damage_mon_got);
                    ch.get_hurt(damage_ch_got);
                    std::cout << "\n\nYou hit the monster with " << damage_mon_got << " damage!\n";
                    std::cout << "Monster hit you with " << damage_ch_got << " damage!\n";
                    break;
                }
                else // if character's mp<15, character cannot do water magic attack
                {
                    int damage_ch_got = mon.attack_basic(ch.get_defense());
                    ch.get_hurt(damage_ch_got);
                    std::cout << "\n\nNot enough MP...\n";
                    std::cout << "Monster hit you with " << damage_ch_got << " damage!\n";
                    break;
                }
            }
            // if an integer other than 1 to 5 is entered, input again.
            else
            {
                continue;
            }
        }
        // if character's current hp<=0, character is dead
        if (ch.get_curr_hp() <= 0)
        {
            std::cout << "\n\nYou died...";
            break;
        }
        // if monster's current hp<=0, monster is dead and character earns reward
        if (mon.get_curr_hp() <= 0)
        {
            if (mon.get_boss_decision() == 0) // if monster is not a boss
            {
                std::cout << "\nYou defeated the monster!\n";
                std::cout << "Reward: " << mon.get_gold() << " Gold, " << mon.get_exp() << " EXP\n\n";
                ch.earn_money(mon.get_gold());    // character earns monster's gold
                ch.level_decision(mon.get_exp()); // character earns monster's exp
                break;
            }
            else // if monster is a boss monster
            {
                std::cout << "\nYou defeated the boss monster!\nCongratulation! You win!";
                ch.youwin(); // end game
                break;
            }
        }
    }
}