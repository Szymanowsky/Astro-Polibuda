#include "Asteroid.h"

Asteroid::Asteroid(string file, float x, float y) : AnimowaneAssety(file,x,y)
{
    this->sprite.scale(0.7f, 0.7f);
}

Asteroid::~Asteroid()
{
}

void Asteroid::update()
{
    this->sprite.move(this->x_speed, this->y_speed);

    if (this->sprite.getPosition().x < 0 || this->sprite.getPosition().x + this->sprite.getGlobalBounds().width > 1280) {
        this->x_speed *= -1;
    }
    if (this->sprite.getPosition().y < 0) {
        this->y_speed *= -1;
    }

	frame += 1;
	if (frame > 1024) { frame = 0; }
	this->sprite.setTextureRect(IntRect(10 + 128*(frame % 8),10 + 128*int(frame / 128), 108, 108));
    //cout << frame%8 << "       " << int(frame / 32) << endl;
}
