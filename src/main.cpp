+#include <raylib.h>
#include "src/Players/Players.h"
#include "src/Enemies/Enemies.h"

int main()
{
    InitWindow(1800, 950, "Player & Enemy Example");
    SetTargetFPS(60);

    Player player(900, 475, 100, 20.0f);
    Enemy enemy(200, 200, 50, 20.0f);

    while (!WindowShouldClose())
    {
        // Update
        player.PlayerController(); // WASD controls
        enemy.UpdateEnemy(player.playerXPosition, player.playerYPosition);

        // Example: damage player if enemy gets too close
        float dx = player.playerXPosition - enemy.enemyXPosition;
        float dy = player.playerYPosition - enemy.enemyYPosition;
        float distance = sqrtf(dx * dx + dy * dy);

        if (distance < player.radius + enemy.radius)
        {
            player.TakeDamage(1); // player takes small damage
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        player.DrawPlayer(WHITE);
        enemy.DrawEnemy(RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
