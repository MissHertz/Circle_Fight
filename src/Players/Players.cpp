#include "Players.h"
#include "../Circle_Fight/src/Environment/Environment.h"
#include "../Circle_Fight/src/Enemies/Enemies.h"

bool IsColliding(Vector2 p, float radius, Enemy& e);

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

Player::Player(float x, float y, int hp, float r)
{
	playerXPosition = x;
	playerYPosition = y;
	health = hp;
	maxHealth = hp;
	radius = r;
}
void Player::TakeDamage(float dmg)
{
	health -= dmg;
	if (health < 0) health = 0;
}

void Player::Heal(int hp)
{
	health += hp;
	if (health > maxHealth) health = maxHealth;
}

bool Player::IsAlive()
{
	return health > 0;
}

void Player::dealDamage(float damageDone)
{
	health -= damageDone;
	if (health < 0) health = 0;
}

void Player::PlayerController(Environment& ble, std::vector<Enemy>& enemies)
{
	float playerSpeed = 280.f;
	float increasedplayerSpeed = 1.4f;
	float reducedplayerSpeed = 0.5f;
	float collisionFix = 10.f;
	float smashXposition = playerXPosition;
	float smashYposition = playerYPosition;

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
			if (playerXPosition <= 0)
			{
				playerXPosition += playerSpeed * GetFrameTime() + collisionFix;
			}
		}
		playerCentre = { playerXPosition, playerYPosition };

		if (IsKeyPressed(KEY_Q))
		{
			float smashSize = 50.f;
			smashColor = DARKGRAY;
			Vector2 p;
			p.x = smashXposition - 80;
			p.y = smashYposition;
			DrawCircle(smashXposition - 80, smashYposition, smashSize, smashColor);

			for (auto& enemy : enemies)
			{
				if (enemy.IsAlive() && IsColliding(p, smashSize, enemy))
				{
					enemy.TakeDamage(25);
				}
			}
		}
	}

	if (IsKeyDown(KEY_D))
	{
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			playerXPosition += playerSpeed * increasedplayerSpeed * GetFrameTime();
			if ((ble.checkWall_1 == true || ble.checkWall_2 == true || ble.checkWall_3 == true || ble.checkWall_4 == true || ble.checkWall_5 == true || ble.checkWall_6 == true || ble.checkWall_7 == true || ble.checkWall_8 == true
				|| ble.checkWall_9 == true || ble.checkWall_10 == true || ble.checkWall_11 == true || ble.checkWall_12 == true || ble.checkWall_13 == true || ble.checkWall_14 == true || ble.checkWall_15 == true || ble.checkWall_16 == true
				|| ble.checkWall_17 == true || ble.checkWall_18 == true || ble.checkWall_19 == true || ble.checkWall_20 == true || ble.checkWall_21 == true || ble.checkColumn_1 == true || ble.checkColumn_2 == true || ble.checkColumn_3 == true
				|| ble.checkColumn_4 == true || ble.checkColumn_5 == true))
			{
				playerXPosition -= playerSpeed * increasedplayerSpeed * GetFrameTime() + collisionFix;
			}
		}
		if (IsKeyDown(KEY_LEFT_CONTROL))
		{
			playerXPosition += playerSpeed * reducedplayerSpeed * GetFrameTime();
			if (ble.checkWall_1 == true || ble.checkWall_2 == true || ble.checkWall_3 == true || ble.checkWall_4 == true || ble.checkWall_5 == true
				|| ble.checkWall_6 == true || ble.checkWall_7 == true || ble.checkWall_8 == true || ble.checkWall_9 == true || ble.checkWall_10 == true
				|| ble.checkWall_11 == true || ble.checkWall_12 == true || ble.checkWall_13 == true || ble.checkWall_14 == true || ble.checkWall_15 == true
				|| ble.checkWall_16 == true || ble.checkWall_17 == true || ble.checkWall_18 == true || ble.checkWall_19 == true || ble.checkWall_20 == true
				|| ble.checkWall_21 == true || ble.checkColumn_1 == true || ble.checkColumn_2 == true || ble.checkColumn_3 == true
				|| ble.checkColumn_4 == true || ble.checkColumn_5 == true)
			{
				playerXPosition -= playerSpeed * reducedplayerSpeed * GetFrameTime() + collisionFix;
			}
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
			if (playerXPosition >= windowWidth)
			{
				playerXPosition -= playerSpeed * GetFrameTime() + collisionFix;
			}
		}
		playerCentre = { playerXPosition, playerYPosition };

		if (IsKeyPressed(KEY_Q))
		{
			void Smash(Color rockColor);
			{
				float smashSize = 50.f;
				smashColor = DARKGRAY;
				Vector2 p;
				p.x = smashXposition + 80;
				p.y = smashYposition;
				DrawCircle(smashXposition + 80, smashYposition, smashSize, smashColor);

				for (auto& enemy : enemies)
				{
					if (enemy.IsAlive() && IsColliding(p, smashSize, enemy))
					{
						enemy.TakeDamage(25);
					}
				}
			}
		}
	}

	if (IsKeyDown(KEY_W))
	{
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			playerYPosition -= playerSpeed * increasedplayerSpeed * GetFrameTime();
			if ((ble.checkWall_1 == true || ble.checkWall_2 == true || ble.checkWall_3 == true || ble.checkWall_4 == true || ble.checkWall_5 == true || ble.checkWall_6 == true || ble.checkWall_7 == true || ble.checkWall_8 == true
				|| ble.checkWall_9 == true || ble.checkWall_10 == true || ble.checkWall_11 == true || ble.checkWall_12 == true || ble.checkWall_13 == true || ble.checkWall_14 == true || ble.checkWall_15 == true || ble.checkWall_16 == true
				|| ble.checkWall_17 == true || ble.checkWall_18 == true || ble.checkWall_19 == true || ble.checkWall_20 == true || ble.checkWall_21 == true || ble.checkColumn_1 == true || ble.checkColumn_2 == true || ble.checkColumn_3 == true
				|| ble.checkColumn_4 == true || ble.checkColumn_5 == true))
			{
				playerYPosition += playerSpeed * increasedplayerSpeed * GetFrameTime() + collisionFix;
			}
		}
		if (IsKeyDown(KEY_LEFT_CONTROL))
		{
			playerYPosition -= playerSpeed * reducedplayerSpeed * GetFrameTime();
			if (ble.checkWall_1 == true || ble.checkWall_2 == true || ble.checkWall_3 == true || ble.checkWall_4 == true || ble.checkWall_5 == true
				|| ble.checkWall_6 == true || ble.checkWall_7 == true || ble.checkWall_8 == true || ble.checkWall_9 == true || ble.checkWall_10 == true
				|| ble.checkWall_11 == true || ble.checkWall_12 == true || ble.checkWall_13 == true || ble.checkWall_14 == true || ble.checkWall_15 == true
				|| ble.checkWall_16 == true || ble.checkWall_17 == true || ble.checkWall_18 == true || ble.checkWall_19 == true || ble.checkWall_20 == true
				|| ble.checkWall_21 == true || ble.checkColumn_1 == true || ble.checkColumn_2 == true || ble.checkColumn_3 == true
				|| ble.checkColumn_4 == true || ble.checkColumn_5 == true)
			{
				playerYPosition += playerSpeed * reducedplayerSpeed * GetFrameTime() + collisionFix;
			}
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
			if (playerYPosition <= 0)
			{
				playerYPosition += playerSpeed * GetFrameTime() + collisionFix;
			}
		}
		playerCentre = { playerXPosition, playerYPosition };

		if (IsKeyPressed(KEY_Q))
		{
			float smashSize = 50.f;
			smashColor = DARKGRAY;
			Vector2 p;
			p.x = smashXposition;
			p.y = smashYposition - 80;
			DrawCircle(smashXposition, smashYposition - 80, smashSize, smashColor);

			for (auto& enemy : enemies)
			{
				if (enemy.IsAlive() && IsColliding(p, smashSize, enemy))
				{
					enemy.TakeDamage(25);
				}
			}
		}
	}

	if (IsKeyDown(KEY_S))
	{
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			playerYPosition += playerSpeed * increasedplayerSpeed * GetFrameTime();
			if ((ble.checkWall_1 == true || ble.checkWall_2 == true || ble.checkWall_3 == true || ble.checkWall_4 == true || ble.checkWall_5 == true || ble.checkWall_6 == true || ble.checkWall_7 == true || ble.checkWall_8 == true
				|| ble.checkWall_9 == true || ble.checkWall_10 == true || ble.checkWall_11 == true || ble.checkWall_12 == true || ble.checkWall_13 == true || ble.checkWall_14 == true || ble.checkWall_15 == true || ble.checkWall_16 == true
				|| ble.checkWall_17 == true || ble.checkWall_18 == true || ble.checkWall_19 == true || ble.checkWall_20 == true || ble.checkWall_21 == true || ble.checkColumn_1 == true || ble.checkColumn_2 == true || ble.checkColumn_3 == true
				|| ble.checkColumn_4 == true || ble.checkColumn_5 == true))
			{
				playerYPosition -= playerSpeed * increasedplayerSpeed * GetFrameTime() + collisionFix;
			}
		}
		if (IsKeyDown(KEY_LEFT_CONTROL))
		{
			playerYPosition += playerSpeed * reducedplayerSpeed * GetFrameTime();
			if (ble.checkWall_1 == true || ble.checkWall_2 == true || ble.checkWall_3 == true || ble.checkWall_4 == true || ble.checkWall_5 == true
				|| ble.checkWall_6 == true || ble.checkWall_7 == true || ble.checkWall_8 == true || ble.checkWall_9 == true || ble.checkWall_10 == true
				|| ble.checkWall_11 == true || ble.checkWall_12 == true || ble.checkWall_13 == true || ble.checkWall_14 == true || ble.checkWall_15 == true
				|| ble.checkWall_16 == true || ble.checkWall_17 == true || ble.checkWall_18 == true || ble.checkWall_19 == true || ble.checkWall_20 == true
				|| ble.checkWall_21 == true || ble.checkColumn_1 == true || ble.checkColumn_2 == true || ble.checkColumn_3 == true
				|| ble.checkColumn_4 == true || ble.checkColumn_5 == true)
			{
				playerYPosition -= playerSpeed * reducedplayerSpeed * GetFrameTime() + collisionFix;
			}
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
				playerYPosition -= playerSpeed * GetFrameTime() + collisionFix;
			}
			if (playerYPosition >= windowHeight)
			{
				playerYPosition -= playerSpeed * GetFrameTime() + collisionFix;
			}
		}
		playerCentre = { playerXPosition, playerYPosition };

		if (IsKeyPressed(KEY_Q))
		{
			float smashSize = 50.f;
			smashColor = DARKGRAY;
			Vector2 p;
			p.x = smashXposition;
			p.y = smashYposition + 80;
			DrawCircle(smashXposition, smashYposition + 80, smashSize, smashColor);

			for (auto& enemy : enemies)
			{
				if (enemy.IsAlive() && IsColliding(p, smashSize, enemy))
				{
					enemy.TakeDamage(25);
				}
			}
		}
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