#pragma once
#include "BirdList.h"
class GGD
{
private:
	// It is used to connect birds in the form of a linked list
	BirdList *bird_list;
	// the limit on the number of killing ducks per round
	int kill_num_limit;
	// round number
	int round_num;
	// constructed falcon's number
	int Falcon_num;
	// constructed Dodobird's number
	int Dodo_num;
	// if dodo is killed or not by voting
	bool dodoiskilled;
	// alive birds' numbers
	int alive_goose_num;
	int alive_duck_num;
	int alive_falcon_num;
	int alive_bird_num;

public:
	// Do not change any function declaration from here //
	GGD();	// constructor
	~GGD(); // destructor
	// print game setting screeen and get input for setting
	void GameStart();
	// perform the voting function, using the output of the round and the skill of each bird.
	void RoundProgress();
	// Determine if a particular group of birds meets the victory conditions
	bool IsGameOver();
	// display message according to the victory conditions of each bird group
	void PrintGameResult();
	// Do not change any function declaration to here //

	// add bird player in bird_list
	void AddPlayer(); // You can change the function declaration
};
