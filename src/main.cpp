#include "raylib.h"
#include <iostream>

// 21 walls needed 

// Global variables 
float windowWidth = 1800.f;
float windowHeight = 950.f;
float widowHalfWidth = windowWidth / 2.f;
float windowHalfHeight = windowHeight / 2.f;

// player variables
float playerXPosition = 150;
float playerYPosition = windowHalfHeight;
Vector2 playerCentre;

// Wall variables
Rectangle wall_1;
Rectangle wall_2;
Rectangle wall_3;
Rectangle wall_4;
Rectangle wall_5;
Rectangle wall_6;
Rectangle wall_7;
Rectangle wall_8;
Rectangle wall_9;
Rectangle wall_10;
Rectangle wall_11;
Rectangle wall_12;
Rectangle wall_13;
Rectangle wall_14;
Rectangle wall_15;
Rectangle wall_16;
Rectangle wall_17;
Rectangle wall_18;
Rectangle wall_19;
Rectangle wall_20;
Rectangle wall_21;
bool checkWall_1;
bool checkWall_2;
bool checkWall_3;
bool checkWall_4;
bool checkWall_5;
bool checkWall_6;
bool checkWall_7;
bool checkWall_8;
bool checkWall_9;
bool checkWall_10;
bool checkWall_11;
bool checkWall_12;
bool checkWall_13;
bool checkWall_14;
bool checkWall_15;
bool checkWall_16;
bool checkWall_17;
bool checkWall_18;
bool checkWall_19;
bool checkWall_20;
bool checkWall_21;
Color wallColor(ORANGE);

// Column variables
Rectangle column_1;
Rectangle column_2;
Rectangle column_3;
Rectangle column_4;
Rectangle column_5;
bool checkColumn_1;
bool checkColumn_2;
bool checkColumn_3;
bool checkColumn_4;
bool checkColumn_5;
Color columnColor(ORANGE);
float columnSizeX = 50;
float columnSizeY = 50;



// Creates player
void DrawPlayer()
{
	float drawPlayerSize = 20.f;
	Color playerColor = { 102, 0, 102, 255 };
	DrawCircle(playerXPosition, playerYPosition, drawPlayerSize, playerColor);
}

// All rectangles 

// Section 1: left side
bool DrawWall_1()
{
	wall_1 = { 1, 350, 300, 10 };

	DrawRectangleRec(wall_1, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_1))
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_1 = true;
		return true;
	}
	checkWall_1 = false;
	return false;
}
bool DrawWall_2()
{
	wall_2 = { 1, 550, 180, 10 };

	DrawRectangleRec(wall_2, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_2))
	{
		checkWall_2 = true;
		return true;
	}
	checkWall_2 = false;
	return false;
}
bool DrawWall_3()
{
	wall_3 = { 300, 1, 10, 200 };

	DrawRectangleRec(wall_3, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_3))
	{
		checkWall_3 = true;
		return true;
	}
	checkWall_3 = false;
	return false;
}
bool DrawWall_4()
{
	wall_4 = { 300, 550, 10, 250 };

	DrawRectangleRec(wall_4, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_4))
	{
		checkWall_4 = true;
		return true;
	}
	checkWall_4 = false;
	return false;
}

// Section 2: middle
bool DrawWall_5()
{
	wall_5 = { 610, 300, 10, 280 };

	DrawRectangleRec(wall_5, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_5))
	{
		checkWall_5 = true;
		return true;
	}
	checkWall_5 = false;
	return false;
}
bool DrawWall_6()
{
	wall_6 = { 610, 300, 60, 10 };

	DrawRectangleRec(wall_6, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_6))
	{
		checkWall_6 = true;
		return true;
	}
	checkWall_6 = false;
	return false;
}
bool DrawWall_7()
{
	wall_7 = { 610, 580, 60, 10 };

	DrawRectangleRec(wall_7, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_7))
	{
		checkWall_7 = true;
		return true;
	}
	checkWall_7 = false;
	return false;
}

// Section 3: right side middle
bool DrawWall_8()
{
	wall_8 = { 1130, 280, 10, 320 };

	DrawRectangleRec(wall_8, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_8))
	{
		checkWall_8 = true;
		return true;
	}
	checkWall_8 = false;
	return false;
}
bool DrawWall_9()
{
	wall_9 = { 1130, 280, 230, 10 };

	DrawRectangleRec(wall_9, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_9))
	{
		checkWall_9 = true;
		return true;
	}
	checkWall_9 = false;
	return false;
}
bool DrawWall_10()
{
	wall_10 = { 1130, 600, 350, 10 };

	DrawRectangleRec(wall_10, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_10))
	{
		checkWall_10 = true;
		return true;
	}
	checkWall_10 = false;
	return false;
}
bool DrawWall_11()
{
	wall_11 = { 1360, 280, 10, 160 };

	DrawRectangleRec(wall_11, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_11))
	{
		checkWall_11 = true;
		return true;
	}
	checkWall_11 = false;
	return false;
}
bool DrawWall_12()
{
	wall_12 = { 1360, 540, 10, 60 };

	DrawRectangleRec(wall_12, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_12))
	{
		checkWall_12 = true;
		return true;
	}
	checkWall_12 = false;
	return false;
}
bool DrawWall_13()
{
	wall_13 = { 1470, 600, 10, 140 };

	DrawRectangleRec(wall_13, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_13))
	{
		checkWall_13 = true;
		return true;
	}
	checkWall_13 = false;
	return false;
}
bool DrawWall_14()
{
	wall_14 = { 1350, 740, 130, 10 };

	DrawRectangleRec(wall_14, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_14))
	{
		checkWall_14 = true;
		return true;
	}
	checkWall_14 = false;
	return false;
}

// Section 4: right side
bool DrawWall_15()
{
	wall_15 = { 1520, 150, 10, 100 };

	DrawRectangleRec(wall_15, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_15))
	{
		checkWall_15 = true;
		return true;
	}
	checkWall_15 = false;
	return false;
}
bool DrawWall_16()
{
	wall_16 = { 1520, 150, 80, 10 };

	DrawRectangleRec(wall_16, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_16))
	{
		checkWall_16 = true;
		return true;
	}
	checkWall_16 = false;
	return false;
}
bool DrawWall_17()
{
	wall_17 = { 1520, 250, 280, 10 };

	DrawRectangleRec(wall_17, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_17))
	{
		checkWall_17 = true;
		return true;
	}
	checkWall_17 = false;
	return false;
}
bool DrawWall_18()
{
	wall_18 = { 1600, 250, 10, 50 };

	DrawRectangleRec(wall_18, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_18))
	{
		checkWall_18 = true;
		return true;
	}
	checkWall_18 = false;
	return false;
}
bool DrawWall_19()
{
	wall_19 = { 1600, 430, 10, 230 };

	DrawRectangleRec(wall_19, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_19))
	{
		checkWall_19 = true;
		return true;
	}
	checkWall_19 = false;
	return false;
}
bool DrawWall_20()
{
	wall_20 = { 1600, 780, 10, 220 };

	DrawRectangleRec(wall_20, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_20))
	{
		checkWall_20 = true;
		return true;
	}
	checkWall_20 = false;
	return false;
}
bool DrawWall_21()
{
	wall_21 = { 1600, 600, 200, 10 };

	DrawRectangleRec(wall_21, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, wall_21))
	{
		checkWall_21 = true;
		return true;
	}
	checkWall_21 = false;
	return false;
}

// Columns
bool DrawColumn_1()
{
	column_1 = { 420, 430, columnSizeX, columnSizeY };

	DrawRectangleRec(column_1, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, column_1))
	{
		checkColumn_1 = true;
		return true;
	}
	checkColumn_1 = false;
	return false;
}
bool DrawColumn_2()
{
	column_2 = { 820, 100, columnSizeX, columnSizeY };

	DrawRectangleRec(column_2, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, column_2))
	{
		checkColumn_2 = true;
		return true;
	}
	checkColumn_2 = false;
	return false;
}
bool DrawColumn_3()
{
	column_3 = { 1080, 100, columnSizeX, columnSizeY };

	DrawRectangleRec(column_3, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, column_3))
	{
		checkColumn_3 = true;
		return true;
	}
	checkColumn_3 = false;
	return false;
}
bool DrawColumn_4()
{
	column_4 = { 820, 800, columnSizeX, columnSizeY };

	DrawRectangleRec(column_4, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, column_4))
	{
		checkColumn_4 = true;
		return true;
	}
	checkColumn_4 = false;
	return false;
}
bool DrawColumn_5()
{
	column_5 = { 1080, 800, columnSizeX, columnSizeY };

	DrawRectangleRec(column_5, wallColor);

	if (CheckCollisionCircleRec(playerCentre, 20.f, column_5))
	{
		checkColumn_5 = true;
		return true;
	}
	checkColumn_5 = false;
	return false;
}


// Player movement
void PlayerController()
{
	float playerSpeed = 150.f;
	float collisionFix = 10.f;
	//|| checkColumn_1 = true || checkColumn_2 = true || checkColumn_3 = true || checkColumn_4 = true || checkColumn_5 = true

	if (IsKeyDown(KEY_A))
	{
		playerXPosition -= playerSpeed * GetFrameTime();
		if (checkWall_1 == true || checkWall_2 == true || checkWall_3 == true || checkWall_4 == true || checkWall_5 == true || checkWall_6 == true || checkWall_7 == true || checkWall_8 == true
			|| checkWall_9 == true || checkWall_10 == true || checkWall_11 == true || checkWall_12 == true || checkWall_13 == true || checkWall_14 == true || checkWall_15 == true || checkWall_16 == true
			|| checkWall_17 == true || checkWall_18 == true || checkWall_19 == true || checkWall_20 == true || checkWall_21 == true || checkColumn_1 == true || checkColumn_2 == true || checkColumn_3 == true
			|| checkColumn_4 == true || checkColumn_5 == true)
		{
			playerXPosition += playerSpeed * GetFrameTime() + collisionFix;
		}
	}
	if (IsKeyDown(KEY_D))
	{
		playerXPosition += playerSpeed * GetFrameTime();
		if (checkWall_1 == true || checkWall_2 == true || checkWall_3 == true || checkWall_4 == true || checkWall_5 == true || checkWall_6 == true || checkWall_7 == true || checkWall_8 == true
			|| checkWall_9 == true || checkWall_10 == true || checkWall_11 == true || checkWall_12 == true || checkWall_13 == true || checkWall_14 == true || checkWall_15 == true || checkWall_16 == true
			|| checkWall_17 == true || checkWall_18 == true || checkWall_19 == true || checkWall_20 == true || checkWall_21 == true || checkColumn_1 == true || checkColumn_2 == true || checkColumn_3 == true
			|| checkColumn_4 == true || checkColumn_5 == true)
		{
			playerXPosition -= playerSpeed * GetFrameTime() + collisionFix;
		}
	}
	if (IsKeyDown(KEY_W))
	{
		playerYPosition -= playerSpeed * GetFrameTime();
		if (checkWall_1 == true || checkWall_2 == true || checkWall_3 == true || checkWall_4 == true || checkWall_5 == true || checkWall_6 == true || checkWall_7 == true || checkWall_8 == true
			|| checkWall_9 == true || checkWall_10 == true || checkWall_11 == true || checkWall_12 == true || checkWall_13 == true || checkWall_14 == true || checkWall_15 == true || checkWall_16 == true
			|| checkWall_17 == true || checkWall_18 == true || checkWall_19 == true || checkWall_20 == true || checkWall_21 == true || checkColumn_1 == true || checkColumn_2 == true || checkColumn_3 == true
			|| checkColumn_4 == true || checkColumn_5 == true)
		{
			playerYPosition += playerSpeed * GetFrameTime() + collisionFix;
		}
	}
	if (IsKeyDown(KEY_S))
	{
		playerYPosition += playerSpeed * GetFrameTime();
		if (checkWall_1 == true || checkWall_2 == true || checkWall_3 == true || checkWall_4 == true || checkWall_5 == true || checkWall_6 == true || checkWall_7 == true || checkWall_8 == true
			|| checkWall_9 == true || checkWall_10 == true || checkWall_11 == true || checkWall_12 == true || checkWall_13 == true || checkWall_14 == true || checkWall_15 == true || checkWall_16 == true
			|| checkWall_17 == true || checkWall_18 == true || checkWall_19 == true || checkWall_20 == true || checkWall_21 == true || checkColumn_1 == true || checkColumn_2 == true || checkColumn_3 == true
			|| checkColumn_4 == true || checkColumn_5 == true)
		{
			playerYPosition -= playerSpeed * GetFrameTime() + collisionFix;
		}
	}
	playerCentre = { playerXPosition, playerYPosition };
}


int main()
{
	InitWindow(windowWidth, windowHeight, "Circle fight.Collision test");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		// Background
		BeginDrawing();
		ClearBackground(BLACK);

		// Player 
		DrawPlayer();
		PlayerController();

		// Draws the walls
		DrawWall_1();
		DrawWall_2();
		DrawWall_3();
		DrawWall_4();
		DrawWall_5();
		DrawWall_6();
		DrawWall_7();
		DrawWall_8();
		DrawWall_9();
		DrawWall_10();
		DrawWall_11();
		DrawWall_12();
		DrawWall_13();
		DrawWall_14();
		DrawWall_15();
		DrawWall_16();
		DrawWall_17();
		DrawWall_18();
		DrawWall_19();
		DrawWall_20();
		DrawWall_21();

		// Draws columns
		DrawColumn_1();
		DrawColumn_2();
		DrawColumn_3();
		DrawColumn_4();
		DrawColumn_5();

		// Stops drawing
		EndDrawing();
	}
	CloseWindow();

	return 0;
}