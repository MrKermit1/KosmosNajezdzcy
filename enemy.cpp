#include "enemy.h"
#include "raylib.h"
#include "bullet.h"

Enemy::Enemy(){}

Enemy::Enemy(int x, int y, int width, int heigth, int speed, Color color) : Player(x, y, width, heigth, speed)
{
	this->color = color;
}

void Enemy::setColor(Color color)
{
	this->color = color;
}

void Enemy::setShotout(bool shootout)
{
	shootOut = shootout;
}

void Enemy::Spawn()
{ 
	DrawRectangleV(position ,size, color);
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

bool Enemy::IsColorBlack(Color color)
{
	return (color.r == BLACK.r) && (color.g == BLACK.g) && (color.b == BLACK.b) && (color.a == BLACK.a);
}

void Enemy::Shoot()
{	
	if (!IsColorBlack(color))
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
	

}