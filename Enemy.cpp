#include "Enemy.h"
#include "Player.h"
#include "raylib.h"
#include <cmath>
Collisions collision;
Projectile bullet;
Enemy enemy;

void Enemy::Update(Player& player) {
	if (player.position.x > position.x) {
		position.x += speed;
	}

	else if (player.position.x < position.x) {
		position.x -= speed;
	}

	if (player.position.y > position.y) {
		position.y += speed;
	}
	
	else if (player.position.y < position.y) {
		position.y -= speed;
	}
}

Vector2 Enemy::GetCenter() {
	return { position.x + width / 2, position.y + height / 2 };
}

void Enemy::FacePlayer(Player& player) {
	Vector2 enemyCenter = GetCenter();
	Vector2	playerCenter = player.GetCenter();

	float dx = playerCenter.x - enemyCenter.x;
	float dy = playerCenter.y - enemyCenter.y;

	rotation = atan2f(dy, dx) * RAD2DEG;

}

void Enemy::Draw() {
	DrawRectanglePro(
		Rectangle{ position.x + width / 2, position.y + height / 2, width, height },
		Vector2{ width / 2, height / 2 },
		rotation,
		color
	);
}

Rectangle Enemy::GetRect()
{
	return {
		position.x,
		position.y,
		width,
		height
	};
}

void Enemy::TakeDamage(int damage) {
	if (collision.isColliding(bullet, enemy)) {
		health -= damage;
	}
	if (health <= 0) {
		active = false;
	}
}