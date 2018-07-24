#pragma once
#include "Vec2.h"
class RectF
{
public:
	RectF();
	RectF(float left, float right, float top, float bottom);
	RectF(const Vec2& topleft, const Vec2& bottomRight);
	RectF(const Vec2& topleft, float width, float height);
	bool IsOverlappingWith(const RectF& other) const;
	~RectF();

private:

	float left;
	float right;
	float top;
	float bottom;
	

};

