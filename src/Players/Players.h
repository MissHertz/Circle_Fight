#pragma once
#include <raylib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

class Environment;

class Player
{
public:

	// Global Variables
	float windowWidth = 1800;
	float windowHeight = 950;
	float windowHalfWidth = windowWidth / 2;
	float windowHalfHeight = windowHeight / 2;

	// Global Player Variables
	float playerXPosition = windowHalfWidth - 870;
	float playerYPosition = windowHalfHeight - 27;
	float player2XPosition = windowHalfWidth - 870;
	float player2YPosition = windowHalfHeight + 27;
	Vector2 playerCentre;
	float playerSpeed = 150.f;
	float collisionFix = 10.f;
	int health = 50;
	int maxHealth = 50;
	float radius = 20.0f;
	Color playerColor{ WHITE };
	Color player2color{ WHITE };
	Color smashColor{ GRAY };

	//constructor
	void DrawPlayer(Color inPlayerColor);
	void DrawPlayer2(Color inPlayer2Color);
	Player(float x, float y, int hp, float r);

	//functions
	void dealDamage(float damageDone);
	void PlayerController(Environment& ble);

	//bool IsPlayerInBounds()
	//{
	//	bool withinXBounds = playerXPosition >= 0 || playerXPosition <= windowWidth ? true : false;

	//	bool withinYBounds = playerYPosition >= 0 || playerYPosition <= windowHeight ? true : false;

	//	return withinXBounds && withinYBounds;
	//}

	void Player2Controller();

	//	bool IsPlayer2InBounds()
	//	{
	//		bool within2XBounds = player2Xposition >= 0 || player2Xposition <= windowWidth ? true : false;
	//
	//		bool within2YBounds = player2Yposition >= 0 || player2Yposition <= windowHeight ? true : false;
	//
	//		return within2XBounds && within2YBounds;
	//	}
	//};
	void TakeDamage(float dmg);
	void Heal(int hp);
	bool IsAlive();
};
