#include "Enemies.h"

// Constructor
Enemy::Enemy(float x, float y, int hp, float r)
{
    enemyXPosition = x;
    enemyYPosition = y;
    health = hp;
    maxHealth = hp;
    radius = r;
}

// Draw enemy with health bar
void Enemy::DrawEnemy(Color inEnemyColor)
{
    enemyColor = inEnemyColor;

    // Enemy circle
    DrawCircle(enemyXPosition, enemyYPosition, radius, enemyColor);

    // Health bar background
    float barWidth = radius * 2;
    float barHeight = 5;
    float barX = enemyXPosition - radius;
    float barY = enemyYPosition - radius - 10;

    DrawRectangle(barX, barY, barWidth, barHeight, GRAY);

    // Current health portion
    float healthPercent = (float)health / maxHealth;
    DrawRectangle(barX, barY, barWidth * healthPercent, barHeight, GREEN);
}

// Simple enemy AI: moves slowly toward target (player position)
void Enemy::UpdateEnemy(float targetX, float targetY)
{
    float speed = 100.0f * GetFrameTime();

    float dx = targetX - enemyXPosition;
    float dy = targetY - enemyYPosition;
    float distance = sqrtf(dx * dx + dy * dy);

    if (distance > 1.0f)
    {
        enemyXPosition += (dx / distance) * speed;
        enemyYPosition += (dy / distance) * speed;
    }
}

// Damage functions
void Enemy::TakeDamage(int dmg)
{
    health -= dmg;
    if (health < 0) health = 0;
}

void Enemy::Heal(int hp)
{
    health += hp;
    if (health > maxHealth) health = maxHealth;
}

bool Enemy::IsAlive()
{
    return health > 0;
}
