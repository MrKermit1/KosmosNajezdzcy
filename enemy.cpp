#include "enemy.h"
#include "raylib.h"
#include "bullet.h"

Enemy::Enemy(){}

Enemy::Enemy(int x, int y, int width, int heigth, int speed) : Player(x, y, width, heigth, speed)
{

}

void Enemy::Spawn()
{ 
	DrawRectangleV(position ,size, WHITE);
	if (shootOut)
	{
		bullet.Spawn();
	}

}

Bullet Enemy::getBullet()
{
	return bullet;
}

void Enemy::Move()
{
	position.x += speed;
	bullet.Move();
}

void Enemy::Shoot()
{	
	if (!shootOut)
	{
		shootOut = true;
		bullet = Bullet(position.x, position.y, 4, RED);
	}

	if (bullet.getBulletPos().y > GetScreenHeight() - 100)
	{
		//bullet = Bullet(position.x, position.y, 4);
		shootOut = false;
	}

}