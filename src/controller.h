#pragma once
#include <SDL2/SDL.h>
#include <map>
class controller
{
	private:
		SDL_Event event;
		
	public:
		//controller();
		//for the button presses,
		//it moves clockwise as follows:
		//triangle 0, circle 1, x 2, square three
		uint8_t buttonPressed(SDL_Event e);//returns button pressed
		SDL_Event getEvent();
		SDL_Event *getEventPointer();

};
