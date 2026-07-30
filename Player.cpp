#include "Player.h"
#include "Bullet.h"
#include <cmath>

void Player::Update() {
	if (IsKeyDown(KEY_W)) {
		position.y -= speed;
	}
	else if (IsKeyDown(KEY_S)) {
		position.y += speed;
	}
	if (IsKeyDown(KEY_A)) {
		position.x -= speed;
	}
	else if (IsKeyDown(KEY_D)) {
		position.x += speed;
	}

}

void Player::FaceMouse() {
	Vector2 playerCenter = GetCenter();
	Vector2 mousePos = GetMousePosition();

	float dx = mousePos.x - playerCenter.x;
	float dy = mousePos.y - playerCenter.y;

	rotation = atan2f(dy, dx) * RAD2DEG;
}


Projectile Player::Shoot() {
	Projectile bullet;
	float spawnOffset = dimension / 2 + 10.0f;

	Vector2 playerCenter = GetCenter();

	bullet.position = {
		playerCenter.x + cosf(rotation * DEG2RAD) * spawnOffset,
		playerCenter.y + sinf(rotation * DEG2RAD) * spawnOffset
	};
	bullet.velocity = { cosf(rotation * DEG2RAD) * 10.f, sinf(rotation * DEG2RAD) * 10.f };
	bullet.active = true;

	return bullet;
}

void Player::Draw() {
	DrawRectanglePro(
		Rectangle{ position.x + dimension / 2, position.y + dimension / 2, dimension, dimension },
		Vector2{ dimension / 2, dimension / 2 },
		rotation,
		color
	);
}


Vector2 Player::GetCenter() {
	return { position.x + dimension / 2, position.y + dimension / 2 };
}

Player::Player() {
	position = { 400, 400};
	speed = 5.0f;
	damage = 5;
	rotation = 0;
	dimension = 50.0f;
	color = RED;
	health = 50;
	money = 0;
	active = true;
}

Rectangle Player::GetRect()
{
	return {
		position.x,
		position.y,
		dimension,
		dimension
	};
}
									