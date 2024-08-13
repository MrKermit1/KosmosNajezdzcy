#pragma once
#include "player.h"
#include "bullet.h"
class Enemy: public GameObject
{
private:

	Bullet bullet;
	Texture2D texture;
	Image image;
	std::vector<Bullet> bullets;
	Color color;
	bool isAlive;
	bool shootOut;
	bool textureLoaded;

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
	std::vector<Bullet>& getBulltets();
	void LoadTextures();
	void UnloadTextures();

};

