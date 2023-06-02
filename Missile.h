#pragma once
#include "AnimowaneAssety.h"



class Missile : public AnimowaneAssety
{
public:
	Missile(string file, float x, float y);
	~Missile();

	int frame = rand() % 21;
	
	void update();

};

