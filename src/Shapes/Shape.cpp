#include "Shape.h"

void Shape::MoveBy(const Vec2D& moveOffset)
{
	for (Vec2D& vec : m_points)
	{
		vec += moveOffset;
	}
}