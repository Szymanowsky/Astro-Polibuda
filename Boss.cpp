#include "Enemy.h"

Enemy::Enemy(Texture* texture, float x, float y) : AnimowaneAssety(texture,x,y)
{
	this->sprite.scale(0.2f,0.2f);
	x_speed = rand() % 40 / 10 - 2;
	y_speed = rand() % 20 / 10 + 1;

	rectangle.setSize(Vector2f(100, 5));
	rectangle.setFillColor(sf::Color::White);
	rectangle.setPosition(
		this->sprite.getPosition().x + ((this->sprite.getGlobalBounds().width - this->rectangle.getGlobalBounds().width)/2), 
		this->sprite.getPosition().y - 10   
	);
	HP_bar.setSize(Vector2f(100, 5));
	HP_bar.setFillColor(sf::Color::Red);
	HP_bar.setPosition(
		this->sprite.getPosition().x + ((this->sprite.getGlobalBounds().width - this->HP_bar.getGlobalBounds().width)/2),
		this->sprite.getPosition().y - 10
	);
}

Enemy::~Enemy()
{
}

void Enemy::update(float& dt)
{
	this->sprite.move(x_speed * dt / 16, y_speed * dt / 16);

	rectangle.setPosition(
		this->sprite.getPosition().x + ((this->sprite.getGlobalBounds().width - this->rectangle.getGlobalBounds().width) / 2),
		this->sprite.getPosition().y - 10
	);
	HP_bar.setPosition(rectangle.getPosition().x, rectangle.getPosition().y);

	if (this->sprite.getPosition().y > 0) {
		this->ScreenGrabbed = 1;
	}

    if (this->sprite.getPosition().x < 0 || this->sprite.getPosition().x + this->sprite.getGlobalBounds().width > 1280) {
        this->x_speed *= -1;
    }
    if (this->sprite.getPosition().y < 0 && ScreenGrabbed == 1) {
        this->y_speed *= -1;
    }
	if (this->sprite.getPosition().y > 300 + this->sprite.getGlobalBounds().height) {
		this->y_speed *= -1;
	}
	HP_bar.setSize(sf::Vector2f(this->HP, 5));
}

void Enemy::render(RenderTarget* target)
{
	target->draw(this->sprite);
	target->draw(this->rectangle);
	target->draw(this->HP_bar);
	
}
