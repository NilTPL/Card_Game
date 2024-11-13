#include "stdafx.h"
#include <iostream>


//using namespace sf;

int main()
{
	//Init srand
	std::srand(time(nullptr));

	//init rest
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Blackjack in C++", sf::Style::Titlebar | sf::Style::Close, settings);

	sf::CircleShape shape(140.f, 8);
	shape.setFillColor(sf::Color(0, 60, 70));
	shape.setOrigin(sf::Vector2f(sf::Vector2i(shape.getLocalBounds().getSize() / 2.f + shape.getLocalBounds().getPosition())));
	shape.setPosition(sf::Vector2f(sf::Vector2i(window.getView().getSize() / 2.f)));
	
	
	sf::Font consolasFont;
	consolasFont.loadFromFile("fonts/Consolas.ttf");
	
	sf::Text startText("words on a screen", consolasFont, 32);
	startText.setOrigin(sf::Vector2f(sf::Vector2i(startText.getLocalBounds().getSize() / 2.f + startText.getLocalBounds().getPosition())));
	startText.setPosition(sf::Vector2f(sf::Vector2i(window.getView().getSize() / 2.f)));


	//main loop

	while (window.isOpen())
	{
		//UPDATE
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Keyboard::Escape)
				window.close();
		}


		//DRAW
		window.clear(sf::Color(20, 30, 50));
		window.draw(shape);
		window.draw(startText);
		window.display();

	}


	//End of application
	return 0;
}