#pragma once
#include "raylib.h"
class Bullet
{
private:

	int shootCount = 0;
	int bulletSpeed = 1;
	Color color;
	Vector2 bulletPos;

public:
	bool active;
	Bullet();
	Bullet(int posX, int posY, int bulletSpeed, Color color);
	void Spawn();
	void Move();
	void Activate();
	bool isActive();
	Vector2 getBulletPos();
};

