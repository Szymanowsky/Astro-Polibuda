#include "Enemy_missile.h"

Enemy_missile::Enemy_missile(Texture* texture, float x, float y) : AnimowaneAssety(texture,x,y)
{
	this->sprite.scale(0.35f, 0.35f);
	this->movementSpeed = this->movementSpeed/2;
}

Enemy_missile::Enemy_missile(Texture* texture, float x, float y, float speed) : AnimowaneAssety(texture,x,y)
{
	this->sprite.scale(0.5f, 0.5f);
	this->movementSpeed = speed;
}

Enemy_missile::~Enemy_missile()
{
}

void Enemy_missile::update(float& dt)
{
	this->sprite.move(0,(this->movementSpeed) * dt / 16);
}
