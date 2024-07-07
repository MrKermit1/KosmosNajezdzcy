#pragma once
#include "player.h"
class Enemy:Player
{
private:
	bool formation[5][10];
public:

	Enemy();
	Enemy(int x, int y, int width, int heigth);

	void Move();
	void Spawn();
	void Shoot();
	
};

