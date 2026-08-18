#pragma once
#include "raylib.h"

class SpawnLogic {
private:
	float spawnTimer = GetRandomValue(1.0, 4.0);
	float pX, pY;

public:

	Vector2 Spawn();
	void PassData(Vector2 playerPos);
	bool CanSpawn ();
};