#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

using namespace sf;
using namespace std;

class AnimowaneAssety
{
protected:
	Sprite sprite;
	Texture texture;

	Clock clock;

	float movementSpeed = 5;
public:
	AnimowaneAssety(Texture* texture, float x, float y);
	virtual ~AnimowaneAssety();

	const Vector2f& getPos() const;
	const FloatRect getBounds() const;

	void setPosition(const float x, const float y);
	void move(const float dirX, const float dirY);

	virtual void update(float& dt);
	void render(RenderTarget* target);
};


