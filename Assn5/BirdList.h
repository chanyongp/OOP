#pragma once
#include "BirdNode.h"

#include <string>

class BirdList
{
private:
	// BirdList's first node
	BirdNode *head;
	// BirdList's last node
	BirdNode *tail;
	// number of killing limit
	int kill_num_limit;
	// number of killing
	int kill_num;

public:
	// Default constructor
	BirdList();
	// Destructor
	~BirdList();

	// Get the member variable head
	BirdNode *GetHead() const;
	// Get the member variable tail
	BirdNode *GetTail() const;
	// assign paramerter to head
	BirdNode *SetHead(BirdNode *);
	// assign paramerter to tail
	BirdNode *SetTail(BirdNode *);
	// add BirdNode in BirdList
	void AddBirdNode(BirdNode *);
	// kill BirdNode with player_name birdname
	void KillBirdNode(std::string birdname);
	// Get the member variable kill_num_limit
	int getKillNumLimit() const;
	// assign paramerter to kill_num_limit
	void setKillNumLimit(int);
	// Get the member variable kill_num
	int getKillNum() const;
	// assign paramerter to kill_num
	void setKillNum(int);
	// add 1 to kill_num
	void addKillNum();
	// get role number of BirdNode with player_name birdname
	int getBirdActNum(std::string birdname);
	// find out if BirdNode with player_name birdname killed somebody
	bool searchBirdNode(std::string birdname);
	// find out if there's murdered player
	bool searchKilledBirdNode();
	// find out role of BirdNode with player_name birdname
	std::string searchKilledBirdNode(std::string birdname);
};
