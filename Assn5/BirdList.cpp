#include "BirdList.h"
#include "Bird.h"
#include "BirdNode.h"
#include "Macro.h"
#include <iostream>
#include <string>

// Linked list
BirdList::BirdList() // Default constructor
{
}

BirdList::~BirdList() // Destructor
{
}
// Get the member variable head
BirdNode *BirdList::GetHead() const
{
	return this->head;
}
// Get the member variable tail
BirdNode *BirdList::GetTail() const
{
	return this->tail;
}
// assign paramerter to head
BirdNode *BirdList::SetHead(BirdNode *head)
{
	return this->head = head;
}
// assign paramerter to tail
BirdNode *BirdList::SetTail(BirdNode *tail)
{
	return this->tail = tail;
}
// add BirdNode in BirdList
void BirdList::AddBirdNode(BirdNode *newNode)
{
	// if there is zero node, add newNode between head and tail
	if (head->GetNext() == tail)
	{
		head->SetNext(newNode);
		newNode->SetNext(tail);
	}
	// if there is at least one node, add newNode before tail
	else
	{
		// use sequential search to find node before tail
		BirdNode *curNode = head->GetNext();
		while (curNode->GetNext() != tail)
		{
			curNode = curNode->GetNext();
		}
		curNode->SetNext(newNode);
		newNode->SetNext(tail);
	}
}
// kill BirdNode with player_name birdname
void BirdList::KillBirdNode(std::string birdname)
{
	// Exclude typing of your own name, name that you don't have, or name of a surviving player
	BirdNode *curNode = head->GetNext();
	while (true)
	{
		// use sequential search to find BirdNode with player_name birdname
		if (curNode->GetBird()->GetPlayerName() == birdname)
		{
			// make this player dead by setting isdead true
			curNode->GetBird()->setIsDead(true);
			return;
		}
		if (curNode->GetNext() == tail)
		{
			return;
		}
		curNode = curNode->GetNext();
	}
}
// Get the member variable kill_num_limit
int BirdList::getKillNumLimit() const
{
	return kill_num_limit;
}
// assign paramerter to kill_num_limit
void BirdList::setKillNumLimit(int GGDkill_num_limit)
{
	kill_num_limit = GGDkill_num_limit;
}
// Get the member variable kill_num
int BirdList::getKillNum() const
{
	return kill_num;
}
// assign paramerter to kill_num
void BirdList::setKillNum(int GGDkill_num)
{
	kill_num = GGDkill_num;
}
// add 1 to kill_num
void BirdList::addKillNum()
{
	kill_num += 1;
}
// get role number of BirdNode with player_name birdname
int BirdList::getBirdActNum(std::string birdname)
{
	BirdNode *curNode = head->GetNext();
	while (true)
	{
		// use sequential search to find BirdNode with player_name birdname
		if (curNode->GetBird()->GetPlayerName() == birdname)
		{
			std::string birdtype = curNode->GetBird()->GetBirdType();
			// return act number by using BirdRoleName
			for (int i = 0; i < 7; i++)
			{
				if (BirdRoleName[i] == birdtype)
				{
					return i;
				}
			}
		}
		// if there's no bird with name birdname, return false number
		if (curNode->GetNext() == tail)
		{
			return -1;
		}
		curNode = curNode->GetNext();
	}
}
// find out if BirdNode with player_name birdname killed somebody
bool BirdList::searchBirdNode(std::string birdname)
{
	// Exclude typing of your own name, name that you don't have, or name of a surviving player
	BirdNode *curNode = head->GetNext();
	while (true)
	{
		// use sequential search to find BirdNode with player_name birdname
		if (curNode->GetBird()->GetPlayerName() == birdname)
		{
			// return if player killed somebody
			return curNode->GetBird()->getKilledBird();
		}
		if (curNode->GetNext() == tail)
		{
			break;
		}
		curNode = curNode->GetNext();
	}
	// exception
	return false;
}
// find out if there's murdered player
bool BirdList::searchKilledBirdNode()
{
	BirdNode *curNode = head->GetNext();
	while (true)
	{
		// use sequential search to find dead BirdNode
		if (curNode->GetBird()->getIsDead() == true)
		{
			// if it is dead, return true
			return true;
		}
		if (curNode->GetNext() == tail)
		{
			break;
		}
		curNode = curNode->GetNext();
	}
	// else return false
	return false;
}
// find out role of BirdNode with player_name birdname
std::string BirdList::searchKilledBirdNode(std::string birdname)
{
	// Exclude typing of your own name, name that you don't have, or name of a surviving player
	BirdNode *curNode = head->GetNext();
	while (true)
	{
		// use sequential search to find dead BirdNode with player_name birdname
		if (curNode->GetBird()->GetPlayerName() == birdname)
		{
			// return role of BirdNode with player_name birdname
			return curNode->GetBird()->GetBirdType();
		}
		if (curNode->GetNext() == tail)
		{
			break;
		}
		curNode = curNode->GetNext();
	}
	// exception
	return NULL;
}