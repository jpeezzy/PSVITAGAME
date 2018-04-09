#include <psp2/kernel/processmgr.h>
#include <psp2/kernel/threadmgr.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
//needed for sdl_img
#include <jpeglib.h>
#include <zlib.h>

#include "debugScreen.h"
#include "grid.h"
#include "sprite.h"
#define printf psvDebugScreenPrintf
/*enum {
	SCREEN_WIDTH  = 960,
	SCREEN_HEIGHT = 544
};
*/
SDL_Window    * gWindow   = NULL;
SDL_Renderer  * gRenderer = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface=NULL;
//Currentl ydisplayed png image
SDL_Surface* gPNGSurface = NULL;
SDL_Rect fillRect = { SCREEN_WIDTH  / 4, 
	SCREEN_HEIGHT / 4, 
	SCREEN_WIDTH  / 2, 
	SCREEN_HEIGHT / 2 
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down sdl
void close();

//Load inidividual image
SDL_Surface* loadSurface(std::string path);

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		//#ifdef DEBUG
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		//#endif
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			//#ifdef DEBUG
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			//#endif
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				#ifdef DEBUG
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				#endif
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface( gWindow );
			}
		}
	}

	return success;
}

bool loadMedia(std::string path)
{
	//Loading success flag
	bool success = true;

	//Load PNG surface
	gPNGSurface = loadSurface(path);
	if( gPNGSurface == NULL )
	{
		//#ifdef DEBUG
		printf( "Failed to load PNG image!\n" );
		//#endif
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded image
	SDL_FreeSurface( gPNGSurface );
	gPNGSurface = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
	//Final image 
	SDL_Surface *optimizedSurface = NULL;

	//Load Image at path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str());
	//initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if(!(IMG_Init(imgFlags)) & imgFlags)
	{
		printf("SDL_Image %s did not load! SDL_img error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		//#ifdef DEBUG
		if(optimizedSurface == NULL)
		{
			printf("Cannot optimize image %s! SDL error: %s \n", path.c_str(), SDL_GetError);
		}
		else
			printf("Loaded SUCESSFULLY!\n");
		//#endif
		//deallocate memory from loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	#ifdef DEBUG
	if(optimizedSurface)
	{
		printf("good to go end of load Surface\n");
	}
	else
	{
		printf("End of load function optimized surface became null!\n");
	}
	#endif
	return optimizedSurface;
}

int main(int argc, char *argv[]) 
{
	//Initialize grid for the game 
	grid gameGrid(SCREEN_WIDTH, SCREEN_HEIGHT);
	psvDebugScreenInit();
	if( !init())
	{
		printf("Failed to initialize! \n");
	}
	else
	{
		//load media
		if(!loadMedia("app0:sce_sys/images/alert_0.png"))
		//if(!loadMedia("ux0:/alert_0.png"))
		{
			printf("failed to load media");
		}
		else
		{
			//Main loop flag
			bool quit = false;
			//Event handler
			SDL_Event e;
			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//Apply the PNG image
				SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
			}
		}
	}

	//Free resources and close SDL
	sceKernelDelayThread(3*10000000);
	close();
	sceKernelExitProcess(0);

	return 0;
}
