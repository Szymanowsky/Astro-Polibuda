#include "Bonus.h"

Bonus::Bonus(string file, float x, float y) : AnimowaneAssety(file,x,y)
{
	this->sprite.scale(0.2f,0.2f);
	
}

Bonus::~Bonus()
{
}

void Bonus::update()
{
	this->sprite.move(0, (this->movementSpeed)/4);
	this->sprite.setRotation(frame*2);

	frame += 1;

	/*
	if (frame > 21) { frame = 0; }
	this->sprite.setTextureRect(IntRect(32 * int(frame / 3), 0, 32, 24));*/
}
