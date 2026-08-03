

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

void Player::FaceMouse(Camera2D& camera) {
	Vector2 playerCenter = GetCenter();
	Vector2 mousePos = GetScreenToWorld2D(GetMousePosition(), camera);

	float dx = mousePos.x - playerCenter.x;
	float dy = mousePos.y - playerCenter.y;

	rotation = atan2f(dy, dx) * RAD2DEG;
}


Projectile Player::Shoot() {
	Projectile bullet;
	bullet.fromPlayer = true;
	float spawnOffset = dimension / 2 + 10.0f;

	Vector2 playerCenter = GetCenter();

	bullet.position = {
		playerCenter.x + cosf(rotation * DEG2RAD) * spawnOffset,
		playerCenter.y + sinf(rotation * DEG2RAD) * spawnOffset
	};
	bullet.velocity = { cosf(rotation * DEG2RAD) * 20.f, sinf(rotation * DEG2RAD) * 20.f };
	bullet.active = true;

	return bullet;
}

void Player::DrawRec() {
	DrawRectanglePro(
		Rectangle{ position.x + dimension / 2, position.y + dimension / 2, dimension, dimension },
		Vector2{ dimension / 2, dimension / 2 },
		rotation,
		color
	);
}

void Player::DrawTex()
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
	dimension,
	dimension
	};

	Vector2 origin = {
		dimension / 2.0f,
		dimension / 2.0f
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



Player::Player() {
	position = { 400, 400 };
	speed = 10;
	damage = 5;
	rotation = 0;
	dimension = 60.0f;
	color = RED;
	health = 50;
	money = 0;
	active = true;
	texture = LoadTexture("../../../assets/blue_tank.png");
}




Vector2 Player::GetCenter() {
	return { position.x + dimension / 2, position.y + dimension / 2 };
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
									