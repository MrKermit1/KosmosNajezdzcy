#pragma once
#include "raylib.h"
class Bullet
{
private:

	int bulletSpeed = 1;
	Color color;
	Vector2 bulletPos;
	bool active;
public:
	
	Bullet();
	Bullet(int, int, int, Color);
	void Spawn();
	void Move();
	Rectangle getRect() const;

	void Activate();
	void Deactivate();
	void Test();

	bool isActive() const;
	Vector2 getBulletPos();
};

