#pragma once
#include "player.h"
#include "bullet.h"
class Enemy: public GameObject
{
private:

	Bullet bullet;
	std::vector<Bullet> bullets;
	Color color;
	bool isAlive;
	bool shootOut;

public:

	Enemy(int, int, int, int, int, Color);
	Enemy();

	void Move();
	void Spawn();
	void Shoot();

	bool IsColorBlack(Color);
	bool getIsAlive();
	Bullet getBullet();

	void setColor(Color);
	void setShotout(bool);
	void setIsAlive(bool);

	void DeleteBullet(std::vector<Bullet>::iterator);
	void ResetBullets();
	std::vector<Bullet>& getBulltets();

};

