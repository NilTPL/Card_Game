#include "stdafx.h"
#include "Text.h"
#include "Game.h"


TextObject::TextObject(sf::Font font, const sf::RenderWindow& window, int characterSize, std::wstring caption)
{
	stringStream << caption;
	this->uiText.setString(stringStream.str());
	this->uiText.setCharacterSize(characterSize);
	this->uiText.setFont(font);
	centerTextOrigin();
	centerTextPosition(&window);


}

void TextObject::centerTextOrigin()
{
	this->uiText.setOrigin(static_cast<int>(this->uiText.getLocalBounds().getSize().x / 2.f + this->uiText.getLocalBounds().getPosition().x),
		static_cast<int> (this->uiText.getLocalBounds().getSize().y / 2.f + this->uiText.getLocalBounds().getPosition().y));
}

void TextObject::centerTextPosition(sf::RenderWindow &window)
{
	this->uiText.setPosition(static_cast<int> (window.getSize().x / 2.f), static_cast<int>(window.getSize().y / 2.f));
}


/*

	this->uiText.setFont(this->consolasFont);
	this->uiText.setCharacterSize(24);
	this->uiText.setFillColor(sf::Color::White);
	//Offset
	this->uiText.setPosition(this->uiText.getPosition() + sf::Vector2f(0, this->window->getSize().y / 5.f));

*/