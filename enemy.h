#pragma once
#include "player.h"
#include "bullet.h"
class Enemy: public Player
{
private:

	Bullet bullet;
	bool shootOut = false;
public:

	Enemy(int x, int y, int width, int heigth, int speed);
	Enemy();

	void Move();
	void Spawn();
	void Shoot();

	Bullet getBullet();

};

