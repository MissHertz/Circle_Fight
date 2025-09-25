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
bool IsColliding(Player& p, Enemy& e)
{
	float dx = p.playerXPosition - e.enemyXPosition;
	float dy = p.playerYPosition - e.enemyYPosition;
	float distance = sqrtf(dx * dx + dy * dy);
	return distance < p.radius + e.radius;
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
	Player Player1{};
	//Player Player2;

	while (!WindowShouldClose())
	{
		if (!gameOver)
		{
			// --- Update ---
			player.PlayerController(); // WASD controls

			for (auto& enemy : enemies)
			{
				if (enemy.IsAlive())
				{
					enemy.UpdateEnemy(player.playerXPosition, player.playerYPosition);

					// Enemy damages player on collision
					if (IsColliding(player, enemy))
					{
						player.TakeDamage(1);
					}
				}
			}

			// Player attack (press E)
			if (IsKeyPressed(KEY_E))
			{
				for (auto& enemy : enemies)
				{
					if (enemy.IsAlive() && IsColliding(player, enemy))
					{
						enemy.TakeDamage(20);
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

		Player1.DrawPlayer(YELLOW);

		//Player2.DrawPlayer2(RED);

		Player1.PlayerController(Env);

		//Player2.Player2Controller();

		// Draw Walls and columns
		Env.DrawWall_1(Player1.player1Centre);
		Env.DrawWall_2(Player1.player1Centre);
		Env.DrawWall_3(Player1.player1Centre);
		Env.DrawWall_4(Player1.player1Centre);
		Env.DrawWall_5(Player1.player1Centre);
		Env.DrawWall_6(Player1.player1Centre);
		Env.DrawWall_7(Player1.player1Centre);
		Env.DrawWall_8(Player1.player1Centre);
		Env.DrawWall_9(Player1.player1Centre);
		Env.DrawWall_10(Player1.player1Centre);
		Env.DrawWall_11(Player1.player1Centre);
		Env.DrawWall_12(Player1.player1Centre);
		Env.DrawWall_13(Player1.player1Centre);
		Env.DrawWall_14(Player1.player1Centre);
		Env.DrawWall_15(Player1.player1Centre);
		Env.DrawWall_16(Player1.player1Centre);
		Env.DrawWall_17(Player1.player1Centre);
		Env.DrawWall_18(Player1.player1Centre);
		Env.DrawWall_19(Player1.player1Centre);
		Env.DrawWall_20(Player1.player1Centre);
		Env.DrawWall_21(Player1.player1Centre);

		Env.DrawColumn_1(Player1.player1Centre);
		Env.DrawColumn_2(Player1.player1Centre);
		Env.DrawColumn_3(Player1.player1Centre);
		Env.DrawColumn_4(Player1.player1Centre);
		Env.DrawColumn_5(Player1.player1Centre);
		
        if (!gameOver)
        {
            player.DrawPlayer(WHITE);

            for (auto& enemy : enemies)
            {
                if (enemy.IsAlive())
                    enemy.DrawEnemy(RED);
            }

            DrawText(TextFormat("Health: %d", player.health), 20, 20, 30, GREEN);
            DrawText("WASD = Move | E = Attack (must touch enemy)", 20, 60, 20, LIGHTGRAY);
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
