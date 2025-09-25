#pragma once
#include <raylib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

class Players
{
public:

	// Global Variables
	float windowWidth = 1800;
	float windowHeight = 950;
	float windowHalfWidth = windowWidth / 2;
	float windowHalfHeight = windowHeight / 2;

	// Global Player Variables
	float rock_SlingerXposition = windowHalfWidth - 870;
	float rock_SlingerYposition = windowHalfHeight - 27;
	float rock_SlingerSize = 20.f;
	Color rock_SlingerColor{ WHITE };
	float swordsmanXposition = windowHalfWidth - 870;
	float swordsmanYposition = windowHalfHeight + 27;
	float swordsmanSize = 30.f;
	Color swordsmanColor{ WHITE };

	//constructor
	void DrawRock_Slinger(Color inPlayerColor);
	void DrawSwordsman(Color inPlayer2Color);

	//functions
	void rock_SlingerController();

	//bool IsPlayerInBounds()
	//{
	//	bool withinXBounds = playerXPosition >= 0 || playerXPosition <= windowWidth ? true : false;

	//	bool withinYBounds = playerYPosition >= 0 || playerYPosition <= windowHeight ? true : false;

	//	return withinXBounds && withinYBounds;
	//}

	void swordsmanController();

	//	bool IsPlayer2InBounds()
	//	{
	//		bool within2XBounds = player2Xposition >= 0 || player2Xposition <= windowWidth ? true : false;
	//
	//		bool within2YBounds = player2Yposition >= 0 || player2Yposition <= windowHeight ? true : false;
	//
	//		return within2XBounds && within2YBounds;
	//	}
	//};
};
