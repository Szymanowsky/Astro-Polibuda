#include "Indicator.h"

Indicator::Indicator(float x, float y, string text, Color color)
{
	if (!this->czcionka.loadFromFile("fonts/BAHNSCHRIFT.ttf"))
		cout << "Error: Font not load!";

	this->tekst.setPosition(x, y);
	this->tekst.setFont(this->czcionka);
	this->tekst.setCharacterSize(20);
	this->tekst.setFillColor(color);
	this->tekst.setStyle(sf::Text::Bold);

	/*stringstream pkt;
	pkt << "-" << this->money;*/
	this->tekst.setString(text);
}


Indicator::~Indicator()
{
}

float Indicator::getCzasTrwania()
{
	return czasTrwania;
}

float Indicator::getCzas()
{
	return clock.getElapsedTime().asMilliseconds();
}

void Indicator::update()
{
	this->tekst.move(0, -2);

	Alpha -= 4.0f;
	if (Alpha < 0.0f) {
		Alpha = 0.0f;
	}

	Color color = tekst.getFillColor();
	color.a = static_cast<sf::Uint8>(Alpha);
	tekst.setFillColor(color);
		
}

void Indicator::render(RenderTarget* target)
{
	target->draw(this->tekst);
}