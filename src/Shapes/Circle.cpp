#include "Circle.h"
#include "../Utils/Utils.h"

Circle::Circle() : Circle(Vec2D::Zero, 0.0f) {}
Circle::Circle(const Vec2D& center, const float radius)
{
	m_points.push_back(center);
	m_Radius = radius;
}

bool Circle::Intersect(const Circle& other) const
{
	return GetCenterPoint().Distance(other.GetCenterPoint()) < (m_Radius + other.m_Radius);
}

bool Circle::ContainsPoint(const Vec2D& point) const
{
	return IsLessThanOrEqual(GetCenterPoint().Distance(point), m_Radius);
}