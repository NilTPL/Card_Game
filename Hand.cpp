#include "Hand.h"
#include <iostream>
#include "Deck.h"

Hand::Hand()
	: hand()
{
	std::deque<Card*> deck = deck;
}

Hand::~Hand()
{
	for (Card* card : hand)
	{
		delete card;
	}
	hand.clear();
}


int Hand::Values()
{
	int values = 0;
	for (Card* card : hand)
	{
		values += card->GetFaceValue();
	}
	return values;
}

void Hand::Print()
{
	for (Card* card : hand)
	{
		std::cout << " ";
		card->Print();
	}
}

void Hand::Grab(std::deque<Card*> deck)
{
	hand.push_front(deck.front());
	
}

