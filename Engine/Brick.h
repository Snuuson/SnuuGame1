#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "RectF.h"
#include "Ball.h"
class Brick
{
public:
	Brick();
	Brick(const RectF rect_in, Color c_in);
	void Draw( Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);

	~Brick();
private:
	static constexpr float padding = 1.0f;
	Color color;
	RectF rect;
	bool destroyed = false;

};

