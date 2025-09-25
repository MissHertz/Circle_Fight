#include "raylib.h"
#include <src/Players/Players.h>
#include <src/Enemies/Enemies.h>
#include <vector>

int main() {
    InitWindow(800, 600, "Player + Enemy Classes with Circles");
    SetTargetFPS(60);

    Player player(100, 100, 100);

    std::vector<Enemy> enemies;
    enemies.emplace_back(500, 100, 1.0f);
    enemies.emplace_back(600, 200, 1.2f);
    enemies.emplace_back(400, 300, 0.8f);

    int damageCooldown = 0;

    while (!WindowShouldClose()) {
        // Update
        player.PlayerController();

        for (auto& e : enemies) {
            if (!e.IsAlive()) continue;
            e.Chase(player);

            if (CheckCollisionCircles({ player.playerXPosition, player.playerYPosition }, player.radius,
                { e.x, e.y }, e.radius)) {
                if (damageCooldown <= 0) {
                    player.TakeDamage(10);
                    damageCooldown = 30;
                }
            }
        }

        if (damageCooldown > 0) damageCooldown--;

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        player.DrawPlayer(BLUE);

        for (auto& e : enemies) e.DrawEnemy();

        DrawText(TextFormat("Player HP: %d", player.health), 10, 10, 20, DARKGREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}