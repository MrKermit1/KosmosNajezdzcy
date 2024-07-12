#pragma once
#include "enemy.h"
class Enemy_grid
{
private:
	Bullet bullet;
	int speed = 5;
	const static int rows = 5;
	const static int cols = 10;
	bool isAlive[rows][cols];
	float lastShotTime;
	constexpr static float shootInterval = 0.50;
	Enemy aliens[rows][cols];
public:
	void Init();
	Enemy_grid();

	void Lower(bool);
	void Spawn();
	void Move();
	void Shoot();
};