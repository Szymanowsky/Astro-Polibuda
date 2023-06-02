#include "AnimowaneAssety.h"


AnimowaneAssety::AnimowaneAssety(Texture* texture, float x, float y)
{
	/*if (this->texture.loadFromFile(file) == false)
	{
		cout << "Error: Nie zaladowano textury!" << endl;
	}*/

	this->sprite.setTexture(*texture);
	this->sprite.scale(1.f, 1.f);
	this->sprite.setPosition(x, y);
}

AnimowaneAssety::~AnimowaneAssety()
{
}



void AnimowaneAssety::render(RenderTarget* target)
{
	target->draw(this->sprite);
}

const Vector2f& AnimowaneAssety::getPos() const
{
	return this->sprite.getPosition();
}

void AnimowaneAssety::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void AnimowaneAssety::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const FloatRect AnimowaneAssety::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void AnimowaneAssety::update(float& dt)
{

}
