#include "Line2D.h"

Line2D::Line2D() : m_p0(Vec2D::Zero), m_p1(Vec2D::Zero)
{
}

Line2D::Line2D(float x0, float y0, float x1, float y1) : Line2D(Vec2D(x0, y0), Vec2D(x1, y1))
{	
}

Line2D::Line2D(const Vec2D& p0, const Vec2D& p1) : m_p0(p0), m_p1(p1)
{
}

bool Line2D::operator==(const Line2D& line) 
{
	return (m_p0 == line.GetP0() && m_p1 == line.GetP1());
}

float Line2D::MinDistanceFrom(const Vec2D& p, bool limitToSegment) const
{
	return p.Distance(ClosestPoint(p, limitToSegment));
}

Vec2D Line2D::ClosestPoint(const Vec2D& p, bool limitToSegment) const
{
	Vec2D p0ToP = p - m_p0;
	Vec2D p0ToP1 = m_p1 - m_p0;

	float l2 = p0ToP1.Mag2();
	float dot = p0ToP.Dot(p0ToP1);
	float t = dot / l2;

	if (limitToSegment)
	{
		t = std::fmax(0, std::fmin(1.0f, t));
	}

	return m_p0 + p0ToP1 * t;
}

Vec2D Line2D::MidPoint() const
{
	float xMid = (m_p1.GetX() + m_p0.GetX()) / 2.0f;
	float yMid = (m_p1.GetY() + m_p0.GetY()) / 2.0f;

	return Vec2D(xMid, yMid);
}

float Line2D::Slope() const
{
	float dx = (m_p1.GetX() - m_p0.GetX());
	if (fabs(dx) < EPSILON)
		return 0;

	float dy = (m_p1.GetY() - m_p0.GetY());

	return (dy / dx);
}

float Line2D::Length() const
{
	float x = m_p1.GetX() - m_p0.GetX();
	float y = m_p1.GetY() - m_p0.GetY();

	return sqrtf(x * x + y * y);
}
