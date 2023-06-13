#pragma once
#include "AnimowaneAssety.h"



class Enemy : public AnimowaneAssety
{
protected:
	float x_speed;
	float y_speed;

	RectangleShape rectangle;
	RectangleShape HP_bar;

	bool ScreenGrabbed = 0;
public:
	Enemy(Texture* texture, float x, float y);
	~Enemy();

	int HP = 100;
	void update(float& dt);
	void render(RenderTarget* target);
};

