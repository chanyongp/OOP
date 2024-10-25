#include "Duck.h"
#include "BirdList.h"
#include <iostream>

// Default constructor
Duck::Duck()
{
    // initialization
    killedbird = false;
    isdead = false;
    votednum = 0;
}
// destructor
Duck::~Duck()
{
}
// Duck's skill
void Duck::Skill(BirdList *bird_list)
{
    // get input to decide killing or not
    char murder;
    std::cout << "살조를 사용하시겠습니까? [Y/N]: ";
    std::cin >> murder;
    if (murder == 'Y')
    {
        if (bird_list->getKillNum() == bird_list->getKillNumLimit())
            // if number of killing equals number of killing limit, it cannot kill
            std::cout << "라운드당 오리 진영의 살조 제한 횟수에 도달하였습니다." << std::endl;
        else
        {
            // get input for birdname and kill that bird
            std::string murderedbirdname;
            std::cout << "살해하고 싶은 플레이어의 이름을 입력하세요: ";
            std::cin >> murderedbirdname;
            bird_list->KillBirdNode(murderedbirdname);
            std::cout << "전체 메시지: " << murderedbirdname << "이(가) 무참히 살해당하였습니다.." << std::endl;
            bird_list->addKillNum();
            killedbird = true;
        }
    }
    else if (murder == 'N')
    {
    }
}
// get Duck's type
std::string Duck::GetBirdType() const
{
    return "오리";
}