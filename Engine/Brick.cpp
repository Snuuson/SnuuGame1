#include "Brick.h"
#include <assert.h>



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

bool Brick::CheckBallCollision(const Ball & ball) const
{
	return !destroyed && rect.IsOverlappingWith(ball.GetRekt());
}

void Brick::ExecuteBallCollision(Ball& ball )
{

	assert(CheckBallCollision(ball));
	
		const Vec2 ballPos = ball.GetPos();
			if (ballPos.x >= rect.left && ballPos.x <= rect.right) {
				ball.ReboundY();
			}
			else 
			{
				ball.ReboundX();
			}
		
		destroyed = true;
		 
}

Vec2 Brick::getCenter() const
{
	return rect.getCenter();
}


Brick::~Brick()
{
}
