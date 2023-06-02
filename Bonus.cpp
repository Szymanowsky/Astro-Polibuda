#include "Bonus.h"

Bonus::Bonus(Texture* texture, float x, float y) : AnimowaneAssety(texture,x,y)
{
	this->sprite.scale(0.2f,0.2f);
	
}

Bonus::~Bonus()
{
}

void Bonus::update(float& dt)
{
	this->sprite.move(0, this->movementSpeed * dt / 64);
}
