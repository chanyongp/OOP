#include "GGD.h"
#include "BirdList.h"
#include "BirdNode.h"
#include "Macro.h"
#include "Falcon.h"
#include "AssassinDuck.h"
#include "Duck.h"
#include "DetectiveGoose.h"
#include "MorticianGoose.h"
#include "Goose.h"
#include "DodoBird.h"
#include <iostream>
#include <string>

GGD::GGD() // constructor
{
	// dynamic allocation
	bird_list = new BirdList(); // bird_list 동적 할당 추가
	// set bird_list's head, tail and connect them
	BirdNode *head = new BirdNode;
	bird_list->SetHead(head);
	BirdNode *tail = new BirdNode;
	bird_list->SetTail(tail);
	bird_list->GetHead()->SetNext(bird_list->GetTail());

	// initialization
	kill_num_limit = 1;
	round_num = 1;
	Falcon_num = 0;
	Dodo_num = 0;
	alive_goose_num = 0;
	alive_duck_num = 0;
	dodoiskilled = false;
	alive_falcon_num = 0;
	alive_bird_num = 0;
}
GGD::~GGD() // destructor
{
	// delete all nodes
	BirdNode *curNode = bird_list->GetHead();
	while (true)
	{
		// delete curNode's next node until it is tail
		if (curNode->GetNext() == bird_list->GetTail())
		{
			break;
		}
		BirdNode *deleteNode = curNode->GetNext();
		curNode->SetNext(deleteNode->GetNext());
		delete deleteNode;
	}
	// then delete head and tail
	delete bird_list->GetHead();
	delete bird_list->GetTail();
}
// print game setting screeen and get input for setting
void GGD::GameStart()
{
	int select;
	bool game_start = false;
	// print menu and get input while game_start is false
	while (!game_start)
	{
		// print game setting menu
		std::cout << "------------게임 설정 메뉴-------------\n";
		std::cout << "1. 플레이어 추가\n";
		std::cout << "2. 라운드당 오리 진영 살조 제한 횟수 설정\n";
		std::cout << "3. 게임 시작하기!\n";
		std::cout << "---------------------------------------\n";
		std::cout << "메뉴 번호를 입력하세요: ";
		std::cin >> select;
		// get input for menu number
		switch (select)
		{
		case 1:
			// add player
			AddPlayer();
			break;
		case 2:
			// get input and decide number of killing limit
			std::cout << "값을 입력하세요: ";
			std::cin >> kill_num_limit;
			bird_list->setKillNumLimit(kill_num_limit);
			break;
		case 3:
			// cannot start game if there's no player
			if (bird_list->GetHead()->GetNext() == bird_list->GetTail())
			{
				std::cout << "게임을 시작할 수 없습니다!!\n";
				break;
			}
			// else start game
			std::cout << "게임 시작!!\n";
			bird_list->setKillNumLimit(kill_num_limit);
			bird_list->setKillNum(0);
			// assign true to game_start to escape repetition.
			game_start = true;
			break;
		default:
			break;
		}
	}
}
// perform the voting function, using the output of the round and the skill of each bird.
void GGD::RoundProgress()
{

	std::cout << "----------------Round " << round_num << "----------------\n";
	BirdNode *curNode = bird_list->GetHead()->GetNext();
	while (true) // Initialize murder, assassination every round
	{
		// use sequential search to initialize
		curNode->GetBird()->setKilledBird(false);
		if (curNode->GetNext() == bird_list->GetTail())
		{
			break;
		}
		curNode = curNode->GetNext();
	}
	while (true) // each alive bird uses its skill
	{
		// skill order is Falcon, AssassinDuck, Duck, DetectiveGoose, MorticianGoose, Goose, and DodoBird
		// Falcon's turn to use skill
		curNode = bird_list->GetHead()->GetNext();
		while (true)
		{
			// use sequential search to print player's name, role and execute skill
			if (curNode->GetBird()->GetBirdType() == "송골매" && curNode->GetBird()->getIsDead() == false)
			{
				std::cout << curNode->GetBird()->GetPlayerName() << "님 당신은 " << curNode->GetBird()->GetBirdType() << "입니다.\n";
				curNode->GetBird()->Skill(bird_list);
				break;
			}
			if (curNode->GetNext() == bird_list->GetTail())
			{
				break;
			}
			curNode = curNode->GetNext();
		}
		// AssassinDuck's turn to use skill
		curNode = bird_list->GetHead()->GetNext();
		while (true)
		{
			// use sequential search to print player's name, role and execute skill
			if (curNode->GetBird()->GetBirdType() == "암살자 오리" && curNode->GetBird()->getIsDead() == false)
			{
				std::cout << curNode->GetBird()->GetPlayerName() << "님 당신은 " << curNode->GetBird()->GetBirdType() << "입니다.\n";
				curNode->GetBird()->Skill(bird_list);
			}
			if (curNode->GetNext() == bird_list->GetTail())
			{
				break;
			}
			curNode = curNode->GetNext();
		}
		// Duck's turn to use skill
		curNode = bird_list->GetHead()->GetNext();
		while (true)
		{
			// use sequential search to print player's name, role and execute skill
			if (curNode->GetBird()->GetBirdType() == "오리" && curNode->GetBird()->getIsDead() == false)
			{
				std::cout << curNode->GetBird()->GetPlayerName() << "님 당신은 " << curNode->GetBird()->GetBirdType() << "입니다.\n";
				curNode->GetBird()->Skill(bird_list);
			}
			if (curNode->GetNext() == bird_list->GetTail())
			{
				break;
			}
			curNode = curNode->GetNext();
		}
		// DetectiveGoose's turn to use skill
		curNode = bird_list->GetHead()->GetNext();
		while (true)
		{
			// use sequential search to print player's name, role and execute skill
			if (curNode->GetBird()->GetBirdType() == "탐정 거위" && curNode->GetBird()->getIsDead() == false)
			{
				std::cout << curNode->GetBird()->GetPlayerName() << "님 당신은 " << curNode->GetBird()->GetBirdType() << "입니다.\n";
				curNode->GetBird()->Skill(bird_list);
			}
			if (curNode->GetNext() == bird_list->GetTail())
			{
				break;
			}
			curNode = curNode->GetNext();
		}
		// MorticianGoose's turn to use skill
		curNode = bird_list->GetHead()->GetNext();
		while (true)
		{
			// use sequential search to print player's name, role and execute skill
			if (curNode->GetBird()->GetBirdType() == "장의사 거위" && curNode->GetBird()->getIsDead() == false)
			{
				std::cout << curNode->GetBird()->GetPlayerName() << "님 당신은 " << curNode->GetBird()->GetBirdType() << "입니다.\n";
				curNode->GetBird()->Skill(bird_list);
			}
			if (curNode->GetNext() == bird_list->GetTail())
			{
				break;
			}
			curNode = curNode->GetNext();
		}
		// Goose's turn to use skill
		curNode = bird_list->GetHead()->GetNext();
		while (true)
		{
			// use sequential search to print player's name, role and execute skill
			if (curNode->GetBird()->GetBirdType() == "거위" && curNode->GetBird()->getIsDead() == false)
			{
				std::cout << curNode->GetBird()->GetPlayerName() << "님 당신은 " << curNode->GetBird()->GetBirdType() << "입니다.\n";
				curNode->GetBird()->Skill(bird_list);
			}
			if (curNode->GetNext() == bird_list->GetTail())
			{
				break;
			}
			curNode = curNode->GetNext();
		}
		// DodoBird's turn to use skill
		curNode = bird_list->GetHead()->GetNext();
		while (true)
		{
			// use sequential search to print player's name, role and execute skill
			if (curNode->GetBird()->GetBirdType() == "도도새" && curNode->GetBird()->getIsDead() == false)
			{
				std::cout << curNode->GetBird()->GetPlayerName() << "님 당신은 " << curNode->GetBird()->GetBirdType() << "입니다.\n";
				curNode->GetBird()->Skill(bird_list);
				break;
			}
			if (curNode->GetNext() == bird_list->GetTail())
			{
				break;
			}
			curNode = curNode->GetNext();
		}
		break;
	}
	// each bird votes
	curNode = bird_list->GetHead()->GetNext();
	while (true)
	{
		// use sequential search to make every alive bird vote
		char vote_decision;
		std::string vote_name;
		// if bird is alive Falcon, automatically vote for invalid votes
		if (curNode->GetBird()->GetBirdType() == "송골매" && curNode->GetBird()->getIsDead() == false)
		{
			std::cout << curNode->GetBird()->GetPlayerName() << "님은 송골매이므로 무효표에 자동 투표됩니다.\n";
		}
		// else if bird is alive, make it vote
		else if (curNode->GetBird()->getIsDead() == false)
		{
			std::cout << curNode->GetBird()->GetPlayerName() << "님 투표를 하시겠습니까? [Y/N]: ";
			std::cin >> vote_decision;
			if (vote_decision == 'Y')
			{
				// get input for name for voting and add vote number to that player
				std::cout << "투표하고 싶은 플레이어의 이름을 입력하세요: ";
				std::cin >> vote_name;
				BirdNode *curNode2 = bird_list->GetHead()->GetNext();
				while (true)
				{
					// use sequential search to find vote_name and add 1 to votednum
					if (curNode2->GetBird()->GetPlayerName() == vote_name)
					{
						curNode2->GetBird()->addVotedNum();
					}
					if (curNode2->GetNext() == bird_list->GetTail())
					{
						break;
					}
					curNode2 = curNode2->GetNext();
				}
			}
			// if player doesn't vote, do nothing
			else if (vote_decision == 'N')
			{
			}
		}
		if (curNode->GetNext() == bird_list->GetTail())
		{
			break;
		}
		curNode = curNode->GetNext();
	}
	// after voting, find maximum value of votednum and corresponding player's name
	int maxvotednum = 0;
	std::string maxname;
	BirdNode *curNode3 = bird_list->GetHead()->GetNext();
	while (true)
	{
		// use sequential search to find maximum value of votednum and corresponding player's name
		if (curNode3->GetBird()->getVotedNum() >= maxvotednum && curNode3->GetBird()->getIsDead() == false)
		{
			maxvotednum = curNode3->GetBird()->getVotedNum();
			maxname = curNode3->GetBird()->GetPlayerName();
		}
		if (curNode3->GetNext() == bird_list->GetTail())
		{
			break;
		}
		curNode3 = curNode3->GetNext();
	}
	// find number of players with overlapping maximum value of votednum
	int dupbirdnum = 0;
	BirdNode *curNode4 = bird_list->GetHead()->GetNext();
	while (true)
	{
		// use sequential search to find number of players with overlapping maximum value of votednum
		if (curNode4->GetBird()->getVotedNum() == maxvotednum && curNode4->GetBird()->getIsDead() == false)
		{
			// if votednum equals to maximum value of votednum, add 1 to dupbirdnum
			dupbirdnum += 1;
		}
		if (curNode4->GetNext() == bird_list->GetTail())
		{
			break;
		}
		curNode4 = curNode4->GetNext();
	}
	// invalidate a vote
	// No one is deported if there are more than one player who receives the most votes, including invalid votes.
	if (maxvotednum == 0 || maxvotednum == 1 || dupbirdnum >= 2)
	{
		std::cout << "전체 메시지: 이번 투표에서는 아무 조류도 당첨되지 않았습니다.\n";
	}
	else // banish player with maximun value of votednum
	{
		bird_list->KillBirdNode(maxname);
		std::cout << maxname << "은(는) 더 좋은 곳으로 갔습니다.\n";
		// find out whether banished player is duck or not and print result
		if (bird_list->searchKilledBirdNode(maxname) == "오리" || bird_list->searchKilledBirdNode(maxname) == "암살자 오리")
		{
			std::cout << "전체 메시지: 만세 " << maxname << "은(는) 오리입니다!!\n";
		}
		else if (bird_list->searchKilledBirdNode(maxname) == "도도새")
		{
			// make dodoiskilled true since it wins when it is banished
			dodoiskilled = true;
			std::cout << "전체 메시지: 맙소사 " << maxname << "은(는) 오리가 아닙니다!!\n";
		}
		else
		{
			std::cout << "전체 메시지: 맙소사 " << maxname << "은(는) 오리가 아닙니다!!\n";
		}
	}

	round_num += 1;
}

// Determine if a particular group of birds meets the victory conditions
bool GGD::IsGameOver() // Returns true if there is a winning team, else return false
{
	// initialize alive birds' numbers
	alive_goose_num = 0;
	alive_duck_num = 0;
	alive_bird_num = 0;
	alive_falcon_num = 0;
	bool res = false;
	BirdNode *curNode = bird_list->GetHead()->GetNext();
	while (true)
	{
		// use sequential search to find alive players' numbers
		if ((curNode->GetBird()->GetBirdType() == "거위" || curNode->GetBird()->GetBirdType() == "탐정 거위" || curNode->GetBird()->GetBirdType() == "장의사 거위") && curNode->GetBird()->getIsDead() == false)
		{
			// add goose number and bird number
			alive_goose_num += 1;
			alive_bird_num += 1;
		}
		else if ((curNode->GetBird()->GetBirdType() == "오리" || curNode->GetBird()->GetBirdType() == "암살자 오리") && curNode->GetBird()->getIsDead() == false)
		{
			// add duck number and bird number
			alive_duck_num += 1;
			alive_bird_num += 1;
		}
		else if (curNode->GetBird()->GetBirdType() == "송골매" && curNode->GetBird()->getIsDead() == false)
		{
			// add falcon number and bird number
			alive_falcon_num = 1;
			alive_bird_num += 1;
		}
		else if (curNode->GetBird()->GetBirdType() == "도도새" && curNode->GetBird()->getIsDead() == false)
		{
			// add bird number
			alive_bird_num += 1;
		}
		if (curNode->GetNext() == bird_list->GetTail())
		{
			break;
		}
		curNode = curNode->GetNext();
	}
	// if if satisfies winning condition, return true
	if ((alive_duck_num >= 1 && alive_duck_num >= (alive_bird_num - alive_duck_num) && !(alive_duck_num == 1 && alive_falcon_num == 1 && alive_bird_num == 2)) || (alive_goose_num >= 1 && alive_duck_num == 0 && alive_falcon_num == 0) || dodoiskilled == true || (alive_falcon_num == 1 && alive_bird_num <= 2))
	{
		res = true;
	}
	return res;
}

// display message according to the victory conditions of each bird group
void GGD::PrintGameResult()
{

	if (dodoiskilled == true)
	{
		// if dodo is banished, dodobird wins
		std::cout << "전체 메시지: 도도새의 승리입니다!";
	}
	else if (alive_goose_num >= 1 && alive_duck_num == 0 && alive_falcon_num == 0)
	{
		// Since the number of geese is not zero and the duck and falcon are dead, it prints out that the goose wins.
		std::cout << "전체 메시지: 거위의 승리입니다!";
	}
	else if (alive_duck_num >= 1 && alive_duck_num >= (alive_bird_num - alive_duck_num) && !(alive_duck_num == 1 && alive_falcon_num == 1 && alive_bird_num == 2))
	{
		/*
		Since the number of ducks is not zero, and the number is greater than or equal to the rest of the living birds,
		and there is not a situation in which there is a duck or a falcon, it is a victory for the duck.
		*/
		std::cout << "전체 메시지: 오리의 승리입니다!";
	}
	else if (alive_falcon_num == 1 && alive_bird_num <= 2)
	{
		// Since falcon is alive and the number of remaining birds is less than 1, it prints out the victory of falcon
		std::cout << "전체 메시지: 송골매의 승리입니다!";
	}
}
// add bird player in bird_list
void GGD::AddPlayer()
{
	// get input for player's name and role code
	std::string player_name;
	std::cout << "플레이어의 이름을 입력해주세요: ";
	std::cin >> player_name;

	int role_code;
	std::cout << "역할 번호를 입력해주세요: ";
	std::cin >> role_code;

	// add player node in bird_list
	switch (role_code)
	{
	case kFalcon:
	{
		// append at most one
		if (Falcon_num == 0)
		{
			Falcon *newFalcon = new Falcon;					// Falcon pointer dynamic allocation
			BirdNode *newNode = new BirdNode(newFalcon);	// BirdNode pointer dynamic allocation
			bird_list->AddBirdNode(newNode);				// add node with falcon to linked list
			newNode->SetBird(newFalcon);					// set bird newFalcon
			newNode->GetBird()->SetPlayerName(player_name); // set player's name player_name
			Falcon_num = 1;									// now its number is 1
			break;
		}
		else
		{
			break;
		}
	}
	case kAssassinDuck:
	{
		AssassinDuck *newAssassinDuck = new AssassinDuck;  // AssassinDuck pointer dynamic allocation
		BirdNode *newNode = new BirdNode(newAssassinDuck); // BirdNode pointer dynamic allocation
		bird_list->AddBirdNode(newNode);				   // add node with AssassinDuck to linked list
		newNode->SetBird(newAssassinDuck);				   // set bird newAssassinDuck
		newNode->GetBird()->SetPlayerName(player_name);	   // set player's name player_name
		break;
	}
	case kDuck:
	{
		Duck *newDuck = new Duck;						// Duck pointer dynamic allocation
		BirdNode *newNode = new BirdNode(newDuck);		// BirdNode pointer dynamic allocation
		bird_list->AddBirdNode(newNode);				// add node with Duck to linked list
		newNode->SetBird(newDuck);						// set bird newDuck
		newNode->GetBird()->SetPlayerName(player_name); // set player's name player_name
		break;
	}
	case kDetectiveGoose:
	{
		DetectiveGoose *newDetectiveGoose = new DetectiveGoose; // DetectiveGoose pointer dynamic allocation
		BirdNode *newNode = new BirdNode(newDetectiveGoose);	// BirdNode pointer dynamic allocation
		bird_list->AddBirdNode(newNode);						// add node with DetectiveGoose to linked list
		newNode->SetBird(newDetectiveGoose);					// set bird newDetectiveGoose
		newNode->GetBird()->SetPlayerName(player_name);			// set player's name player_name
		break;
	}
	case kMorticianGoose:
	{
		MorticianGoose *newMorticianGoose = new MorticianGoose; // MorticianGoose pointer dynamic allocation
		BirdNode *newNode = new BirdNode(newMorticianGoose);	// BirdNode pointer dynamic allocation
		bird_list->AddBirdNode(newNode);						// add node with MorticianGoose to linked list
		newNode->SetBird(newMorticianGoose);					// set bird newMorticianGoose
		newNode->GetBird()->SetPlayerName(player_name);			// set player's name player_name
		break;
	}
	case kGoose:
	{
		Goose *newGoose = new Goose;					// Goose pointer dynamic allocation
		BirdNode *newNode = new BirdNode(newGoose);		// BirdNode pointer dynamic allocation
		bird_list->AddBirdNode(newNode);				// add node with Goose to linked list
		newNode->SetBird(newGoose);						// set bird newGoose
		newNode->GetBird()->SetPlayerName(player_name); // set player's name player_name
		break;
	}
	case kDodoBird:
	{
		// append at most one
		if (Dodo_num == 0)
		{
			DodoBird *newDodoBird = new DodoBird;			// DodoBird pointer dynamic allocation
			BirdNode *newNode = new BirdNode(newDodoBird);	// BirdNode pointer dynamic allocation
			bird_list->AddBirdNode(newNode);				// add node with DodoBird to linked list
			newNode->SetBird(newDodoBird);					// set bird newDodoBird
			newNode->GetBird()->SetPlayerName(player_name); // set player's name player_name
			Dodo_num = 1;									// now its number is 1
			break;
		}
		else
		{
			break;
		}
	}
	default:
		break;
	}
}
