#pragma once
#include "player.h"
class Enemy: public Player
{
private:

	void CheckBorderPos(int pos);

public:

	Enemy();
	Enemy(int x, int y, int width, int heigth, int speed);

	void Move();
	void Spawn();
	void Shoot();
	
};

