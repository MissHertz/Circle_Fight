#include <algorithm>
#include <cmath>
#include <iostream>
#include <math.h>
#include <random>
#include <raylib.h>
#include <string>
#include <vector>
#include "../Circle_Fight/src/Players/Players.h"
#include "../Circle_Fight/src/Enemies/Enemies.h"
#include "../Circle_Fight/src/Environment/Environment.h"

// Global Variables
float windowWidth = 1800;
float windowHeight = 950;
float windowHalfWidth = windowWidth / 2;
float windowHalfHeight = windowHeight / 2;

int main()
{
	InitWindow(windowWidth, windowHeight, "Circle Fight!");

	SetTargetFPS(60);

	Players rock_Slinger;
	Players swordsman;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawFPS(10, 10);

		rock_Slinger.DrawRock_Slinger(YELLOW);

		swordsman.DrawSwordsman(RED);

		rock_Slinger.rock_SlingerController();

		swordsman.swordsmanController();

		EndDrawing();
	}

	CloseWindow();
}