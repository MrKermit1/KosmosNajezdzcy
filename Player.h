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
	int score = 0;
	int speed;
	bool shootOut = false;
	int life = 3;

public:
	
	Player();
	Player(float, float, float, float, int);

	void Move();
	void Spawn();
	void Shoot();


	void setPosX(float);
	void setPosY(float);
	void setSpeed(float);
	void setWidth(int);
	void setHeigth(int);
	void DeleteBullets();
	void setLife(int);
	void DeleteBullet(std::vector<Bullet>::iterator);
	int getScore();
	int getLife();
	void addScore(int);
	
	float getPosX();
	float getPosY();
	float getSpeed();
	float getWidth();
	float getHeigth();

	std::vector<Bullet>& getBulltets();
	Rectangle getRect();

	

};

