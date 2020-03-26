#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle();
	Circle(const Vec2D& center, const float radius);

	inline virtual Vec2D GetCenterPoint() const override { return m_points[0]; }
	inline float GetRadius() const { return m_Radius; }

	inline float SetRadius(float radius) { m_Radius = radius; }
	inline void MoveTo(const Vec2D& point) { m_points[0] = point; }

	bool Intersect(const Circle& other) const;
	bool ContainsPoint(const Vec2D& point) const;

private:
	float m_Radius;
};

#endif