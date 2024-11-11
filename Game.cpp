#include "stdafx.h"
#include "Game.h"
#include "Deck.h"
#include "Hand.h"
#include "Text.h"

#include <iostream>
#include <ctime>

//Privates
void Game::initVariables()
{
	this->window = nullptr;

	Deck basicDeck;
	Hand playersHand;
	Hand dealersHand;
	TextObject startText(this->consolasFont, this->window, 16, L"Start");

}

void Game::initWindow()
{
	this->videoMode.width = 800;
	this->videoMode.height = 600;
	this->window = new sf::RenderWindow(this->videoMode, "Blackjack in C++", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(75);
}

void Game::initFonts()
{
	if (!this->consolasFont.loadFromFile("fonts/Consolas.ttf"))
	{
		sf::err() << "ERROR::GAME::INITFONTS:: failed to load font! \n";
	}
}



//Constructors
Game::Game()
{
	this->initWindow();
	this->initFonts();
	this->initVariables();
}

Game::~Game()
{
	delete this->window;
}

//Accessors 

const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions


void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updateMousePos()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}



void Game::update()
{

	this->pollEvents();

	this->updateMousePos();

	this->updateText();
}

void Game::updateText()
{
	
}


void Game::renderText(sf::RenderTarget& target, sf::Text text)
{
	target.draw(text);
}

void Game::render()
{
	this->window->clear(sf::Color(20, 20, 20));

	this->renderText(*this->window, uiText);

	//LAST
	this->window->display();
}