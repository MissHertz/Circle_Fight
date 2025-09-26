#pragma once
#include <raylib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

class Enemy
{
public:
    // Enemy properties
    float enemyXPosition;
    float enemyYPosition;
    float radius = 20.0f;

    Color enemyColor = { 255, 255, 255, 200 };
    Color inEnemyColor;

    // Health system
    int health = 50;
    int maxHealth = 50;

    // Constructor
    Enemy(float x, float y, int hp, float r);

    // Drawing
    void DrawEnemy();

    // Enemy chase
    void UpdateEnemy(float targetX, float targetY);

    // Health management
    void TakeDamage(int dmg);
    void Heal(int hp);
    bool IsAlive();
};