#include "Environment.h"

bool Environment::DrawWall_1(Vector2 la)
{
	wall_1 = { 1, 350, 300, 10 };

	DrawRectangleRec(wall_1, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_1)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_1 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_1 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_2(Vector2 la)
{
	wall_2 = { 1, 550, 180, 10 };

	DrawRectangleRec(wall_2, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_2)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_2 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_2 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_3(Vector2 la)
{
	wall_3 = { 300, 1, 10, 200 };

	DrawRectangleRec(wall_3, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_3)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_3 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_3 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_4(Vector2 la)
{
	wall_4 = { 300, 550, 10, 250 };

	DrawRectangleRec(wall_4, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_4)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_4 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_4 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_5(Vector2 la)
{
	wall_5 = { 610, 300, 10, 280 };

	DrawRectangleRec(wall_5, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_5)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_5 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_5 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_6(Vector2 la)
{
	wall_6 = { 610, 300, 60, 10 };

	DrawRectangleRec(wall_6, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_6)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_6 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_6 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_7(Vector2 la)
{
	wall_7 = { 610, 580, 60, 10 };

	DrawRectangleRec(wall_7, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_7)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_7 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_7 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_8(Vector2 la)
{
	wall_8 = { 1130, 280, 10, 320 };

	DrawRectangleRec(wall_8, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_8)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_8 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_8 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_9(Vector2 la)
{
	wall_9 = { 1130, 280, 230, 10 };

	DrawRectangleRec(wall_9, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_9)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_9 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_9 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_10(Vector2 la)
{
	wall_10 = { 1130, 600, 350, 10 };

	DrawRectangleRec(wall_10, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_10)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_10 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_10 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_11(Vector2 la)
{
	wall_11 = { 1360, 280, 10, 160 };

	DrawRectangleRec(wall_11, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_11)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_11 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_11 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_12(Vector2 la)
{
	wall_12 = { 1360, 540, 10, 60 };

	DrawRectangleRec(wall_12, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_12)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_12 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_12 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_13(Vector2 la)
{
	wall_13 = { 1470, 600, 10, 140 };

	DrawRectangleRec(wall_13, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_13)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_13 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_13 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_14(Vector2 la)
{
	wall_14 = { 1350, 740, 130, 10 };

	DrawRectangleRec(wall_14, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_14)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_14 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_14 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_15(Vector2 la)
{
	wall_15 = { 1520, 150, 10, 100 };

	DrawRectangleRec(wall_15, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_15)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_15 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_15 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_16(Vector2 la)
{
	wall_16 = { 1520, 150, 80, 10 };

	DrawRectangleRec(wall_16, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_16)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_16 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_16 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_17(Vector2 la)
{
	wall_17 = { 1520, 250, 280, 10 };

	DrawRectangleRec(wall_17, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_17)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_17 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_17 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_18(Vector2 la)
{
	wall_18 = { 1600, 250, 10, 50 };

	DrawRectangleRec(wall_18, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_18)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_18 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_18 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_19(Vector2 la)
{
	wall_19 = { 1600, 430, 10, 230 };

	DrawRectangleRec(wall_19, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_19)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_19 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_19 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_20(Vector2 la)
{
	wall_20 = { 1600, 780, 10, 220 };

	DrawRectangleRec(wall_20, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_20)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_20 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_20 = false; //Sets variable to false so the code wont continue running on true
	return false;
}
bool Environment::DrawWall_21(Vector2 la)
{
	wall_21 = { 1600, 600, 200, 10 };

	DrawRectangleRec(wall_21, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, wall_21)) //Checks for collision 
	{
		//std::cout << "Collision detected!!" << std::endl; 
		checkWall_21 = true; //Sets variable to true, is used in the player movement if-sentence
		return true;
	}
	checkWall_21 = false; //Sets variable to false so the code wont continue running on true
	return false;
}

bool Environment::DrawColumn_1(Vector2 la)
{
	column_1 = { 420, 430, columnSizeX, columnSizeY };

	DrawRectangleRec(column_1, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, column_1))
	{
		checkColumn_1 = true;
		return true;
	}
	checkColumn_1 = false;
	return false;
}
bool Environment::DrawColumn_2(Vector2 la)
{
	column_2 = { 820, 100, columnSizeX, columnSizeY };

	DrawRectangleRec(column_2, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, column_2))
	{
		checkColumn_2 = true;
		return true;
	}
	checkColumn_2 = false;
	return false;
}
bool Environment::DrawColumn_3(Vector2 la)
{
	column_3 = { 1080, 100, columnSizeX, columnSizeY };

	DrawRectangleRec(column_3, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, column_3))
	{
		checkColumn_3 = true;
		return true;
	}
	checkColumn_3 = false;
	return false;
}
bool Environment::DrawColumn_4(Vector2 la)
{

	column_4 = { 820, 800, columnSizeX, columnSizeY };

	DrawRectangleRec(column_4, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, column_4))
	{
		checkColumn_4 = true;
		return true;
	}
	checkColumn_4 = false;
	return false;
}
bool Environment::DrawColumn_5(Vector2 la)
{
	column_5 = { 1080, 800, columnSizeX, columnSizeY };

	DrawRectangleRec(column_5, wallColor);

	if (CheckCollisionCircleRec(la, 20.f, column_5))
	{
		checkColumn_5 = true;
		return true;
	}
	checkColumn_5 = false;
	return false;
}

