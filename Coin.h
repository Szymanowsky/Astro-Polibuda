#pragma once
#include "AnimowaneAssety.h"



class Coin : public AnimowaneAssety
{
public:
	Coin(string file, float x, float y);
	~Coin();

	int frame = rand() % 21;
	
	void update();

};

