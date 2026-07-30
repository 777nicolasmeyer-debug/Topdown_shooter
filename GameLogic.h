#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Spawn_logic.h"
#include "Collisions.h"
#include "GameManager.h"
#include "GameState.h"
#include <vector>


class Game {
public:
	void Run(int SCREENWIDTH, int SCREENHEIGHT, GameManager& gameManager);
	Player& GetPlayer();

private:
	Player player;
	std::vector<Projectile>bullets;
	std::vector<Enemy>enemies;
	SpawnLogic spawnLogic;
	Collisions collision;
	GameManager gameManager;
};