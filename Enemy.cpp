#include "Enemy.h"
#include "Player.h"
#include "raylib.h"
#include <cmath>
class Collisions;
class Projectile;

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

void Enemy::DrawRec() {
	DrawRectanglePro(
		Rectangle{ position.x + width / 2, position.y + height / 2, width, height },
		Vector2{ width / 2, height / 2 },
		rotation,
		color
	);
}

Enemy::Enemy() {
	
	speed = GetRandomValue(8, 9);
	width = 50.0f;
	height = 50.0f;
	color = BLUE;
	active = true;
	health = 10;
	damage = 5.0f;
	texture = LoadTexture("../../../assets/red_tank.png");
}

void Enemy::DrawTex()
{
	Rectangle source = {
		0, 0,
		(float)texture.width,
		(float)texture.height
	};

	float scale = 0.2;
	Rectangle dest = {
	GetCenter().x,
	GetCenter().y,
	width,
	height
	};

	Vector2 origin = {
		width / 2.0f,
		height / 2.0f
	};

	DrawTexturePro(
		texture,
		source,
		dest,
		origin,
		rotation - 90,
		RAYWHITE
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

void Enemy::TakeDamage(int damage, Enemy& enemy) {
		health -= damage;
	if (health <= 0) {
		active = false;
	}
}

void Enemy::RewardPlayer(Player& player) {
	player.money += 10;
}

Projectile  Enemy::Shoot() {
	Projectile bullet;
	bullet.fromPlayer = false;
	float spawnOffset = width / 2 + 10.0f;

	Vector2 playerCenter = GetCenter();

	bullet.position = {
		playerCenter.x + cosf(rotation * DEG2RAD) * spawnOffset,
		playerCenter.y + sinf(rotation * DEG2RAD) * spawnOffset
	};
	bullet.velocity = { cosf(rotation * DEG2RAD) * 20.f, sinf(rotation * DEG2RAD) * 20.f };
	bullet.active = true;

	return bullet;
}

