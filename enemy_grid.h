#pragma once
#include "enemy.h"
class Enemy_grid : Enemy
{
public:
	static const int rows = 5;
	static const int cols = 10;

	Enemy grid[cols][rows];

	Enemy_grid();

	void Init();
	void Spawn();
	void Lower();
	void Move();
};

