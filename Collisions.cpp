#include "Collisions.h"
#include "Enemy.h"

bool Collisions::isColliding(Projectile& bullet, Enemy& enemy) {
	Vector2 BulletPos = bullet.GetPosition();
	float BulletRadius = bullet.GetRadius();
	if (CheckCollisionCircleRec(BulletPos, BulletRadius ,enemy.GetRect())) {
		return true;
	}
	else {
		return false;
	}
}
bool Collisions::isCollidingEnt(Player& player, Enemy& enemy) {
	if (CheckCollisionRecs(player.GetRect(), enemy.GetRect())) {
		return true;
	}
	else {
		return false;
	}
}