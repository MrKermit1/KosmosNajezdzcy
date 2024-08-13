#pragma once
#include "gameobject.h"
#include "enemy.h"
#include "raylib.h"
class Brick : public GameObject
{
private:
	Color color;
	bool destroyed;
public: 
	Brick(float, float, float, float);
	Brick();
	void Spawn();

	bool isDestroyed();
	void Destroy();
	void setColor(Color);
	
};

