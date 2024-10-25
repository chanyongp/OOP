#pragma once
#include "Bird.h"

class Duck : public Bird // Derived class of Bird
{
protected:
private:
public:
    // Default constructor
    Duck();
    // destructor
    ~Duck();
    // Duck's skill
    void Skill(BirdList *);
    // get Duck's type
    std::string GetBirdType() const;
};
