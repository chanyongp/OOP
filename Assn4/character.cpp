#include "character.h"
#include "monster.h"
#include <cmath>
#include <iostream>
#include <string>

Character::Character() // definition of class Character's constructor
{
    attack = 10;
    defense = 2;
    gold = 0;
    level = 1;
    max_hp = 100;
    curr_hp = 100;
    max_mp = 20;
    curr_mp = 20;
    max_exp = 100;
    curr_exp = 0;
    victory = 0;
}

void Character::show_status() // print character's status
{
    std::cout << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Attack: " << attack << "\n";
    std::cout << "Defense: " << defense << "\n";
    std::cout << "Gold: " << gold << "\n";
    std::cout << "HP: " << curr_hp << " / " << max_hp << "\n";
    std::cout << "MP: " << curr_mp << " / " << max_mp << "\n";
    std::cout << "EXP: " << curr_exp << " / " << max_exp << "\n";
    std::cout << "\n";
}
int Character::get_attack() // return character's attack
{
    return attack;
}
int Character::get_defense() // return character's defense
{
    return defense;
}
int Character::get_gold() // return character's gold
{
    return gold;
}

int Character::get_level() // return character's level
{
    return level;
}
int Character::get_max_hp() // return character's max_hp
{
    return max_hp;
}
int Character::get_curr_hp() // return character's curr_hp
{
    return curr_hp;
}
int Character::get_max_mp() // return character's max_mp
{
    return max_mp;
}
int Character::get_curr_mp() // return character's curr_mp
{
    return curr_mp;
}
int Character::get_max_exp() // return character's max_exp
{
    return max_exp;
}
int Character::get_curr_exp() // return character's curr_exp
{
    return curr_exp;
}
int Character::get_victory() // return character's victory value
{
    return victory;
}
// Suppose character is in RANDOM
void Character::random_hurt() // reduce 30% of character's current hp and round off
{
    curr_hp *= 0.7;
    curr_hp = floor(curr_hp + 0.5);
}
void Character::random_heal() // recover 30% of character's current hp and round off
{
    curr_hp *= 1.3;
    curr_hp = floor(curr_hp + 0.5);
    if (curr_hp >= max_hp)
    {
        curr_hp = max_hp;
    }
}
void Character::earn_money(int money) // add money to character's gold
{
    gold += money;
}
void Character::get_hurt(int damage) // reduce character's current hp by damage
{
    curr_hp -= damage;
}

int Character::attack_basic(int mondef) // return meele attack's damage
{
    // damage=(character's attack)-(monster's defense)
    if ((attack - mondef) > 0)
    {
        return attack - mondef;
    }
    else
    {
        return 0;
    }
}
int Character::attack_skill(int mondef) // return magic attack's damage
{
    curr_mp -= 15; // reduce current mp by 15
    // damage=1.5*(character's attack)-(monster's defense)
    if ((1.5 * attack - mondef) > 0)
    {
        return 1.5 * attack - mondef;
    }
    else
    {
        return 0;
    }
}
int Character::attack_fire(int mondef, std::string montype)
{
    curr_mp -= 15; // reduce current mp by 15
    // damage=2*(character's attack)-(monster's defense) if type of monster is "grass"
    if ((montype == "grass") && (2 * attack - mondef) > 0)
    {
        return 2 * attack - mondef;
    }
    // otherwise (character's attack)-(monster's defense)
    else if ((montype != "grass") && (attack - mondef) > 0)
    {
        return attack - mondef;
    }
    else
    {
        return 0;
    }
}
int Character::attack_grass(int mondef, std::string montype)
{
    curr_mp -= 15; // reduce current mp by 15
    // damage=2*(character's attack)-(monster's defense) if type of monster is "water"
    if ((montype == "water") && (2 * attack - mondef) > 0)
    {
        return 2 * attack - mondef;
    }
    // otherwise (character's attack)-(monster's defense)
    else if ((montype != "water") && (attack - mondef) > 0)
    {
        return attack - mondef;
    }
    else
    {
        return 0;
    }
}
int Character::attack_water(int mondef, std::string montype)
{
    curr_mp -= 15; // reduce current mp by 15
    // damage=2*(character's attack)-(monster's defense) if type of monster is "fire"
    if ((montype == "fire") && (2 * attack - mondef) > 0)
    {
        return 2 * attack - mondef;
    }
    // otherwise (character's attack)-(monster's defense)
    else if ((montype != "fire") && (attack - mondef) > 0)
    {
        return attack - mondef;
    }
    else
    {
        return 0;
    }
}

void Character::youwin() // change victory value 0 -> 1
{
    victory = 1;
}
void Character::use_money(int money) // subtract money to character's gold
{
    gold -= money;
}
void Character::restore_hp() // assign max_hp to curr_hp
{
    curr_hp = max_hp;
}
void Character::restore_mp() // assign max_mp to curr_mp
{
    curr_mp = max_mp;
}
void Character::potion_attack() // add 10 to attack
{
    attack += 10;
}
void Character::potion_defense() // add 5 to defense
{
    defense += 5;
}
void Character::potion_exp() // add 300 to exp
{
    curr_exp += 300;
}
void Character::level_decision(int exp)
{
    if (curr_exp + exp >= max_exp) // if total exp>=max_exp, level up
    {
        std::cout << "Level up!\n";
        std::cout << "=======================================\n";
        std::cout << "Character status\n";
        std::cout << "Level: " << level << " => ";
        int tot_exp = curr_exp + exp;  // for calculation
        int tot_exp2 = curr_exp + exp; // in order to print previus exp
        int max_exp_before = max_exp;  // in order to print previus max_exp
        int level_before = level;      // for calculation
        // while tot_exp>=max_exp, add 1 to level and update tot_exp and max_exp
        while (tot_exp >= max_exp)
        {
            level += 1;
            tot_exp -= max_exp;
            max_exp = level * 100;
        }
        curr_exp = tot_exp;
        std::cout << level << "\n";
        std::cout << "Attack: " << attack << " => ";
        attack += 3 * (level - level_before); // add 3*(level difference) to attack
        std::cout << attack << "\n";
        std::cout << "Defense: " << defense << " => ";
        defense += (level - level_before); // add (level difference) to defense
        std::cout << defense << "\n";
        std::cout << "HP: " << curr_hp << " / " << max_hp << " => ";
        max_hp += 50 * (level - level_before); // add 50*(level difference) to max_hp and restore curr_hp
        curr_hp = max_hp;
        std::cout << curr_hp << " / " << max_hp << "\n";
        std::cout << "MP: " << curr_mp << " / " << max_mp << " => ";
        max_mp += 10 * (level - level_before); // add 10*(level difference) to max_hp and restore curr_hp
        curr_mp = max_mp;
        std::cout << curr_mp << " / " << max_mp << "\n";
        std::cout << "EXP: " << tot_exp2 << " / " << max_exp_before << " => " << curr_exp << " / " << max_exp << "\n";
        std::cout << "=======================================\n";
    }
    else // if total exp<max_exp, just show change of exp
    {
        std::cout << "=======================================\n";
        std::cout << "Character status\n";
        std::cout << "Level: " << level << "\n";
        std::cout << "Attack: " << attack << "\n";
        std::cout << "Defense: " << defense << "\n";
        std::cout << "HP: " << curr_hp << " / " << max_hp << "\n";
        std::cout << "MP: " << curr_mp << " / " << max_mp << "\n";
        std::cout << "EXP: " << curr_exp << " / " << max_exp << " => ";
        curr_exp += exp;
        std::cout << curr_exp << " / " << max_exp << "\n";
        std::cout << "=======================================\n";
    }
}
