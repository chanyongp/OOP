#include "MorticianGoose.h"
#include "BirdList.h"
#include <iostream>
#include <string>
// Default constructor
MorticianGoose::MorticianGoose()
{
    // initialization
    killedbird = false;
    isdead = false;
    votednum = 0;
}
// destructor
MorticianGoose::~MorticianGoose()
{
}
// MorticianGoose's skill
void MorticianGoose::Skill(BirdList *birdlist)
{
    // get input to search killed bird
    char searchyn;
    std::cout << "염습을 사용하시겠습니까? [Y/N]: ";
    std::cin >> searchyn;
    if (searchyn == 'Y')
    {
        if (birdlist->searchKilledBirdNode() == true)
        {
            // if killed bird exists, find out its role name
            std::string name;
            std::cout << "염습하고 싶은 플레이어의 이름을 입력하세요: ";
            std::cin >> name;
            std::cout << name << "의 역할은 " << birdlist->searchKilledBirdNode(name) << "입니다." << std::endl;
        }
        else
        {
            // if there's no killed bird
            std::cout << "염습 가능 대상이 없습니다." << std::endl;
        }
    }
    else if (searchyn == 'N')
    {
    }
}
// get MorticianGoose's type
std::string MorticianGoose::GetBirdType() const
{
    return "장의사 거위";
}