#pragma once
#include <vector>
#include "raylib.h"
class GameObject
{
protected:
	Vector2 position;
	Vector2 size;
	int speed;
public:

	GameObject(float, float, float, float, int);
	GameObject();

	void Move();
	void Spawn();
	void Shoot();


	void setPosX(float);
	void setPosY(float);
	void setSpeed(float);
	void setWidth(int);
	void setHeigth(int);
	Vector2 getPosition();
	Rectangle getRect();
	float getPosX();
	float getPosY();
	float getWidth();
	float getSpeed();
	float getHeigth();
};

class gameobject
{
};

