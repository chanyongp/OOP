#include "Goose.h"

#include <iostream>
// Default constructor
Goose::Goose()
{
	// initialization
	killedbird = false;
	isdead = false;
	votednum = 0;
}
// destructor
Goose::~Goose()
{
}
// Goose's skill
void Goose::Skill(BirdList *)
{
	std::cout << "당신은 능력이 없는 조류입니다." << std::endl;
}
// get Goose's type
std::string Goose::GetBirdType() const
{
	return "거위";
}