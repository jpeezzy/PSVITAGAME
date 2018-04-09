#pragma once
#include "sprite.h"

/* For Hobbes, he will hvae extra custom fighting moves
 * Defined here
  */
#define SPR_HOBBES_HADOKEN 3
#define SPR_HOBBES_TENSHOUZAN 4
#define SPR_HOBBES_KURAOKAMI 5
class hobbes:sprite 
{
	private:
		int basicAttackCounter; //can have a max combo of 5 or 7
		int chooseAttackAnimation(int attackMove);
	public:
		hobbes(int width, int height);
		void attack(int attackMove);
};
