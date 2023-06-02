#pragma once
#include "AnimowaneAssety.h"



class Bonus : public AnimowaneAssety
{
public:
	Bonus(Texture* texture, float x, float y);
	~Bonus();

	int frame = rand() % 21;
	
	void update(float& dt);

};

