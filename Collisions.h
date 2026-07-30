#pragma once
#include "Bullet.h"
class Enemy;
class Player;

class Collisions {
public:
	bool isColliding(Projectile& bullet, Enemy& enemy);
	bool isCollidingEnt(Player& player, Enemy& enemy);
};