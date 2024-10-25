#pragma once
#include "Bird.h"

class Falcon : public Bird // Derived class of Bird
{
protected:
private:
public:
    // Default constructor
    Falcon();
    // destructor
    ~Falcon();
    // Falcon's skill
    void Skill(BirdList *);
    // get Falcon's type
    std::string GetBirdType() const;
};
