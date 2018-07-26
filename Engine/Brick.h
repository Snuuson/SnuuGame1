#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "RectF.h"
class Brick
{
public:
	Brick();
	Brick(const RectF rect_in, Color c_in);
	void Draw( Graphics& gfx) const;
	~Brick();
private:
	Color color;
	RectF rect;

};

