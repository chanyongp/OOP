#pragma once
#include "Bird.h"

class MorticianGoose : public Bird // Derived class of Bird
{
protected:
private:
public:
    // Default constructor
    MorticianGoose();
    // destructor
    ~MorticianGoose();
    // MorticianGoose's skill
    void Skill(BirdList *);
    // get MorticianGoose's type
    std::string GetBirdType() const;
};
