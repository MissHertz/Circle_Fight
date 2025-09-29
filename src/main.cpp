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
#include "src/Enemies/Enemies.h"

// Global Variables
float windowWidth = 1800;
float windowHeight = 950;
float windowHalfWidth = windowWidth / 2;
float windowHalfHeight = windowHeight / 2;
bool IsColliding(Vector2 p, float radius, Enemy& e)
{
	float dx = p.x - e.enemyXPosition;
	float dy = p.y - e.enemyYPosition;
	float distance = sqrtf(dx * dx + dy * dy);
	return distance < radius + e.radius;
}

int main()
{
	InitWindow(windowWidth, windowHeight, "Circle Fight!");

	SetTargetFPS(60);
	// Create player
	Player player(900, 475, 100, 20.0f);

	// Create multiple enemies
	std::vector<Enemy> enemies;
	enemies.emplace_back(200, 200, 50, 20.0f);
	enemies.emplace_back(500, 300, 50, 20.0f);
	enemies.emplace_back(1400, 600, 50, 20.0f);
	enemies.emplace_back(1600, 600, 50, 20.0f);
	enemies.emplace_back(1800, 600, 50, 20.0f);

	bool gameOver = false;

	Environment Env;

	//Player Player2;

	while (!WindowShouldClose())
	{
		if (!gameOver)
		{
			// --- Update ---
			void PlayerController(Environment & ble); // WASD controls

			for (auto& enemy : enemies)
			{
				if (enemy.IsAlive())
				{
					enemy.UpdateEnemy(player.playerXPosition, player.playerYPosition);

					// Enemy damages player on collision
					Vector2 p;
					p.x = player.playerXPosition;
					p.y = player.playerYPosition;
					if (IsColliding(p, player.radius, enemy))
					{
						player.TakeDamage(1);
					}
				}
			}

			// Player attack (press E)
			if (IsKeyPressed(KEY_E))
			{
				float smashRadius = 70.f;
				Color smashColor = SKYBLUE;
				float smashXlocation = player.playerXPosition;
				float smashYlocation = player.playerYPosition;
				DrawCircle(smashXlocation, smashYlocation, smashRadius, smashColor);
				Vector2 p;
				p.x = smashXlocation;
				p.y = smashYlocation;

				for (auto& enemy : enemies)
				{
					if (enemy.IsAlive() && IsColliding(p, smashRadius, enemy))
					{
						enemy.TakeDamage(8);
					}
				}
			}

			if (!player.IsAlive())
			{
				gameOver = true;
			}
		}
		else
		{
			// Restart game when ENTER is pressed
			if (IsKeyPressed(KEY_ENTER))
			{
				player = Player(900, 475, 100, 20.0f); // reset player

				enemies.clear(); // reset enemies
				enemies.emplace_back(200, 200, 50, 20.0f);
				enemies.emplace_back(500, 300, 50, 20.0f);
				enemies.emplace_back(1400, 600, 50, 20.0f);
				enemies.emplace_back(1600, 600, 50, 20.0f);
				enemies.emplace_back(1800, 600, 50, 20.0f);

				gameOver = false;
			}
		}
		BeginDrawing();

		ClearBackground(BLACK);

		DrawFPS(10, 10);

		player.DrawPlayer(YELLOW);

		//Player2.DrawPlayer2(RED);

		player.PlayerController(Env, enemies);

		//Player2.Player2Controller();

		// Draw Walls and columns
		Env.DrawWall_1(player.playerCentre);
		Env.DrawWall_2(player.playerCentre);
		Env.DrawWall_3(player.playerCentre);
		Env.DrawWall_4(player.playerCentre);
		Env.DrawWall_5(player.playerCentre);
		Env.DrawWall_6(player.playerCentre);
		Env.DrawWall_7(player.playerCentre);
		Env.DrawWall_8(player.playerCentre);
		Env.DrawWall_9(player.playerCentre);
		Env.DrawWall_10(player.playerCentre);
		Env.DrawWall_11(player.playerCentre);
		Env.DrawWall_12(player.playerCentre);
		Env.DrawWall_13(player.playerCentre);
		Env.DrawWall_14(player.playerCentre);
		Env.DrawWall_15(player.playerCentre);
		Env.DrawWall_16(player.playerCentre);
		Env.DrawWall_17(player.playerCentre);
		Env.DrawWall_18(player.playerCentre);
		Env.DrawWall_19(player.playerCentre);
		Env.DrawWall_20(player.playerCentre);
		Env.DrawWall_21(player.playerCentre);

		Env.DrawColumn_1(player.playerCentre);
		Env.DrawColumn_2(player.playerCentre);
		Env.DrawColumn_3(player.playerCentre);
		Env.DrawColumn_4(player.playerCentre);
		Env.DrawColumn_5(player.playerCentre);

		if (!gameOver)
		{
			player.DrawPlayer(YELLOW);

			for (auto& enemy : enemies)
			{
				if (enemy.IsAlive())
					enemy.DrawEnemy();
			}

			DrawText(TextFormat("Health: %d", player.health), 20, 20, 30, GREEN);
			DrawText("WASD = Move | E = Attack (must touch enemy)  |  Q = Smash", 20, 60, 20, LIGHTGRAY);
		}
		else
		{
			const char* msg = "YOU DIED";
			int fontSize = 100;
			int textWidth = MeasureText(msg, fontSize);
			DrawText(msg, (GetScreenWidth() - textWidth) / 2, GetScreenHeight() / 2 - 100, fontSize, RED);

			const char* restartMsg = "Press ENTER to play again";
			int restartWidth = MeasureText(restartMsg, 40);
			DrawText(restartMsg, (GetScreenWidth() - restartWidth) / 2, GetScreenHeight() / 2, 40, WHITE);
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}