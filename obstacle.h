#pragma once
#include "gameobject.h"
#include "enemy.h"
#include "brick.h"
#include "raylib.h"
class Obstacle : public GameObject
{
private:
	const static int rows = 3;
	const static int cols = 3;
	Brick bricks[rows][cols];
public:
	Obstacle(int, int);
	void Init();
	void Spawn();
	bool CheckCollisionWithBullets(std::vector<Bullet>::iterator);
};

