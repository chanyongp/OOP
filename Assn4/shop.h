#ifndef SHOP_
#define SHOP_ // in order to prevent duplication

class Shop
{
private:
    // potion numbers
    int potion_attack_num;
    int potion_defense_num;
    int potion_exp_num;

public:
    Shop();    // constructor
    ~Shop(){}; // destructor
    // used in shopping()
    int get_potion_attack_num();
    int get_potion_defense_num();
    int get_potion_exp_num();
    void buy_potion_attack();
    void buy_potion_defense();
    void buy_potion_exp();
};

#endif