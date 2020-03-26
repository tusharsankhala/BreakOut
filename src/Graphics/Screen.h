#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>
#include <vector>
#include "ScreenBuffer.h"
#include "Color.h"

class Vec2D;
class Line2D;
class Triangle;
class AARectangle;
class Circle;
struct SDL_Window;
struct SDL_Surface;

class Screen
{
public:
	Screen();
	~Screen();
	Screen(const Screen& screen) = delete;
	Screen operator=(const Screen& screen) = delete;

	SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag);
	void SwapScreen();

	inline void SetClearColor(const Color& clearColor) { m_ClearColor = clearColor; }
	inline uint32_t GetWidth() const { return m_Width; }
	inline uint32_t GetHeight() const { return m_Height; }

	// Draw Methods.
	void Draw(int x, int y, const Color& color);
	void Draw(const Vec2D& point, const Color& color);
	void Draw(const Line2D& line, const Color& color);
	void Draw(const Triangle& triangle, const Color& color, bool fill = false, const Color& fillColor = Color::White());
	void Draw(const AARectangle& rect, const Color& color, bool fill = false, const Color& fillColor = Color::White());
	void Draw(const Circle& circle, const Color& color, bool fill = false, const Color& fillColor = Color::White());

private:
	void ClearScreen();
	void FillPoly(const std::vector<Vec2D>& points, const Color& color);

	uint32_t m_Width;
	uint32_t m_Height;

	Color			m_ClearColor;
	ScreenBuffer	m_BackBuffer;

	SDL_Window*		m_Window;
	SDL_Surface*	m_WindowSurface;
};

#endif