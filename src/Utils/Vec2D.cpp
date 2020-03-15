#include "Vec2D.h"
#include "Utils.h"
#include <cassert>

const Vec2D Vec2D::Zero;

Vec2D::Vec2D() : m_X(0.0f), m_Y(0.0f) {}
Vec2D::Vec2D(float x, float y) : m_X(x), m_Y(y) {}

Vec2D Vec2D::operator+(const Vec2D& other) const
{
	return Vec2D(m_X + other.m_X, m_Y + other.m_Y);
}
Vec2D Vec2D::operator-(const Vec2D& other) const
{
	return Vec2D(m_X - other.m_X, m_Y - other.m_Y);
}

Vec2D& Vec2D::operator+=(const Vec2D& other)
{
	*this = *this + other;
	return *this;
}

Vec2D& Vec2D::operator-=(const Vec2D& other)
{
	*this = *this - other;
	return *this;
}

bool Vec2D::operator==(const Vec2D& other)
{
	return IsEqual(m_X, other.m_X) && IsEqual(m_Y, other.m_Y);
}

bool Vec2D::operator!=(const Vec2D& other)
{
	return (*this == other);
}

Vec2D Vec2D::operator-() const
{
	return Vec2D(-m_X, -m_Y);
}

Vec2D Vec2D::operator*(const float scale) const
{
	return Vec2D(m_X * scale, m_Y * scale);
}

Vec2D Vec2D::operator/(const float scale) const
{
	assert(fabsf(scale) > EPSILON);
	return Vec2D(m_X / scale, m_Y / scale);
}

Vec2D& Vec2D::operator*=(const float scale)
{
	*this = *this * scale;
	return *this;
}

Vec2D& Vec2D::operator/=(const float scale)
{
	assert(fabsf(scale) > EPSILON);
	*this = *this / scale;
	return *this;
}

Vec2D operator*(const float scale, const Vec2D& vec)
{
	return (vec * scale);
}

float Vec2D::Mag2() const
{
	return Dot(*this);
}

float Vec2D::Mag() const
{
	return sqrtf(Mag2());
}

Vec2D Vec2D::GetUnitVec() const
{
	float mag = Mag();

	if (mag > EPSILON)
	{
		return *this / mag;
	}
	
	return Vec2D::Zero;
}

Vec2D& Vec2D::Normalize()
{
	float mag = Mag();

	if (mag > EPSILON)
	{
		*this /= mag;
	}

	return *this;
}

float Vec2D::Distance(const Vec2D& vec) const
{
	return (vec - *this).Mag();
}

float Vec2D::Dot(const Vec2D& vec) const
{
	return ((m_X * vec.m_X) + (m_Y * vec.m_Y));
}

