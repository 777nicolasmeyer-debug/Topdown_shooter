#include "Spawn_logic.h"

void SpawnLogic::PassData(Vector2 playerPos) {
    pX = playerPos.x;
    pY = playerPos.y;
}

Vector2 SpawnLogic::Spawn() {
    Vector2 Locations[4] = {
    {(float) pX - 400.0f, (float)pY - 400.0f},
    {(float) pX - 400.0f, (float)pY + 400.0f},
    {(float) pX + 400.0f, (float)pY - 400.0f},
    {(float) pX + 400.0f, (float)pY + 400.0f}
    };

	int locationNumber = GetRandomValue(0, 4);
	return Locations[locationNumber];
};

bool SpawnLogic::CanSpawn() {
    float frameTime = GetFrameTime();
    spawnTimer -= frameTime;

    if (spawnTimer <= 0.0f) {
        spawnTimer = GetRandomValue(1.0, 1.5);
        return true;
    }
    return false;
}