#pragma once
#include <string>

class BirdList;

class Bird
{
protected:
	// player's name
	std::string player_name;
	// used in deciding whether player killed somebody
	bool killedbird;
	// used in deciding whether player is dead
	bool isdead;
	// used in voting
	int votednum;

public:
	// Default constructor
	Bird();
	// destructor with virtual function because of GetBirdType, Skill
	virtual ~Bird();
	// assign parameter to player_name
	void SetPlayerName(std::string name);
	// get the member variable player_name
	std::string GetPlayerName() const;
	// assign parameter to killedbird
	void setKilledBird(bool);
	// assign parameter to isdead
	void setIsDead(bool);
	// get the member variable killedbird
	bool getKilledBird();
	// get the member variable isdead
	bool getIsDead();
	// add 1 to votednum
	void addVotedNum();
	// get the member variable votednum
	int getVotedNum();
	virtual std::string GetBirdType() const = 0; // pure virtual function
	virtual void Skill(BirdList *) = 0;			 // pure virtual function
};
