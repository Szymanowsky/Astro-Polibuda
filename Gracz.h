#pragma once
#include "AnimowaneAssety.h"



class Gracz : public AnimowaneAssety
{
private:
	
public:
	Gracz(Texture* texture, float x, float y);
	~Gracz();
	void update();
};

