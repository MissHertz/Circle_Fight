#include "Enemies.h"
#include <cmath>
#include <algorithm>

Enemy::Enemy(float startX, float startY, float spd, int hp, float r) {
    x = startX;
    y = startY;
    radius = r;
    maxHealth = hp;
    health = hp;
    speed = spd;
    alive = true;
}

void Enemy::DrawEnemy() {
    if (!alive) return;

    DrawCircle(x, y, radius, RED);

    // Health bar
    float barWidth = 32;
    float barHeight = 4;
    float percent = (float)health / maxHealth;
    DrawRectangle(x - barWidth / 2, y - radius - 8, barWidth, barHeight, RED);
    DrawRectangle(x - barWidth / 2, y - radius - 8, barWidth * percent, barHeight, GREEN);
    DrawRectangleLines(x - barWidth / 2, y - radius - 8, barWidth, barHeight, BLACK);
}

void Enemy::Chase(Player& player) {
    if (!alive) return;

    float dx = player.playerXPosition - x;
    float dy = player.playerYPosition - y;
    float dist = sqrtf(dx * dx + dy * dy);

    if (dist > 0) {
        x += speed * dx / dist;
        y += speed * dy / dist;
    }
}

void Enemy::TakeDamage(int dmg) {
    health = std::max(0, health - dmg);
    if (health <= 0) alive = false;
}

bool Enemy::IsAlive() {
    return alive;
}