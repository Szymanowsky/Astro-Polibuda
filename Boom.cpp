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


void Boom::update(float& dt)
{
	if (this->clock.getElapsedTime().asMilliseconds() > 699) { clock.restart(); }
	this->sprite.setTextureRect(IntRect(126 * int(this->clock.getElapsedTime().asMilliseconds()/60), 20, 120, 160));
}
