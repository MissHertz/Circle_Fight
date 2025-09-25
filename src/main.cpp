#include <algorithm>
#include <cmath>
#include <iostream>
#include <math.h>
#include <random>
#include <raylib.h>
#include <string>
#include <vector>
#include "Players/Players.h"
#include "Environment/Environment.h"

// Global Variables
float windowWidth = 1800;
float windowHeight = 950;
float windowHalfWidth = windowWidth / 2;
float windowHalfHeight = windowHeight / 2;

int main()
{
	InitWindow(windowWidth, windowHeight, "Circle Fight!");

	SetTargetFPS(60);

	Environment Env;
	Player Player1;
	//Player Player2;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		
		ClearBackground(BLACK);

		DrawFPS(10, 10);

		Player1.DrawPlayer(YELLOW);

		//Player2.DrawPlayer2(RED);

		Player1.PlayerController(Env);

		//Player2.Player2Controller();

		// Draw Walls and columns
		Env.DrawWall_1(Player1.player1Centre);
		Env.DrawWall_2(Player1.player1Centre);
		Env.DrawWall_3(Player1.player1Centre);
		Env.DrawWall_4(Player1.player1Centre);
		Env.DrawWall_5(Player1.player1Centre);
		Env.DrawWall_6(Player1.player1Centre);
		Env.DrawWall_7(Player1.player1Centre);
		Env.DrawWall_8(Player1.player1Centre);
		Env.DrawWall_9(Player1.player1Centre);
		Env.DrawWall_10(Player1.player1Centre);
		Env.DrawWall_11(Player1.player1Centre);
		Env.DrawWall_12(Player1.player1Centre);
		Env.DrawWall_13(Player1.player1Centre);
		Env.DrawWall_14(Player1.player1Centre);
		Env.DrawWall_15(Player1.player1Centre);
		Env.DrawWall_16(Player1.player1Centre);
		Env.DrawWall_17(Player1.player1Centre);
		Env.DrawWall_18(Player1.player1Centre);
		Env.DrawWall_19(Player1.player1Centre);
		Env.DrawWall_20(Player1.player1Centre);
		Env.DrawWall_21(Player1.player1Centre);

		Env.DrawColumn_1(Player1.player1Centre);
		Env.DrawColumn_2(Player1.player1Centre);
		Env.DrawColumn_3(Player1.player1Centre);
		Env.DrawColumn_4(Player1.player1Centre);
		Env.DrawColumn_5(Player1.player1Centre);


		EndDrawing();
	}

	CloseWindow();
}