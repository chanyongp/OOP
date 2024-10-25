#pragma once
#include "Bird.h"

class DetectiveGoose : public Bird // Derived class of Bird
{
protected:
private:
public:
    // Default constructor
    DetectiveGoose();
    // destructor
    ~DetectiveGoose();
    // DetectiveGoose's skill
    void Skill(BirdList *);
    // get DetectiveGoose's type
    std::string GetBirdType() const;
};
