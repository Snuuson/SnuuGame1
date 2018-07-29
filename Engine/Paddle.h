#pragma once
#include "Graphics.h"
#include "Ball.h"
#include "RectF.h"
#include "Colors.h"

class Paddle
{
public:
	Paddle();
	Paddle(Vec2& pos_in,Color c_in, float speed_in);
	void Update(float dt);
	bool DoBallCollision(Ball & ball) const;
	bool DoWallCollision(const RectF& walls);
	void Draw(Graphics& gfx) const	;
	RectF GetRect();
	~Paddle();

private:
	
	Vec2 pos;
	float speed;
	float halfWidth;
	float halfHeight;
	Color c;
};

