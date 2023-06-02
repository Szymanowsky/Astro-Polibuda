#pragma once
#include "AnimowaneAssety.h"



class Asteroid : public AnimowaneAssety
{
private:
	float x_speed = rand() % 2000 / 1000 - 4;
	float y_speed = rand()%2000/1000 +1;
public:
	Asteroid(Texture* texture, float x, float y);
	~Asteroid();

	int frame = rand() % 1024;
	
	void update();

};

