#pragma once
#include "raylib.h"
#include "Bullet.h"

class Player {
	public:
		Vector2 position;
		float speed;
		float dimension;
		float rotation;
		int damage;
		Color color;

		void Update();
		void Draw();
		void FaceMouse();
		Vector2 GetCenter();
		Projectile Shoot();
};