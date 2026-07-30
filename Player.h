#pragma once
#include "raylib.h"
#include "Bullet.h"

class Player {
	public:
		Player();

		Vector2 position;
		float speed;
		float dimension;
		float rotation;
		int damage;
		int health;
		int money;
		Color color;
		bool active;

		void Update();
		void Draw();
		void FaceMouse();
		Vector2 GetCenter();
		Projectile Shoot();
		Rectangle GetRect();
};