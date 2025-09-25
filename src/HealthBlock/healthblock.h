#pragma once
#include "raylib.h"

#include <algorithm>

#include <cmath>

#include <vector>
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
