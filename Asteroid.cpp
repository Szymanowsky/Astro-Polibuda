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
    this->sprite.move(this->x_speed, this->y_speed);

    if (this->sprite.getPosition().x < 0 || this->sprite.getPosition().x + this->sprite.getGlobalBounds().width > 1280) {
        this->x_speed *= -1;
    }

	frame += 1;
	if (frame > 255) { frame = 0; }
	this->sprite.setTextureRect(IntRect(14 + 128*int((frame%32)/4),10 + 128*int(frame / 32), 100, 104));
    //cout << frame%64/8 << "       " << int(frame / 64) << endl;
}
