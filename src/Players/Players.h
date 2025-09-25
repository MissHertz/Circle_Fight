#pragma once
#include <raylib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

class Player
{
public:
    // Window dimensions
    float windowWidth = 1800;
    float windowHeight = 950;
    float windowHalfWidth = windowWidth / 2;
    float windowHalfHeight = windowHeight / 2;

    // Player properties
    float playerXPosition = windowHalfWidth;
    float playerYPosition = windowHalfHeight;
    float radius = 20.0f;

    Color playerColor{ WHITE };

    // Health system
    int health = 400;
    int maxHealth = 400;

    // Constructor
    Player(float x, float y, int hp, float r);

    // Drawing
    void DrawPlayer(Color inPlayerColor);

    // Controllers
    void PlayerController();
    void Player2Controller();

    // Health management
    void TakeDamage(float dmg);
    void Heal(int hp);
    bool IsAlive();
};
