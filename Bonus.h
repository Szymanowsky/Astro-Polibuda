#pragma once
#include "AnimowaneAssety.h"



class Bonus : public AnimowaneAssety
{
public:
	Bonus(Texture* texture, float x, float y);
	~Bonus();
	
	void update(float& dt);
};

