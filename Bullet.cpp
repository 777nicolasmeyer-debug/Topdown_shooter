#include "Bullet.h"

void Projectile::Update() {
	position.x += velocity.x;
	position.y += velocity.y;
}

void Projectile::Draw() {
	if (active) {
		DrawCircleV(position, radius, color);
	}
}

Vector2 Projectile::GetPosition() {
	return position;
}

float Projectile::GetRadius() {
	return radius;
}