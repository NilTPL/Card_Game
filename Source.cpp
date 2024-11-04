#include "Deck.h"
#include "Hand.h"
#include <ctime>
#include <vector>
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

bool promptYesNo(std::string text) {
	bool YesNo = false;
	std::string value;
	do {
		std::cout << text << std::endl;
		std::cin >> value;

		if (value == "Y") YesNo = true;
		else YesNo = false;
	} while (value != "Y" && value != "N");

	return YesNo;
}

void GrabACard(Hand& hand, Deck& deck) {
	hand.Grab(deck.GetDeck());
	deck.PopCard();
}


int main()
{
	using namespace std::this_thread;
	using namespace std::chrono;
	srand(time(nullptr));

	Deck deck;
	Hand hand;
	/*
	deck.Shuffle();
	deck.Print();
	std::cout << std::endl;
	Card* card = deck.TopCard();
	card->Print();
	std::cout << std::endl;
	deck.PopCard();
	deck.Print();
	std::cout << std::endl;
	*/
	// ^^^ this prints out a shuffled deck, then takes the first card, moves it to the back.

	/*
	deck.Shuffle();
	std::cout << "Here\'s the deck: " << std::endl;
	deck.Print();
	std::cout << std::endl;
	*/
	// ^^^ This prints out just a shuffled deck.

	deck.Shuffle();
	GrabACard(hand, deck);
	std::cout << "your hand is:";
	hand.Print();
	std::cout << ", The value of your hand is: " << hand.Values() << std::endl;
	Hand dealerhand;
	GrabACard(dealerhand, deck);
	std::cout << "The dealer's hand is:";
	dealerhand.Print();
	std::cout << " XX ";
	std::cout << ", The value of the dealer's hand is at least " << dealerhand.Values() << std::endl;
	do {
		if (hand.Values() <= 21) {
			bool value = promptYesNo("\nTake one more? If no, you will finish this turn. (Y/N)");
			if (value == true)
			{
				system("cls");
				hand.Grab(deck.GetDeck());
				deck.PopCard();
				std::cout << "Your hand is:";
				hand.Print();
				std::cout << ", The value of your hand is: " << hand.Values() << std::endl;
				std::cout << "The dealer's hand is:";
				dealerhand.Print();
				std::cout << " XX ";
				std::cout << ", The value of the dealer's hand is at least " << dealerhand.Values() << std::endl;
			}
			else break;
		}
		else
		{
			std::cout << "Your cards have exceeded the value of 21!" << std::endl;
			sleep_for(seconds(5));
			break;
		}
	} while (true);

	GrabACard(dealerhand, deck);

	system("cls");
	std::cout << "------------END TURN-----------" << std::endl;

	std::cout << "\nYour cards have a value of " << hand.Values() << "." << std::endl;
	sleep_for(seconds(5));
	std::cout << "The dealer's hand is:";
	dealerhand.Print();
	std::cout << ", The value of the dealer's hand is " << dealerhand.Values() << std::endl;
	sleep_for(seconds(3));
	std::cout << std::endl;
	if (hand.Values() <= 21 && hand.Values() > dealerhand.Values())
	{
		std::cout << "The value of your hand is higher than the dealer's, but within the limit of 21. You win!" << std::endl;
	}
	else if (hand.Values() > 21)
	{
		std::cout << "The value of your hand is above 21. You lose!" << std::endl;
	}
	else if (hand.Values() <= 21 && hand.Values() < dealerhand.Values() && dealerhand.Values() < 22)
	{
		std::cout << "The value of your hand is lower than the value of the hand of the dealer, whose hand is within the limit of 21. You lose!" << std::endl;
	}
	else if (hand.Values() > 21 && dealerhand.Values() > 21)
	{
		std::cout << " Both yours, and the dealer's hands are of a higher value than 21. neither of you wins!" << std::endl;
	}
	else if (hand.Values() <= 21 && hand.Values() == dealerhand.Values())
	{
		std::cout << "Both you and the dealer have an acceptable hand, but you both drew the same value cards. It's a draw!" << std::endl;
	}
	else { std::cout << "Something messed up in the logic, please inform the developer!" << std::endl; }
	return 0;
}