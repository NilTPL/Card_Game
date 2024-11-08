#include "stdafx.h"
#include "Game.h"
#include "Deck.h"
#include "Hand.h"


#include <iostream>
#include <ctime>
#include <sstream>

//Privates
void Game::initVariables()
{
	this->window = nullptr;

	Deck basicDeck;
	Hand playersHand;
	Hand dealersHand;

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

void Game::initText()
{
	this->uiText.setFont(this->consolasFont);
	this->uiText.setCharacterSize(16);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setOrigin(this->uiText.getLocalBounds().getSize() / 2.f + this->uiText.getLocalBounds().getPosition());
	std::cout << static_cast<std::string>(this->uiText.getLocalBounds().getSize() / 2.f);
	this->uiText.setPosition(this->window->getSize().x / 2.f, this->window->getSize().y / 2.f);
	this->uiText.setString("EMPTY");
}

void Game::initButtons()
{
	/*
	this->button.setFillColor(sf::Color(255, 255, 255));
	this->button.setCharacterSize(16);
	this->button.setFont(this->consolasFont);
	this->button.setPosition((this->window->getSize().x - 20.f), (this->window->getSize().y - 20.f));
	*/
}



//Constructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
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
	std::stringstream stringStream;
	stringStream << "something i want to print";
	this->uiText.setString(stringStream.str());
}


void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
}

void Game::render()
{
	this->window->clear(sf::Color(20, 20, 20));

	this->renderText(*this->window);

	//LAST
	this->window->display();
}