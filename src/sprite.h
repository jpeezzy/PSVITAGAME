#pragma once
#include <iostream>
#include <map>
#define SPR_IDLE 0
#define SPR_DEAD -1
#define SPR_MOVE 1
#define SPR_ATTACK 2
class sprite{
	private:
		int _width;
		int _height;
		std::map<int, std::string> key;
		//X and Y position of the monster
		int x;
		int y;
	public:
		sprite(int width, int height);
		virtual void move(int speed, std::string direction) = 0;
		virtual void attack(int attackMove) = 0;
		int getWidth();
		int getHeight();
		int chooseAnimation(int animation);
};
