#pragma once
#include "AnimowaneAssety.h"



class Bonus : public AnimowaneAssety
{
public:
	Bonus(string file, float x, float y);
	~Bonus();

	int frame = rand() % 21;
	
	void update();

};

