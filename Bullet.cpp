#include "Bullet.h"

void Projectile::Update() {
	position.x += velocity.x;
	position.y += velocity.y;
}

void Projectile::Draw() {
	DrawCircleV(position, radius, color);
}
