#include "raylib.h"
#include <iostream>

float windowWidth = 1800.f;
float windowHeight = 950.f;
float windowHalfWidth = windowWidth / 2.f;
float windowHalfHeight = windowHeight / 2.f;

// Player Variables
float playerXPosition = 150;
//float playerXPosition = windowHalfWidth
float playerYPosition = windowHalfHeight;

// Wall variables
float wallXPosition;
float wallYPosition;
float wallHeight;
float wallWidth;
Rectangle myRectangle;
Color wallColor; 


// Draws a wall 
void DrawWall(int inWallXPosition, int inWallYPosition, int inWallHeight, int inWallWidth, Color inWallColor)
{
	wallXPosition = inWallXPosition;
	wallYPosition = inWallYPosition;
	wallHeight = inWallHeight;
	wallWidth = inWallWidth; 
	wallColor = inWallColor;

	myRectangle = { wallXPosition, wallYPosition, wallHeight, wallWidth };

	DrawRectangleRec(myRectangle, wallColor);
}
// Creating player character
void DrawPlayer()
{
	float drawPlayerSize = 35.f;
	Color playerColor = { 102, 0, 102, 255 };
	DrawCircle(playerXPosition, playerYPosition, drawPlayerSize, playerColor);

}

// Checks for collision between player and wall
bool isPlayerCollidingWithWall(Vector2 centre) {
	if (CheckCollisionCircleRec(centre, 35.0f, myRectangle)) {
		return true;
	}
	return false;
}

// Player movement
void PlayerController(Vector2 centre)
{
	float playerSpeed = 150.f;
	float collisionFix = 5.0f;
	if (IsKeyDown(KEY_A))
	{
		playerXPosition -= playerSpeed * GetFrameTime();
		//std::cout << "A is pressed! \n";
		if (isPlayerCollidingWithWall(centre)) {
			playerXPosition += playerSpeed * GetFrameTime() + 10.0f; // undos movement
		}
	}

	if (IsKeyDown(KEY_D))
	{
		playerXPosition += playerSpeed * GetFrameTime();
		//std::cout << "D is pressed! \n";
		if (isPlayerCollidingWithWall(centre)) {
			playerXPosition -= playerSpeed * GetFrameTime() + 10.0f; // undos movement
		}
	}

	if (IsKeyDown(KEY_W))
	{
		playerYPosition -= playerSpeed * GetFrameTime();
		//std::cout << "W is pressed! \n";
		if (isPlayerCollidingWithWall(centre)) {
			playerYPosition += playerSpeed * GetFrameTime() + 10.0f; // undos movement
		}
	}
	if (IsKeyDown(KEY_S))
	{
		playerYPosition += playerSpeed * GetFrameTime();
		//std::cout << "S is pressed! \n";
		if (isPlayerCollidingWithWall(centre)) {
			playerYPosition -= playerSpeed * GetFrameTime() + 10.0f; // undos movement
		}
	}
}


int main()
{
	InitWindow(windowWidth, windowHeight, "Circle fight.test");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		// Background
		BeginDrawing();
		ClearBackground(BLACK);
		Vector2 playerCentre = { playerXPosition, playerYPosition };
		DrawWall(100, 100, 20, 10, ORANGE);
		DrawWall(1, 350, 300, 10, ORANGE);


		// Player
		DrawPlayer();

		PlayerController(playerCentre);
		if (CheckCollisionCircleRec(playerCentre, 35.0f, myRectangle) == true) {
			std::cout << "Collision detected!!" << std::endl;
		}

		EndDrawing();
	}
	CloseWindow();

	return 0;
}