#pragma once
#include <iostream>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include <string>
#include <sstream>

using namespace sf;
using namespace std;

class Indicator
{
private:
	Clock clock;
	float czasTrwania = 980.f; // Czas trwania "Indicatoru" (w sekundach)
	Text tekst;
	Font czcionka;
	float Alpha = 255.f;
public:
	Indicator(float x, float y, string text, Color color);
	~Indicator();

	float getCzasTrwania();
	float getCzas();

	int frame = rand() % 21;
	void update();
	void render(RenderTarget* target);
};

