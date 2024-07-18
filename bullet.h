#pragma once
#include "raylib.h"
class Bullet
{
private:

	int bulletSpeed = 1;
	Color color;
	Vector2 bulletPos;

public:
	bool active;
	Bullet();
	Bullet(int posX, int posY, int bulletSpeed, Color color);
	void Spawn();
	void Move();
	Rectangle getRect() const;

	void Activate();
	void Deactivate();
	void Test();

	bool isActive() const;
	Vector2 getBulletPos();
};

