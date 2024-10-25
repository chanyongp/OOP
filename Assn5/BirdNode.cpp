#include "BirdNode.h"

// Default constructor
BirdNode::BirdNode()
{
	// initialize bird, next with NULL
	this->bird = NULL;
	this->next = NULL;
}
// Constructor with parameter for the member variable bird
BirdNode::BirdNode(Bird *bird)
{
	// initialize bird, next with bird, NULL
	this->bird = bird;
	this->next = NULL;
}
// Destructor (delete the member variable bird)
BirdNode::~BirdNode()
{
	delete this->bird;
}

// assign Bird * bird to BirdNode's member variable bird
void BirdNode::SetBird(Bird *bird)
{
	this->bird = bird;
}

// assign BirdNode * next to BirdNode's member variable next
void BirdNode::SetNext(BirdNode *next)
{
	this->next = next;
}
// Get the member variable bird
Bird *BirdNode::GetBird() const
{
	return this->bird;
}
// Get the member variable next
BirdNode *BirdNode::GetNext() const
{
	return this->next;
}