#include "Brick.h"



Brick::Brick()
{
}

Brick::Brick(const RectF rect_in, Color c_in)
	:
	rect( rect_in),
	color(c_in)
	
{
}

void Brick::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect, color);
}


Brick::~Brick()
{
}
