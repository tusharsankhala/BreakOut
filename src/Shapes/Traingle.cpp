#include "Traingle.h"
#include <cmath>
#include "../Utils/Utils.h"

Triangle::Triangle():Triangle(Vec2D::Zero, Vec2D::Zero, Vec2D::Zero)
{}

Triangle::Triangle(const Vec2D& p0, const Vec2D& p1, const Vec2D& p2)
{
	m_points.push_back(p0);
	m_points.push_back(p1);
	m_points.push_back(p2);
}

Vec2D Triangle::GetCenterPoint() const
{
	auto midX = (m_points[0].GetX() + m_points[1].GetX() + m_points[2].GetX()) / 3.0f;
	auto midY = (m_points[0].GetY() + m_points[1].GetY() + m_points[2].GetY()) / 3.0f;

	return Vec2D(midX, midY);
}

float Triangle::Area() const
{
	return Area(GetP0(), GetP1(), GetP2());
}

bool Triangle::ContainPoints(Vec2D& pt) const
{
	float originalArea = Area();
	float a1 = Area(pt, GetP0(), GetP1());
	float a2 = Area(GetP0(), pt, GetP2());
	float a3 = Area(GetP0(), GetP1(), pt);

	if ((a1 + a2 + a3) == originalArea)
		return true;

	return false;
}

float Triangle::Area(const Vec2D& p0, const Vec2D& p1, const Vec2D& p2) const
{
	auto Ax = GetP0().GetX();
	auto Ay = GetP0().GetY();
	auto Bx = GetP1().GetX();
	auto By = GetP1().GetY();
	auto Cx = GetP2().GetX();
	auto Cy = GetP2().GetY();

	return fabs((Ax*(By-Cy) + Bx*(Cy - Ay) + Cx*(Ay - By))/2);
}

