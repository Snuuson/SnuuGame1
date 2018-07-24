#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "RectF.h"
class Brick
{
public:
	Brick();
	Brick(const RectF rect_in, Color c_in);
	
	~Brick();
private:
	Color c;
	RectF rect;

};

