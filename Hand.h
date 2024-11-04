#pragma once

#include <deque>
#include "Card.h"

class Hand
{
public:
	Hand();
	~Hand();

	void Print();
	void Grab(std::deque<Card*> deck);
	int Values();
private:
	std::deque<Card*> hand;
};
