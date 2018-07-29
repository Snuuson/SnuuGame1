#pragma once
#include "RectF.h"
#include "Vec2.h"
#include "Graphics.h"
#include "SpriteCodex.h"
class Ball
{
public:
	Ball();
	Ball(const Vec2 pos_in, const Vec2 vel_in);
	void Draw(Graphics& gfx);
	void Update(float dt);
	bool DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRekt() const;
	Vec2 GetVel() const;
	Vec2 GetPos() const;
	~Ball();

private:

	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;

};

