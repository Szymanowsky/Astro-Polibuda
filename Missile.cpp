#include "Missile.h"

Missile::Missile(string file, float x, float y) : AnimowaneAssety(file,x,y)
{
	this->sprite.scale(0.5f, 0.5f);
}

Missile::Missile(string file, float x, float y, float speed) : AnimowaneAssety(file,x,y)
{
	this->sprite.scale(0.5f, 0.5f);
	this->movementSpeed = speed;
}

Missile::~Missile()
{
}

void Missile::update()
{
	this->sprite.move(0,-(this->movementSpeed));

	frame += 1;
	if (frame > 15) { frame = 0; }
	this->sprite.setTextureRect(IntRect(11 + 50 * int(frame / 5), 11, 28, 28));


}
