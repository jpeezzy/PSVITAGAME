#include "grid.h"
#include <iostream>
grid::grid(int width, int height)
{
	_width = width;
	_height = height;
}

int grid::getWidth()
{
	return _width;
}

int grid::getHeight()
{
	return _height;
}

#ifdef DEBUG
int main()
{
	grid gG(500,500);
	grid *gameGrid = &gG;
	int tH = gameGrid->getHeight();
	std::cout << "The height is " << gameGrid->getHeight() << std::endl;
	return 0;
}
#endif
