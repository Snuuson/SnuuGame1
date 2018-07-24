#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "RectF.h"
class Brick
{
public:
	Brick();
	Brick(const RectF rect, Color c);

	~Brick();
private:
	Color c;
	RectF rect;

};

