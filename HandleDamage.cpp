#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

class HandleDamage {
private: 
	float damageTimer = 2.0;

public:
	void DamagePlayer(Player& player, Enemy& enemy, Projectile& bullet) {
		if (CheckCollisionRecs(player.GetRect(), enemy.GetRect())) {
			
			float frameTime = GetFrameTime();

			damageTimer -= frameTime;
			if (damageTimer <= 0.0) {
				player.health -= enemy.damage;
				damageTimer = 2.0;
			}

			if (player.health <= 0) {
				player.active = false;
			}

		}

		if (CheckCollisionCircleRec(bullet.position, bullet.radius, player.GetRect())) {
			if (bullet.fromPlayer == false) {
				player.health -= enemy.damage;
				bullet.active = false;
				std::cout << player.health;
			}

			if (player.health <= 0) {
				player.active = false;
			}
		}
	}
};