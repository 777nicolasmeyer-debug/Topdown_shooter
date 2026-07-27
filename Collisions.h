#pragma once
#include "Bullet.h"
class Enemy;

class Collisions {
public:
	bool isColliding(Projectile& bullet, Enemy& enemy);
};