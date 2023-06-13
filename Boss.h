#pragma once
#include "AnimowaneAssety.h"



class Boss : public AnimowaneAssety
{
protected:
	float x_speed;
	float y_speed;

	RectangleShape rectangle;
	RectangleShape HP_bar;

	bool ScreenGrabbed = 0;
public:
	Boss(Texture* texture, float x, float y);
	~Boss();

	int HP = 1000;
	void update(float& dt);
	void render(RenderTarget* target);
};

