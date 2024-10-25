#pragma once
#include "Bird.h"

class AssassinDuck : public Bird // Derived class of Bird
{
protected:
private:
    // number of assassination limit
    int assassin_num;

public:
    // Default constructor
    AssassinDuck();
    // destructor
    ~AssassinDuck();
    // AssassinDuck's skill
    void Skill(BirdList *);
    // get AssassinDuck's type
    std::string GetBirdType() const;
};
