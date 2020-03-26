// BreakOut.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL2/SDL.h>

#include "Graphics/Color.h"
#include "Graphics/Screen.h"
#include "Shapes/Line2D.h"
#include "Shapes/Traingle.h"
#include "Shapes/AARectangle.h"
#include "Shapes/Circle.h"

const int SCREEN_WIDTH = 244;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

int main(int arcg, char* argv[])
{
    Screen winScreen;
    winScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);

    //Line2D line = {Vec2D(0,0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT)};
    Triangle triangle = { Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110) };
    AARectangle rectangle = { Vec2D(SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT / 2 - 25), 50, 50 };
    Circle circle = { Vec2D((SCREEN_WIDTH / 2) + 50, (SCREEN_HEIGHT / 2) + 50), 50.0f };

    winScreen.Draw(triangle, Color::Red(), true, Color::Red());
    winScreen.Draw(rectangle, Color::Blue(), true, Color::Blue());
    winScreen.Draw(circle, Color::Cyan(), true, Color::Cyan());

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