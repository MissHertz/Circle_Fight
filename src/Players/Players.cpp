
#include "Players.h"
#include <algorithm>

Player::Player(float x, float y, int hp, float r) {
    playerXPosition = x;
    playerYPosition = y;
    maxHealth = hp;
    health = hp;
    radius = r;
    playerColor = BLUE;
}

void Player::DrawPlayer(Color inPlayerColor) {
    playerColor = inPlayerColor;
    DrawCircle(playerXPosition, playerYPosition, radius, playerColor);

    // Health bar
    float barWidth = 40;
    float barHeight = 5;
    float percent = (float)health / maxHealth;
    DrawRectangle(playerXPosition - barWidth / 2, playerYPosition - radius - 10, barWidth, barHeight, RED);
    DrawRectangle(playerXPosition - barWidth / 2, playerYPosition - radius - 10, barWidth * percent, barHeight, GREEN);
    DrawRectangleLines(playerXPosition - barWidth / 2, playerYPosition - radius - 10, barWidth, barHeight, BLACK);
}

void Player::PlayerController() {
    float speed = 200.f;
    float fast = 1.5f;
    float slow = 0.6f;

    if (IsKeyDown(KEY_A)) {
        if (IsKeyDown(KEY_LEFT_SHIFT)) playerXPosition -= speed * fast * GetFrameTime();
        else if (IsKeyDown(KEY_LEFT_CONTROL)) playerXPosition -= speed * slow * GetFrameTime();
        else playerXPosition -= speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_D)) {
        if (IsKeyDown(KEY_LEFT_SHIFT)) playerXPosition += speed * fast * GetFrameTime();
        else if (IsKeyDown(KEY_LEFT_CONTROL)) playerXPosition += speed * slow * GetFrameTime();
        else playerXPosition += speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_W)) {
        if (IsKeyDown(KEY_LEFT_SHIFT)) playerYPosition -= speed * fast * GetFrameTime();
        else if (IsKeyDown(KEY_LEFT_CONTROL)) playerYPosition -= speed * slow * GetFrameTime();
        else playerYPosition -= speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_S)) {
        if (IsKeyDown(KEY_LEFT_SHIFT)) playerYPosition += speed * fast * GetFrameTime();
        else if (IsKeyDown(KEY_LEFT_CONTROL)) playerYPosition += speed * slow * GetFrameTime();
        else playerYPosition += speed * GetFrameTime();
    }
}

void Player::Player2Controller() {
    float speed = 200.f;
    float fast = 1.5f;
    float slow = 0.6f;

    if (IsKeyDown(KEY_LEFT)) {
        if (IsKeyDown(KEY_RIGHT_SHIFT)) playerXPosition -= speed * fast * GetFrameTime();
        else if (IsKeyDown(KEY_RIGHT_ALT)) playerXPosition -= speed * slow * GetFrameTime();
        else playerXPosition -= speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_RIGHT)) {
        if (IsKeyDown(KEY_RIGHT_SHIFT)) playerXPosition += speed * fast * GetFrameTime();
        else if (IsKeyDown(KEY_RIGHT_ALT)) playerXPosition += speed * slow * GetFrameTime();
        else playerXPosition += speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_UP)) {
        if (IsKeyDown(KEY_RIGHT_SHIFT)) playerYPosition -= speed * fast * GetFrameTime();
        else if (IsKeyDown(KEY_RIGHT_ALT)) playerYPosition -= speed * slow * GetFrameTime();
        else playerYPosition -= speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_DOWN)) {
        if (IsKeyDown(KEY_RIGHT_SHIFT)) playerYPosition -= speed * fast * GetFrameTime();
        else if (IsKeyDown(KEY_RIGHT_ALT)) playerYPosition -= speed * slow * GetFrameTime();
        else playerYPosition -= speed * GetFrameTime();
    }
}

void Player::TakeDamage(int dmg) {
    health = std::max(0, health - dmg);
}

void Player::Heal(int hp) {
    health = std::min(maxHealth, health + hp);
}

bool Player::IsAlive() {
    return health > 0;
}