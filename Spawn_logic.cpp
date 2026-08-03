#include "Spawn_logic.h"

Vector2 SpawnLogic::Spawn(int screenWidth, int screenHeight) {
    Vector2 Locations[4] = {
    {(float)screenWidth - 100.0f, (float)screenHeight - 100.0f},
    {(float)screenWidth - 100.0f, (float)screenHeight + 100.0f},
    {(float)screenWidth + 100.0f, (float)screenHeight - 100.0f},
    {(float)screenWidth + 100.0f, (float)screenHeight + 100.0f}
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