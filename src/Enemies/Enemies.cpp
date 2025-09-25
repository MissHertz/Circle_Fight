//#include "Enemies.h"
//#include "raylib.h"
//#include <algorithm>
//#include <cmath>
//#include <vector>
//
//// Constructor
//Enemy::Enemy(float x, float y, int hp, int enemyR)
//{
//	enemyXPosition = x;
//	enemyYPosition = y;
//	health = hp;
//	maxHealth = hp;
//	enemyR = 25;
//};
//
//bool IsColliding(Players& p, Enemy& e)
//{
//	float dx = p.rock_SlingerXposition - e.enemyXPosition;
//	float dy = p.rock_SlingerYposition - e.enemyYPosition;
//	float distance = sqrtf(dx * dx + dy * dy);
//	return distance < p.rock_SlingerSize + e.radius;
//};
//
//// Create multiple enemies
//std::vector<Enemy> enemies;
//enemies.emplace_back(200, 200, 50, 20.0f);
//enemies.emplace_back(500, 300, 50, 20.0f);
//enemies.emplace_back(1400, 600, 50, 20.0f);
//enemies.emplace_back(1600, 600, 50, 20.0f);
//enemies.emplace_back(1800, 600, 50, 20.0f);
//
//bool gameOver = false;
//
//// Draw enemy with health bar
//void Enemy::DrawEnemy(Color inEnemyColor)
//{
//	enemyColor = inEnemyColor;
//
//	// Enemy circle
//	DrawCircle(enemyXPosition, enemyYPosition, radius, enemyColor);
//
//	// Health bar background
//	float barWidth = radius * 2;
//	float barHeight = 5;
//	float barX = enemyXPosition - radius;
//	float barY = enemyYPosition - radius - 15;
//
//	DrawRectangle(barX, barY, barWidth, barHeight, GRAY);
//
//	// Current health portion
//	float healthPercent = (float)health / maxHealth;
//	DrawRectangle(barX, barY, barWidth * healthPercent, barHeight, GREEN);
//};
//
//void Enemy::UpdateEnemy(float targetX, float targetY)
//{
//	float speed = 100.0f * GetFrameTime();
//
//	float dx = targetX - enemyXPosition;
//	float dy = targetY - enemyYPosition;
//	float distance = sqrtf(dx * dx + dy * dy);
//
//	if (distance > 1.0f)
//	{
//		enemyXPosition += (dx / distance) * speed;
//		enemyYPosition += (dy / distance) * speed;
//	};
//};
//
//// Damage functions
//void Enemy::TakeDamage(int dmg)
//{
//	health -= dmg;
//	if (health < 0) health = 0;
//};
//
//void Enemy::Heal(int hp)
//{
//	health += hp;
//	if (health > maxHealth) health = maxHealth;
//};
//
//bool Enemy::IsAlive()
//{
//	return health > 0;
//};
//
//bool gameOver = false;
//
//while (!WindowShouldClose())
//{
//	if (!gameOver)
//	{
//		// --- Update ---
//		player.PlayerController(); // WASD controls
//
//		for (auto& enemy : enemies)
//		{
//			if (enemy.IsAlive())
//			{
//				enemy.UpdateEnemy(player.playerXPosition, player.playerYPosition);
//
//				// Enemy damages player on collision
//				if (IsColliding(player, enemy))
//				{
//					player.TakeDamage(1);
//				}
//			}
//		}
//
//		// Player attack (press E)
//		if (IsKeyPressed(KEY_E))
//		{
//			for (auto& enemy : enemies)
//			{
//				if (enemy.IsAlive() && IsColliding(player, enemy))
//				{
//					enemy.TakeDamage(20);
//				}
//			}
//		}
//
//		if (!player.IsAlive())
//		{
//			gameOver = true;
//		}
//	}
//	else
//	{
//		// Restart game when ENTER is pressed
//		if (IsKeyPressed(KEY_ENTER))
//		{
//			player = Player(900, 475, 100, 20.0f); // reset player
//
//			enemies.clear(); // reset enemies
//			enemies.emplace_back(200, 200, 50, 20.0f);
//			enemies.emplace_back(500, 300, 50, 20.0f);
//			enemies.emplace_back(1400, 600, 50, 20.0f);
//			enemies.emplace_back(1600, 600, 50, 20.0f);
//			enemies.emplace_back(1800, 600, 50, 20.0f);
//
//			gameOver = false;
//		}
//	}
//
//	// --- Draw ---
//	BeginDrawing();
//	ClearBackground(BLACK);
//
//	if (!gameOver)
//	{
//		player.DrawPlayer(WHITE);
//
//		for (auto& enemy : enemies)
//		{
//			if (enemy.IsAlive())
//				enemy.DrawEnemy(RED);
//		}
//
//		DrawText(TextFormat("Health: %d", player.health), 20, 20, 30, GREEN);
//		DrawText("WASD = Move | E = Attack (must touch enemy)", 20, 60, 20, LIGHTGRAY);
//	}
//	else
//	{
//		const char* msg = "YOU DIED";
//		int fontSize = 100;
//		int textWidth = MeasureText(msg, fontSize);
//		DrawText(msg, (GetScreenWidth() - textWidth) / 2, GetScreenHeight() / 2 - 100, fontSize, RED);
//
//		const char* restartMsg = "Press ENTER to play again";
//		int restartWidth = MeasureText(restartMsg, 40);
//		DrawText(restartMsg, (GetScreenWidth() - restartWidth) / 2, GetScreenHeight() / 2, 40, WHITE);
//	}
//
//	EndDrawing();
//}
//
//CloseWindow();
//return 0;
//}