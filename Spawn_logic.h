#pragma once
#include "raylib.h"

class SpawnLogic {
private:
	float spawnTimer = GetRandomValue(1.0, 4.0);

public:

	Vector2 Spawn(int screenWidth, int screenHeight);
	bool CanSpawn ();
};