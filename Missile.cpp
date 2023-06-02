#include "Missile.h"

Missile::Missile(Texture* texture, float x, float y) : AnimowaneAssety(texture,x,y)
{
	this->sprite.scale(0.5f, 0.5f);
}

Missile::Missile(Texture* texture, float x, float y, float speed) : AnimowaneAssety(texture,x,y)
{
	this->sprite.scale(0.5f, 0.5f);
	this->movementSpeed = speed;
}

Missile::~Missile()
{
}

void Missile::update(float& dt)
{
	this->sprite.move(0,-(this->movementSpeed) * dt / 16);

	frame += 1;
	if (frame > 15) { frame = 0; }
	this->sprite.setTextureRect(IntRect(11 + 50 * int(frame / 5), 11, 28, 28));


}
