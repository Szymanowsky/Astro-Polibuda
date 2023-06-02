#include "Coin.h"

Coin::Coin(string file, float x, float y) : AnimowaneAssety(file,x,y)
{
	this->sprite.scale(1.2f,1.2f);
}

Coin::~Coin()
{
}

void Coin::update()
{
	this->sprite.move(0, (this->movementSpeed)/3);

	frame += 1;
	if (frame > 21) { frame = 0; }
	this->sprite.setTextureRect(IntRect(32 * int(frame / 3), 0, 32, 24));
}
