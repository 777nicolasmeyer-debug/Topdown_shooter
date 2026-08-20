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
	Game();
	void Run(int SCREENWIDTH, int SCREENHEIGHT, GameManager& gameManager);
	void Reset(GameManager& gameManager);
	Player& GetPlayer();
	Texture2D GetBackground();
	Music bgMusic;
	Music gameMusic;
	Music deathMusic;

private:
	Texture2D background;
	Sound blasterSound;
	Sound btnClick;
	Camera2D camera;
	Player player;
	std::vector<Projectile>bullets;
	std::vector<Enemy>enemies;
	SpawnLogic spawnLogic;
	Collisions collision;
	GameManager gameManager;
};