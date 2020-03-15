#include "Screen.h"
#include "../Utils/Vec2D.h"
#include "../Shapes/Line2D.h"
#include <SDL2/SDL.h>
#include <cassert>
#include <cmath>

Screen::Screen() : m_Width(0), m_Height(0), m_Window(nullptr), m_WindowSurface(nullptr)
{
}

Screen::~Screen()
{
    if (m_Window)
    {
        SDL_DestroyWindow(m_Window);
        m_Window = nullptr;
    }

    SDL_Quit();
}

SDL_Window* Screen::Init(uint32_t w, uint32_t h, uint32_t mag)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "SDL could not be initialized! SDL_ERROR: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    m_Width = w;
    m_Height = h;

    m_Window = SDL_CreateWindow("BreakOut", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width * mag, m_Height * mag, 0);

    if (m_Window)
    {
        m_WindowSurface = SDL_GetWindowSurface(m_Window);
        SDL_PixelFormat* pixelFormat = m_WindowSurface->format;
        Color::InitColorFormat(pixelFormat);
        m_ClearColor = Color::Black();
        m_BackBuffer.Init(pixelFormat->format, m_Width, m_Height);
        m_BackBuffer.Clear();
    }

    return m_Window;
}

void Screen::ClearScreen()
{
    assert(m_Window);
    if (m_Window)
    {
        SDL_FillRect(m_WindowSurface, nullptr, m_ClearColor.GetPixelColor());
    }
}

 void Screen::Draw(int x, int y, const Color& color)
 {
    assert(m_Window);
    if (m_Window)
    {  
        m_BackBuffer.SetPixel(color, x, y);
    }
 }

 void Screen::Draw(const Vec2D& point, const Color& color)
 {
    assert(m_Window);
    if (m_Window)
    {
        m_BackBuffer.SetPixel(color, point.GetX(), point.GetY());
    }
 }

 void Screen::Draw(const Line2D& line, const Color& color)
 {
    assert(m_Window);
    if (m_Window)
    {
        int dx, dy;

        int x0 = roundf(line.GetP0().GetX());
        int y0 = roundf(line.GetP0().GetY());
        int x1 = roundf(line.GetP1().GetX());
        int y1 = roundf(line.GetP1().GetY());

        dx = x1 - x0;
        dy = y1 - y0;

        signed const char ix((dx > 0) - (dx < 0)); // evaluate to 1 tor -1;
        signed const char iy((dy > 0) - (dy < 0)); // evaluate to 1 tor -1;

        dx = abs(dx) * 2;
        dy = abs(dy) * 2;

        Draw(x0, y0, color);

        if (dx >= dy)
        {
            // go along in the x direction.
            int d = dy - dx/2;

            while (x0 != x1)
            {
                if (d >= 0)
                {
                    d -= dx;
                    y0 += iy;
                }

                d += dy;
                x0 += ix;

                Draw(x0, y0, color);
            }
        }
        else
        {
            // go along in the y direction.
            int d = dx - dy/2;

            while (y0 != y1)
            {
                if (d >= 0)
                {
                    d -= dy;
                    x0 += ix;
                }

                d += dx;
                y0 += iy;

                Draw(x0, y0, color);
            }
        }
    }
 }

 void Screen::SwapScreen()
 {
    assert(m_Window);
    if (m_Window)
    {
        ClearScreen();
        SDL_BlitScaled(m_BackBuffer.GetSurface(), nullptr, m_WindowSurface, nullptr);
        SDL_UpdateWindowSurface(m_Window);
        m_BackBuffer.Clear();
    }
 }