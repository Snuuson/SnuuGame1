#pragma once
#include "Graphics.h"
#include "Ball.h"
#include "RectF.h"
#include "Colors.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle();
	Paddle(Vec2& pos_in,float halfWidth, float halfHeight);
	void Update(Keyboard& kbd,float dt);
	bool DoBallCollision(Ball & ball);
	void DoWallCollision(const RectF& walls);
	void Draw(Graphics& gfx) const	;
	RectF GetRect() const;
	~Paddle();

private:
	
	const Color randomColor() const;
	Vec2 pos;
	float speed = 200;
	float halfWidth;
	float halfHeight;
	Color coreColor = Colors::Green;
	Color wingColor = Colors::Red;
	float wingWidth = 10;
};

