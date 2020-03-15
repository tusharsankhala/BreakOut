
#ifndef LINE2D_H
#define LINE2D_H

#include "../Utils/Vec2D.h"
#include "../Utils/Utils.h"

class Line2D
{
public:
	Line2D();
	Line2D(float x0, float y0, float x1, float y1);
	Line2D(const Vec2D& v0, const Vec2D& v1);

	inline const Vec2D& GetP0() const { return m_p0; }
	inline const Vec2D& GetP1() const { return m_p1; }

	inline void SetP0(const Vec2D& p0) { m_p0 = p0; }
	inline void SetP1(const Vec2D& p1) { m_p1 = p1; }

	bool operator==(const Line2D& line);
	float MinDistanceFrom(const Vec2D& p, bool limitToSegment = false) const;
	Vec2D ClosestPoint(const Vec2D& p, bool limitToSegment = false) const;
	Vec2D MidPoint() const;
	float Slope() const;
	float Length() const;

private:
	Vec2D m_p0;
	Vec2D m_p1;
};

#endif
