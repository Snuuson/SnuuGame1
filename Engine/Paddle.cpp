#include "Paddle.h"



Paddle::Paddle()
{
}

Paddle::Paddle(Vec2 & pos_in, float halfWidth_in, float halfHeight_in)
	:
	pos( pos_in),
	halfWidth(halfWidth_in),
	halfHeight(halfHeight_in)

{

}

void Paddle::Update(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT)) {
		pos.x -= speed * dt;
		}

	if (kbd.KeyIsPressed(VK_RIGHT)) {
			pos.x += speed * dt;
		}
}

void Paddle::Draw(Graphics & gfx) const
{
	gfx.DrawRect(GetRect(), wingColor);
	gfx.DrawRect(RectF::FromCenter(pos,halfWidth-wingWidth,halfHeight), coreColor);
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, halfWidth, halfHeight);
}
bool Paddle::DoBallCollision(Ball & ball)
{
	RectF rect_b = ball.GetRekt();

	if (ball.GetVel().y > 0 && GetRect().IsOverlappingWith(ball.GetRekt()) && ((ball.GetPos().y-(pos.y-halfHeight))>-5 && (ball.GetPos().y - (pos.y - halfHeight)<0))) {
		ball.ReboundY();	
		wingColor = randomColor();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const RectF & walls)
{
	RectF rect = GetRect();
	if (rect.left < walls.left) {
		pos.x += walls.left - rect.left;
	}else if (rect.right > walls.right) {
		pos.x += walls.right - rect.right;
	}
	
}



Paddle::~Paddle()
{
}

const Color Paddle::randomColor() const
{
	int red = rand() % (255 - 0 + 1) + 0;
	int green = rand() % (255 - 0 + 1) + 0;
	int blue = rand() % (255 - 0 + 1) + 0;
	return Color(red,green,blue);
}
