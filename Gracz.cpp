#include "Gracz.h"

Gracz::Gracz(Texture* texture, float x, float y) : AnimowaneAssety(texture,x,y)
{
    this->sprite.scale(0.6f, 0.6f);
}

Gracz::~Gracz()
{
}

void Gracz::update()
{
    /*
    if (this->sprite.getPosition().x + this->sprite.getGlobalBounds().width > 1280) {     //   this->setPosition(1280, this->getPos().y);
    }
    if (this->sprite.getPosition().y < 0 || this->sprite.getPosition().y + this->sprite.getGlobalBounds().height > 720) {
        this->setPosition(this->getPos().x, 720);
    }*/
}
