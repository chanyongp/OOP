#pragma once

#include <string>

// used to return the role number of a specific role in the course of the game.
const std::string BirdRoleName[7] =
	{"송골매", "암살자 오리", "오리", "탐정 거위", "장의사 거위", "거위", "도도새"};

// used to create the corresponding bird in the process of adding a player
enum BirdRoleCode
{
	kFalcon = 0,
	kAssassinDuck = 1,
	kDuck = 2,
	kDetectiveGoose = 3,
	kMorticianGoose = 4,
	kGoose = 5,
	kDodoBird = 6,
};
