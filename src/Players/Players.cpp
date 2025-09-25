#include "Players.h"

// Constructor
Player::Player(float x, float y, int hp, float r)
{
    playerXPosition = x;
    playerYPosition = y;
    health = hp;
    maxHealth = hp;
    radius = r;
}

// Draw player with health bar
void Player::DrawPlayer(Color inPlayerColor)
{
    playerColor = inPlayerColor;

    // Draw player circle
    DrawCircle(playerXPosition, playerYPosition, radius, playerColor);

    // Health bar background
    float barWidth = radius * 2;
    float barHeight = 5;
    float barX = playerXPosition - radius;
    float barY = playerYPosition - radius - 10;

    DrawRectangle(barX, barY, barWidth, barHeight, GRAY);

    // Current health portion
    float healthPercent = (float)health / maxHealth;
    DrawRectangle(barX, barY, barWidth * healthPercent, barHeight, GREEN);
}

// First player controller (WASD + Shift/Ctrl speed modifiers)
void Player::PlayerController()
{
    float playerSpeed = 200.f;
    float increasedplayerSpeed = 1.5f;
    float reducedplayerSpeed = 0.6f;

    if (IsKeyDown(KEY_A))
    {
        if (IsKeyDown(KEY_LEFT_SHIFT))
            playerXPosition -= playerSpeed * increasedplayerSpeed * GetFrameTime();
        else if (IsKeyDown(KEY_LEFT_CONTROL))
            playerXPosition -= playerSpeed * reducedplayerSpeed * GetFrameTime();
        else
            playerXPosition -= playerSpeed * GetFrameTime();
    }

    if (IsKeyDown(KEY_D))
    {
        if (IsKeyDown(KEY_LEFT_SHIFT))
            playerXPosition += playerSpeed * increasedplayerSpeed * GetFrameTime();
        else if (IsKeyDown(KEY_LEFT_CONTROL))
            playerXPosition += playerSpeed * reducedplayerSpeed * GetFrameTime();
        else
            playerXPosition += playerSpeed * GetFrameTime();
    }

    if (IsKeyDown(KEY_W))
    {
        if (IsKeyDown(KEY_LEFT_SHIFT))
            playerYPosition -= playerSpeed * increasedplayerSpeed * GetFrameTime();
        else if (IsKeyDown(KEY_LEFT_CONTROL))
            playerYPosition -= playerSpeed * reducedplayerSpeed * GetFrameTime();
        else
            playerYPosition -= playerSpeed * GetFrameTime();
    }

    if (IsKeyDown(KEY_S))
    {
        if (IsKeyDown(KEY_LEFT_SHIFT))
            playerYPosition += playerSpeed * increasedplayerSpeed * GetFrameTime();
        else if (IsKeyDown(KEY_LEFT_CONTROL))
            playerYPosition += playerSpeed * reducedplayerSpeed * GetFrameTime();
        else
            playerYPosition += playerSpeed * GetFrameTime();
    }
}

// Second player controller (Arrow keys + modifiers)
void Player::Player2Controller()
{
    float player2Speed = 200.f;
    float increasedplayer2Speed = 1.5f;
    float reducedplayer2Speed = 0.6f;

    if (IsKeyDown(KEY_LEFT))
    {
        if (IsKeyDown(KEY_RIGHT_SHIFT))
            playerXPosition -= player2Speed * increasedplayer2Speed * GetFrameTime();
        else if (IsKeyDown(KEY_RIGHT_ALT))
            playerXPosition -= player2Speed * reducedplayer2Speed * GetFrameTime();
        else
            playerXPosition -= player2Speed * GetFrameTime();
    }

    if (IsKeyDown(KEY_RIGHT))
    {
        if (IsKeyDown(KEY_RIGHT_SHIFT))
            playerXPosition += player2Speed * increasedplayer2Speed * GetFrameTime();
        else if (IsKeyDown(KEY_RIGHT_ALT))
            playerXPosition += player2Speed * reducedplayer2Speed * GetFrameTime();
        else
            playerXPosition += player2Speed * GetFrameTime();
    }

    if (IsKeyDown(KEY_UP))
    {
        if (IsKeyDown(KEY_RIGHT_SHIFT))
            playerYPosition -= player2Speed * increasedplayer2Speed * GetFrameTime();
        else if (IsKeyDown(KEY_RIGHT_ALT))
            playerYPosition -= player2Speed * reducedplayer2Speed * GetFrameTime();
        else
            playerYPosition -= player2Speed * GetFrameTime();
    }

    if (IsKeyDown(KEY_DOWN))
    {
        if (IsKeyDown(KEY_RIGHT_SHIFT))
            playerYPosition += player2Speed * increasedplayer2Speed * GetFrameTime();
        else if (IsKeyDown(KEY_RIGHT_ALT))
            playerYPosition += player2Speed * reducedplayer2Speed * GetFrameTime();
        else
            playerYPosition += player2Speed * GetFrameTime();
    }
}

// Damage functions
void Player::TakeDamage(int dmg)
{
    health -= dmg;
    if (health < 0) health = 0;
}

void Player::Heal(int hp)
{
    health += hp;
    if (health > maxHealth) health = maxHealth;
}

bool Player::IsAlive()
{
    return health > 0;
}
