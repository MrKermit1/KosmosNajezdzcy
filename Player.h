#pragma once
#include "raylib.h"
#include "bullet.h"
#include <vector>
#include <iostream>
#include "gameobject.h"

class Player : public GameObject
{
protected:
	Texture2D texture;
	Image image;
	std::vector<Bullet> bullets;
	int score;
	bool shootOut;
	int life;
	bool textureLoaded;

public:
	
	Player();
	Player(float, float, float, float, int, int);

	void Move();
	void Spawn();
	void Shoot();

	void setLife(int);
	void DeleteBullet(std::vector<Bullet>::iterator);
	int getScore();
	int getLife();
	void addScore(int);
	void ResetBullets();

	std::vector<Bullet>& getBulltets();
	Rectangle getRect();
	void LoadTextures();
	void UnloadTextures();
	

};

