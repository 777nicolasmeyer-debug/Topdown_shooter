#pragma once
#include "raylib.h"

class Projectile {
public:
	Vector2 position;
	Vector2 velocity;
	float radius = 5.f;
	bool active;
	Color color;

	void Update();
	void Draw();
	Vector2 GetPosition();
	float GetRadius();
};