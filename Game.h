#include "stdafx.h"
#pragma once

class Game
{
public:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Resources
	sf::Font consolasFont;

	//Text
	sf::Text uiText;


	//Mouse pos
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Game logic

	//Game objects
	std::vector<sf::Text> vectorButtons;
	sf::Text button;

	//Constructor & destructor
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions

	void pollEvents();
	void updateMousePos();
	void update();
	void updateText();
	void renderText(sf::RenderTarget& target);
	void render();


private:
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initButtons();
};
