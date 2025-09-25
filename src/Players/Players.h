#pragma once
#include "raylib.h"

class Player {
public:
    float playerXPosition;
    float playerYPosition;
    Color playerColor;

    int health;
    int maxHealth;
    float radius;

    Player(float x, float y, int hp = 100, float r = 20.0f);

    void DrawPlayer(Color inPlayerColor);
    void PlayerController();   // WASD
    void Player2Controller();  // Arrow keys
    void TakeDamage(int dmg);
    void Heal(int hp);
    bool IsAlive();
};