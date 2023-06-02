#include "Boom.h"

Boom::Boom(string file, float x, float y) : AnimowaneAssety(file,x,y)
{
	this->sprite.scale(1.f,1.f);
}

Boom::~Boom()
{
}

float Boom::getCzasTrwania()
{
	return czasTrwania;
}

float Boom::getCzas()
{
	return clock.getElapsedTime().asMilliseconds();
}

void Boom::update()
{
	frame += 1;
	if (frame > 42) { frame = 0; }
	this->sprite.setTextureRect(IntRect(126*int(frame / 6), 0, 120, 200));
}
