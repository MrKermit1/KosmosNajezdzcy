#pragma once
#include "raylib.h"
#include "bullet.h"
#include <vector>
class Player
{
protected:

	Vector2 position;
	Vector2 size;
	//Bullet bullet;
	std::vector<Bullet> bullets;
	bool shootOut = false;
	
	int speed;

public:

	Player();
	Player(float x, float y, float width, float heigth, int speed);

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

