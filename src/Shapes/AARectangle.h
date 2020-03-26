// Axis Aligned Rectangle.

#ifndef AARECTANGLE_H
#define AARECTANGLE_H

#include "Shape.h"

class AARectangle : public Shape
{
public:
	AARectangle();
	AARectangle(const Vec2D& topLeft, const Vec2D& bottomRight);
	AARectangle(const Vec2D& topLeft, unsigned int width, unsigned int height);
	
	inline void SetTopLeftPoint(const Vec2D& topLeft) { m_points[0] = topLeft; }
	inline void SetBottomRightPoint(const Vec2D& bottomRight) { m_points[1] = bottomRight; }

	inline Vec2D GetTopLeftPoint() const { return m_points[0]; }
	inline Vec2D GetBottomRightPoint() const { return m_points[1]; }

	float GetWidth() const;
	float GetHeight() const;

	void MoveTo(const Vec2D& position);
	Vec2D GetCenterPoint() const override;
	
	bool Intersects(const AARectangle& otherRect) const;
	bool ContainsPoint(const Vec2D& point) const;

	AARectangle Inset(const AARectangle& rect, Vec2D& insets);
	virtual std::vector<Vec2D> GetPoints() const override;
};

#endif
