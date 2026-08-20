#pragma once
#include "raylib.h"
#include "Bullet.h"

class Player {
	public:
		Player();

		Vector2 position;
		int speed;
		float dimension;
		float rotation;
		int damage;
		int health;
		int money;
		Color color;
		bool active;
		Texture2D texture;

		void Update();
		void Reset();
		void DrawRec();
		void DrawTex();
		void FaceMouse(Camera2D& camera);
		Vector2 GetCenter();
		Projectile Shoot();
		Rectangle GetRect();
};