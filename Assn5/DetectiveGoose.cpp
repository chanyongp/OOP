#include "DetectiveGoose.h"
#include "BirdList.h"
#include <iostream>
#include <string>
// Default constructor
DetectiveGoose::DetectiveGoose()
{
    // initialization
    killedbird = false;
    isdead = false;
    votednum = 0;
}
// destructor
DetectiveGoose::~DetectiveGoose()
{
}
// DetectiveGoose's skill
void DetectiveGoose::Skill(BirdList *birdlist)
{
    // get input to search or not
    char searchyn;
    std::cout << "조사를 사용하시겠습니까? [Y/N]: ";
    std::cin >> searchyn;
    if (searchyn == 'Y')
    {
        // get input for name and find out if it killed somebody
        std::string name;
        std::cout << "조사하고 싶은 플레이어의 이름을 입력하세요: ";
        std::cin >> name;
        if (birdlist->searchBirdNode(name) == true)
        {
            std::cout << name << "은(는) 이번 라운드에 누군가를 무참히 살해하였습니다..!" << std::endl;
        }
        else
        {
            std::cout << name << "은(는) 이번 라운드에 아무도 해치지 않았습니다." << std::endl;
        }
    }
    else if (searchyn == 'N')
    {
    }
}
// get DetectiveGoose's type
std::string DetectiveGoose::GetBirdType() const
{
    return "탐정 거위";
}