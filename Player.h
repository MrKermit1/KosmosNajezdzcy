#pragma once
#include "raylib.h"
#include "bullet.h"
#include <vector>
#include <iostream>
class Player
{
protected:

	Vector2 position;
	Vector2 size;
	//Bullet bullet;
	std::vector<Bullet> bullets;

	int speed;

public:
	bool shootOut = false;
	Player();
	Player(float x, float y, float width, float heigth, int speed);

	void Move();
	void Spawn();
	void Shoot();
	void DeleteBullets();
	void DeleteBullet(std::vector<Bullet>::iterator);

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
	std::vector<Bullet>& getBulltets();
	Rectangle getRect();

	

};

