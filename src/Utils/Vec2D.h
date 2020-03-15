#ifndef VEC2D_H
#define VEC2D_H

#include <iostream>

class Vec2D
{
public:
	static const Vec2D Zero;

	Vec2D();
	Vec2D(float x, float y);

	inline void SetX(const float x) { m_X = x; }
	inline void SetY(const float y) { m_Y = y; }
	inline const float GetX() const { return m_X; }
	inline const float GetY() const { return m_Y; }

	// Arithematic operations.
	Vec2D operator+(const Vec2D& other) const;
	Vec2D operator-(const Vec2D& other) const;
	Vec2D& operator+=(const Vec2D& other);
	Vec2D& operator-=(const Vec2D& other);
	Vec2D operator-() const;
	Vec2D operator*(const float scale) const;
	Vec2D operator/(const float scale) const;
	Vec2D& operator*=(const float scale);
	Vec2D& operator/=(const float scale);

	float Mag2() const;
	float Mag() const;

	Vec2D GetUnitVec() const;
	Vec2D& Normalize();

	float Distance(const Vec2D& vec) const;

	float Dot(const Vec2D& vec) const;


	friend Vec2D operator*(const float scale, const Vec2D& vec);

	// Comparison operations.
	bool operator==(const Vec2D& other);
	bool operator!=(const Vec2D& other);

	friend std::ostream& operator<<(std::ostream& stream, const Vec2D& vec)
	{
		stream << "X: " << vec.m_X << ", Y: " << vec.m_Y << std::endl;
		return stream;
	}

private:
	float m_X, m_Y;
};

#endif
