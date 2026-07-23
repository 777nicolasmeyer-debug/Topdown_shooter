#pragma once
#include "raylib.h"
#include "Player.h"

class Enemy {
public:
	Vector2 position;
	float width;
	float height;
	float rotation;
	float speed;
	Color color;

	void Update(Player& player);
	void Draw();
	void FacePlayer(Player& player);
	Vector2 GetCenter();
};