#pragma once
#include "enemy.h"
#include "raylib.h"
#include "player.h"
#include "obstacle.h"
class Enemy_grid
{
private:
	Bullet bullet;
	int speed;
	const static int rows = 5;
	const static int cols = 10;
	constexpr static float shootInterval = 0.50;
	float lastShotTime;
	Enemy aliens[rows][cols];
public:
	void Init();
	Enemy_grid();

	void Lower();
	void Spawn();
	void Move();
	void Shoot();
	void CheckPlayerHits(Player&);
	void CheckAlienHits(Player&, Obstacle*);
};