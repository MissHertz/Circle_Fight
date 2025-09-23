#include "raylib.h"

#include <algorithm>

#include <cmath>

#include <vector>



struct Player {

    Rectangle rect;

    int health;

    int maxHealth;



    Player(float x, float y, float w, float h, int hp) {

        rect = { x, y, w, h };

        maxHealth = hp;

        health = hp;

    }



    void Draw() {

        DrawRectangleRec(rect, BLUE);

        DrawHealthBar();

    }



    void DrawHealthBar() {

        float barWidth = rect.width;

        float barHeight = 5;

        Vector2 pos = { rect.x, rect.y - 10 };

        DrawRectangleV(pos, { barWidth, barHeight }, RED);

        float healthPercent = (float)health / maxHealth;

        DrawRectangleV(pos, { barWidth * healthPercent, barHeight }, GREEN);

        DrawRectangleLines(pos.x, pos.y, barWidth, barHeight, BLACK);

    }



    void TakeDamage(int dmg) { health = std::max(0, health - dmg); }

    void Heal(int hp) { health = std::min(maxHealth, health + hp); }

    bool IsAlive() { return health > 0; }

};



struct Enemy {

    Rectangle rect;

    int health;

    int maxHealth;

    float speed;



    Enemy(float x, float y, float w, float h, int hp, float spd) {

        rect = { x, y, w, h };

        maxHealth = hp;

        health = hp;

        speed = spd;

    }



    void Draw() {

        DrawRectangleRec(rect, RED);

        DrawHealthBar();

    }



    void DrawHealthBar() {

        float barWidth = rect.width;

        float barHeight = 5;

        Vector2 pos = { rect.x, rect.y - 10 };

        DrawRectangleV(pos, { barWidth, barHeight }, RED);

        float healthPercent = (float)health / maxHealth;

        DrawRectangleV(pos, { barWidth * healthPercent, barHeight }, GREEN);

        DrawRectangleLines(pos.x, pos.y, barWidth, barHeight, BLACK);

    }



    void TakeDamage(int dmg) { health = std::max(0, health - dmg); }

    bool IsAlive() { return health > 0; }



    void Chase(Player& player) {

        float dx = player.rect.x - rect.x;

        float dy = player.rect.y - rect.y;

        float dist = sqrt(dx * dx + dy * dy);

        if (dist > 0) {

            rect.x += speed * dx / dist;

            rect.y += speed * dy / dist;

        }

    }

};



struct HealBlock {

    Rectangle rect;

    bool active;



    HealBlock(float x, float y) {

        rect = { x, y, 20, 20 };

        active = true;

    }



    void Draw() {

        if (active) DrawRectangleRec(rect, GREEN);

    }

};



bool CanDamageEnemy(Player& player, Enemy& enemy) {

    return CheckCollisionRecs(player.rect, enemy.rect);

}



int main() {

    InitWindow(800, 600, "Damage Mechanism");

    SetTargetFPS(60);



    Player player(100, 100, 32, 32, 100);



    std::vector<Enemy> enemies;

    enemies.emplace_back(500, 100, 32, 32, 50, 1.0f);

    enemies.emplace_back(600, 200, 32, 32, 50, 1.2f);

    enemies.emplace_back(400, 300, 32, 32, 50, 0.8f);

    enemies.emplace_back(700, 150, 32, 32, 50, 1.1f);

    enemies.emplace_back(300, 400, 32, 32, 50, 0.9f);



    int damageCooldown = 0;

    bool gameOver = false;



    int enemiesKilled = 0;

    HealBlock* healBlock = nullptr; // nullptr until spawned



    while (!WindowShouldClose()) {

        // --- GAMEPLAY ---

        if (!gameOver) {

            // WASD Movement

            if (IsKeyDown(KEY_D)) player.rect.x += 2;

            if (IsKeyDown(KEY_A)) player.rect.x -= 2;

            if (IsKeyDown(KEY_W)) player.rect.y -= 2;

            if (IsKeyDown(KEY_S)) player.rect.y += 2;



            // Enemy AI

            for (auto& enemy : enemies) {

                if (enemy.IsAlive()) {

                    enemy.Chase(player);

                    // Enemy damages player on collision

                    if (CheckCollisionRecs(player.rect, enemy.rect) && damageCooldown <= 0) {

                        player.TakeDamage(10);

                        damageCooldown = 30;

                    }

                }

            }



            // Player self damage

            if (IsKeyPressed(KEY_SPACE)) player.TakeDamage(5);



            // Player attacks enemy

            if (IsKeyPressed(KEY_E)) {

                for (auto& enemy : enemies) {

                    if (enemy.IsAlive() && CanDamageEnemy(player, enemy)) {

                        enemy.TakeDamage(10);

                        if (!enemy.IsAlive()) {

                            enemiesKilled++;

                        }

                    }

                }

            }



            // Spawn heal block after killing 2 enemies

            if (enemiesKilled >= 2 && healBlock == nullptr) {

                healBlock = new HealBlock(400, 300); // spawn at center

            }



            // Collect heal block

            if (healBlock && healBlock->active && CheckCollisionRecs(player.rect, healBlock->rect)) {

                player.Heal(50);

                healBlock->active = false;

            }



            if (damageCooldown > 0) damageCooldown--;

            if (!player.IsAlive()) gameOver = true;



        }

        else {

            // --- DEATH SCREEN ---

            if (IsKeyPressed(KEY_ENTER)) {

                // Reset player

                player.health = player.maxHealth;

                player.rect.x = 100;

                player.rect.y = 100;



                // Reset enemies

                enemies.clear();

                enemies.emplace_back(500, 100, 32, 32, 50, 1.0f);

                enemies.emplace_back(600, 200, 32, 32, 50, 1.2f);

                enemies.emplace_back(400, 300, 32, 32, 50, 0.8f);

                enemies.emplace_back(700, 150, 32, 32, 50, 1.1f);

                enemies.emplace_back(300, 400, 32, 32, 50, 0.9f);



                enemiesKilled = 0;

                if (healBlock) { delete healBlock; healBlock = nullptr; }



                gameOver = false;

            }

        }



        // --- DRAW ---

        BeginDrawing();

        ClearBackground(RAYWHITE);



        if (!gameOver) {

            player.Draw();



            for (auto& enemy : enemies) {

                if (enemy.IsAlive()) enemy.Draw();

            }



            if (healBlock && healBlock->active) healBlock->Draw();



            DrawText(TextFormat("Player Health: %d", player.health), 10, 10, 20, DARKGREEN);

            DrawText("WASD = Move, SPACE = Self Damage, E = Attack Enemy (must touch)", 10, 40, 20, DARKGRAY);

            DrawText(TextFormat("Enemies killed: %d", enemiesKilled), 10, 70, 20, DARKBLUE);



        }

        else {

            char* msg = (char*)"YOU DIED";

            int fontSize = 80;

            int textWidth = MeasureText(msg, fontSize);

            DrawText(msg, (GetScreenWidth() - textWidth) / 2, GetScreenHeight() / 2 - 60, fontSize, RED);



            char* restartMsg = (char*)"Press ENTER to play again";

            int restartWidth = MeasureText(restartMsg, 30);

            DrawText(restartMsg, (GetScreenWidth() - restartWidth) / 2, GetScreenHeight() / 2 + 20, 30, BLACK);

        }



        EndDrawing();

    }



    if (healBlock) delete healBlock;

    CloseWindow();

    return 0;

}