//#include "Enemies.h"
//#include "raylib.h"
//#include <algorithm>
//#include <cmath>
//#include <vector>
//#include <src/Players/Players.h>
//
//struct Enemy {
//	Rectangle rect;
//
//	int health;
//
//	int maxHealth;
//
//	float speed;
//
//	Enemy(float x, float y, float w, float h, int hp, float spd) {
//		rect = { x, y, w, h };
//		float enemySize1 = 25.f;
//
//		maxHealth = hp;
//
//		health = hp;
//
//		speed = spd;
//	}
//
//	void Draw() {
//		DrawRectangleRec(rect, RED);
//
//		DrawHealthBar();
//	}
//
//	void DrawHealthBar() {
//		float barWidth = rect.width;
//
//		float barHeight = 5;
//
//		Vector2 pos = { rect.x, rect.y - 10 };
//
//		DrawRectangleV(pos, { barWidth, barHeight }, RED);
//
//		float healthPercent = (float)health / maxHealth;
//
//		DrawRectangleV(pos, { barWidth * healthPercent, barHeight }, GREEN);
//
//		DrawRectangleLines(pos.x, pos.y, barWidth, barHeight, BLACK);
//	}
//
//	void TakeDamage(int dmg) { health = std::max(0, health - dmg); }
//
//	bool IsAlive() { return health > 0; }
//
//	void Chase(Player& player) {
//		float dx = player.rect.x - rect.x;
//
//		float dy = player.rect.y - rect.y;
//
//		float dist = sqrt(dx * dx + dy * dy);
//
//		if (dist > 0) {
//			rect.x += speed * dx / dist;
//
//			rect.y += speed * dy / dist;
//		}
//	}
//};