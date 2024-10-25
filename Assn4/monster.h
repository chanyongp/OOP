#ifndef MONSTER_
#define MONSTER_ // in order to prevent duplication
#include <iostream>
#include <string>

class Monster
{
private:
    // monster status values
    int max_hp;
    int curr_hp;
    int attack;
    int defense;
    int gold;
    int exp;
    int boss_decision; // in order to classify if monster is boss or not
    std::string type;

public:
    Monster(int x, int y);             // constructor
    Monster(int hp, int atk, int def); // constructor overloading
    ~Monster(){};                      // default destructor
    // used in fight event in fight()
    int get_attack();
    int get_defense();
    int get_max_hp();
    int get_curr_hp();
    int get_gold();
    int get_exp();
    int get_boss_decision();
    std::string get_type();
    void get_hurt(int damage);
    int attack_basic(int chdef);
};

#endif