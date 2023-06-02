#pragma once
#include "AnimowaneAssety.h"



class Boom : public AnimowaneAssety
{
private:
	Clock clock;
	float czasTrwania = 460.f; // Czas trwania "boomu" (w sekundach)
public:
	Boom(string file, float x, float y);
	~Boom();

	float getCzasTrwania();
	float getCzas();

	int frame = rand() % 21;
	void update();

};

