#pragma once
#include <raylib.h>
#include "../Circle_Fight/src/Players/Players.h"

class Environment
{

public: 
	
	// FUNCTIONS
	bool DrawWall_1(Vector2 la);
	bool DrawWall_2(Vector2 la);
	bool DrawWall_3(Vector2 la);
	bool DrawWall_4(Vector2 la);
	bool DrawWall_5(Vector2 la);
	bool DrawWall_6(Vector2 la);
	bool DrawWall_7(Vector2 la);
	bool DrawWall_8(Vector2 la);
	bool DrawWall_9(Vector2 la);
	bool DrawWall_10(Vector2 la);
	bool DrawWall_11(Vector2 la);
	bool DrawWall_12(Vector2 la);
	bool DrawWall_13(Vector2 la);
	bool DrawWall_14(Vector2 la);
	bool DrawWall_15(Vector2 la);
	bool DrawWall_16(Vector2 la);
	bool DrawWall_17(Vector2 la);
	bool DrawWall_18(Vector2 la);
	bool DrawWall_19(Vector2 la);
	bool DrawWall_20(Vector2 la);
	bool DrawWall_21(Vector2 la);
	
	bool DrawColumn_1(Vector2 la);
	bool DrawColumn_2(Vector2 la);
	bool DrawColumn_3(Vector2 la);
	bool DrawColumn_4(Vector2 la);
	bool DrawColumn_5(Vector2 la);
	
	// GLOBAL VARIABLES
	// Wall variables
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
	// Column variables
	 bool checkColumn_1;
	 bool checkColumn_2;
	 bool checkColumn_3;
	 bool checkColumn_4;
	 bool checkColumn_5;

	// VARIABLES
	Color wallColor = { 255, 161, 0, 255 };
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

	// Column variables
	Rectangle column_1;
	Rectangle column_2;
	Rectangle column_3;
	Rectangle column_4;
	Rectangle column_5;
	float columnSizeX = 50;
	float columnSizeY = 50;
};

