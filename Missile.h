#pragma once
#include "AnimowaneAssety.h"



class Missile : public AnimowaneAssety
{
public:
	Missile(Texture* texture, float x, float y);
	Missile(Texture* texture, float x, float y, float speed);
	~Missile();

	int frame = rand() % 21;
	
	void update();

};

