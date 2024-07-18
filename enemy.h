#pragma once
#include "player.h"
#include "bullet.h"
class Enemy: public Player
{
private:

	Bullet bullet;
	Color color;
	bool shootOut = false;
public:

	Enemy(int, int, int, int, int, Color);
	Enemy();

	void Move();
	void Spawn();
	void Shoot();

	bool IsColorBlack(Color);
	Bullet getBullet();
	void setColor(Color);
	void setShotout(bool);

};

