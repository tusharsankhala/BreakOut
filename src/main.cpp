// BreakOut.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL2/SDL.h>

#include "Graphics/Color.h"
#include "Graphics/Screen.h"
#include "Shapes/Line2D.h"

const int SCREEN_WIDTH = 244;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

int main(int arcg, char* argv[])
{
    Screen winScreen;
    winScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
   
    Line2D line = {Vec2D(0,0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT)};
    winScreen.Draw(line, Color::White());

    winScreen.SwapScreen();

    SDL_Event sdlEvent;
    bool isRunning = true;

    while (isRunning)
    {
        while (SDL_PollEvent(&sdlEvent))
        {
            switch (sdlEvent.type)
            {
            case SDL_QUIT:
                isRunning = false;
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}

