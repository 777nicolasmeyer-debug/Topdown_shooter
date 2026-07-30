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
	int damage;
	Color color;
	bool active;

	void Update(Player& player);
	void TakeDamage(int damage, Enemy& enemy);
	void Draw();
	void FacePlayer(Player& player);
	void RewardPlayer(Player& player);
	
	Vector2 GetCenter();
	Rectangle GetRect();
};