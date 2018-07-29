#include "Paddle.h"



Paddle::Paddle()
{
}

Paddle::Paddle(Vec2 & pos_in, Color c_in, float speed_in)
	:
	pos( pos_in),
	c(c_in),
	speed(speed_in)

{

}

void Paddle::Update(float dt)
{
	pos.y += speed * dt;
}


bool Paddle::DoBallCollision(Ball & ball) const
{
	RectF rect_b = ball.GetRekt();

	if(GetRect().IsOverlappingWith(ball.GetRekt()))
	return false;
}

RectF Paddle::GetRect()
{
	return RectF::FromCenter(pos,halfHeight,halfWidth);
}

Paddle::~Paddle()
{
}
