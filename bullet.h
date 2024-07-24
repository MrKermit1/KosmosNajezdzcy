#pragma once
#include "raylib.h"
#include "gameobject.h"
class Bullet : public GameObject
{
private:

	Color color;
	bool active;
public:
	
	Bullet();
	Bullet(int, int, int, int, int, Color);
	void Spawn();
	void Move();
	Rectangle getRect() const;

	void Activate();
	void Deactivate();
	void Test();

	bool isActive() const;
};

