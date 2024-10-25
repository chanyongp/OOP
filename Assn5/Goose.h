#pragma once
#include "Bird.h"

class Goose : public Bird // Derived class of Bird
{
protected:
private:
public:
    // Default constructor
    Goose();
    // destructor
    ~Goose();
    // Goose's skill
    void Skill(BirdList *);
    // get Goose's type
    std::string GetBirdType() const;
};
