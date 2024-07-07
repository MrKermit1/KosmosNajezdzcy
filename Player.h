#pragma once
#include "raylib.h"
class Player
{
protected:

	Vector2 position;
	Vector2 size;

private:
	float speed;

public:

	Player();
	Player(float x, float y, float width, float heigth);

	void Move();
	void Spawn();
	void Shoot();

	void setPosX(float x);
	void setPosY(float y);
	void setSpeed(float speed);
	void setWidth(int width);
	void setHeigth(int heigth);


	float getPosX();
	float getPosY();
	float getSpeed();
	float getWidth();
	float getHeigth();




};

