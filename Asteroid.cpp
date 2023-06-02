#include "Asteroid.h"

Asteroid::Asteroid(Texture* texture, float x, float y) : AnimowaneAssety(texture,x,y)
{
    this->sprite.scale(0.7f, 0.7f);
}

Asteroid::~Asteroid()
{
}

void Asteroid::update(float& dt)
{
    this->sprite.move(this->x_speed*dt/16, this->y_speed*dt/16);


    if (this->sprite.getPosition().x < 0 || this->sprite.getPosition().x + this->sprite.getGlobalBounds().width > 1280) {
        this->x_speed *= -1;
    }

	if (this->clock.getElapsedTime().asMilliseconds() > 4095) { clock.restart(); }
	this->sprite.setTextureRect(IntRect(14 + 128*int((this->clock.getElapsedTime().asMilliseconds() % 512) / 64) -4,10 + 128*int(this->clock.getElapsedTime().asMilliseconds()/512), 100, 104));

}
