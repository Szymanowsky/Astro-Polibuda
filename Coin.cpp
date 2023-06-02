#include "Coin.h"

Coin::Coin(Texture* texture, float x, float y) : AnimowaneAssety(texture,x,y)
{
	this->sprite.scale(1.2f,1.2f);
}

Coin::~Coin()
{
}

void Coin::update(float& dt)
{
	this->sprite.move(0, (this->movementSpeed) * dt / 48);

	frame += 1;
	if (frame > 21) { frame = 0; }
	this->sprite.setTextureRect(IntRect(32 * int(frame / 3), 0, 32, 24));
}
