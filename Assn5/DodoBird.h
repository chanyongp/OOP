#pragma once
#include "Bird.h"

class DodoBird : public Bird // Derived class of Bird
{
protected:
private:
public:
    // Default constructor
    DodoBird();
    // Default constructor
    ~DodoBird();
    // DodoBird's skill
    void Skill(BirdList *);
    // get DodoBird's type
    std::string GetBirdType() const;
};
