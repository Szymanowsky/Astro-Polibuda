#pragma once
#include "AnimowaneAssety.h"



class Boom : public AnimowaneAssety
{
public:
	Boom(string file, float x, float y);
	~Boom();

	Clock clock;
	float czasTrwania = 460.f; // Czas trwania "boomu" (w sekundach)
	float getCzasTrwania();
	float getCzas();

	int frame = rand() % 21;
	void update();

};

