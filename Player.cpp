#include "Player.h"
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
	Vector2 mousePosition = GetMousePosition();
	Vector2 direction = { mousePosition.x - position.x, mousePosition.y - position.y };
	rotation = atan2f(direction.y, direction.x) * RAD2DEG;
}

void Player::Draw() {
	DrawRectanglePro(Rectangle{ position.x, position.y, dimension, dimension }, Vector2{dimension / 2, dimension / 2}, rotation, color);
}