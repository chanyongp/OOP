#include "Falcon.h"
#include "BirdList.h"
#include <iostream>
#include <string>
// Default constructor
Falcon::Falcon()
{
    killedbird = false;
    isdead = false;
    votednum = 0;
}
// destructor
Falcon::~Falcon()
{
}
// Falcon's skill
void Falcon::Skill(BirdList *bird_list)
{
    // get input to decide killing or not
    char murder;
    std::cout << "살조를 사용하시겠습니까? [Y/N]: ";
    std::cin >> murder;
    if (murder == 'Y')
    {
        // get input for birdname and kill that bird
        std::string murderedbirdname;
        std::cout << "살해하고 싶은 플레이어의 이름을 입력하세요: ";
        std::cin >> murderedbirdname;
        bird_list->KillBirdNode(murderedbirdname);
        std::cout << "전체 메시지: " << murderedbirdname << "이(가) 무참히 살해당하였습니다.." << std::endl;
        killedbird = true;
    }
    else if (murder == 'N')
    {
    }
}
// get Falcon's type
std::string Falcon::GetBirdType() const
{
    return "송골매";
}