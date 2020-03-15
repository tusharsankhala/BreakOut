#include "ScreenBuffer.h"
#include <SDL2\SDL.h>
#include <cassert>

ScreenBuffer::ScreenBuffer() : m_Surface(nullptr)
{
}

ScreenBuffer::ScreenBuffer(const ScreenBuffer& screenBuffer)
{
    m_Surface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.m_Surface->w,
        screenBuffer.m_Surface->h, 0, screenBuffer.m_Surface->format->format);

    SDL_BlitSurface(screenBuffer.m_Surface, nullptr, m_Surface, nullptr);
}

ScreenBuffer::~ScreenBuffer()
{
    if (m_Surface)
        SDL_FreeSurface(m_Surface);
}

ScreenBuffer& ScreenBuffer::operator=(const ScreenBuffer& screenBuffer)
{
    if (this == &screenBuffer)
        return *this;

    if (m_Surface != nullptr)
    {
        SDL_FreeSurface(m_Surface);
        m_Surface = nullptr;
    }

    if (screenBuffer.m_Surface != nullptr)
    {
        m_Surface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.m_Surface->w,
            screenBuffer.m_Surface->h, 0, screenBuffer.m_Surface->format->format);

        SDL_BlitSurface(screenBuffer.m_Surface, nullptr, m_Surface, nullptr);
    }

    return *this;
}

void ScreenBuffer::Init(uint32_t format, uint32_t width, uint32_t height)
{
    m_Surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format);
    Clear();
}

void ScreenBuffer::Clear(const Color& c)
{
    assert(m_Surface);
    if (m_Surface)
    {
        SDL_FillRect(m_Surface, nullptr, c.GetPixelColor());
    }
}

void ScreenBuffer::SetPixel(const Color& color, int x, int y)
{
    assert(m_Surface);
    if (m_Surface && (y < m_Surface->h && y >= 0 && x >= 0 && x < m_Surface->w))
    {
        SDL_LockSurface(m_Surface);
        uint32_t* pixels = (uint32_t*)m_Surface->pixels;
        size_t index = GetIndex(y, x);
        pixels[index] = color.GetPixelColor();

        SDL_UnlockSurface(m_Surface);
    }
}

uint32_t ScreenBuffer::GetIndex(int row, int column)
{
    assert(m_Surface);
    if (m_Surface)
    {
        return (row * m_Surface->w + column);
    }
    return 0;    
}
