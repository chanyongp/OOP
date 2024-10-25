#include "Bird.h"
#include "BirdList.h"

#include <iostream>

// Default constructor
Bird::Bird()
{
	// initialization
	killedbird = false;
	isdead = false;
	votednum = 0;
}
// destructor
Bird::~Bird()
{
}
// assign parameter to player_name
void Bird::SetPlayerName(std::string name)
{
	player_name = name;
}
// get the member variable player_name
std::string Bird::GetPlayerName() const
{
	return this->player_name;
}
// assign parameter to killedbird
void Bird::setKilledBird(bool tf)
{
	killedbird = tf;
}
// assign parameter to isdead
void Bird::setIsDead(bool tf)
{
	isdead = tf;
}
// get the member variable killedbird
bool Bird::getKilledBird()
{
	return killedbird;
}
// get the member variable isdead
bool Bird::getIsDead()
{
	return isdead;
}
// add 1 to votednum
void Bird::addVotedNum()
{
	votednum += 1;
}
// get the member variable votednum
int Bird::getVotedNum()
{
	return votednum;
}