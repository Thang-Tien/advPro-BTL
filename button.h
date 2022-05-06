#ifndef buttonClass
#define buttonClass
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <fstream>
#include "LTexture.h"
enum buttonType
{
    restartButton,
    nextLevelButton,
    previousLevelButton,
    undoButton,
    restartButton_MouseIn,
    nextLevelButton_MouseIn,
    previousLevelButton_MouseIn,
    undoButton_MouseIn,
    totalButton
};
class button:public LTexture
{
	public:
		//Initializes internal variables
		LButton();
		//Sets top left position
		void setPosition(int SCREEN_WIDTH, int SCREEN_HEIGHT);
		//Shows button
		void renderButton(SDL_Renderer* renderer);
        // load button texture
        void loadButton(SDL_Renderer* renderer);
        bool isClicked = false;
        void handleMouseIn (SDL_Renderer* renderer, SDL_Event& e);
        void checkMouseIn ();

        bool mouseIn;
        int currentButton;
		SDL_Rect mouseRect;
		SDL_Rect buttonRect [totalButton];
		LTexture buttonTexture[totalButton];

};
#endif // buttonClass
