#ifndef CHAR_
#define CHAR_ // in order to prevent duplication
#include <iostream>
#include <string>

class Character
{
private:
    // character status values
    int attack;
    int defense;
    int gold;
    int level;
    int max_hp;
    int curr_hp;
    int max_mp;
    int curr_mp;
    int max_exp;
    int curr_exp;
    // it is used for boss fight
    int victory;

public:
    Character();    // constructor
    ~Character(){}; // default destructor
    void show_status();
    int get_attack();
    int get_defense();
    int get_gold();
    int get_level();
    int get_max_hp();
    int get_curr_hp();
    int get_max_mp();
    int get_curr_mp();
    int get_max_exp();
    int get_curr_exp();
    int get_victory();
    // used in random event in judge()
    void random_hurt();
    void random_heal();
    void earn_money(int money); // used in both judge() and fight()
    void get_hurt(int damage);
    // used in fight event in fight()
    int attack_basic(int mondef);
    int attack_skill(int mondef);
    int attack_fire(int mondef, std::string montype);
    int attack_grass(int mondef, std::string montype);
    int attack_water(int mondef, std::string montype);
    void youwin();
    // used in shopping()
    void use_money(int money);
    void restore_hp();
    void restore_mp();
    void potion_attack();
    void potion_defense();
    void potion_exp();
    // used in level up decision
    void level_decision(int exp);
};

#endif