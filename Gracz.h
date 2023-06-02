#pragma once
#include "AnimowaneAssety.h"



class Gracz : public AnimowaneAssety
{
private:
	
public:
	Gracz(string file, float x, float y);
	~Gracz();
	void update();
};

