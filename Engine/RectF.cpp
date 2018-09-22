#include "RectF.h"



RectF::RectF()
{
}


RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(const Vec2 & topleft, const Vec2 & bottomRight)
	:
	RectF(topleft.x, bottomRight.x, topleft.y, bottomRight.y)
{
}

RectF::RectF(const Vec2 & topleft, float width, float height)
	:
	RectF(topleft,Vec2(topleft.x + width,topleft.y + height))
{

}

bool RectF::IsOverlappingWith(const RectF & other) const
{
	return right > other.left && left < other.right && bottom > other.top && top < other.bottom;

}

RectF RectF::FromCenter(const Vec2 & center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(center-half,center+half);
}

RectF RectF::getExpanded(float offset) const
{
	return RectF(left - offset,right +offset,top-offset,bottom + offset );
}

RectF::~RectF()
{
}
