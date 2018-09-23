/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  * 
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Brick.h"
#include "Ball.h"
#include "FrameTimer.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(300.0f, 300.0f), Vec2(300.0f, 300.0f)),
	walls(0.0f, float(gfx.ScreenWidth), 0.0f, float(gfx.ScreenHeight)),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav"),
	paddle(Vec2(100, 500), 40, 20)
	
	
	
	
{
	int i = 0;
	int l = 0;
	int c = 0;
	
	
	for (int y = 0; y < brickRowCount; y++) {
		for (int x = 0; x < brickColumnCount; x++) {
			bricks[c] = Brick(RectF(Vec2(x*brickWidth, y*brickHeight), brickWidth, brickHeight), Colors::Yellow);
			i++;
			c++;
		}
		l++;
		i = 0;
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt = ft.Mark();
	paddle.Update(wnd.kbd, dt);
	
	bool collisionHappend = false;
	float curColDisSq;
	int curColIndex;

	for (int i = 0; i < brickCount; i++) {
		if (bricks[i].CheckBallCollision(ball)){
			const float newColDisSq = (ball.GetPos() - bricks[i].getCenter()).GetLengthSq();
			if (collisionHappend)
			{
				if (curColDisSq < newColDisSq) {
					curColDisSq = newColDisSq;
					curColIndex = i;
				}
			}
			else 
			{
				curColDisSq = newColDisSq;
				curColIndex = i;
				collisionHappend = true;
			}
		}
	}
	if (collisionHappend) {
			bricks[curColIndex].ExecuteBallCollision(ball);
			soundBrick.Play();
	}
	ball.Update(dt);
	paddle.DoWallCollision(walls);

	if (paddle.DoBallCollision(ball)) {
			soundPad.Play();
		}
	if (ball.DoWallCollision(walls)) {
			soundBrick.Play();
		}
	
	
	

}

void Game::ComposeFrame()
{
	paddle.Draw(gfx);
	ball.Draw(gfx);
	for each (Brick& b in bricks)
	{
		b.Draw(gfx);
	}
	
	
}
