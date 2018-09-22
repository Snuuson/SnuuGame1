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
	gfx.DrawRect(rect.getExpanded(-padding), color);
}

bool Brick::DoBallCollision(Ball& ball )
{

	
	if (!destroyed && rect.IsOverlappingWith(ball.GetRekt())) {
		const Vec2 ballPos = ball.GetPos();
			if (ballPos.x >= rect.left && ballPos.x <= rect.right) {
				ball.ReboundY();
			}
			else 
			{
				ball.ReboundX();
			}
		
		destroyed = true;
		return true;
	}
	return false;
}


Brick::~Brick()
{
}
