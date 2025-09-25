#include <raylib.h>
#include "src/Players/Players.h"
#include "src/Enemies/Enemies.h"
#include <vector>
#include <cmath>

bool IsColliding(Player& p, Enemy& e)
{
    float dx = p.playerXPosition - e.enemyXPosition;
    float dy = p.playerYPosition - e.enemyYPosition;
    float distance = sqrtf(dx * dx + dy * dy);
    return distance < p.radius + e.radius;
}

int main()
{
    InitWindow(1800, 950, "Circle Fight");
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
                    
                        player.TakeDamage(0.5);
                    
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
                    enemy.TakeDamage(30);
                }
            }
        }

        if (!player.IsAlive())
        {
            gameOver = true;
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

        // --- Draw ---
        BeginDrawing();
        ClearBackground(BLACK);

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


   CloseWindow();
   return 0;
}

