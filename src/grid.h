#pragma once
#include "sprite.h"
class grid
{
	private:
		int _width;
		int _height;
	public:
		grid(int width, int height);
		int getWidth();
		int getHeight();
		int placeSprite(sprite *Sprite, int topLeft, int botLeft, int topRight, int botRight);
};
