#include "controller.h"

uint8_t controller::buttonPressed(SDL_Event e)
{
	switch(e.type)
	{
		case SDL_JOYBUTTONDOWN:
			{
				return e.jbutton.button;
			}
	}
	return -1;

}

SDL_Event controller::getEvent()
{
	return event;
}

SDL_Event *controller::getEventPointer()
{
	return &event;
}
