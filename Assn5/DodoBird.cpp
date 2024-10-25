#include "DodoBird.h"

#include <iostream>
// Default constructor
DodoBird::DodoBird()
{
    killedbird = false;
    isdead = false;
    votednum = 0;
}
// destructor
DodoBird::~DodoBird()
{
}
// DodoBird's skill
void DodoBird::Skill(BirdList *)
{
    std::cout << "당신은 능력이 없는 조류입니다." << std::endl;
}
// get DodoBird's type
std::string DodoBird::GetBirdType() const
{
    return "도도새";
}