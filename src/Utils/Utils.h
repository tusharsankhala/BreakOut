#pragma once

static const float EPSILON = 0.001f;

inline bool IsEqual(float x, float y)
{
	return fabsf(x - y) < EPSILON;
}

inline bool IsGreaterThanOrEqual(float x, float y)
{
	return x > y || IsEqual(x, y);
}

inline bool IsLessThanOrEqual(float x, float y)
{
	return x < y || IsEqual(x, y);
}

