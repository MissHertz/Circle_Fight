#include "Players.h"
#include "../Circle_Fight/src/Environment/Environment.h"


void Player::DrawPlayer(Color inPlayerColor)
{
	float playerSize = 20.f;
	playerColor = inPlayerColor;
	DrawCircle(playerXPosition, playerYPosition, playerSize, playerColor);
}

void Player::DrawPlayer2(Color inPlayer2Color)
{
	float player2size = 30.f;
	player2color = inPlayer2Color;
	DrawCircle(player2XPosition, player2YPosition, player2size, player2color);
}

void Player::PlayerController(Environment& ble)
{
	float playerSpeed = 280.f;
	float increasedplayerSpeed = 1.4f;
	float reducedplayerSpeed = 0.5f;
	float collisionFix = 10.f;

	if (IsKeyDown(KEY_A))
	{
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			playerXPosition -= playerSpeed * increasedplayerSpeed * GetFrameTime();
			if ((ble.checkWall_1 == true || ble.checkWall_2 == true || ble.checkWall_3 == true || ble.checkWall_4 == true || ble.checkWall_5 == true || ble.checkWall_6 == true || ble.checkWall_7 == true || ble.checkWall_8 == true
				|| ble.checkWall_9 == true || ble.checkWall_10 == true || ble.checkWall_11 == true || ble.checkWall_12 == true || ble.checkWall_13 == true || ble.checkWall_14 == true || ble.checkWall_15 == true || ble.checkWall_16 == true
				|| ble.checkWall_17 == true || ble.checkWall_18 == true || ble.checkWall_19 == true || ble.checkWall_20 == true || ble.checkWall_21 == true || ble.checkColumn_1 == true || ble.checkColumn_2 == true || ble.checkColumn_3 == true
				|| ble.checkColumn_4 == true || ble.checkColumn_5 == true))
			{
				playerXPosition += playerSpeed * increasedplayerSpeed * GetFrameTime() + collisionFix;
			}
		}

		if (IsKeyDown(KEY_LEFT_CONTROL))
		{
			playerXPosition -= playerSpeed * reducedplayerSpeed * GetFrameTime();
			if (ble.checkWall_1 == true || ble.checkWall_2 == true || ble.checkWall_3 == true || ble.checkWall_4 == true || ble.checkWall_5 == true
				|| ble.checkWall_6 == true || ble.checkWall_7 == true || ble.checkWall_8 == true || ble.checkWall_9 == true || ble.checkWall_10 == true
				|| ble.checkWall_11 == true || ble.checkWall_12 == true || ble.checkWall_13 == true || ble.checkWall_14 == true || ble.checkWall_15 == true
				|| ble.checkWall_16 == true || ble.checkWall_17 == true || ble.checkWall_18 == true || ble.checkWall_19 == true || ble.checkWall_20 == true
				|| ble.checkWall_21 == true || ble.checkColumn_1 == true || ble.checkColumn_2 == true || ble.checkColumn_3 == true
				|| ble.checkColumn_4 == true || ble.checkColumn_5 == true)
			{
				playerXPosition += playerSpeed * reducedplayerSpeed * GetFrameTime() + collisionFix;
			}
		}

		else
		{
			playerXPosition -= playerSpeed * GetFrameTime();
			if (ble.checkWall_1 == true || ble.checkWall_2 == true || ble.checkWall_3 == true || ble.checkWall_4 == true || ble.checkWall_5 == true
				|| ble.checkWall_6 == true || ble.checkWall_7 == true || ble.checkWall_8 == true || ble.checkWall_9 == true || ble.checkWall_10 == true
				|| ble.checkWall_11 == true || ble.checkWall_12 == true || ble.checkWall_13 == true || ble.checkWall_14 == true || ble.checkWall_15 == true
				|| ble.checkWall_16 == true || ble.checkWall_17 == true || ble.checkWall_18 == true || ble.checkWall_19 == true || ble.checkWall_20 == true
				|| ble.checkWall_21 == true || ble.checkColumn_1 == true || ble.checkColumn_2 == true || ble.checkColumn_3 == true
				|| ble.checkColumn_4 == true || ble.checkColumn_5 == true)
			{
				playerXPosition += playerSpeed * GetFrameTime() + collisionFix;
			}
		}
		player1Centre = { playerXPosition, playerYPosition };
	}

	if (IsKeyDown(KEY_D))
	{
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			playerXPosition += playerSpeed * increasedplayerSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_LEFT_CONTROL))
		{
			playerXPosition += playerSpeed * reducedplayerSpeed * GetFrameTime();
		}
		else
		{
			playerXPosition += playerSpeed * GetFrameTime();
			if (ble.checkWall_1 == true || ble.checkWall_2 == true || ble.checkWall_3 == true || ble.checkWall_4 == true || ble.checkWall_5 == true
				|| ble.checkWall_6 == true || ble.checkWall_7 == true || ble.checkWall_8 == true || ble.checkWall_9 == true || ble.checkWall_10 == true
				|| ble.checkWall_11 == true || ble.checkWall_12 == true || ble.checkWall_13 == true || ble.checkWall_14 == true || ble.checkWall_15 == true
				|| ble.checkWall_16 == true || ble.checkWall_17 == true || ble.checkWall_18 == true || ble.checkWall_19 == true || ble.checkWall_20 == true
				|| ble.checkWall_21 == true || ble.checkColumn_1 == true || ble.checkColumn_2 == true || ble.checkColumn_3 == true
				|| ble.checkColumn_4 == true || ble.checkColumn_5 == true)
			{
				playerXPosition -= playerSpeed * GetFrameTime() + collisionFix;
			}
		}
		player1Centre = { playerXPosition, playerYPosition };
	}

	if (IsKeyDown(KEY_W))
	{
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			playerYPosition -= playerSpeed * increasedplayerSpeed * GetFrameTime();
		}

		if (IsKeyDown(KEY_LEFT_CONTROL))
		{
			playerYPosition -= playerSpeed * reducedplayerSpeed * GetFrameTime();
		}

		else
		{
			playerYPosition -= playerSpeed * GetFrameTime();
			if (ble.checkWall_1 == true || ble.checkWall_2 == true || ble.checkWall_3 == true || ble.checkWall_4 == true || ble.checkWall_5 == true
				|| ble.checkWall_6 == true || ble.checkWall_7 == true || ble.checkWall_8 == true || ble.checkWall_9 == true || ble.checkWall_10 == true
				|| ble.checkWall_11 == true || ble.checkWall_12 == true || ble.checkWall_13 == true || ble.checkWall_14 == true || ble.checkWall_15 == true
				|| ble.checkWall_16 == true || ble.checkWall_17 == true || ble.checkWall_18 == true || ble.checkWall_19 == true || ble.checkWall_20 == true
				|| ble.checkWall_21 == true || ble.checkColumn_1 == true || ble.checkColumn_2 == true || ble.checkColumn_3 == true
				|| ble.checkColumn_4 == true || ble.checkColumn_5 == true)
			{
				playerYPosition += playerSpeed * GetFrameTime() + collisionFix;
			}
		}
		player1Centre = { playerXPosition, playerYPosition };
	}

	if (IsKeyDown(KEY_S))
	{
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			playerYPosition += playerSpeed * increasedplayerSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_LEFT_CONTROL))
		{
			playerYPosition += playerSpeed * reducedplayerSpeed * GetFrameTime();
		}
		else
		{
			playerYPosition += playerSpeed * GetFrameTime();
			if (ble.checkWall_1 == true || ble.checkWall_2 == true || ble.checkWall_3 == true || ble.checkWall_4 == true || ble.checkWall_5 == true
				|| ble.checkWall_6 == true || ble.checkWall_7 == true || ble.checkWall_8 == true || ble.checkWall_9 == true || ble.checkWall_10 == true
				|| ble.checkWall_11 == true || ble.checkWall_12 == true || ble.checkWall_13 == true || ble.checkWall_14 == true || ble.checkWall_15 == true
				|| ble.checkWall_16 == true || ble.checkWall_17 == true || ble.checkWall_18 == true || ble.checkWall_19 == true || ble.checkWall_20 == true
				|| ble.checkWall_21 == true || ble.checkColumn_1 == true || ble.checkColumn_2 == true || ble.checkColumn_3 == true
				|| ble.checkColumn_4 == true || ble.checkColumn_5 == true)
			{
				playerXPosition -= playerSpeed * GetFrameTime() + collisionFix;
			}
		}
		player1Centre = { playerXPosition, playerYPosition };
	}
}

void Player::Player2Controller()
{
	float player2Speed = 200.f;
	float increasedplayer2Speed = 1.6f;
	float reducedplayer2Speed = 0.7f;

	if (IsKeyDown(KEY_LEFT))
	{
		if (IsKeyDown(KEY_RIGHT_SHIFT))
		{
			player2XPosition -= player2Speed * increasedplayer2Speed * GetFrameTime();
		}

		if (IsKeyDown(KEY_RIGHT_ALT))
		{
			player2XPosition -= player2Speed * reducedplayer2Speed * GetFrameTime();
		}

		else
		{
			player2XPosition -= player2Speed * GetFrameTime();
		}
	}

	if (IsKeyDown(KEY_RIGHT))
	{
		if (IsKeyDown(KEY_RIGHT_SHIFT))
		{
			player2XPosition += player2Speed * increasedplayer2Speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_RIGHT_ALT))
		{
			player2XPosition += player2Speed * reducedplayer2Speed * GetFrameTime();
		}
		else
		{
			player2XPosition += player2Speed * GetFrameTime();
		}
	}

	if (IsKeyDown(KEY_UP))
	{
		if (IsKeyDown(KEY_RIGHT_SHIFT))
		{
			player2YPosition -= player2Speed * increasedplayer2Speed * GetFrameTime();
		}

		if (IsKeyDown(KEY_RIGHT_ALT))
		{
			player2YPosition -= player2Speed * reducedplayer2Speed * GetFrameTime();
		}

		else
		{
			player2YPosition -= player2Speed * GetFrameTime();
		}
	}

	if (IsKeyDown(KEY_DOWN))
	{
		if (IsKeyDown(KEY_RIGHT_SHIFT))
		{
			player2YPosition += player2Speed * increasedplayer2Speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_RIGHT_ALT))
		{
			player2YPosition += player2Speed * reducedplayer2Speed * GetFrameTime();
		}
		else
		{
			player2YPosition += player2Speed * GetFrameTime();
		}
	}
}