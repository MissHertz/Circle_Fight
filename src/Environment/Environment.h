#pragma once
#include <raylib.h>
#include "../Circle_Fight/src/Players/Players.h"

class Environment
{

public: 
	
	// FUNCTIONS
	bool DrawWall_1();
	bool DrawWall_2();
	bool DrawWall_3();
	bool DrawWall_4();
	bool DrawWall_5();
	bool DrawWall_6();
	bool DrawWall_7();
	bool DrawWall_8();
	bool DrawWall_9();
	bool DrawWall_10();
	bool DrawWall_11();
	bool DrawWall_12();
	bool DrawWall_13();
	bool DrawWall_14();
	bool DrawWall_15();
	bool DrawWall_16();
	bool DrawWall_17();
	bool DrawWall_18();
	bool DrawWall_19();
	bool DrawWall_20();
	bool DrawWall_21();
	
	bool DrawColumn_1();
	bool DrawColumn_2();
	bool DrawColumn_3();
	bool DrawColumn_4();
	bool DrawColumn_5();
	
	// GLOBAL VARIABLES
	// Wall variables
	 bool checkWall_1;
	static bool checkWall_2;
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

