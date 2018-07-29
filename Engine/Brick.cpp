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
	if(!destroyed)
	gfx.DrawRect(rect, color);
}

bool Brick::DoBallCollision(Ball& ball )
{
	if (!destroyed && rect.IsOverlappingWith(ball.GetRekt())) {
		
		ball.ReboundY();
		destroyed = true;
		return true;
	}
	return false;
}


Brick::~Brick()
{
}
