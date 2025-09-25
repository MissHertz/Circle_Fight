#include <algorithm>
#include <cmath>
#include <iostream>
#include <math.h>
#include <random>
#include <raylib.h>
#include <string>
#include <vector>
#include "Players/Players.h"

// Global Variables
float windowWidth = 1800;
float windowHeight = 950;
float windowHalfWidth = windowWidth / 2;
float windowHalfHeight = windowHeight / 2;

int main()
{
	InitWindow(windowWidth, windowHeight, "Circle Fight!");

	SetTargetFPS(60);

	Player Player1;
	Player Player2;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawFPS(10, 10);

		//Player1.DrawPlayer(YELLOW);

		//Player2.DrawPlayer2(RED);

		//Player1.PlayerController();

		//Player2.Player2Controller();

		EndDrawing();
	}

	CloseWindow();
}