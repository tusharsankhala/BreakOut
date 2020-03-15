#ifndef SHAPE_H
#define SHAPE_H

#include "../Utils/Vec2D.h"
#include <vector>

class Shape
{
public:
	virtual Vec2D GetCenterPoint() const = 0;
	virtual ~Shape() {}
	inline virtual std::vector<Vec2D> GetPoints() { return m_points; }
	void MoveBy(const Vec2D& moveOffset);
protected:
	std::vector<Vec2D> m_points;
};

#endif