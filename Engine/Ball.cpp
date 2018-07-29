#include "Ball.h"



Ball::Ball()
{
}

Ball::Ball(const Vec2 pos_in, const Vec2 vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{
}

void Ball::Draw(Graphics & gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

bool Ball::DoWallCollision(const RectF & walls)
{
	bool collided = false;
	const RectF rect = GetRekt();
	if (rect.left < walls.left) {
		pos.x += walls.left - rect.left;
		collided = true;
		ReboundX();
	}
	else if (rect.right > walls.right) {
		pos.x -= rect.right - walls.right;
		collided = true;
		ReboundX();
	}

	if (rect.top < walls.top) {
		pos.y += walls.top - rect.top;
		collided = true;
		ReboundY();
	}
	else if (rect.bottom > walls.bottom) {
		pos.y -= rect.bottom - walls.bottom;
		collided = true;
		ReboundY();
	}
	return collided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectF Ball::GetRekt() const
{
	return RectF::FromCenter(pos,radius,radius);
}

Vec2 Ball::GetVel() const
{
	return vel;
}


Ball::~Ball()
{
}
