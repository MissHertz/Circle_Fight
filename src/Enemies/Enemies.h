
#pragma once
#include "raylib.h"

#include <src/Players/Players.h>

class Enemy {
public:
    float x, y;
    float radius;
    int health;
    int maxHealth;
    float speed;
    bool alive;

    Enemy(float startX, float startY, float spd, int hp = 50, float r = 16.0f);

    void DrawEnemy();
    void Chase(Player& player);
    void TakeDamage(int dmg);
    bool IsAlive();
};