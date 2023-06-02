#pragma once
#include "AnimowaneAssety.h"



class Missile : public AnimowaneAssety
{
public:
	Missile(string file, float x, float y);
	Missile(string file, float x, float y, float speed);
	~Missile();

	int frame = rand() % 21;
	
	void update();

};

