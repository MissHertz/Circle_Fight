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
	Player Player1(Env);
	//Player Player2;

	/*Environment Wall2;
	Environment Wall3;
	Environment Wall4;
	Environment Wall5;
	Environment Wall6;
	Environment Wall7;
	Environment Wall8;
	Environment Wall9;
	Environment Wall10;
	Environment Wall11;
	Environment Wall12;
	Environment Wall13;
	Environment Wall14;
	Environment Wall15;
	Environment Wall16;
	Environment Wall17;
	Environment Wall18;
	Environment Wall19;
	Environment Wall20;
	Environment Wall21;

	Environment Column1; 
	Environment Column2; 
	Environment Column3; 
	Environment Column4; 
	Environment Column5; */

	while (!WindowShouldClose())
	{
		BeginDrawing();
		
		ClearBackground(BLACK);

		DrawFPS(10, 10);

		Player1.DrawPlayer(YELLOW);

		//Player2.DrawPlayer2(RED);

		Player1.PlayerController();

		//Player2.Player2Controller();

		// Draw Walls and columns
		Env.DrawWall_1();
		Env.DrawWall_2();
		/*Wall3.DrawWall_3();
		Wall4.DrawWall_4();
		Wall5.DrawWall_5();
		Wall6.DrawWall_6();
		Wall7.DrawWall_7();
		Wall8.DrawWall_8();
		Wall9.DrawWall_9();
		Wall10.DrawWall_10();
		Wall11.DrawWall_11();
		Wall12.DrawWall_12();
		Wall13.DrawWall_13();
		Wall14.DrawWall_14();
		Wall15.DrawWall_15();
		Wall16.DrawWall_16();
		Wall17.DrawWall_17();
		Wall18.DrawWall_18();
		Wall19.DrawWall_19();
		Wall20.DrawWall_20();
		Wall21.DrawWall_21();*/


		EndDrawing();
	}

	CloseWindow();
}