#pragma once
#include "raylib.h"
#include "Player.h"
#include "Collisions.h"

class Enemy {
public:
	Enemy();
	Vector2 position;
	float width;
	float height;
	
	float shootTimer = GetRandomValue(3, 5);
	float rotation;
	float speed;
	int health;
	int damage;
	Color color;
	bool active;
	Texture2D texture;

	void Update(Player& player);
	void TakeDamage(int damage, Enemy& enemy);
	void DrawRec();
	void DrawTex();
	Projectile Shoot();
	void FacePlayer(Player& player);
	void RewardPlayer(Player& player);
	
	Vector2 GetCenter();
	Rectangle GetRect();
};