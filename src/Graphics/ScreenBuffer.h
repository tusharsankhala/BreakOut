#ifndef GRAPHICS_SCREENBUFFER_H
#define GRAPHICS_SCREENBUFFER_H

#include "Color.h"

struct SDL_Surface;

class ScreenBuffer
{
public:
	ScreenBuffer();
	ScreenBuffer(const ScreenBuffer& screenBuffer);
	~ScreenBuffer();

	ScreenBuffer& operator=(const ScreenBuffer& screenBuffer);

	void Init(uint32_t format, uint32_t width, uint32_t height);
	inline SDL_Surface* GetSurface() { return m_Surface; }
	void Clear(const Color& c = Color::Black());
	void SetPixel(const Color& color, int x, int y);

private:
	SDL_Surface* m_Surface;
	uint32_t GetIndex(int row, int column);
};

#endif