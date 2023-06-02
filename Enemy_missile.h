#pragma once
#include "AnimowaneAssety.h"



class Enemy_missile : public AnimowaneAssety
{
public:
	Enemy_missile(Texture* texture, float x, float y);
	Enemy_missile(Texture* texture, float x, float y, float speed);
	~Enemy_missile();

	void update(float& dt);
};

