#pragma once
#include "raylib.h"
#include "Player.h"
#include "Collisions.h"

class Enemy {
public:
	Vector2 position;
	float width;
	float height;
	float rotation;
	float speed;
	int health;
	Color color;
	bool active;

	void Update(Player& player);
	void TakeDamage(int damage);
	void Draw();
	void FacePlayer(Player& player);
	Vector2 GetCenter();
	Rectangle GetRect();
};