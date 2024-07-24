#pragma once
#include "raylib.h"
#include "bullet.h"
#include <vector>
#include <iostream>
#include "gameobject.h"
class Player : public GameObject
{
protected:
	//Bullet bullet;
	std::vector<Bullet> bullets;
	int score = 0;
	bool shootOut = false;
	int life = 3;

public:
	
	Player();
	Player(float, float, float, float, int);

	void Move();
	void Spawn();
	void Shoot();

	void setLife(int);
	void DeleteBullet(std::vector<Bullet>::iterator);
	int getScore();
	int getLife();
	void addScore(int);

	std::vector<Bullet>& getBulltets();
	Rectangle getRect();

	

};

