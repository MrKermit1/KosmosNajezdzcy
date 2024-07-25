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

	void Activate();
	void Deactivate();
	bool isActive() const;

	Rectangle getRect() const;
};

