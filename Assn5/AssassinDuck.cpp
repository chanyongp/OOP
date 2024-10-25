#include "AssassinDuck.h"
#include "BirdList.h"
#include <iostream>

// Default constructor
AssassinDuck::AssassinDuck()
{
    // initialization
    killedbird = false;
    isdead = false;
    votednum = 0;
    assassin_num = 0;
}
// destructor
AssassinDuck::~AssassinDuck()
{
}
// AssassinDuck's skill
void AssassinDuck::Skill(BirdList *bird_list)
{
    // get input to decide assassination
    char murder;
    std::cout << "암살을 사용하시겠습니까? [Y/N]: ";
    std::cin >> murder;
    if (murder == 'Y')
    {
        if (assassin_num == 2)
            // if number of assassination equals to number of assassination limit, it cannot assassinate
            std::cout << "더 이상 암살 능력을 사용할 수 없습니다!" << std::endl;
        else
        {
            // get input for name and role number
            std::string murderedbirdname;
            int act_num;
            std::cout << "암살하고 싶은 플레이어의 이름을 입력하세요: ";
            std::cin >> murderedbirdname;
            std::cout << "암살하고 싶은 플레이어의 역할 번호를 입력하세요: ";
            std::cin >> act_num;
            if (bird_list->getBirdActNum(murderedbirdname) == act_num)
            {
                // if role number is correct, kill that bird
                bird_list->KillBirdNode(murderedbirdname);
                std::cout << "전체 메시지: " << murderedbirdname << "이(가) 무참히 살해당하였습니다.." << std::endl;
                assassin_num += 1;
                killedbird = true;
            }
            else
            {
                // if role number is incorrect, kill itself
                bird_list->KillBirdNode(player_name);
                std::cout << "전체 메시지: " << player_name << "은(는) 극단적 선택을 하였습니다." << std::endl;
                return;
            }
        }
    }
    else if (murder == 'N')
    {
    }

    // get input to decide killing or not
    char murder2;
    std::cout << "살조를 사용하시겠습니까? [Y/N]: ";
    std::cin >> murder2;
    if (murder2 == 'Y')
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
        }
    }
    else if (murder2 == 'N')
    {
    }
}
// get AssassinDuck's type
std::string AssassinDuck::GetBirdType() const
{
    return "암살자 오리";
}