#include "Boom.h"

Boom::Boom(Texture* texture, float x, float y) : AnimowaneAssety(texture,x,y)
{
	this->sprite.scale(1.f,1.f);
}

Boom::Boom(Texture* texture, float x, float y, float scale) : AnimowaneAssety(texture, x, y)
{
	this->sprite.scale(scale, scale);
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
	this->sprite.setTextureRect(IntRect(126*int(frame / 6), 20, 120, 160));
}
