#pragma once
#include "AnimowaneAssety.h"



class Asteroid : public AnimowaneAssety
{
private:
	int x_speed = rand() % 2 - 4;
	int y_speed = rand() % 2 - 4;;
public:
	Asteroid(string file, float x, float y);
	~Asteroid();

	int frame = rand() % 45;
	
	void update();

};

